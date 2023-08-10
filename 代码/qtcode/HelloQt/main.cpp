#include "welcome.h"
#include <QApplication>
//典型的客户端程序，入口
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Welcome w;//在栈中构建 Welcome  界面对象  w
    w.show();//使用 w的show方法显示自身，show()来自继承的基类QWidget

    return a.exec();//开启循环监听，阻塞防止程序退出
}
