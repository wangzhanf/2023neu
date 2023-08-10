#include "mywidget.h"
#include "ui_mywidget.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //验证默认支持的驱动接口
    qDebug() << QSqlDatabase::drivers();

    //通过指定驱动连接数据库
    QSqlDatabase db =  QSqlDatabase::addDatabase("QSQLITE");
    //设置具体的数据库文件路径,如果不存在则创建
    db.setDatabaseName("../sqliteDemo/neu.db");//建议使用发布资源的方式
    //打开数据库
    if(db.open()){
        qDebug() << "数据库打开成功";
        //数据操作
        //db.close();
    }else{
        qDebug() << "数据库打开失败";
    }
    //


    //
    connect(ui->addBtn,&QPushButton::clicked,this,[=](){
        insertRec();
    });
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::insertRec()
{


    QSqlQuery qsq;//用以封装需要执行的sql语句，   封装执行结果
    QString sql = QString("insert into users(username,passwd) values('%1','%2');").
            arg(ui->username->text()).
            arg(ui->passwd->text());
    //QString sql = QString("select * from users");
    //qsq.exec(sql);
    if(qsq.exec(sql)){
        qDebug() << "数据插入成功";
    }
    //也可以使用prepareStatement  方式放置SQL注入攻击
}
