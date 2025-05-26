#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent*) override;
    void enterEvent(QEnterEvent*) override;
    void leaveEvent(QEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
private:
    bool m_isEntered;
    bool m_isHighlighted;
    QTimer m_timer; // 계속 여러 번 버튼 클릭했을 때를 대비
    int cnt = 0;
signals:
    void clicked();
};
#endif // WIDGET_H
