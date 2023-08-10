#include "controlform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControlForm w;
    w.show();

    return a.exec();
}
