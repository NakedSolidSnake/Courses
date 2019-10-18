#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tempo = new QTimer(this);
//    tempo->setSingleShot(true);

    connect(tempo, &QTimer::timeout, this, &MainWindow::minhaFuncao);
    tempo->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::minhaFuncao()
{
    qDebug() << "Timeout" ;
//    tempo->start(1000);
}
