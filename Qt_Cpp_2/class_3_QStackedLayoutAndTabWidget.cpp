/* QStackedLayout 클래스 : 여러 겹의 레이어로 되어있는 한 위치에 위젯들을 배치할 때 사용
 * QTabWidget 클래스 : 탭이 있는 스택된 페이지 영역을 제공
 */
#include "widget.h"
#include <QApplication>

int main(int argc, char* argv[]){
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
