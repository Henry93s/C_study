#include "qteditor.h"
// QTextEdit : 여러 줄의 문자열의 입력을 위한 위젯
#include <QTextEdit>
// QMenuBar : window 의 타이틀 바 아래쪽에 위치하는 메뉴바 위젯
/* - 부모 위젯 크기가 바뀌면 자동으로 크기 변경됨
 * - QMenu : QMenuBar 를 만들고 하위 메뉴 추가할 때 사용
 *  - addSeparator() : 하위 메뉴 요소들을 구분(ex. line)
 *  - addMenu : 서브 메뉴 추가
 *  - addAction : 지정한 메소드를 실행하는 액션
 *      - QAction : QMenu, QToolBar 등의 동작을 하나로 연결해서 사용
 *                  - 하나의 코드로 메뉴와 툴바를 한꺼번에 지원 : 코드의 통일성 증대
 */
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QStatusBar>
// QKeySequence : 단축키에 사용되는 키 시퀀스 정의 -> OS 표준 단축키를 적용할 수도 있음
#include <QKeySequence>
#include <QApplication>
#include <QIcon>
#include <QObject>
// QToolBar : 버튼으로 구성된 이동 가능한 패널을 제공
#include <QToolBar>
#include <QFontComboBox>
#include <QDoubleSpinBox>
// QStatusBar : 상태바 클래스
#include <QStatusBar>
#include <QLabel>

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    // QTextEdit ###
    QTextEdit* textedit = new QTextEdit(this);
    // textedit 중앙 배치
    setCentralWidget(textedit);
    // ###

    // QMenuBar + QMenu ###
    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);
    // 상위 2줄과 QMenuBar* menubar = this -> menuBar(); 와 같음
    // QMenu* fileMenu = menubar->addMenu("&File");

    // QAction
    // 액션의 쉬운 구현으로 변경 : 액션의 생성 및 설정과 시그널/슬롯을 한꺼번에 처리하는 메소드를 작성 예정
    /*
    QAction* newAct = new QAction(QIcon("./icon/new.png"), "&new", this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("make new file"));
    // 세 번째 인자가 this 일 경우 생략할 수 있다.
    connect(newAct, SIGNAL(triggered()), SLOT(newFile()));
    QMenu* fileMenu = menubar->addMenu("&File");
    // statusBar 에서 위 setStatusTip 이 출력됨
    QStatusBar* statusBar = new QStatusBar();
    setStatusBar(statusBar); // == this->statusBar();
    fileMenu->addAction(newAct);
    */

    QAction* newAct = makeAction("./icon/new.png", tr("&New"), QKeySequence::New,
                                 tr("make new file"), this, SLOT(newFile()));
    QAction* openAct = makeAction("./icon/open.png", tr("&Open"), QKeySequence::Open,
                                 tr("open file"), this, SLOT(open()));
    QAction* saveAct = makeAction("./icon/save.png", tr("&Save"), QKeySequence::Save,
                                 tr("save file"), this, SLOT(save()));
    QAction* saveAsAct = makeAction("./icon/saveAs.png", tr("&SaveAs"), QKeySequence::SaveAs,
                                 tr("save as file"), this, SLOT(saveAs()));
    QAction* printAct = makeAction("./icon/print.png", tr("&Print"), QKeySequence::Print,
                                    tr("print as file"), this, SLOT(print()));
    // 단축키를 문자열로 입력하면 제대로 동작하지 않는다
    // -> 해결 : 템플릿의 특수화 함수로 const char* 를 인자로 받는 메서드로 해결
    QAction* quitAct = makeAction("./icon/quit.png", tr("&Quit"), tr("Ctrl+Q"),
                                 tr("Quit this program"), qApp, SLOT(quit()));
    QMenu* fileMenu = menubar->addMenu("&File");
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator(); // 구분 선
    fileMenu->addAction(quitAct);
    // ###

    // QStatusBar : 상태바 클래스
    // 일시적 : 잠시 보여주는 정보(툴팁 이나 엔트리)
    // 보통 : 상태바의 일부를 차지하지만 일시적인 메시지에 의해서 가려질 수 있는 정보
    // 영구적 : 중요한 정보로 절대 가려지지 않음 -> 상태바에 새 위젯을 추가해서 사용
    QStatusBar* statusbar = statusBar();
    QLabel* statusLabel = new QLabel(tr("Qt Editor"), statusbar);
    statusLabel->setObjectName("StatusLabel");
    statusbar->addPermanentWidget(statusLabel); // 영구적 상태바 추가
    statusbar->showMessage("started", 1500);
    // ###

    // Edit 메뉴도 통째로 만들어보기 실습 ###
    QMenu* editMenu = menubar->addMenu("&Edit");
    // 중요 check ! : 시그널 연결시의 인자 설정
    // -> QTextEdit 객체 생성해놓은 textedit 에서 textedit 메소드(슬롯 함수) 를 찾아야 함
    QAction* undoAct = makeAction("./icon/undo.png", tr("&Undo"), QKeySequence::Undo,
                                 tr("undo text"), textedit, SLOT(undo()));
    QAction* redoAct = makeAction("./icon/redo.png", tr("&Redo"), QKeySequence::Redo,
                                  tr("redo text"), textedit, SLOT(redo()));
    QAction* copyAct = makeAction("./icon/copy.png", tr("&Copy"), QKeySequence::Copy,
                                  tr("copy text"), textedit, SLOT(copy()));
    QAction* cutAct = makeAction("./icon/cut.png", tr("&Cut"), QKeySequence::Cut,
                                  tr("cut text"), textedit, SLOT(cut()));
    QAction* pasteAct = makeAction("./icon/paste.png", tr("&Paste"), QKeySequence::Paste,
                                  tr("paste text"), textedit, SLOT(paste()));
    QAction* zoomInAct = makeAction("./icon/zoomIn.png", tr("&Zoom In"), QKeySequence::ZoomIn,
                                  tr("zoomIn text"), textedit, SLOT(zoomIn()));
    QAction* zoomOutAct = makeAction("./icon/zoomOut.png", tr("&Zoom Out"), QKeySequence::ZoomOut,
                                  tr("zoomOut text"), textedit, SLOT(zoomOut()));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();
    editMenu->addAction(zoomInAct);
    editMenu->addAction(zoomOutAct);
    // ###

    // QTextEdit 의 정렬 ###
    /*
     * (추가) SIGNAL 인자가 SLOT 메소드의 인자보다 많을 경우 동작 가능성 O (나머지 인자는 버려짐)
     *       - SIGNAL 인자가 SLOT 메소드의 인자보다 적을 경우 동작 X
     */
    // QTextEdit 객체를 헤더 파일 에 선언하지 않고, 따로 함수에서 만들지 않을 Case
    QMenu* alignMenu = menubar->addMenu("&Align");
    // 중요 check ! : 시그널 연결시의 인자 설정
    // -> QTextEdit 객체 생성해놓은 textedit 에서 textedit 메소드(슬롯 함수) 를 찾아야 함

    // left
    QAction* alignLeftAct = new QAction("&Left", textedit);
    alignLeftAct->setIcon(QIcon("./icon/left.png"));
    alignLeftAct->setShortcut(QString("Ctrl+Shift+L"));
    alignLeftAct->setStatusTip("text left align");
    connect(alignLeftAct, &QAction::triggered, textedit, [=]{textedit->setAlignment(Qt::AlignLeft);});
    alignMenu->addAction(alignLeftAct);

    // center
    QAction* alignCenterAct = new QAction("&Center", textedit);
    alignCenterAct->setIcon(QIcon("./icon/center.png"));
    alignCenterAct->setShortcut(QString("Ctrl+Shift+C"));
    alignCenterAct->setStatusTip("text center align");
    connect(alignCenterAct, &QAction::triggered, textedit, [=]{textedit->setAlignment(Qt::AlignCenter);});
    alignMenu->addAction(alignCenterAct);

    // right
    QAction* alignRightAct = new QAction("&Right", textedit);
    alignRightAct->setIcon(QIcon("./icon/right.png"));
    alignRightAct->setShortcut(QString("Ctrl+Shift+R"));
    alignRightAct->setStatusTip("text right align");
    connect(alignRightAct, &QAction::triggered, textedit, [=]{textedit->setAlignment(Qt::AlignRight);});
    alignMenu->addAction(alignRightAct);

    // justify
    QAction* alignJustifyAct = new QAction("&Justify", textedit);
    alignJustifyAct->setIcon(QIcon("./icon/justify.png"));
    alignJustifyAct->setShortcut(QString("Ctrl+Shift+J"));
    alignJustifyAct->setStatusTip("text justify align");
    connect(alignJustifyAct, &QAction::triggered, textedit, [=]{textedit->setAlignment(Qt::AlignJustify);});
    alignMenu->addAction(alignJustifyAct);
    // ###


    // toolbar 만들기 ###
    QToolBar* fileToolBar = addToolBar("&File");
    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    fileToolBar->addAction(newAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(saveAsAct);
    fileToolBar->addAction(printAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(quitAct);

    QMenu* windowMenu = menubar->addMenu("&Window");
    QMenu* toolbarMenu = windowMenu->addMenu("&Toolbar");
    toolbarMenu->addAction(fileToolBar->toggleViewAction()); // 툴바 끄고 켜기

    QFontComboBox* fontComboBox = new QFontComboBox(this);
    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)),
            textedit, SLOT(setCurrentFont(QFont)));
    QDoubleSpinBox* sizeSpinBox = new QDoubleSpinBox(this);
    connect(sizeSpinBox, SIGNAL(valueChanged(double)),
            textedit, SLOT(setFontPointSize(qreal)));

    addToolBarBreak(); // 다음 툴바는 아랫 줄에 위치

    QToolBar* formatToolbar = addToolBar("&Format");
    formatToolbar->addSeparator();
    formatToolbar->addWidget(fontComboBox);
    formatToolbar->addWidget(sizeSpinBox);
    // ###

}

// 템플릿 특수화 : const char* 인자로 받는 메서드를 구현하기 위해서 템플릿의 특수화
template <>
QAction* QtEditor::makeAction(QString icon, QString text, const char* shortCut,
                              QString toolTip, QObject* recv, const char* slot){
    QAction* act = new QAction(text, this);
    if(icon.length()){
        act->setIcon(QIcon(icon));
    }
    // 함수 인자 전달 시 묵시적 형변환으로 const char* 가 QString 형으로 변환
    act->setShortcut(QString(shortCut));
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()),recv,slot);
    return act;
}

template <typename T>
QAction* QtEditor::makeAction(QString icon, QString text, T shortCut,
                              QString toolTip, QObject* recv, const char* slot){
    QAction* act = new QAction(text, this);
    if(icon.length()){
        act->setIcon(QIcon(icon));
    }
    QKeySequence keySequence(shortCut);
    act->setShortcut(keySequence);
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()),recv,slot);
    return act;
}

// 일반 클래스 내에서 템플릿 기반의 메서드 정의(구현) 시 일반 템플릿 함수처럼 구현
template <typename T,typename Functor>
QAction* QtEditor::makeAction(QString icon, QString text, T shortCut,
                              QString toolTip, Functor lambda){
    QAction* act = new QAction(text, this);
    if(icon.length()){
        act->setIcon(QIcon(icon));
    }
    // 단축키를 QKeySequence 의 객체로 만들어 넣으면 템플릿의 특수화(act->setShortcut(QString(shortCut));)는 필요없음
    QKeySequence keySequence(shortCut);
    act->setShortcut(keySequence);
    act->setStatusTip(toolTip);

    connect(act, SIGNAL(triggered()),this,lambda);

    return act;
}

// 사용자 정의 슬롯 : alignText 정의
void QtEditor::alignText(){

}

// newFile() 외 파일 메뉴 SLOT
void QtEditor::newFile(){
    qDebug("Make New File Debug");
}
void QtEditor::open(){
    qDebug("open File Debug");
}
void QtEditor::save(){
    qDebug("save File Debug");
}
void QtEditor::saveAs(){
    qDebug("saveAs File Debug");
}
void QtEditor::print(){
    qDebug("print File Debug");
}
void QtEditor::quit(){
    qDebug("quit program Debug");
}
// edit 메뉴 SLOT debug
// 문제 : (QtEditor 클래스에서 정의한 메소드 이므로 this 일 때 텍스트 출력됨!)
// 해결 : QTextEdit 클래스 객체에서 함수를 가져와야 함
void QtEditor::undo(){
    qDebug("undo text Debug");
}
void QtEditor::redo(){
    qDebug("redo text Debug");
}
void QtEditor::copy(){
    qDebug("copy text Debug");
}
void QtEditor::cut(){
    qDebug("cut text Debug");
}
void QtEditor::paste(){
    qDebug("paste text Debug");
}
void QtEditor::zoomIn(){
    qDebug("zoomIn text Debug");
}
void QtEditor::zoomOut(){
    qDebug("zoomOut text Debug");
}


QtEditor::~QtEditor() {}
