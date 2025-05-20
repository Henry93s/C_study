#include <QApplication>
#include <QLabel>
#include <QPushbutton>

int main(int argc, char *argv[])
{
    // 어플리케이션 초기화는 주로 메인 함수에서 하는데 qApp 라는 전역 인스턴스를 제공함 -> QApplication include 필요
    QApplication a(argc, argv);

    // QWidget 을 윈도우로 사용하고 QLabel 과 QPushButton 의 부모로 지정
    // 위젯의 기본적인 위치는 (0,0) -> move() 메서드로 위치 지정
    QWidget w;
    QLabel hello("<font color=blue>Hello <i>Qt!</i> </font>", &w);
    hello.resize(75,35);

    QPushButton quit("Quit", &w);
    quit.move(100,400); // == quit.geometry(100,400,75,35);
    quit.resize(752,35);


    QObject::connect(&quit, &QPushButton::clicked, &hello, [&](){hello.setText("<b>Hi</b>");});
    /*
        QObject::connect(&quit, &QPushButton::clicked, &hello, [&]() {
            hello.setText("<b>Hi</b>");
        });
    */
    // 부모가 보여지면 자식은 자동으로 보여지므로 굳이 show 를 안해도 됨
    w.show();

    return a.exec();
}
