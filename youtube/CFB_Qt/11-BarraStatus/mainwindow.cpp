#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->addPermanentWidget(ui->btCFB);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btOk_clicked()
{
    QString nome = ui->txtNome->text();
    QString email = ui->txtEmail->text();
    ui->statusBar->showMessage("Nome: " + nome + " | email: " + email);
}

void MainWindow::on_btCFB_clicked()
{
    QString msg = "www.youtube.com/cfbcursos";
    ui->statusBar->showMessage(msg);
    QMessageBox::about(this, "Canal", msg);
}
