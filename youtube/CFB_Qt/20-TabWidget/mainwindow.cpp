#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "form_tab.h"

int i;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    i = ui->tabWidget->count();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
    i--;
}

void MainWindow::on_btAddTab_clicked()
{
    i++;
    ui->tabWidget->addTab(new QWidget(), "New Tab:" + QString::number(i));
}

void MainWindow::on_pushButton_2_clicked()
{
    i++;
    ui->tabWidget->addTab(new Form_tab(), "Cadastro");
}

void MainWindow::on_pushButton_clicked()
{
    i--;
    ui->tabWidget->removeTab(i);
}
