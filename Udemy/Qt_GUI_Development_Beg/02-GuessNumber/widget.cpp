#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    secretNumber(0),
    guessNumber(0)
{
    ui->setupUi(this);
    srand(time(nullptr));

    secretNumber = rand() % 100 + 1;
    qDebug() << "Secret Number: " << QString::number(secretNumber);
 }

Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    if(guessNumber == secretNumber){
        ui->messageLabel->setText("You Won");
        ui->guessButton->setEnabled(false);
        ui->startOverButton->setEnabled(true);
    }
    else if(guessNumber > secretNumber){
        ui->messageLabel->setText("Greater than secret number");
    }
    else{
        ui->messageLabel->setText("Lesser than secret number");
    }
}

void Widget::on_startOverButton_clicked()
{
    ui->guessButton->setEnabled(true);
    ui->startOverButton->setEnabled(false);

    ui->spinBox->setValue(1);

    ui->messageLabel->clear();
}
