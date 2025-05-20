/* QRadioButton : 사용자로부터 복수의 옵션 중 하나만 선택할 때 사용하는 라디오 버튼 위젯
 * - 보통 여러 개의 라디오 버튼을 하나로 묶어서 사용
 *  -> QButtonGroup 클래스 사용 : 여러 버튼 위젯들을 하나로 관리하기 위한 클래스
 */

#include <QApplication>
#include "widget.h"
\

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QWidget 이 아닌 사용자 정의 위젯(widget.cpp) 의 객체를 생성하여 사용함
    // 라디오 버튼 그룹 위젯은 widget.cpp 에 정의해놓음
    Widget w;
    w.show();

    return a.exec();
}
