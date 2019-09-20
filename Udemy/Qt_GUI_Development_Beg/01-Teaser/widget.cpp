#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btSubmit_clicked()
{
    qDebug() << "Submitting data..";
    qDebug() << "First Name: " << ui->firstNameLineEdit->text();
    qDebug() << "Last Name: " << ui->lastNameLineEdit->text();
    qDebug() << "Message: " << ui->messageTextEdit->toPlainText();
}
