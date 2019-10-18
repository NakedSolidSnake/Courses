#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QString local = "/home/solid/Courses/youtube/CFB_Qt/23-QFile/";
QString file = "file.txt";

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

void MainWindow::on_btGravar_clicked()
{
    QFile arquivo(local + file);
    if(!arquivo.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "ERRO", "Erro ao abrir arquivo");
    }

    QTextStream saida(&arquivo);
    QString texto = ui->plainTextEdit->toPlainText();

    saida << texto;
    arquivo.flush();
    arquivo.close();
}

void MainWindow::on_btLer_clicked()
{
    QFile arquivo(local + file);
    if(!arquivo.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "ERRO", "Erro ao abrir arquivo");
    }

    ui->plainTextEdit->clear();

    QString text;
    QTextStream input(&arquivo);

//    input >> text;

    text = input.readAll();

    ui->plainTextEdit->setPlainText(text);
    arquivo.flush();
    arquivo.close();


}
