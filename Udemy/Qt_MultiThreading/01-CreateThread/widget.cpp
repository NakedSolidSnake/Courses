#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

static void counting1(int count){
    for(int i{0}; i < count ; i++){
        qDebug() << "Counting : " << i << " Thread id: " << QThread::currentThreadId();
    }
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "Main Thread " << QThread::currentThread();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btStart_clicked()
{
    thread = QThread::create(counting1, 10);
//    thread = QThread::create([](int x){
//        for(int i{0}; i < x ; i++){
//            qDebug() << "Counting : " << i << " Thread id: " << QThread::currentThreadId();
//        }
//    }, 10);

    connect(thread, &QThread::started, [](){
       qDebug() << "Thread Started";
    });

    connect(thread, &QThread::finished, [](){
        qDebug() << "Thread Finished";
    });

    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    thread->start();
    qDebug() << "Clicked Button";
}
