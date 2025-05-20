#include <QApplication>
#include <QProgressBar>
#include <QTimer>

// QProgressBar : 바 형태로 현재의 진행 결과처럼 숫자의 값을 도식화하여 보여줄 때 사용
// - 전체 단계를 정의해서 단계별로 진행 상항을 표시
// - 기본 범위 : 0 ~ 100, 전체 단계 설정 : QProgressBar::setRange. 현재 값 설정 : QProgressBar::setValue

int main(int argc, char* argv[]){
    QApplication a(argc, argv);

    QProgressBar *progBar = new QProgressBar();
    progBar->setValue(20);

    // 1. setValue 를 수정하지 않고, 현재 값을 조절할 때 전체 범위(setRange)를 반절로 줄이면 됨
    // progBar->setRange(0,50);
    // progBar->setInvertedAppearance(true);
    progBar->show();

    // 2. QTimer 타이머 객체 예제 : 10ms 주기로 QTimer 객체를 연속 실행
    QTimer timer;
    int n = 0;
    QObject::connect(&timer, &QTimer::timeout,[&]{progBar->setValue(++n%101);});
    timer.start(10);


    return a.exec();
}
