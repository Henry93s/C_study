//#include "widget.h"
#include <QLabel>
#include <QApplication>

// int argc, char *argv[] : 명령행 인수 -> QApplication 객체 생성에 필요
int main(int argc, char *argv[])
{
    // QApplication : 애플리케이션의 초기화와 이벤트 루프 등을 담당
    // Qt 의 애플리케이션은 QApplication 클래스의 객체가 반드시 필요함
    QApplication a(argc, argv);
    // 레이블(label) 위젯의 인스턴스 생성
    QLabel hello("<font color=blue>"\
                 "Hello <i>Qt!</i> </font>",0);
    hello.show();

    // return a.exec(); : 이벤트 루프를 돌면서 생성된 "창" 이 닫히지 않도록 한다.
    return a.exec();
}
