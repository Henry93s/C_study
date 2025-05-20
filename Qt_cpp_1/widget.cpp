#include "widget.h"
#include <QApplication>
#include <QPushbutton>
#include <QLabel>
#include <QObject>
#include <QRadioButton>
#include <QCheckBox>
#include <QButtonGroup>
#include <QFormLayout>
#include <QLineEdit>
#include <QValidator>

// widget.h 에 기본으로 있는 위젯을 사용자 커스텀
Widget::Widget(QWidget *parent): QWidget(parent){
    // 닫기 버튼 생성
    // &Quit :  this, SLOT(slotQuit()) : 사용자 정의 슬롯 사용을 위함
    /*
    QPushButton *quit = new QPushButton("&Quit", this);
    quit->move(10,10);
    quit->resize(75,35);
    // quit->show();
    */
    // 라벨 정의
    /*
    QLabel* label= new QLabel("<font color=blue>Label1!</font>", this);
    label->setGeometry(10,50,75,35);
    // 객체 이름(label1) 로 접근 가능은 findChild 메소드를 통해 가능
    label->setObjectName("label1");
    */

    // 라디오 버튼 그룹 생성
    /*
    resize(140,110);
    buttonGroup=new QButtonGroup(this);
    for(int i=0;i<4;i++){
        // %1 은 arg 첫번째 인자를 의미함
        QString str = QString("RadioButton %1").arg(i+1);
        radioButton[i] = new QRadioButton(str,this);
        radioButton[i]->move(10,10+20*i);
        buttonGroup->addButton(radioButton[i]);
    }
    */

    // 체크 박스 버튼 그룹 생성
    /*
    resize(140,110);
    buttonGroup=new QButtonGroup(this);
    buttonGroup->setExclusive(false);
    connect(buttonGroup, SIGNAL(idClicked(int)),SLOT(selectButton(int)));
    // 라벨 정의
    QLabel* label= new QLabel("0", this);
    label->move(10,10);
    connect(buttonGroup, &QButtonGroup::idClicked,
            [=](int id)mutable{label->setText(QString::number(id+1));});
    for(int i=0;i<4;i++){
        // %1 은 arg 첫번째 인자를 의미함
        QString str = QString("CheckBox %1").arg(i+1);
        checkBox[i] = new QCheckBox(str,this);
        checkBox[i]->move(10,10+20*i);
        // 버튼에 i 라는 id 를 넣어줌으로써 나중에 이 id 값을 가져올 수 있다.
        buttonGroup->addButton(checkBox[i],i);
    }
    */

    // QValidator 클래스
    QDoubleValidator* doubleValidator = new QDoubleValidator(this);

    //doubleValidator->setRange(10.0,100.0,3);
    doubleValidator->setBottom(10.0);
    doubleValidator->setTop(100.0);
    doubleValidator->setDecimals(3);

    QIntValidator* intValidator = new QIntValidator(this);

    //intValidator->setRange(13,19);
    intValidator->setBottom(13);
    intValidator->setTop(19);

    // excape C 는 \ 사용
    QRegularExpression re("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$");
    QRegularExpressionValidator* regExpValidator =
        new QRegularExpressionValidator(re,this);
    // lineEditRegExp->setInputMask("000.000.000.000;_); // ;_ : 숫자 입력 부분에 _ 이 들어감

    QLineEdit* lineEditDouble = new QLineEdit(this);
    lineEditDouble->setValidator(doubleValidator);

    QLineEdit* lineEditInt = new QLineEdit(this);
    lineEditInt->setValidator(intValidator);

    QLineEdit* lineEditRegExp = new QLineEdit(this);
    lineEditRegExp->setValidator(regExpValidator);

    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->addRow("&Double", lineEditDouble);
    formLayout->addRow("&Int", lineEditInt);
    formLayout->addRow("&Regular Expression", lineEditRegExp);

    setWindowTitle("Validator");
    //

    // 닫기 버튼 동작 &Quit 이므로 qApp -> this 로 변경
    // this, SLOT(slotQuit()) : 사용자 정의 슬롯 사용
    // connect(quit, SIGNAL(clicked()), this, SLOT(slotQuit()));
}
// label 위젯을 추가하고 체크박스에서 선택한 버튼의 숫자가 표시되는 메소드 구현
void Widget::selectButton(int id){
    // 슬롯을 호출한 객체는 sender() 메소드를 통해서 접근
    // (QButtonGroup*)sender(); 보다 dynamic_cast<QButtonGroup*>(sender()) 로 동적 캐스팅으로 구현하는 것이 더 좋음
    // QButtonGroup* buttonGroup = (QButtonGroup*)sender(); // 강제 형 변환 부분 주석처리
    QButtonGroup* buttonGroup = dynamic_cast<QButtonGroup*>(sender());
    QCheckBox* button = (QCheckBox*)buttonGroup->button(id);
    qDebug("CheckBox %d is selected(%s)", id+1,
           (button->isChecked()) ? "On" : "Off");
}

// 사용자 정의 슬롯 정의
void Widget::slotQuit(){
    // 객체 찾기 메소드 findChild 사용
    QLabel* label = findChild<QLabel*>("label1");
    qDebug("%s",qPrintable(label->metaObject()->className()));
    // qApp->quit(); 을 주석 처리하고 quit 버튼 클릭 시 World 로 텍스트 바뀜을 눈으로 "확인"할 수 있음
    label->setText("World");

    qDebug("slotQuit");

    // 사용자 정의 시그널 : 시그널은 호출하는게 아니라 emit 키워드로 "발생" 시킨다.
    emit clicked();

    // 사용자 정의 슬롯
    // qApp->quit();
}

Widget::~Widget(){

}
/*
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{}

Widget::~Widget() {}
*/
