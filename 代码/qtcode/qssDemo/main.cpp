#include "mywidget.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();

    //加载样式
    QFile qssFile(":/style/res/freeStyle.css");
    qssFile.open(QFile::ReadOnly);
    QString qss = qssFile.readAll();
    a.setStyleSheet(qss);

    return a.exec();
}
