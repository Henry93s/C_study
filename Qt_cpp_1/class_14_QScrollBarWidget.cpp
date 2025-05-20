/*
 * QScrollBar : 수직 또는 수평의 스크롤 바를 제공
 * - 마우스로 스크롤 바의 버튼을 클릭하거나 스크롤 바 중앙의 핸들
 */
#include <QApplication>
#include <QScrollBar>
#include <QScrollArea>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel* label = new QLabel("1234567890123456789012345678901234567890");

    QScrollArea* scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(label);
    scrollArea->resize(60,30);
    scrollArea->show();

    QScrollBar* slider = scrollArea->horizontalScrollBar();
    slider->setValue(slider->maximum());

    return a.exec();
}
