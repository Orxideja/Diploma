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
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
