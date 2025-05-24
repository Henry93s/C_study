#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 계산기 위젯 기본 size
    this->setFixedSize(400, 500);

    // Layout 셋팅
    defaultLayout = new QVBoxLayout();
    defaultLayout->setAlignment(Qt::AlignTop); // 내부 상단 정렬 시킴(!)
    defaultLayout->setSpacing(10); // 내부 요소 간격
    gridLayout = new QGridLayout();

    // 상단 edit text Label 객체 정의
    resultLabel = new QLabel("0"); // 초기 데이터 0
    stack.push("0"); // 첫 계산기 객체 생성 시 stack 에 기본 값 0 push
    resultLabel->setFixedHeight(80);  // 높이 고정
    resultLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter); // 결과 라벨 텍스트 정렬
    resultLabel->setStyleSheet(
        "background-color: black;"
        "color: limegreen;"
        "border: 2px solid cyan;"
        "font-size: 40px;"
        "font-family: 'Segment7';"
        "padding: 10px;"
    ); // 결과 라벨 텍스트 디지털스타일 적용
    resultLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy:: Fixed);  // Fixed height 를 포함한 size policy


    // 하단 gridLayout 에 들어갈 버튼 객체 정의
    for(int i = 0; i < 16; i++){
        calcButton[i] = new QPushButton(buttonStr[i]);
        calcButton[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);  // 버튼도 최대한 키움
        calcButton[i]->setStyleSheet(
                "color: black;"
                "background-color: lightgray;"
                "font-weight: bold;"
                "font-size: 25px;"
        );
        // 모든 버튼에 signal <-> slot connect 함수 연결
        connect(calcButton[i], SIGNAL(clicked()), this, SLOT(pushDial()));
    }
    // gridlayout 으로 계산기에 맞는 레이아웃에 위젯을 추가하기
    int btnIndex = 0;
    // 4 x 4 버튼을 그리드 레이아웃에 모두 추가하기
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            gridLayout->addWidget(calcButton[btnIndex++], i, j);
        }
    }

    // 전체 default 레이아웃에 결과 label 과 gridlayout 추가 후 계산기 객체에 layout Set(적용)
    // 20 : 80 비율 레이아웃 stretch 추가(2번째 인자)
    defaultLayout->addWidget(resultLabel, 1);
    defaultLayout->addLayout(gridLayout, 4);
    this->setLayout(defaultLayout);
}

// 계산기 버튼 눌렀을 때 signal 에 따른 slot 함수 정의
void Widget::pushDial(){
    // QObject::sender() 함수로 슬롯을 호출한 객체 정보를 가져온다.
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    // 호출한 객체 정보에 따라 다르게 동작한다.
    if(btn){
        QString text = btn->text();
        bool ok;
        /* longlong 표현 가능 범위
         * -9,223,372,036,854,775,808 ~ +9,223,372,036,854,775,807
         */
        qint64 value = text.toLongLong(&ok);

        if(text.compare("C") == 0){ // 초기화
            // 스택을 비우고
            stack.clear();
            // 결과 라벨의 값을 0 으로 초기화 시키고, 스택엔 다시 "0" 을 넣는다.
            resultLabel->setText("0");
            stack.push("0");
        }
        // 입력 버튼 데이터가 숫자일 때
        else if(ok){
            bool s_ok;
            // Qint64(longlong) 으로 데이터를 받고, 스택 최상단 값이 숫자인지 판별한다.
            qint64 s_value = stack.top().toLongLong(&s_ok);
            if(!s_ok){ // case 1. 직전 stack 데이터가 연산자였을 경우
                // label 에 바로 값을 입력하고, 스택에 값을 push 한다.
                resultLabel->setText(text);
                stack.push(text);
            } else { // case 2. 직전 stack 데이터가 숫자 였을 경우
                // 1. stack pop
                // 2-1. pop 값이 0이면 append 없이 라벨 텍스트 수정, stack 에 push
                // 2-2. pop 값이 0이 아니면 append 후 stack 에 push
                QString temp = stack.pop();
                qDebug() << temp;
                if(temp.toLongLong() == 0){ // 직전 stack pop 숫자가 0일 때
                    resultLabel->setText(text);
                    stack.push(text);
                } else{ // 직전 stack pop 숫자가 0이 아닐 때(계속 숫자 입력 시)
                    temp.append(text);
                    stack.push(temp);
                    resultLabel->setText(temp);
                }
            }
        }
        // = 연산자
        // 동작 조건 : 스택에 3개의 데이터(숫자1, 연산자, 숫자2)가 있고, 직전 데이터가 숫자일 때만 동작한다.
        else if(text.compare("=") == 0){ // = 연산
            bool s_ok;
            // Qint64(longlong) 으로 데이터를 받고, 스택 최상단 값이 숫자인지 판별한다.
            qint64 s_value = stack.top().toLongLong(&s_ok);
            // 동작 과정 1. stack 에서 숫자2 pop, 연산자 pop, 숫자1 pop 한다.
            // 과정 2. 연산 결과를 다시 stack 에 push 한다.
            if(stack.size() == 3 && s_ok){
                // stack 에서 데이터(숫자1, 연산자, 숫자2) 를 빼고 결과 값을 다시 insert
                calculate();
            }
        }
        // 사칙 연산자 일 때
        // 동작 최소 조건 : 직전 데이터가 숫자일 때만 동작한다.
        // 동작 케이스 1. stack의 size가 3이라서 이미 연산자를 가지고 있는 stack일 경우
        // 1-1. = 연산자와 동일하게 동작하고
        // 1-2. 마지막에 입력한 연산자를 추가로 push 한다.
        // 동작 케이스 2. stack 의 size 가 1일 때, 연산자를 가지고 있지 않은 stack일 경우
        // 2-1. 입력한 연산자를 push 한다.
        else if(text.compare("+") == 0 || text.compare("-") == 0 || text.compare("*") == 0 || text.compare("/") == 0){
            bool s_ok;
            // Qint64(longlong) 으로 데이터를 받고, 스택 최상단 값이 숫자인지 판별한다.
            qint64 s_value = stack.top().toLongLong(&s_ok);
            // 동작 1. stack의 size가 3이라서 이미 연산자를 가지고 있는 stack일 경우
            // 1-1. = 연산자와 동일하게 동작하고
            // 1-2. 마지막에 입력한 연산자를 추가로 push 한다.
            if(stack.size() == 3 && s_ok){
                // stack 에서 데이터(숫자1, 연산자, 숫자2) 를 빼고 결과 값을 다시 insert
                calculate();
                // 추가로 연산자까지 삽입한다.
                stack.push(text);
            } else if(stack.size() == 1 && s_ok){
                // 연산자만 추가 삽입한다.
                stack.push(text);
            }
        }
        // debugging test
        QStack<QString> temp = stack;
        while (!temp.isEmpty()) {
            qDebug() << temp.pop();
        }
        qDebug() << "\n";
    }
}

void Widget::calculate(){
    QString y = stack.pop(); // 숫자 2 를 뺀다.
    QString op = stack.pop(); // 연산자 를 뺀다.
    QString x = stack.pop(); // 숫자 1 을 뺀다.

    if(op == "+"){
        auto result = x.toLongLong() + y.toLongLong(); // + 연산을 한다.
        stack.push(QString::number(result)); // 연산 결과를 QString 으로 insert 한다.
        resultLabel->setText(QString::number(result)); // 결과 라벨에도 즉시 결과를 반영한다.
    } else if(op == "-"){
        auto result = x.toLongLong() - y.toLongLong(); // + 연산을 한다.
        stack.push(QString::number(result)); // 연산 결과를 QString 으로 insert 한다.
        resultLabel->setText(QString::number(result)); // 결과 라벨에도 즉시 결과를 반영한다.
    } else if(op == "*"){
        auto result = x.toLongLong() * y.toLongLong(); // + 연산을 한다.
        stack.push(QString::number(result)); // 연산 결과를 QString 으로 insert 한다.
        resultLabel->setText(QString::number(result)); // 결과 라벨에도 즉시 결과를 반영한다.
    } else if(op == "/"){
        auto result = x.toLongLong() / y.toLongLong(); // + 연산을 한다.
        stack.push(QString::number(result)); // 연산 결과를 QString 으로 insert 한다.
        resultLabel->setText(QString::number(result)); // 결과 라벨에도 즉시 결과를 반영한다.
    }
}

Widget::~Widget() {}
