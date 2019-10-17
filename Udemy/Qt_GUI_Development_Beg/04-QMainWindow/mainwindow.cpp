#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *button = new QPushButton(
                "Hello",
                this);
    setCentralWidget(button);

    //Declare quit action
    QAction *quitAction = new QAction("quit");
    connect(quitAction,
            &QAction::triggered,
            [=](){
        QApplication::quit();
    });

    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    statusBar()->showMessage("Uploading file ...", 3000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint() const
{
    return QSize(800, 500);
}
