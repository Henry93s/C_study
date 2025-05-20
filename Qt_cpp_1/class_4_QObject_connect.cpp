#include <QApplication>
#include <QLabel>
#include <QPushbutton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton quit("Quit", nullptr);
    quit.resize(75, 35);
    quit.show();

    // QObject::connect static 메소드를 사용하여 QPushButton 위젯과 시그널과 QApplication 클래스의 슬롯을 연결
    QObject::connect(&quit, SIGNAL(clicked()), &a, SLOT(quit()));

    return a.exec();
}
