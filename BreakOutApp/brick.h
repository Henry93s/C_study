#ifndef BRICK_H
#define BRICK_H

// 사용자 정의 QLabel 위젯 만들기
#include <QLabel>
// 사용자 정의 painter 위젯 드로잉
#include <QWidget>

// 사용자 정의 painter 위젯 드로잉
// class Brick : public QWidget
// 사용자 정의 QLabel 위젯 만들기
class Brick : public QLabel
{
    Q_OBJECT
public:
    explicit Brick(QWidget *parent = nullptr);

// 사용자 정의 painter 위젯 드로잉
    /*
private:
    void paintEvent(QPaintEvent*) override;
*/

signals:
};

#endif // BRICK_H
