#ifndef CONTROLFORM_H
#define CONTROLFORM_H

#include <QWidget>

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

    //声明自定义的槽函数
public slots:
    void initDefault(int);
};

#endif // CONTROLFORM_H
