#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{


    //String notation
    ui->setupUi(this);
    connect(ui->pushButton,
            SIGNAL(clicked()),
            this,
            SLOT(changeText()));

    QPalette labelPallete;
    labelPallete.setColor(QPalette::WindowText, Qt::green);

    QFont labelFont("Times", 20, QFont::Bold);
    ui->label->setFont(labelFont);
    ui->label->setPalette(labelPallete);

    //Functor notation : Regular SLOTS
//    connect(ui->pushButton,
//            &QPushButton::clicked,
//            this,
//            &Widget::changeText);

//    connect(ui->slider,
//            &QSlider::valueChanged,
//            ui->progressBar,
//            &QProgressBar::setValue);

    connect(ui->slider,
            &QSlider::valueChanged,
            [=](){
       ui->progressBar->setValue(ui->slider->value()) ;
    });


    //Functor Notation : Lambdas
//    connect(ui->pushButton,
//            &QPushButton::clicked,
//            [=](){
//       ui->label->setText("Lambda called") ;
//    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    ui->label->setText("Button Clicked");
}
