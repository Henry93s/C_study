/* QComboBox : 라디오 박스와 유사하게 여러 옵션 중에서 하나의 값을 "드롭 다운" 을 통해서 선택할 때 사용
 * - 항목이 너무 많은 경우 화면을 넘기는 문제가 발생하기도 함
 *   => 항목의 성격에 따라서 각각의 소그룹으로 나누어 여러개의 콤보 박스나 다른 위젯을 활용하면 좋음
 *
 */
#include <QApplication>
#include <QComboBox>

int main(int argc, char* argv[]){
    QApplication a(argc, argv);

    QComboBox* comboBox = new QComboBox();
    comboBox->addItem("KDE");
    comboBox->addItem("Gnome");
    comboBox->addItem("FVWM");
    comboBox->addItem("CDE");
    comboBox->setEditable(false); // 입력 가능 여부
    comboBox->addItem("CDE2");
    comboBox->show();

    return a.exec();
}
