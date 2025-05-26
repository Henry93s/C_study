#include "ball.h"
#include <QPainter>

#define RADIUS  10

// 사용자 정의 painter 위젯 드로잉
//Ball::Ball(QWidget *parent)
//    : QWidget{parent}
// 사용자 정의 QLabel 위젯 만들기
Ball::Ball(QWidget *parent)
   : QLabel{parent}
{
    resize(RADIUS, RADIUS);
    // scaled : 이미지를 게임에서 사용하는 크기로 변경
    setPixmap(QPixmap("ball.png").scaled(RADIUS, RADIUS));

    // 사용자 정의 painter 위젯 드로잉
    //setStyleSheet("background-color: rgba(0,0,0,0)"); // 투명 배경 적용
}
/*
void Ball::paintEvent(QPaintEvent* e){
    Q_UNUSED(e);
    QPainter p(this);
    // 선 그리기
    p.setPen(QColor(Qt::transparent));
    // 채우기
    p.setBrush(QColor(Qt::red));
    // 원 그리기
    p.drawEllipse(0,0,RADIUS,RADIUS);
}
*/
