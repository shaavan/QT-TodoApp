#include "Task.h"
#include "ui_Task.h"

#include <QInputDialog>

Task::Task(const QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->editButton, &QPushButton::clicked, this, &Task::rename);
    connect(ui->removeButton, &QPushButton::clicked, [this] {
        emit removed(this);
    });
    connect(ui->checkbox, &QCheckBox::toggled,
            this, &Task::checked);
}

Task::~Task()
{
    delete ui;
}

void Task::rename()
{
    bool ok;
    QString value = QInputDialog::getText(this,
                                         tr("Edit task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         this->name(), &ok);
    if(ok && !value.isEmpty()) {
        setName(value);
    }

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

void Task::checked(bool checked)
{
    QFont font(ui->checkbox->font());
    font.setStrikeOut(checked);
    ui->checkbox->setFont(font);
    emit statusChanged(this);
}
