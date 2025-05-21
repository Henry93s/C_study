/* QVBoxLayout : 위젯들을 "수평" 이나 "수직" 인 일렬로 배열할 때 사용
 * - QHBoxLayout : Horizontal(수평) 으로 위젯 배열
 * - QVBoxLayout : Vertical(수직) 으로 위젯 배열
 *
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
