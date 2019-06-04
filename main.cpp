#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "authorization.h"
#include "logictest.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Authorization user;
    LogicTest ltest;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.rootContext()->setContextProperty("ltest", &ltest);
    engine.rootContext()->setContextProperty("user", &user);
    QObject::connect(&user, &Authorization::nameChanged, &ltest, &LogicTest::setUser);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    QObject *stackView = engine.rootObjects()[0]->findChild<QObject*>("baseView");
    QObject::connect(&ltest, &LogicTest::finishTest, &app, [stackView](){qDebug()<<"stackView.pop()";
        QMetaObject::invokeMethod(stackView, "home");});
    QObject::connect(&user, &Authorization::startTest, &app, [stackView](){
        QMetaObject::invokeMethod(stackView, "firstTest");});

    return app.exec();
}
