#ifndef WELCOME_H
#define WELCOME_H
//头文件守卫，防止重复包含

#include <QWidget>
//#include <QPushButton>//不推荐，推荐使用前向声明方式

class QPushButton;

namespace Ui {
class Welcome;
}

//声明了一个界面类，派生自QWidget
class Welcome : public QWidget
{
    Q_OBJECT  //Qt核心宏， 信号和槽等特性需要该宏作为支持

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();


private slots:
    void on_closeBtn_clicked();

private:
    Ui::Welcome *ui;
    QDialog* tips;//声明为成员， 和当前对象的生命周期相同
    QPushButton* disBtn;
};

#endif // WELCOME_H
