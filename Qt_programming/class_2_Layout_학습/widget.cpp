#include "widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(500, 300);

    hboxLayout = new QHBoxLayout();
    for(int i=0;i<6;i++){
        btn[i] = new QPushButton(btnStr[i]);
        hboxLayout->addWidget(btn[i]);
    }

    vboxLayout = new QVBoxLayout();
    for(int i=0;i<3;i++){
        vBtn[i] = new QPushButton(btnStr2[i]);
        vboxLayout->addWidget(vBtn[i]);
    }

    gridLayout = new QGridLayout();
    for(int i=0;i<5;i++){
        gBtn[i] = new QPushButton(btnStr3[i]);
    }
    gridLayout->addWidget(gBtn[0], 0, 0);
    gridLayout->addWidget(gBtn[1], 0, 1);
    gridLayout->addWidget(gBtn[2], 1, 0, 1, 2);
    gridLayout->addWidget(gBtn[3], 2, 0);
    gridLayout->addWidget(gBtn[4], 2, 1);

    defaultLayout = new QVBoxLayout();
    defaultLayout->addLayout(hboxLayout);
    defaultLayout->addLayout(vboxLayout);
    defaultLayout->addLayout(gridLayout);

    this->setLayout(defaultLayout);
}



Widget::~Widget() {}
