/* QSpinBox : 숫자 형태의 값을 입력받을 때 사용
 * - 스핀박스 끝에 있는 화살표를 이용하여 값을 변경
 * - 기본 값 : 0~99
 * - 기본 증감 크기 : 1
 *
 */

#include <QApplication>
#include <QSpinBox>

int main(int argc, char* argv[]){
    QApplication a(argc, argv);

    QSpinBox* spinBox = new QSpinBox();
    spinBox->setRange(0,10);
    spinBox->setSuffix("%"); // suffix 설정
    spinBox->setWrapping(true); // 순환 허용 여부
    spinBox->setSpecialValueText("Percent"); // 특별한 "텍스트" 값 설정
    // : 현재 코드에서는 0 (첫번째값) 대신 들어감
    spinBox->show();

    return a.exec();
}
