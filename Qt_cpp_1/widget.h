#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// class 지시어 : 현재 파일에서 사용하는 클래스가 다른 곳에서 정의되어 있다고 지정함
// -> class 의 헤더 파일을 main 과 같은 다른 파일에서 사용한다.
// => 효과 : 컴파일 시 반복해서 동일한 헤더 파일을 로드하지 않아
//          컴파일 시간 단축
class QRadioButton;
class QCheckBox;
class QButtonGroup;

class Widget : public QWidget
{
    // 사용자 정의 슬롯을 위한 조건 중 하나
    // -> 헤더 파일에서 클래스 선언 부분 아래에 Q_OBJECT 지시어 필요
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

// 사용자 정의 슬롯 선언
public slots:
    void slotQuit();
    void selectButton(int id);

// 사용자 정의 시그널 선언(따로 정의는 하지 않음!)
signals:
    void clicked();

private:
    QRadioButton* radioButton[4];
    QCheckBox* checkBox[4];
    QButtonGroup* buttonGroup;
};





#endif // WIDGET_H
