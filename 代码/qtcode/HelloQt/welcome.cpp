#include "welcome.h"
#include "ui_welcome.h"
#include <QDebug>  //方便日志输出调试
#include <QDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QPushButton>
//采用了初始化列表方式构造ui成员
Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    //ui->label

    //创建一个顶级窗口
    //QLabel* label = new QLabel("这是一个顶级窗口");
    //label->show();

    QLabel* label2 = new QLabel("这是一个子部件");
    label2->setParent(this);//设置父组件关系

    //几何布局
    qDebug() << "当前窗口尺寸" << this->geometry() ;//通过getter获取属性
    this->setGeometry(200,200,800,600);//通过setter设置属性
    qDebug() << "当前窗口宽度" << this->geometry().width() ;


    //弹出广告
    //QDialog dialog(this);//栈中声明
    //调试的方式1    输出日志
    //qDebug() << "dialog显示" ;
    //调试的方式2    断点调试
    //dialog.show();//此例会出现闪退现象
    //dialog.exec();//阻塞式

    //弹出每日提示
    tips = new QDialog(this);//构造函数中初始化， 创建在堆中
//    tips->setModal(true);//设定是否是模态框
//    QLabel* label = new QLabel("您的余额不足，请充值",tips);
//    tips->setGeometry(300,300,400,200);
//    tips->show();

    //显示颜色对话框
//    QColorDialog qcd(QColor(239,37,178,255),this);
//    qcd.setOption(QColorDialog::ShowAlphaChannel);//显示alpha通道
//    qcd.exec();//显示对话框
//    QColor choiceColor = qcd.currentColor();//获取用户选择的颜色
//    qDebug() << "选择的颜色是：" << choiceColor;

    //打开字体对话框，选择字体则将选择的字体应用到界面中的按钮上，如果未选择则弹出信息提示框
//    disBtn =  new QPushButton("演示字体选择的按钮",this);
//    disBtn->setGeometry(200,200,400,200);
//    bool flag = false;
//    QFont qf = QFontDialog::getFont(&flag,QFont("微软雅黑"),this,"选择按钮字体");
//    qDebug() << flag;
//    if(flag){
//        disBtn->setFont(qf);
//    }else{
//        QMessageBox::information(this,"提醒标题","您还未选择任何字体","朕知道了");
//    }

//    label2->setGeometry(200,200,400,200);
//    QString filename = QFileDialog::getOpenFileName(this,"打开展示文件","c:","文本文件(*txt *cvs)");
//    qDebug() << filename;
//    if(!filename.isEmpty()){
//        QFile file(filename);
//        file.open(QIODevice::ReadOnly);
//        QTextStream qts(&file);
//        QString content = qts.readAll();
//        label2->setText(content);
//    }else{
//        QMessageBox::warning(this,"提醒标题","您还未选择任何文件","朕知道了");
//    }

    QPushButton* exitBtn = new QPushButton("关闭",this);
    //点击按钮关闭当前窗口,Qt4版本
    connect(exitBtn,SIGNAL(click()),this,SLOT(cse()));


}

Welcome::~Welcome()
{
    //析构时自动  销毁ui内存空间
    delete ui;
}


void Welcome::on_closeBtn_clicked()
{
    this->close();
}
