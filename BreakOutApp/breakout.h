#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>

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
    static const int MOVE_SPEED = 30; // 패들 이동 속도

private:
    static const int NO_OF_BRICKS=30;
    QLabel* score;
    QLabel* ball;
    QLabel* paddle;
    QLabel* bricks[NO_OF_BRICKS];
    QLabel* text;
    // 공의 이동을 위한 타이머 셋팅
    int timerId;
    int xDir, yDir;
    int num;
};
#endif // BREAKOUT_H
