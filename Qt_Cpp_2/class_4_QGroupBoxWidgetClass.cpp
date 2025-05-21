/*
 *  QGroupBox Widget : 타이틀과 단축키가 있는 그룹 박스를 만들 때 사용
 *  타이틀 : 그룹 박스 위쪽에 표시
 *  키보드 단축키 : 그룹 박스 내 자식 위젯으로 포커스 이동 시 사용
 *
 * (추가) QFrame Widget : 프레임을 갖는 위젯들의 기본 클래스
 *  - 화면 상의 위젯들을 묶는 프레임이 있는 위젯으로도 사용
 *  - 폼에 라인 위젯을 위치시키기 위해서도 사용한다.
 */
#include "widget.h"
#include <QApplication>

int main(int argc,char* argv[]){
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
