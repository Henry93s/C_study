#include "paddle.h"
#include <QPainter>

#define WIDTH   50
#define HEIGHT  12

// 사용자 정의 painter 위젯 드로잉
//Paddle::Paddle(QWidget *parent)
//    : QWidget{parent}
// 사용자 정의 QLabel 위젯 만들기
Paddle::Paddle(QWidget *parent)
    : QLabel{parent}
{
    resize(WIDTH, HEIGHT);
    // scaled : 이미지를 게임에서 사용하는 크기로 변경
    setPixmap(QPixmap("paddle.png").scaled(WIDTH,HEIGHT));

    // 사용자 정의 painter 위젯 드로잉
    //setStyleSheet("background-color: rgba(0,0,0,0)"); // 투명 배경 적용
}
/*
void Paddle::paintEvent(QPaintEvent* e){
    Q_UNUSED(e);
    QPainter p(this);
    // 선 그리기
    p.setPen(QColor(Qt::transparent));
    // 채우기
    p.setBrush(QColor(Qt::blue));
    // 사각형 그리기
    p.drawRoundedRect(0,0,WIDTH,HEIGHT,5,5);
}
*/
