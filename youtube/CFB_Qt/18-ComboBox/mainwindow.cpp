#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList listCountries = {"Argentina","Brazil", "Italy", "Portugal"};
    QStringList listIcons = {":/images/icons/Argentina.png",
                             ":/images/icons/brazil.png",
                             ":/images/icons/Italy.png",
                             ":/images/icons/Portugal.png"};

    for(int i = 0; i < listIcons.size(); i++){
        ui->comboBox->addItem(QIcon(listIcons[i]), listCountries[i]);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString qt = "Qt Creator";
    QIcon icon(":/images/icons/Portugal.png");
    ui->comboBox->setItemIcon(0, QIcon(icon));
    ui->comboBox->setItemText(0, qt);
    QMessageBox::about(this, "Cursos", ui->comboBox->currentText());
}
