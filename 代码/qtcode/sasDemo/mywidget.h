#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class ControlForm;

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    Ui::MyWidget *ui;
    ControlForm* bcf;//亮度控制条

    //覆写基类提供的事件函数
protected:
    virtual void resizeEvent(QResizeEvent *event);


//声明信号
signals:
    void changeDef(int,QString);
};

#endif // MYWIDGET_H
