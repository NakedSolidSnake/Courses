#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mTasks()
{
    ui->setupUi(this);
//    connect(ui->addTaskButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    updateStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateStatus()
{
    int completeCount = 0;
    for(auto t : mTasks){
        if(t->isCompleted()){
            completeCount++;
        }
    }

    int todoCount = mTasks.size() - completeCount;
    ui->statusLabel->setText(
                QString ("Status: %1 todo / %2 completed")
                .arg(todoCount)
                .arg(completeCount));
}

void MainWindow::addTask()
{
//    qDebug() << "User clicked on button!";
    bool ok;
    QString name = QInputDialog::getText(this, tr("Add task"), tr("Task name"), QLineEdit::Normal, tr("Untitled task"), &ok);
    if(ok && !name.isEmpty()){
        qDebug() << "Addind new Task";
        Task *task = new Task(name);
        connect(task, &Task::removed, this, &MainWindow::removeTask);
        connect(task, &Task::statusChanged, this, &MainWindow::taskStatusChanged);
        mTasks.append(task);
        ui->tasksLayout->addWidget(task);
        updateStatus();
    }
}

void MainWindow::removeTask(Task *task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged(Task * /*task*/)
{
    updateStatus();
}
