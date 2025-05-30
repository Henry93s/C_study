#include "widget.h"
#include <QtGui>
#include <QtWidgets>

#include "thread.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel* label = new QLabel(this);
    QPushButton* button = new QPushButton("Pause", this);
    button->setCheckable(true);

    thread = new Thread(label);

    QHBoxLayout* hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(label);
    hBoxLayout->addWidget(button);
    hBoxLayout->setSpacing(10);
    connect(button, SIGNAL(toggled(bool)), SLOT(threadControl(bool)));
    connect(thread, SIGNAL(setLabeled(QString)), label, SLOT(setText(QString)));

    thread->start();
}

Widget::~Widget() {
    thread->terminate(); // wait();
}

void Widget::threadControl(bool flag){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    button->setText((flag) ? "Resume" : "Pause");
    (flag) ? thread->stopThread():thread->resumeThread();
}
