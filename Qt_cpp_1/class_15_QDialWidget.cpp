/* QDial : 아날로그 다이얼(초시계)와 같은 모양을 가지고 범위를 원형으로 설정
 * - 노치(Notch) : 다이얼에 구간을 알 수 있도록 하는 작은 표시
 * - wrapping : 키보드를 이용해서 값의 원형 순환도 가능
 *
 */
#include <QApplication>
#include <QDial>

int main(int argc,char* argv[]){
    QApplication a(argc, argv);

    QDial* dial = new QDial();
    dial->setWrapping(true);
    dial->setNotchesVisible(true);
    dial->setNotchTarget(10);
    dial->show();

    return a.exec();
}
