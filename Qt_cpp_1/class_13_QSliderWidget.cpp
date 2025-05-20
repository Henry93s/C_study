/* 범위 조정 위젯 : 사용자가 미리 정해 놓은 범위의 값들을 선택하기 위해서 사용
 *  기본값의 범위 : 0 ~ 99
 *  QSlider : 슬라이더를 수직 또는 수평으로 이동시켜서 슬라이더의 비율로 어떤 범위 내의 값을 표시
 *  QScrollBar :
 *
 *  setWrapping() : 원형 순환에서 사용
 */
#include <QApplication>
#include <QSlider>
#include <QStyleFactory>
#include <QProgressBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 추가 : 슬라이드 바가 움직일 때 프로그레스 바가 움직이도록 해보기
    // 윈도우 w 위젯 생성(QWidget 기본 클래스)
    QWidget w;

    // only slider
    QSlider* slider = new QSlider(&w); // &w 를 인자로 추가하여 생성 -> w 의 자식
    slider->setOrientation(Qt::Horizontal);
    slider->setTickPosition(QSlider::TicksAbove);
    // setStyle() : qt 에서 기본으로 제공해주는 스타일 템플릿
    slider->setStyle(QStyleFactory::create("Fusion"));
    // slider->show();

    // 추가 : 슬라이드 바가 움직일 때 프로그레스 바가 움직이도록 해보기
    QProgressBar *progBar = new QProgressBar(&w); // &w 를 인자로 추가하여 생성 -> w 의 자식
    progBar->setGeometry(10,10,150,20);
    slider->setGeometry(10,40,150,20);

    // 위젯을 어떻게 생성했느냐에 따라서 connect 등 클래스 함수 매개변수에 레퍼런스 또는 일반 변수 타입으로 넣는지 파악 필요!
    QObject::connect(slider, SIGNAL(valueChanged(int)), progBar, SLOT(setValue(int)));
    w.show();

    return a.exec();
}
