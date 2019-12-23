#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "errorlevel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterUncreatableType<ErrorLevel>("com.solid.errorlevel", 1, 0,"ErrorLevel",
                                           "Cannot create Error Level type in QML.Not allowed.");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
