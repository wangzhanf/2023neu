#include "mywidget.h"
#include "controlform.h"
#include "ui_mywidget.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //初始化亮度控制条
    bcf = new ControlForm(this);
    bcf->setGeometry(100,150,600,75);

    //关联 自定义信号和  封装组件  之间的信号和槽关系
    connect(this,&MyWidget::changeDef,ui->volCtrl,&ControlForm::initDefault);

    //点击音量按钮给自定义组件发送带参信号
    connect(ui->volBtn,&QPushButton::clicked,this,[=](){
        // [] 代表作用域链的识别区域   = 代表和当前对象同样的识别域
        // () 信号传递过来的参数
        //lambda函数式编程的函数体
        qDebug() << "触发了自定义的信号";
        emit changeDef(11,"学习模式");  //发送信号使用emit 指令
        ui->volBtn->setIcon(QIcon(":/icon/res/hand.png"));
    });
}

MyWidget::~MyWidget()
{
    delete ui;
}

//覆写基类提供的事件函数
void MyWidget::resizeEvent(QResizeEvent *event)
{
    qDebug() << this->width();
    //匹配修改组件的大小
    ui->volBtn->resize(this->width()*0.2,ui->volBtn->height());
    ui->volCtrl->resize(this->width()*0.7,ui->volCtrl->height());
}
