#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QDebug>
#include <QStack>

class Widget : public QWidget
{
    Q_OBJECT

private:
// layout 객체
    QVBoxLayout* defaultLayout;
    QGridLayout* gridLayout;

// 레이아웃에 들어갈 qwidget 선언
    QLabel* resultLabel; // 계산 결과 출력 Label
    QFont* digitalFont; // 계산 결과 폰트 스타일
    QPushButton* calcButton[16];  // 계산기 버튼들 (4 x 4 = 16 개)
    // 버튼 string 배열
    QString buttonStr[16] = {"7", "8", "9", "/",
                             "4", "5", "6", "*",
                             "1", "2", "3", "-",
                             "0", "C", "=", "+"};

// 입력 데이터 Stack 클래스
    QStack<QString> stack;

// 연산 함수
    void calculate();

private slots:
    // 계산기 버튼 눌렀을 때 signal 에 따른 slot 함수 선언
    void pushDial();

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
