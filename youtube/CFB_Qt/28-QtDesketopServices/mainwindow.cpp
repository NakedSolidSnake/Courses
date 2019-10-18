#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btSite_clicked()
{
    QString link = "http://www.cfbcursos.com.br";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_btBloco_clicked()
{
    QString link = "file:///snap/bin/gnome-calculator";
    QDesktopServices::openUrl(QUrl(link));
}
