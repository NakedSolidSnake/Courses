#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVector>
#include <QDebug>

QVector<int> mark;

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

void MainWindow::on_bt_add_clicked()
{
    if(ui->txtItem->text() != ""){
        ui->listWidget->addItem(ui->txtItem->text());
        ui->txtItem->clear();
        ui->txtItem->setFocus();
    }
}

void MainWindow::on_bt_addMany_clicked()
{
    QListWidgetItem *item1 = new QListWidgetItem("C++");
    QListWidgetItem *item2 = new QListWidgetItem("Java");
    QListWidgetItem *item3 = new QListWidgetItem("C");
    QListWidgetItem *item4 = new QListWidgetItem("C#");

    ui->listWidget->addItem(item1);
    ui->listWidget->addItem(item2);
    ui->listWidget->addItem(item3);
    ui->listWidget->addItem(item4);

}

void MainWindow::on_btMark_clicked()
{
    ui->listWidget->currentItem()->setForeground(Qt::lightGray);
    ui->listWidget->currentItem()->setBackground(Qt::darkGreen);
    mark.push_back(ui->listWidget->currentRow());
    qDebug() << "Mark:" << mark;
}


void MainWindow::on_bt_Unmark_clicked()
{
    ui->listWidget->currentItem()->setForeground(Qt::black);
    ui->listWidget->currentItem()->setBackground(Qt::white);
    mark.erase(mark.begin() + ui->listWidget->currentRow());
    qDebug() << "Unmark:" << mark;
}

void MainWindow::on_bt_unmarkall_clicked()
{
    while(!mark.isEmpty()){
        ui->listWidget->setCurrentRow(mark.last());
        ui->listWidget->currentItem()->setForeground(Qt::black);
        ui->listWidget->currentItem()->setBackground(Qt::white);
        mark.pop_back();
    }
    qDebug() << "Mark:" << mark;
}
