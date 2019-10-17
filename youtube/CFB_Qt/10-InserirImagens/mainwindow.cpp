#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString path = "/home/solid/Desktop/RaspberryProjects/imagens/ponteH.jpg";
    this->setImage(path);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setImage(QString &path)
{
    QPixmap image(path);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(image.scaled(300, 100, Qt::KeepAspectRatio));
}

void MainWindow::on_pushButton_clicked()
{
   QString path = "/home/solid/Desktop/RaspberryProjects/imagens/servo.jpg";
   this->setImage(path);
}
