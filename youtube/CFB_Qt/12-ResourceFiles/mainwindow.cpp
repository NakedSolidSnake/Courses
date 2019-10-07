#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap img1(":/imgs/imagens/circuito_motores.jpg");
    ui->label->setScaledContents(true);
    ui->label->setPixmap(img1);
    QPixmap img2(":/imgs/imagens/cms168_sch.jpg");
    ui->label_2->setScaledContents(true);
    ui->label_2->setPixmap(img2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
