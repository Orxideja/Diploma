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
    QObject::connect(&user, &Authorization::startTest, &ltest, &LogicTest::startTest);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    QObject *stackView = engine.rootObjects()[0]->findChild<QObject*>("baseView");
    QObject::connect(&ltest, &LogicTest::finishTest, &app, [stackView](){
        QMetaObject::invokeMethod(stackView, "home");});
    QObject::connect(&ltest, &LogicTest::startTest, &app, [stackView](){
        QMetaObject::invokeMethod(stackView, "previewTest");});
    QObject::connect(&ltest, &LogicTest::doEnterTest, &app, [stackView](){
        QMetaObject::invokeMethod(stackView, "enterTest");});
    QObject::connect(&ltest, &LogicTest::showResults, &app, [stackView](){
        QMetaObject::invokeMethod(stackView, "endAllTests");});

    return app.exec();
}
