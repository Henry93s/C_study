#include <QTime>
#include <QTimeEdit>
#include <QApplication>

int main(int argc,char* argv[]){
    QApplication a(argc, argv);

    // QTimeEdit : 시간을 처리하기 위한 메소드를 제공
    // - 시 분 초 표시 영역과 입력 영역으로 구성
    /*
    QTimeEdit* timeEdit = new QTimeEdit(0);
    timeEdit->setTime(QTime::currentTime());
    timeEdit->show();
    */

    // QDateEdit : 날짜를 처리하기 위한 메소드를 제공
    // - 년 월 일 표시 영역과 입력 영역으로 구성
    QDateEdit* dateEdit = new QDateEdit(0);
    dateEdit->setCalendarPopup(true);
    dateEdit->show();

    return a.exec();
}
