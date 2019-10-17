#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QDebug>
#include <QMessageBox>

QString local = "/home/solid/Courses/youtube/CFB_Qt/22-Diretorios";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir unidades;

    foreach(QFileInfo dir ,unidades.drives()){
        ui->comboBox->addItem(dir.absolutePath());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
     QDir conteudo(arg1);

     ui->listWidget->clear();

     qDebug() << "size : " + QString::number(conteudo.count());


//     ui->listWidget->addItem(conteudo.rootPath());

     foreach(QFileInfo dir ,conteudo.entryInfoList()){
         if(dir.isDir()){
            ui->listWidget->addItem(dir.canonicalPath());
         }
//         else if(dir.isFile()){
//             ui->listWidget->addItem("Arquivo: " + dir.absolutePath());
//         }

     }

//     foreach(QString n, conteudo.entryList()){

//         qDebug() << n;
//     }
}

void MainWindow::on_pushButton_clicked()
{
    QString local = ui->listWidget->currentItem()->text();
//    QMessageBox::about(this, "teste", local);
    QString nomeDir = "/" + ui->lineEdit->text();
    QDir dir(local + nomeDir);
    if(dir.exists()){
        QMessageBox::about(this, "pasta", "Diretorio ja existe");
    }else{
        dir.mkdir(local + nomeDir);
        ui->listWidget->clear();
        ui->listWidget->addItem(ui->comboBox->currentText());
        QDir conteudo(ui->comboBox->currentText());

        foreach(QFileInfo info, conteudo.entryInfoList()){
            if(info.isDir()){
                ui->listWidget->addItem(info.absoluteFilePath());
            }
        }
    }

    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString local = ui->listWidget->currentItem()->text();

    QDir dir(local);
    if(!dir.exists()){
        QMessageBox::about(this, "pasta", "Diretorio ja existe");
    }else{
        dir.rmdir(local);
        ui->listWidget->clear();
        ui->listWidget->addItem(ui->comboBox->currentText());
        QDir conteudo(ui->comboBox->currentText());

        foreach(QFileInfo info, conteudo.entryInfoList()){
            if(info.isDir()){
                ui->listWidget->addItem(info.absoluteFilePath());
            }
        }
    }
}
