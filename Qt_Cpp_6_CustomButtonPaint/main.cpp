#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    // 버튼을 눌렀을 때 app 을 종료시킴
    //QObject::connect(&w, SIGNAL(clicked()), &a, SLOT(quit()));

    return a.exec();
}
