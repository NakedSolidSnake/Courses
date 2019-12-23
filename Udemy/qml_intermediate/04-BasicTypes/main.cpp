#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "cppclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    CppClass cpp;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("CppClass", &cpp);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
