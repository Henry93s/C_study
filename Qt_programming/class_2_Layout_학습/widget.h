#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGridLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QVBoxLayout* defaultLayout;

    QHBoxLayout* hboxLayout;
    QPushButton* btn[6];
    const QString btnStr[6] = {"Mon", "Tue", "Wed", "Thu",
                         "Fri", "Sat"};

    QVBoxLayout* vboxLayout;
    QPushButton* vBtn[3];
    const QString btnStr2[3] = {"Movie", "Drama", "Animation"};

    QGridLayout* gridLayout;
    QPushButton* gBtn[5];
    const QString btnStr3[5] = {"Mon", "Tue", "Wed", "Thu",
                                "Fri"};

};
#endif // WIDGET_H
