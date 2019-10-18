#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *telaSplash = new QSplashScreen() ;
    telaSplash->setPixmap(QPixmap(":/splash/img/high-moon-studios-logo-600x300.jpg"));
    telaSplash->show();

    MainWindow w;

    QTimer::singleShot(2000, telaSplash, &QSplashScreen::close);
    QTimer::singleShot(2000, &w, &MainWindow::show);

//    w.show();

    return a.exec();
}
