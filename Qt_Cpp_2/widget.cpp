#include "widget.h"
#include <QPushButton>
// QHBoxLayout
#include <QHBoxLayout>
// QGridLayout
#include <QGridLayout>
#define NO_OF_ROW 3
// QStackedLayout
#include <QStackedLayout>
#include <QDial>
#include <QLabel>
#include <QCalendarWidget>
#include <QTextEdit>
// QGroupBoxWidget
#include <QGroupBox>
#include <QStringList>
#include <QLineEdit>
#include <QFormLayout>
// QTabWidget
#include <QTabWidget>
// QToolBox
#include <QToolBox>
// QSplitter
#include <QSplitter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    /* QHBoxLayout or QVBoxLayout 확인을 위한 PushButton
    QPushButton* pushButton1 = new QPushButton(); // () 은 nullptr 이나 null 과 같음
    pushButton1->setText("Button1");
    QPushButton* pushButton2 = new QPushButton("Button2");
    // this : 위젯을 추가 시 처음부터 부모를 지정해주기도 함
    QPushButton* pushButton3 = new QPushButton("Button3", this);
    */

    /*
    // this : 위젯을 추가 시 처음부터 부모를 지정해주기도 함
    // QHBoxLayout class
    QHBoxLayout* hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->setContentsMargins(0,0,0,0);
    hBoxLayout->addWidget(pushButton1);
    hBoxLayout->addWidget(pushButton2);
    hBoxLayout->addWidget(pushButton3);
    setLayout(hBoxLayout);
    */


    /*
    // this : 위젯을 추가 시 처음부터 부모를 지정해주기도 함
    // QVBoxLayout class
    QVBoxLayout* vBoxLayout = new QVBoxLayout(this); // this -> setLayout
    vBoxLayout->setSpacing(6); // 레이아웃 내부 간격
    vBoxLayout->setDirection(QBoxLayout::TopToBottom);
    vBoxLayout->addWidget(pushButton1);
    vBoxLayout->addWidget(pushButton2);
    vBoxLayout->addWidget(pushButton3);
    setLayout(vBoxLayout);
    */

    /*
    // QGridLayout class
    QGridLayout* gridLayout=new QGridLayout;
    QPushButton* pushButton[NO_OF_ROW * NO_OF_ROW];
    for(int y=0;y<NO_OF_ROW;y++){
        for(int x=0;x<NO_OF_ROW;x++){
            int p = x+y*NO_OF_ROW;
            QString str = QString("Button%1").arg(p+1);
            pushButton[p] = new QPushButton(str,this);
            gridLayout->addWidget(pushButton[p],x,y);
        }
    }
    setLayout(gridLayout);
    */

    // #####

    /*
    // QStackedLayout class 시작
    // 다이얼 위젯 객체 생성
    QDial* dial = new QDial(this);
    dial->setRange(0,2);

    // 스택 레이아웃에 담을 객체를 생성
    QLabel* label = new QLabel("Stack 1", this);
    QCalendarWidget* calendarWidget = new QCalendarWidget(this);
    QTextEdit* textEdit = new QTextEdit("Stack 3", this);

    // QTabWidget (QStackedLayout class 시작 이어서)
    QTabWidget* tabWidget = new QTabWidget(this);
    // tab 위젯에 생성한 객체 추가
    tabWidget->addTab(dial, "Stack &1");
    tabWidget->addTab(calendarWidget, "Stack &2");
    tabWidget->addTab(textEdit, "Stack &3");
    // tabShape, tabPosition 설정 후 변화 확인
    tabWidget->setTabShape(QTabWidget::Triangular);
    tabWidget->setTabPosition(QTabWidget::West);

    resize(tabWidget->sizeHint());
    */
    // QStackedLayout (QStackedLayout class 시작 이어서)
    /*
    // new QStackedLayout(this); 는 레이아웃 깨짐 현상 발생
    // -> 레이아웃이 복잡해 질 때, 레이아웃 생성자에서는 생성자 매개변수에 this 를 사용하지 않는 것이 좋음
    // 스택 레이아웃 클래스 정의 후 레이아웃에 위젯 객체 추가
    QStackedLayout* stackedLayout = new QStackedLayout();
    stackedLayout->addWidget(label);
    stackedLayout->addWidget(calendarWidget);
    stackedLayout->addWidget(textEdit);

    // #####


    // &QDial::valueChanged == SIGNAL(valueChanged(int))
    // &QStackedLayout::setCurrentIndex == SLOT(setCurrentIndex(int))
    // connect 이벤트 전달
    connect(dial,&QDial::valueChanged, \
            stackedLayout, &QStackedLayout::setCurrentIndex);

    // horizontal 레이아웃 사용자 정의 클래스 정의
    QHBoxLayout* hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(dial);
    // widget 이 아닌 클래스 레이아웃 객체 이므로 addWidget 이 아닌 addLayout 메소드를 사용한다.
    hBoxLayout->addLayout(stackedLayout);
    // 수평 레이아웃 적용
    setLayout(hBoxLayout);
    */

    /*
    // QGroupBox Widget
    // 문자열 리스트 생성 및 정의
    QStringList labels;
    labels << "&IP Address" << "&Mac Address" << "&Date";

    // lineEdit 객체 생성
    QLineEdit* lineEdit[3];
    QFormLayout* formLayout = new QFormLayout;
    for(int i=0;i<3;i++){
        lineEdit[i] = new QLineEdit(this);
        // 각 label 과 edit 을 formlayout 에 행 추가
        formLayout->addRow(labels.at(i), lineEdit[i]);
    }

    // groupbox 객체 생성
    QGroupBox* groupBox = new QGroupBox("&Widget Group", this);
    groupBox->move(5,5);
    // groupbox 에 formlayout(label + edit) 레이아웃을 적용
    groupBox->setLayout(formLayout);

    resize(groupBox->sizeHint().width()+10, groupBox->sizeHint().height()+10);
    */


    // QSplitter
    // default : 수평 슬리터
    /*
    QLabel* label = new QLabel("&Value", this);
    QDial* dial1 = new QDial(this);
    QDial* dial2 = new QDial(this);
    label->setBuddy(dial2);

    QSplitter* splitter = new QSplitter(this);
    splitter->addWidget(label);
    splitter->addWidget(dial1);
    splitter->addWidget(dial2);

    resize(splitter->sizeHint());
    */


}

Widget::~Widget() {}
