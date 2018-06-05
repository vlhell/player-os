#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "myplayer.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<MyPlayer>("com.myplayer", 1, 0, "MyPlayer");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
