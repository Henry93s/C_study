#include <QApplication>
#include <QLabel>
#include "widget.h"
\

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QWidget 이 아닌 사용자 정의 위젯(widget.cpp) 의 객체를 생성하여 사용함
    Widget w;
    w.show();


    /*
    Widget ww;
    QLabel* label= new QLabel("<font size=20>Hello, World!</font>", &ww);
    label->setGeometry(10,90,175,35); // x,y,label size_x, label size_y
    ww.show();
    */

    return a.exec();
}
