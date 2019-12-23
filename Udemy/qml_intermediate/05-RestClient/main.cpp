#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "appwrapper.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    AppWrapper wrapper;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("Wrapper", &wrapper);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
