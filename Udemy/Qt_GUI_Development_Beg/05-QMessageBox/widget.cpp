#include "widget.h"
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button = new QPushButton(this);
    button->setText(("Click Me"));
    button->move(200, 200);
    connect(button,
            &QPushButton::clicked,
            [=](){
//        QMessageBox message;
//        message.setMinimumSize(300, 200);
//        message.setWindowTitle("Message Title");
//        message.setText("Something happened");
//        message.setInformativeText("Do you want to do something about it?");
//        message.setIcon(QMessageBox::Critical);
//        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
//        message.setDefaultButton(QMessageBox::Cancel);

//        int choose = message.exec();

//        int choose = QMessageBox::warning(this, "Message Title", "Something happened."
//                                                                 "Do you want to do"
//                                                                 "something about it?",
//                                          QMessageBox::Ok | QMessageBox::Cancel);

//        int choose = QMessageBox::question(this, "Message Title", "Something happened."
//                                                                 "Do you want to do"
//                                                                 "something about it?",
//                                          QMessageBox::Ok | QMessageBox::Cancel);

//        int choose = QMessageBox::information(this, "Message Title", "Something happened."
//                                                                 "Do you want to do"
//                                                                 "something about it?",
//                                          QMessageBox::Ok | QMessageBox::Cancel);

        int choose = QMessageBox::critical(this, "Message Title", "Something happened."
                                                                 "Do you want to do"
                                                                 "something about it?",
                                          QMessageBox::Ok | QMessageBox::Cancel);

        if(choose == QMessageBox::Ok)
        {
            qDebug() << "CLicked OK";
        }

        if(choose == QMessageBox::Cancel)
        {
            qDebug() << "CLicked Cancel";
        }
    });
}

Widget::~Widget()
{

}
