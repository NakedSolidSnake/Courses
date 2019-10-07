#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::on_pushButton_clicked()
{
    QString nome = ui->lineEdit->text();
    QString fone = ui->lineEdit_2->text();
    QString email = ui->lineEdit_3->text();

    QMessageBox::information(this, "Dados digitados", "Nome:"+nome+"\nFone:" + fone + "\nemail:" + email);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();

    ui->lineEdit->setFocus();
}
