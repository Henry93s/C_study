#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), m_isEntered(false), m_isHighlighted(false)
{
    resize(130, 30);
}

void Widget::paintEvent(QPaintEvent*){
    QPainter painter;
    painter.begin(this);
    // highlight 상태면 yellow, 마우스 들어온 상태면 darkYellow, 마우스 나간 상태면 lightGray
    painter.setBrush(m_isHighlighted?(Qt::yellow) : (m_isEntered ? (Qt::darkYellow):(Qt::lightGray)));
    // 그림은 현재 객체 rect 를 15, 15 만큼 round 처리하여 draw
    painter.drawRoundedRect(this->rect(), 15,15);
    // 위치 좌표 text draw
    painter.drawText(10,20,QString("x : %1 / y : %2").arg(x()).arg(y()));
    painter.end();

    // 클릭시 하이라이트 상태를 선택된 상태로 변경
    if(m_isHighlighted){
        m_timer.stop();
        // update() 와 repaint() :
        //
        // 0.3 초 뒤 현재 객체의 update() - painter 슬롯 함수 실행
        m_timer.singleShot(300, this, SLOT(update()));
        m_isHighlighted = false;
    }
}

// rollover(hover) 버튼 동작 구현
void Widget::enterEvent(QEnterEvent*){
    m_isEntered = true;
    m_isHighlighted = false;
    // update() - painter
    update();
}

void Widget::leaveEvent(QEvent*){
    m_isEntered = false;
    m_isHighlighted = false;
    // repaint() - painter
    repaint();
}

// 버튼 누르면 clicked() 시그널 발생
void Widget::mousePressEvent(QMouseEvent*){
    // m_entered false
    m_isHighlighted = true;
    update();
    // clicked() 정의 이벤트 시그널 함수를 발생 시킴: emit
    emit clicked();
}

Widget::~Widget() {}
