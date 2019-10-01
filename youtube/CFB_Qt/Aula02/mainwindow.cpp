#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
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
    QString css = "background-color:#f00;color:#000";
    ui->label->setStyleSheet(css);
    ui->label->setText("ChangeText");
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::aboutQt(this);
    QMessageBox::information(this, "CFB Cursos", "Messagem informativa");
    QMessageBox::question(this, "CFB Cursos", "Messagem Pergunta");
    QMessageBox::warning(this, "CFB Cursos", "Messagem de Alerta");
    QMessageBox::critical(this, "CFB Cursos", "Messagem Critica");
    qFatal("Messagem para terminar a aplicação");

}

void MainWindow::on_pushButton_3_clicked()
{
//    int ret = QMessageBox::question(this, "CFB Cursos", "Escolha uma opção");
//    int ret = QMessageBox::question(this, "CFB Cursos", "Escolha uma opção", QMessageBox::Yes | QMessageBox::No);
    QMessageBox::StandardButton ret = QMessageBox::question(this, "CFB Cursos", "Deseja encerrar?", QMessageBox::Yes | QMessageBox::No);
    if(ret == QMessageBox::Yes){
        qDebug() << "Yes pressionado";
        QApplication::quit();
    }else{
        qDebug() << "No Pressionado";
    }
}
