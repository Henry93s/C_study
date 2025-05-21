#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>

class QAction;
class QTextEdit;

// 사용자 정의 메인 윈도우 QtEditor 클래스
class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

// 슬롯 추가
// 사용자 정의 슬롯을 위한 3가지 조건
/*
 * 1. 부모 클래스는 QObject 클래스를 직/간접적으로 상속
 * 2. 헤더파일에서 클래스의 선언 부분 아래에 Q_OBJECT 지시어 필요
 * 3. 클래스 내에 시그널과 슬롯을 선언
 */
public slots:
    // File menu
    void newFile();
    void open();
    void save();
    void saveAs();
    void print();
    void quit();
    // edit menu
    // (QtEditor 클래스에서 정의한 메소드 이므로 this 일 때 텍스트 출력됨!)
    void undo();
    void redo();
    void copy();
    void cut();
    void paste();
    void zoomIn();
    void zoomOut();
    // alignText 선언
    void alignText();

// 액션의 생성 및 설정과 시그널 및 슬롯을 한꺼번에 처리하는 메소드 선언
private:
    // QTextEdit 객체의 클래스 멤버 선언
    QTextEdit* textedit;

    template <typename T>
    QAction* makeAction(QString icon, QString text, T shortCut,
                        QString toolTip, QObject* recv, const char* slot);
    // 템플릿 특수화 함수 선언 : const char* 인자로 받는 메서드를 구현하기 위해서 템플릿의 특수화
    template <>
    QAction* makeAction(QString icon, QString text, const char* shortCut,
                        QString toolTip, QObject* recv, const char* slot);
    // 람다 함수 사용 : 람다 함수를 메서드의 인자로 사용시 템플릿을 사용
    // 펑터는 함수나 클래스의 객체로 정의 -> 템플릿 사용
    template <typename T, typename Functor>
    QAction* makeAction(QString icon, QString text, T shortCut,
                        QString toolTip, Functor lambda);
};
#endif // QTEDITOR_H
