//#include "widget.h"
#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel hello("<font color=blue>"\
                 "Hello <i>Qt!</i> </font>", nullptr);
    // 2번째 인자가 0 이 아닌 C++11 부터는 nullptr 을 사용

    // hello QLabel 의 크기를 조절함 : resize 함수
    hello.resize(750, 35);
    hello.show();

    return a.exec();
}
