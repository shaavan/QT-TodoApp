#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                                         tr("Add Task"),
                                         tr("Task Name"),
                                         QLineEdit::Normal,
                                         tr("Untitled Task"), &ok);
    if(ok && !name.isEmpty()) {
        qDebug()<<"Adding new task";
        Task* task = new Task(name);
        connect(task, &Task::removed,
                this, &MainWindow::removeTask);
        mTasks.append(task);
        ui->tasksLayout->addWidget(task);
    }
}

void MainWindow::removeTask(Task* task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    delete task;
}

