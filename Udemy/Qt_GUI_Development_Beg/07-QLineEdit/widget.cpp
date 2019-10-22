#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel *firstNameLabel =  new QLabel("First Name", this);
    firstNameLabel->setMinimumSize(70,20);
    firstNameLabel->move(10,10);

    QLineEdit *firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200, 20);
    firstNameLineEdit->move(100, 10);

    QLabel *lastNameLabel =  new QLabel("Last Name", this);
    lastNameLabel->setMinimumSize(70,20);
    lastNameLabel->move(10,50);

    QLineEdit *lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200, 20);
    lastNameLineEdit->move(100, 50);

    QLabel *cityNameLabel =  new QLabel("City Name", this);
    cityNameLabel->setMinimumSize(70,20);
    cityNameLabel->move(10,90);

    QLineEdit *cityNameLineEdit = new QLineEdit(this);
    cityNameLineEdit->setMinimumSize(200, 20);
    cityNameLineEdit->move(100, 90);


    QFont buttonFont("Times", 20, QFont::Bold);
    QPushButton *button = new QPushButton("Grab data", this);
    button->setFont(buttonFont);
    button->move(80, 130);

    connect(button, &QPushButton::clicked, [=](){
        QString firstName = firstNameLineEdit->text();
        QString lastName = lastNameLineEdit->text();
        QString city = cityNameLineEdit->text();

        if(!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty()){
            qDebug() << "First name: " + firstName;
            qDebug() << "Last name: " + lastName;
            qDebug() << "City: " + city;
        }else{
            qDebug() << "One field is empty";
        }

    });

//    connect(firstNameLineEdit, &QLineEdit::cursorPositionChanged, [=](){
//       qDebug () << "The current cursos porsition : " << firstNameLineEdit->cursorPosition();
//    });

//    connect(firstNameLineEdit, &QLineEdit::editingFinished, [=](){
//       qDebug () << "Editing Finished";
//    });

    connect(firstNameLineEdit, &QLineEdit::returnPressed, [=](){
       qDebug () << "Return Pressed";
    });

}

Widget::~Widget()
{

}
