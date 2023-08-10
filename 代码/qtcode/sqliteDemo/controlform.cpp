#include "controlform.h"
#include "ui_controlform.h"

ControlForm::ControlForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlForm)
{
    ui->setupUi(this);
    //默认界面

    //login.show();
}

ControlForm::~ControlForm()
{
    delete ui;
}
