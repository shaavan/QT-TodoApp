#include "Task.h"
#include "ui_Task.h"

Task::Task(const QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
}

Task::~Task()
{
    delete ui;
}

void Task::setName(const QString& name)  //Setter: Sets Task's name
{
    ui->checkbox->setText(name);
}

QString Task::name() const  //Getter: Get Task's name
{
    return ui->checkbox->text();
}

bool Task::isCompleted() const  //Getter: Gets state of Task
{
    return ui->checkbox->isChecked();
}
