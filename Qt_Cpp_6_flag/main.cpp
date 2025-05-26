#include "widget.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 윈도우 플래그 : 윈도우의 모양을 지정하는 여러 방법을 제공
    // - 위젯을 생성할 때 위젯의 모양을 사용자화할 수 있는 인수를 제공, windowFlags 속성을 이용해서 설정함
    QLabel* hello = new QLabel("Hello Qt!", 0, Qt::FramelessWindowHint);
    hello->setCursor(QCursor(Qt::PointingHandCursor));
    hello->showMaximized();
    return a.exec();
}
