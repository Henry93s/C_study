/* QSplitter : 위젯들의 크기를 동적으로 조정
 * - 슬릿터의 핸들을 마우스로 잡고 드래그해서 자식 위젯의 크기를 동적으로 조정
 */


#include "widget.h"
#include <QApplication>
int main(int argc, char* argv[]){
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
