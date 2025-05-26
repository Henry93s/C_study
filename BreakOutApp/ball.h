#ifndef BALL_H
#define BALL_H

// 사용자 정의 QLabel 위젯 만들기
#include <QLabel>
// 사용자 정의 painter 위젯 드로잉
#include <QWidget>

// 사용자 정의 painter 위젯 드로잉
//class Ball : public QWidget
// 사용자 정의 QLabel 위젯 만들기
class Ball : public QLabel
{
    Q_OBJECT
public:
    explicit Ball(QWidget *parent = nullptr);

// 사용자 정의 painter 위젯 드로잉
    /*
private:
    void paintEvent(QPaintEvent*) override;
*/

signals:
};

#endif // BALL_H
