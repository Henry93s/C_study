/* QValidator 클래스
 * : 입력받은 문자열을 검사할 때 사용하는 추상 클래스
 * 서브 클래스들
 *  - QDoubleValidator : 부동 소수점 수에 대해 범위 검사를 할 때
 *  - QIntValidator : 정수형 숫자에 대해 범위 검사를 할 때
 *  - QRegularExpressionValidator : 정규 표현식이 적용된 문자열을 검사(패턴 매칭)
 *      - 정규 표현식에서 문자열의 시작은 ^ 기호로 기술하고 문자열의 끝은 $ 기호로 기술
 *          - ex1. a로 시작하는 두 글자의 문자 검색 : a?
 *          - ex2. a로 시작하는 문자열을 검색 : a+
 */
#include <QApplication>
#include "widget.h"
\

    int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QWidget 이 아닌 사용자 정의 위젯(widget.cpp) 의 객체를 생성하여 사용함
    // QValidator클래스의 서브 클래스 객체 생성은 widget.cpp 에 정의해놓음
    Widget w;
    w.show();

    return a.exec();
}
