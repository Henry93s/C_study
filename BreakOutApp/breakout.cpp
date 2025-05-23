#include "breakout.h"
#include <QLabel>
#include <QApplication>

#define WIDTH 50
#define HEIGHT 12
#define SCR_WIDTH 300
#define SCR_HEIGHT 400

BreakOut::BreakOut(QWidget *parent)
    : QWidget(parent), xDir(1), yDir(-1)
{
    num = 0;
    score = new QLabel(this);
    score->setGeometry(140,SCR_HEIGHT*0.9,50,50);
    score->setStyleSheet("QLabel {color: red; font-size: 20px; font-weight: bold;}");

    text = new QLabel(this);
    text->setGeometry(110,170,150,50);
    text->setStyleSheet("QLabel {font-size: 20px; font-weight: bold;}");
    //
    ball = new QLabel(this);
    ball->setGeometry(SCR_WIDTH*0.8, SCR_HEIGHT*0.875, 10, 10);
    ball->setStyleSheet("QLabel {background-color: red; border-radius: 5px;}");
    paddle = new QLabel(this);
    paddle->setGeometry(SCR_WIDTH*0.7, SCR_HEIGHT*0.9, WIDTH, HEIGHT);
    paddle->setStyleSheet("QLabel {background-color: blue;}");



    for(int y=0,i=0;y<5;y++){
        for(int x=0;x<6;x++,i++){
            bricks[i] = new QLabel(this);
            bricks[i]->setStyleSheet("QLabel {background-color: cyan; border: 1px solid black}");
            bricks[i]->setGeometry(x*WIDTH, y*HEIGHT+30, WIDTH, HEIGHT);
        }
    }
    resize(SCR_WIDTH,SCR_HEIGHT);

    // 마우스를 클릭하지 않아도 이동을 감시할지를 설정
    setMouseTracking(true);

    // QObject 의 타이머 시작
    timerId = startTimer(10);
}

// 키보드 이동시 패들을 좌우로만 이동(y축 고정, esc 키 종료)
void BreakOut::keyPressEvent(QKeyEvent* e){
    int x;
    switch(e->key()){
    case Qt::Key_Left:
        x = paddle->x()-MOVE_SPEED;
        // if :
        if (x < 0){
            x = 0;
        } else {
            if(x + WIDTH > this->width()){
                x = this->width() - WIDTH;
            }
        }
        paddle->move(x, paddle->y());
        break;
    case Qt::Key_Right:
        x = paddle->x()+MOVE_SPEED;
        // if
        if (x < 0){
            x = 0;
        } else {
            if(x + WIDTH > this->width()){
                x = this->width() - WIDTH;
            }
        }
        paddle->move(x, paddle->y());
        break;
    case Qt::Key_Escape:
        qApp->exit();
        break;
    default:
        QWidget::keyPressEvent(e);
    }
}

// 마우스 이동시 패들을 좌우로만 이동(y축 고정)
void BreakOut::mouseMoveEvent(QMouseEvent* e){
    int x = e->pos().x();
    // if
    if(x < 0){
        x = 0;
    } else {
        if(x + WIDTH > width()){
            x = width()-WIDTH;
        }
    }
    paddle->move(x, paddle->y());
}

// 타이머 이벤트 (e 는 사용하지 않으므로 unused)
void BreakOut::timerEvent(QTimerEvent* e){
    Q_UNUSED(e);
    moveObjects();
    checkCollision();
}

// 공의 이동 메소드 (볼의 특정 값을 더함, 충돌하면 반대 부호(-) 를 더함)
void BreakOut::moveObjects(){
    ball->move(ball->x() + xDir, ball->y() + yDir);
    if((ball->x() <= 0) || (ball->x()+10 >=SCR_WIDTH)){
        xDir *= -1; // 충돌 케이스 마이너스 이동
    }
    if(ball->y() <= 0){
        yDir = 1;
    }

    // 아래는 땅에 부딫힐 때 튕기는 추가 케이스
    /*
    if(ball->y() <= 0 || ball->y()+10 >= SCR_HEIGHT){ // || ball->y()+10 >= SCR_HEIGHT 추가 케이스 작성
        yDir *= -1; // 충돌 케이스
    }
    */
}

// 패들과 충돌 처리 메소드
void BreakOut::checkCollision(){
    if(ball -> geometry().bottom() > height()){
        killTimer(timerId);
        qDebug("Game lost");
        text->setText("Game lost");
    }

    // 남은 블록이 없으면 게임 종료
    int j =0;
    for(int i=0;i<NO_OF_BRICKS;i++){
        if(bricks[i]->isHidden()){
            j++;
        }
    }

    if(j==NO_OF_BRICKS){
        killTimer(timerId);
        qDebug("Victory");
        text->setText("Victory");
    }

    // 패들과의 충돌 처리
    if((ball->geometry()).intersects(paddle->geometry())){
        int paddleLPos = paddle->geometry().left();
        int ballLPos = ball->geometry().left();
        int first = paddleLPos + 8;
        int second = paddleLPos + 16;
        int third = paddleLPos + 24;
        int fourth = paddleLPos + 32;

        // 패들 맞은 부분에 대해 공의 반사되는 방향 조정
        if(ballLPos < first){
            xDir = -1; yDir = -1;
        }
        if(ballLPos >= first && ballLPos < second){
            xDir = -1; yDir *= -1;
        }
        if(ballLPos >= second && ballLPos < third){
            xDir = 0; yDir = -1;
        }
        if(ballLPos >= third && ballLPos < fourth){
            xDir = 1; yDir *= -1;
        }
        if(ballLPos > fourth){
            xDir = 1; yDir = -1;
        }
    }

    // 블록 충돌을 처리
    for(int i=0;i<NO_OF_BRICKS;i++){
        if((ball->geometry()).intersects(bricks[i]->geometry())){
            int ballLeft = ball->geometry().left();
            int ballHeight = ball->geometry().height();
            int ballWidth = ball->geometry().width();
            int ballTop = ball->geometry().top();

            // 현재 블록 위치 계산
            QPoint pointRight(ballLeft + ballWidth + 1, ballTop);
            QPoint pointLeft(ballLeft - 1, ballTop);
            QPoint pointTop(ballLeft, ballTop - 1);
            QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);

            // 공과 블록의 충돌 계산
            if(!bricks[i]->isHidden()){
                if(bricks[i]->geometry().contains(pointRight)){
                    xDir = -1;
                } else if(bricks[i]->geometry().contains(pointLeft)){
                    xDir = 1;
                }

                if(bricks[i]->geometry().contains(pointTop)){
                    yDir = 1;
                } else if(bricks[i]->geometry().contains(pointBottom)){
                    yDir = -1;
                }
                // 점수 측정
                num++;
                score->setText(QString::number(num));
                bricks[i]->setHidden(true);
            }
        }
    }
}

BreakOut::~BreakOut() {
    delete ball;
    delete paddle;

    for(int i=0;i<NO_OF_BRICKS;i++){
        delete bricks[i];
    }
}
