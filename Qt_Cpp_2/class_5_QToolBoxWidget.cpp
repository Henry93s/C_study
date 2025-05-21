/* QToolBox widget : 여러 페이지를 쌓아놓고 필요에 따라 선택하여 보여줄 수 있는 컨테이너 위젯
 * - 한 번에 하나의 페이지 내용만 표시
 */

#include <QApplication>
#include <QToolBox>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>

int main(int argc,char* argv[]){
    QApplication a(argc, argv);
    QToolBox toolbox;
    toolbox.resize(300, 380);
    toolbox.show();

    QDial dial(&toolbox);
    QCalendarWidget calendarWidget(&toolbox);
    QTextEdit textEdit("QTextEdit", &toolbox);
    toolbox.addItem(&dial, "Page &1");
    toolbox.addItem(&calendarWidget, "Page &2");
    toolbox.addItem(&textEdit, "Page &3");

    return a.exec();
}
