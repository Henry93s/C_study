#include <QApplication>
#include <QLCDNumber>

// QLCDNumber : LCD 형태로 숫자와 관련된 문자를 표시
// 2진수(Bin), 10진수(Dec), 8진수(Oct), 16진수(Hex) 모드로 숫자 표시

int main(int argc, char* argv[]){
    QApplication a(argc, argv);

    QLCDNumber* lcd=new QLCDNumber();
    // lcd -> setBinaryMode(); (2진수 일 때)
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->display(2002); // 0111 1101 0010 (2진수 일 때 예시)
    // lcd->setDigitCount(15);
    lcd->show();

    return a.exec();
}
