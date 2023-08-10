#include "controlform.h"
#include "ui_controlform.h"

ControlForm::ControlForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlForm)
{
    ui->setupUi(this);

    //完成信号和槽的关联
    //Qt5实现
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

    //void valueChanged(int i)  信号的原始声明
    //void valueChanged(const QString &text)
    void (QSpinBox::*vci)(int) = &QSpinBox::valueChanged;//函数指针
    void (QSpinBox::*vcs)(const QString&) = &QSpinBox::valueChanged;//函数指针
    connect(ui->spinBox,vci,ui->horizontalSlider,&QSlider::setValue);

}

ControlForm::~ControlForm()
{
    delete ui;
}

//定义槽函数
void ControlForm::initDefault(int num)
{
    ui->spinBox->setValue(num);
}
