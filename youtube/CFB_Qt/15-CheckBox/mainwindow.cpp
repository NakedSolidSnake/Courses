#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

QString msg = "";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->checkBox, &QCheckBox::stateChanged, this, &MainWindow::appendMsg);
    connect(ui->checkBox_2, &QCheckBox::stateChanged, this, &MainWindow::appendMsg);
    connect(ui->checkBox_3, &QCheckBox::stateChanged, this, &MainWindow::appendMsg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool cb1, cb2, cb3;
    cb1 = ui->checkBox->isChecked();
    cb2 = ui->checkBox_2->isChecked();
    cb3 = ui->checkBox_3->isChecked();

    msg = "";

    if(cb1){
        msg += " CB1 checked ";
    }
    if (cb2) {
        msg += " CB2 checked ";
    }
    if (cb3) {
        msg += " CB3 checked ";
    }

    QMessageBox::information(this, "Result", msg, QMessageBox::StandardButton::Ok);

}

void MainWindow::on_pushButton_2_clicked()
{
    bool cb[3];
    cb[0] = ui->checkBox->isChecked();
    cb[1] = ui->checkBox_2->isChecked();
    cb[2] = ui->checkBox_3->isChecked();

    msg = "";

    for (int i = 0; i < 3; i++) {
        if(cb[i]){
            msg += "CB" + QString::number(i + 1) + " Checked ";
        }
    }

    QMessageBox::information(this, "Result", msg, QMessageBox::StandardButton::Ok);

}

void MainWindow::appendMsg()
{
    msg = "";
    if(ui->checkBox->isChecked()){
        msg += " CB1 checked ";
    }
    if(ui->checkBox_2->isChecked()){
        msg += " CB2 checked ";
    }

    if(ui->checkBox_3->isChecked()){
        msg += " CB3 checked ";
    }

    qDebug() << msg;
}
