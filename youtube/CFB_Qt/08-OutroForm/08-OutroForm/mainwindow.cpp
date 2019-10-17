#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "janela2.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    janela = new Janela2(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    Janela2 janela;
//    janela.exec();

//    janela->exec();
    janela->show();
}
