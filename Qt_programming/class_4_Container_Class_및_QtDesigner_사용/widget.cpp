#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    // 현재 위젯 객체에 gui 인 ui 를 setup (필수)
    ui->setupUi(this);

    // ui 객체 포인터 이므로 -> 사용해서 각종 ui 위젯 객체를 가져온다.
    // ui 에 저장, 출력 버튼에서 SIGNAL 발생 시 SLOT 함수 연결 connect 정의
    connect(ui->pbtSave, SIGNAL(pressed()),
            this, SLOT(slot_pbtSave()));
    connect(ui->pbtPrint, SIGNAL(pressed()),
            this, SLOT(slot_pbtPrint()));
}

void Widget::slot_pbtSave(){
    // Q_FUNC_INFO 함수 반환 타입 및 이름 출력 : 디버그용으로 사용하기도 함
    qDebug() << Q_FUNC_INFO; // debugging

    // ui 에서 lineedit 위젯 에서 text 를 가져오고 변수에 저장
    int num = ui->leNum->text().toInt();
    QString name = ui->leName->text();
    QString part = ui->lePart->text();

    // ui 에서 가져온 변수를 employee 구조체를 만들고 값을 저장
    tEmployee employee;
    employee.num = num;
    employee.name = name;
    employee.part = part;

    // tEmployee 구조체 배열 리스트인 QList m_employeeList 에 추가
    m_employeeList.append(employee);

    // 배열 리스트에 추가하고 lineedit 에 작성된 내용은 clear()
    ui->leNum->clear();
    ui->leName->clear();
    ui->lePart->clear();
}

void Widget::slot_pbtPrint(){
    qDebug() << Q_FUNC_INFO; // debugging

    // 혹시 이전 출력물이 ui->textEdit 에 값이 남아있을 수 있으므로 모든 값 제거
    ui->textEdit->clear();

    // employee 구조체 배열 QList 에 있는 모든 사원 정보를
    // str 구조에 맞춰서 출력 ui->edit 란에 출력
    // qsizetype -> Qt 컨테이너 크기 표현 전용 타입
    //              개념은 완전 다르지만 동작은 c++ auto 느낌만 생각하면 될듯
    // ++i : for 문에서는 어차피 맨 마지막 단계에서 증감되므로
    // 메모리 소모를 덜하는 전위 증가로 i 를 처리한다.
    for(qsizetype i = 0;i<m_employeeList.size();++i){
        int num = m_employeeList.at(i).num;
        QString name = m_employeeList.at(i).name;
        QString part = m_employeeList.at(i).part;

        QString str;
        str = QString("[사원번호: %1] [성명: %2] [부서: %3]")
                  // .arg(num).arg(name).arg(part);
                  .arg(num).arg(name, part); // arg 인자 타입이 같을 때는 , 로 구분하여 동시 작성(warning 제거)

        // str 을 구조체에 남은 사원이 있을 때까지 계속 ui 에 출력
        ui->textEdit->append(str);
    }


}

Widget::~Widget()
{
    delete ui;
}
