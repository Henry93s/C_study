#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QWidget>
// Ball, Brick, Paddle 클래스 추가하여 코드 분리 작업
#include "ball.h"
#include "brick.h"
#include "paddle.h"

#include <QMouseEvent>
#include <QKeyEvent>
// multimedia 플레이어 추가
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFileInfo>

class QLabel;

class BreakOut : public QWidget
{
    Q_OBJECT

public:
    BreakOut(QWidget *parent = nullptr);
    ~BreakOut();

protected:
    void keyPressEvent(QKeyEvent*) override;
    void mouseMoveEvent(QMouseEvent* e) override;
    // 공의 이동을 위한 타이머
    void timerEvent(QTimerEvent*) override;
    void moveObjects();
    // 패들과의 충돌처리
    void checkCollision();

protected:
    static const int MOVE_SPEED = 50; // 패들 이동 속도

private:
    static const int NO_OF_BRICKS = 30;

    // Ball, Brick, Paddle 클래스 추가하여 코드 분리 작업
    Ball* ball;
    Paddle* paddle;
    Brick* bricks[NO_OF_BRICKS];

    // 게임 점수 (깬 블록 수)
    // Ball, Brick, Paddle 클래스 추가하여 코드 분리 작업으로 인한 ball paddle bricks 주석 처리
    QLabel* score;
    // QLabel* ball;
    // QLabel* paddle;
    // QLabel* bricks[NO_OF_BRICKS];
    // 게임 승리, 패배 중앙 텍스트 출력 레이블
    QLabel* text;
    // 게임 life 관리 텍스트 레이블 및 변수
    QLabel* lifeText;
    qint64 life = 3;
    //
    // 공의 이동을 위한 타이머 셋팅
    int timerId;
    int xDir, yDir;
    int num;

    // multimedia sound 관련 변수 추가
    QMediaPlayer* bgPlayer;
    QMediaPlayer* effectPlayer;
};
#endif // BREAKOUT_H
