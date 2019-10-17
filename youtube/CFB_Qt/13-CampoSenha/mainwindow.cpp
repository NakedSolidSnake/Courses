#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->txtPassword->setEchoMode(QLineEdit::Password);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btLogin_clicked()
{
    QString username = ui->txtUsername->text();
    QString password = ui->txtPassword->text();

    if(password == "senha" && username == "solid"){
        QMessageBox::information(this, "Access", "Access Granted.", QMessageBox::Ok);
    }else{
        QMessageBox::warning(this, "Access", "Access Denied.", QMessageBox::Ok);
    }

}
