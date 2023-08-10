#ifndef CONTROLFORM_H
#define CONTROLFORM_H

#include <QWidget>

class MyWidget;

namespace Ui {
class ControlForm;
}

class ControlForm : public QWidget
{
    Q_OBJECT

public:
    explicit ControlForm(QWidget *parent = nullptr);
    ~ControlForm();

private:
    Ui::ControlForm *ui;

    //登录界面
    //注册界面
    //主界面
    MyWidget* mw;
};

#endif // CONTROLFORM_H
