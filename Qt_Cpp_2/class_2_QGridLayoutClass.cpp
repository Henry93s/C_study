/* QGridLayout : 위젯들을 격자 모양으로 정렬할 때 사용
 * - 부모 레이아웃의 빈 공간을 행과 열로 나눠서 각각의 위젯을 해당 셀에 배치
 */

#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
