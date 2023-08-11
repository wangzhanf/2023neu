#include "mywidget.h"
#include "ui_mywidget.h"




MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //测试创建图表
    QChart* chart = new QChart();//构建图表对象
    QLineSeries* series = new QLineSeries();//构建具体图形类型【容器】
    series->append(1,1);
    series->append(2,2);
    series->append(3,3);
    series->append(4,3);
    series->append(5,2);
    series->append(6,2);

    QStringList lists;
    lists.append("aaa");
    lists.append("bbb");
    lists << "ccc" << "ddd" << "eee";//STL以及重载

    //将容器添加到  图表对象
    chart->addSeries(series);
    // 将图表对象绑定到   已有  可视区域
    chart->setTitle(tr("销售曲线"));
    chart->createDefaultAxes();
    ui->widget->setChart(chart);

}

MyWidget::~MyWidget()
{
    delete ui;
}
