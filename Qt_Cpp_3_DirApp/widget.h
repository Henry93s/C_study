#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QDir;
class QListWidget;
class QListWidgetItem;
class QLineEdit;
class QTextEdit;
class QMenu;
class QContextMenuEvent; // 오른쪽 마우스 버튼 클릭할 때의 메뉴 이벤트

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    // 컨텍스트 메뉴를 위한 이벤트 핸들러
    void contextMenuEvent(QContextMenuEvent*);

private:
    void refreshDir(); // QListWidget 위젯의 내용 갱신

    QDir* directory;
    QListWidget* dirListWidget; // 현재 디렉터리 파일 목록 표시
    QLineEdit* filenameLineEdit; // 수정을 위한 입력창
    QTextEdit* outputEdit; // 결과 출력창
    QMenu* m_menu; // 컨텍스트 메뉴

public slots:
    void selectItem(QListWidgetItem*); // QListWidget 의 클릭
    void changeDir(); // QlistWidget 의 더블 클릭
    void copyFile(); // 파일 복사
    void makeDir(); // 디렉터리 생성
    void removeDir(); // 디렉터리/파일 삭제
    void renameDir(); // 디렉터리/파일 이름 변경
};
#endif // WIDGET_H
