#ifndef PADDLE_H
#define PADDLE_H

// 사용자 정의 QLabel 위젯 만들기
#include <QLabel>

// 사용자 정의 painter 위젯 드로잉
#include <QWidget>

// 사용자 정의 painter 위젯 드로잉
// class Paddle : public QWidget
// 사용자 정의 QLabel 위젯 만들기
class Paddle : public QLabel
{
    Q_OBJECT
public:
    explicit Paddle(QWidget *parent = nullptr);

// 사용자 정의 painter 위젯 드로잉
    /*
private:
    void paintEvent(QPaintEvent*) override;
*/

signals:
};

#endif // PADDLE_H
