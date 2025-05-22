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
// QDockWidget 클래스 : 다른 독 위젯을 담을 수 있는 독 위젯
#include <QDockWidget>
//
#include <QMdiArea>
#include <QMdiSubWindow>
// QDialog
#include <QDialog>
#include <QMessageBox>
// filedialog
#include <QFileDialog>
// color, font Dialog
#include <QColorDialog>
#include <QFontDialog>
// print
#include <QPrinter>
#include <qprintdialog.h>


QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    mdiArea = new QMdiArea(this);
    connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),SLOT(setFontWidget()));
    setCentralWidget(mdiArea);

    // QDockWidget ###
    QWidget* w = new QWidget(this);
    QLabel* label = new QLabel("Dock Widget", w);
    QDockWidget* dock = new QDockWidget("Dock Widget", this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    dock->setWidget(w);
    // ###
    // QMenuBar + QMenu ###

    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);
    QMenu* fileMenu = menubar->addMenu("&File");
    windowMenu = menubar->addMenu("&Window");
#if 0
    // QTextEdit ###
    // QTextEdit* textedit = new QTextEdit(this);
    QTextEdit* textedit = new QTextEdit(this);
    // textedit 중앙 배치
    // setCentralWidget(textedit);
    // ###
    mdiArea->addSubWindow(textedit);
#else
    QTextEdit* textedit = newFile();
#endif
    /*
    // QMenuBar + QMenu ###
    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);*/
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
    // QMenu* fileMenu = menubar->addMenu("&File");
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
    // (매우 중요 !) mdiArea 구현 중 세 번째 인자(textEdit)를 동적으로 변경하는 방법
    // 1. 창이 바뀔 때마다 인자 변경(QmdiArea 시그널을 이용, 비추)
    // 2. 슬롯이 불러질 때 선택된 창을 찾아서 호출하는 방법(사용자 슬롯 정의 방법, 권장)

    // 2. 슬롯이 불러질 때 선택된 창을 찾아서 호출하는 방법(사용자 슬롯 정의 방법)
    QAction* undoAct = makeAction("./icon/undo.png", tr("&Undo"), QKeySequence::Undo,
                                 tr("undo text"), this, SLOT(undo()));
    QAction* redoAct = makeAction("./icon/redo.png", tr("&Redo"), QKeySequence::Redo,
                                  tr("redo text"), this, SLOT(redo()));
    // 리소스 시스템 : 실시간 어플에 의하여 다른 자원들에 접근할 수 있도록 데이터 파일이 실행 파일 내에 저장
    // qteditor.qrc -> :/images/copy.png
    QAction* copyAct = makeAction(":/images/copy.png", tr("&Copy"), QKeySequence::Copy,
                                  tr("copy text"), this, SLOT(copy()));
    QAction* cutAct = makeAction("./icon/cut.png", tr("&Cut"), QKeySequence::Cut,
                                  tr("cut text"), this, SLOT(cut()));
    // 리소스 시스템 : 실시간 어플에 의하여 다른 자원들에 접근할 수 있도록 데이터 파일이 실행 파일 내에 저장
    // qteditor.qrc -> :images/paste.png
    QAction* pasteAct = makeAction(":/images/paste.png", tr("&Paste"), QKeySequence::Paste,
                                  tr("paste text"), this, SLOT(paste()));
    QAction* zoomInAct = makeAction("./icon/zoomIn.png", tr("&Zoom In"), QKeySequence::ZoomIn,
                                  tr("zoomIn text"), this, SLOT(zoomIn()));
    QAction* zoomOutAct = makeAction("./icon/zoomOut.png", tr("&Zoom Out"), QKeySequence::ZoomOut,
                                  tr("zoomOut text"), this, SLOT(zoomOut()));
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

    // format 메뉴 - font(수정 + ), color(수정 + ), QTextEdit 의 정렬 ###
    /*
     * (추가) SIGNAL 인자가 SLOT 메소드의 인자보다 많을 경우 동작 가능성 O (나머지 인자는 버려짐)
     *       - SIGNAL 인자가 SLOT 메소드의 인자보다 적을 경우 동작 X
     *
    // 2. 슬롯이 불러질 때 선택된 창을 찾아서 호출하는 방법(사용자 슬롯 정의 방법)
    // lambda Case !
    connect(fontAct, &QAction::triggered, textedit, [=]{dynamic_cast<QTextEdit*>(mdiArea->currentSubWindow()->widget())->setFont(QFont());});
     */
    QMenu* formatMenu = menubar->addMenu("&Format");
    QAction* fontAct = new QAction("&Font", textedit);
    fontAct->setIcon(QIcon("./icon/font.png"));
    fontAct->setShortcut(QString("Ctrl+F"));
    fontAct->setStatusTip("text font");
    // 2. 슬롯이 불러질 때 선택된 창을 찾아서 호출하는 방법(사용자 슬롯 정의 방법)
    connect(fontAct, SIGNAL(triggered()),
            this, SLOT(setFont()));

    QAction* colorAct = new QAction("&Color", textedit);
    colorAct->setIcon(QIcon("./icon/color.png"));
    colorAct->setShortcut(QString("Ctrl+G"));
    colorAct->setStatusTip("text color");
    // 2. 슬롯이 불러질 때 선택된 창을 찾아서 호출하는 방법(사용자 슬롯 정의 방법)
    connect(colorAct, SIGNAL(triggered()),
            this, SLOT(setColor()));

    formatMenu->addAction(fontAct);
    formatMenu->addAction(colorAct);
    // QTextEdit 객체를 헤더 파일 에 선언하지 않고, 따로 함수에서 만들지 않을 Case
    QMenu* alignMenu = formatMenu->addMenu("&Align");
    // 중요 check ! : 시그널 연결시의 인자 설정
    // -> QTextEdit 객체 생성해놓은 textedit 에서 textedit 메소드(슬롯 함수) 를 찾아야 함

    // left
    QAction* alignLeftAct = new QAction("&Left", textedit);
    alignLeftAct->setIcon(QIcon("./icon/left.png"));
    alignLeftAct->setShortcut(QString("Ctrl+Shift+L"));
    alignLeftAct->setStatusTip("text left align");
    // 2. 슬롯이 불러질 때 선택된 창을 찾아서 호출하는 방법(사용자 슬롯 정의 방법)
    // lambda Case !
    connect(alignLeftAct, &QAction::triggered, textedit, [=](){dynamic_cast<QTextEdit*>(mdiArea->currentSubWindow()->widget())->setAlignment(Qt::AlignLeft);});
    alignMenu->addAction(alignLeftAct);

    // center
    QAction* alignCenterAct = new QAction("&Center", textedit);
    alignCenterAct->setIcon(QIcon("./icon/center.png"));
    alignCenterAct->setShortcut(QString("Ctrl+Shift+C"));
    alignCenterAct->setStatusTip("text center align");
    // 2. 슬롯이 불러질 때 선택된 창을 찾아서 호출하는 방법(사용자 슬롯 정의 방법)
    // lambda Case !
    connect(alignCenterAct, &QAction::triggered, textedit, [=]{dynamic_cast<QTextEdit*>(mdiArea->currentSubWindow()->widget())->setAlignment(Qt::AlignCenter);});
    alignMenu->addAction(alignCenterAct);

    // right
    QAction* alignRightAct = new QAction("&Right", textedit);
    alignRightAct->setIcon(QIcon("./icon/right.png"));
    alignRightAct->setShortcut(QString("Ctrl+Shift+R"));
    alignRightAct->setStatusTip("text right align");
    connect(alignRightAct, &QAction::triggered, textedit, [=]{dynamic_cast<QTextEdit*>(mdiArea->currentSubWindow()->widget())->setAlignment(Qt::AlignRight);});
    alignMenu->addAction(alignRightAct);

    // justify
    QAction* alignJustifyAct = new QAction("&Justify", textedit);
    alignJustifyAct->setIcon(QIcon("./icon/justify.png"));
    alignJustifyAct->setShortcut(QString("Ctrl+Shift+J"));
    alignJustifyAct->setStatusTip("text justify align");
    connect(alignJustifyAct, &QAction::triggered, textedit, [=]{dynamic_cast<QTextEdit*>(mdiArea->currentSubWindow()->widget())->setAlignment(Qt::AlignJustify);});
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

    // windowMenu = menubar->addMenu("&Window");
    // cascade, tile | prev, next
    QAction* cascadeAct = new QAction("&Cascade", this);
    cascadeAct->setIcon(QIcon("./icon/cascade.png"));
    cascadeAct->setShortcut(QString("Ctrl+A+C"));
    cascadeAct->setStatusTip("cascade align");
    connect(cascadeAct, SIGNAL(triggered()),
            mdiArea, SLOT(cascadeSubWindows()));
    QAction* tileAct =  new QAction("&Tile", this);
    cascadeAct->setIcon(QIcon("./icon/tile.png"));
    cascadeAct->setShortcut(QString("Ctrl+A+T"));
    cascadeAct->setStatusTip("tile align");
    connect(tileAct, SIGNAL(triggered()),
            mdiArea, SLOT(tileSubWindows()));
    windowMenu->addAction(cascadeAct);
    windowMenu->addAction(tileAct);
    windowMenu->addSeparator();
    QAction* prevAct =  new QAction("&Prev", this);
    cascadeAct->setIcon(QIcon("./icon/prev.png"));
    cascadeAct->setShortcut(QString("Ctrl+W+P"));
    cascadeAct->setStatusTip("window prev");
    connect(prevAct, SIGNAL(triggered()),
            mdiArea, SLOT(activatePreviousSubWindow()));
    QAction* nextAct =  new QAction("&Next", this);
    cascadeAct->setIcon(QIcon("./icon/next.png"));
    cascadeAct->setShortcut(QString("Ctrl+W+N"));
    cascadeAct->setStatusTip("window next");
    connect(nextAct, SIGNAL(triggered()),
            mdiArea, SLOT(activateNextSubWindow()));
    windowMenu->addAction(prevAct);
    windowMenu->addAction(nextAct);
    windowMenu->addSeparator();
    // toolbar
    QMenu* toolbarMenu = windowMenu->addMenu("&Toolbar");
    toolbarMenu->addAction(fileToolBar->toggleViewAction()); // 툴바 끄고 켜기
    // QDockWidget add
    toolbarMenu->addAction(dock->toggleViewAction());

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

    // about menu ###
    QMenu* helpMenu = menubar->addMenu("&Help");
    QAction* aboutAct = new QAction("&About", this);
    aboutAct->setIcon(QIcon("./icon/about.png"));
    aboutAct->setShortcut(QString("Ctrl+H+A"));
    aboutAct->setStatusTip("help about");
    connect(aboutAct, SIGNAL(triggered()),
            this, SLOT( aboutHelp()) );
    helpMenu->addAction(aboutAct);



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
    connect(act, SIGNAL(triggered()),this,slot);
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


// newFile() 외 파일 메뉴 SLOT
QTextEdit* QtEditor::newFile(){
    //

    QAction* windowAct = new QAction("New File", this);
    windowMenu->addAction(windowAct);
    // ##
    qDebug("Make New File Debug");
    QTextEdit* textedit = new QTextEdit;
    //
    connect(textedit, SIGNAL(cursorPositionChanged()), SLOT(setFontWidget()));
    connect(windowAct, SIGNAL(triggered()),textedit, SLOT(setFocus()));
    connect(textedit,SIGNAL(destroyed(QObject*)), textedit, SLOT(deleteLater()));
    connect(textedit,SIGNAL(destroyed(QObject*)), windowAct, SLOT(deleteLater()));
    // ##
    mdiArea->addSubWindow(textedit);
    textedit->show();
    //
    windowHash[windowAct] = textedit;
    // ##

    return textedit;
}
void QtEditor::open(){
    qDebug("open File Debug");
    QString fileName = QFileDialog::getOpenFileName(this, "select file open", QDir::home().dirName(), "Text File (*.txt *.html *.c *.cpp *.h)");
    qDebug() << fileName;

    // 메모장 읽기
    if(!fileName.length()){
        return;
    }

    QFileInfo fileInfo(fileName); // 파일을 읽을 수 있는지 검사
    if(fileInfo.isReadable()){
        QFile file(fileName); // 파일을 읽기 모드로 열기
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray msg = file.readAll(); // 파일 읽기
        file.close(); // 열었던 파일 닫기


    QTextEdit* textedit = newFile(); // 새 창 생성
    textedit->setWindowTitle(fileName); // save 를 위해 경로 저장
    windowHash.key(textedit)->setText(fileName); // QAction 의 text 변경

    if(fileInfo.suffix() == "html" || fileInfo.suffix() == "html"){
        textedit->setHtml(msg); // 서식 있는 문자열 일 때
    } else {
        textedit->setPlainText(msg); // 서식 없는 문자열 일 때
    }

    } else {
        QMessageBox::warning(this, "Error", "Can't Read this file", QMessageBox::Ok);
    }
}
void QtEditor::save(){
    qDebug("save File Debug");
    QTextEdit* textedit = (QTextEdit*)this->mdiArea->currentSubWindow()->widget();
    QMdiSubWindow* window = this->mdiArea->currentSubWindow();
    if(window!=nullptr){
        textedit = qobject_cast<QTextEdit*>(window->widget());
    }

    QString fileName = textedit->windowTitle(); // 기존 파일명은 타이틀 바에 있음
    // 메모장 쓰기
    if(!fileName.length()){ // 파일명이 없을 때 사용자로부터 받아온다.
        fileName = QFileDialog::getSaveFileName(this, "select file save", ".", "Text File (*.txt *.html *.c *.cpp *.h)");
        qDebug() << fileName;

        if(!fileName.length()){ return; }
        textedit->setWindowTitle(fileName);
        windowHash.key(textedit)->setText(fileName); // QAction 의 text 변경
    }

    QFile file(fileName); // 파일 객체 생성
    file.open(QIODevice::WriteOnly | QIODevice::Text); // 파일을 문자 모드로 열기
    QFileInfo fileInfo(fileName); // 파일을 쓸 수 있는지 검사

    if(fileInfo.isWritable()){
        // QString 을 QByteArray 로
        QByteArray msg = (fileInfo.suffix() == "htm" || fileInfo.suffix() == "html") ?
                             textedit->toHtml().toUtf8():textedit->toPlainText().toUtf8();
        file.write(msg); // 파일을 저장
    } else {
        QMessageBox::warning(this, "Error", "Can't save this file", QMessageBox::Ok);
    }
    file.close();
}
void QtEditor::saveAs(){
    qDebug("saveAs File Debug");
    // 파일의 이름을 일단 무조건 불러온다
    QMdiSubWindow* window = this->mdiArea->currentSubWindow();
    if(window!=nullptr){
        QTextEdit* textedit = qobject_cast<QTextEdit*>(window->widget());
        QString fileName = QFileDialog::getSaveFileName(this, "select file save as", ".", "Text File (*.txt *.html *.c *.cpp *.h)");
        if(!fileName.length()){ return; }
        textedit->setWindowTitle(fileName);
        QFile* file = new QFile(fileName); // 파일 객체 생성

        file->open(QIODevice::WriteOnly | QIODevice::Text); // 파일을 문자 모드로 열기
        QFileInfo fileInfo(fileName); // 파일을 쓸 수 있는지 검사

        if(fileInfo.isWritable()){
            // QString 을 QByteArray 로
            QByteArray msg = (fileInfo.suffix() == "htm" || fileInfo.suffix() == "html") ?
                                 textedit->toHtml().toUtf8():textedit->toPlainText().toUtf8();
            file->write(msg); // 파일을 저장
        } else {
            QMessageBox::warning(this, "Error", "Can't save this file", QMessageBox::Ok);
        }
        file->close();
        qDebug() << fileName;
    }
}
void QtEditor::print(){
    qDebug("print File Debug");
    QPrinter printer(QPrinter::HighResolution);
    printer.setFullPage(true);
    QPrintDialog printDialog(&printer, this);
    if(printDialog.exec()==QDialog::Accepted){
        QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
        textedit->print(&printer);
    }
}
void QtEditor::quit(){
    qDebug("quit program Debug");
}
// edit 메뉴 SLOT debug
// 문제 : (QtEditor 클래스에서 정의한 메소드 이므로 this 일 때 텍스트 출력됨!)
// 해결 : QTextEdit 클래스 객체에서 함수를 가져와야 함
void QtEditor::undo(){
    qDebug("undo text Debug");
    QMdiSubWindow* subWindow = mdiArea->currentSubWindow();
    if(subWindow!=nullptr){
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->undo();
    }
}
void QtEditor::redo(){
    qDebug("redo text Debug");
    QMdiSubWindow* subWindow = mdiArea->currentSubWindow();
    if(subWindow!=nullptr){
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->redo();
    }
}
void QtEditor::copy(){
    qDebug("copy text Debug");
    QMdiSubWindow* subWindow = mdiArea->currentSubWindow();
    if(subWindow!=nullptr){
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->copy();
    }
}
void QtEditor::cut(){
    qDebug("cut text Debug");
    QMdiSubWindow* subWindow = mdiArea->currentSubWindow();
    if(subWindow!=nullptr){
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->cut();
    }
}
void QtEditor::paste(){
    qDebug("paste text Debug");
    QMdiSubWindow* subWindow = mdiArea->currentSubWindow();
    if(subWindow!=nullptr){
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->paste();
    }
}
void QtEditor::zoomIn(){
    qDebug("zoomIn text Debug");
    QMdiSubWindow* subWindow = mdiArea->currentSubWindow();
    if(subWindow!=nullptr){
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->zoomIn();
    }
}
void QtEditor::zoomOut(){
    qDebug("zoomOut text Debug");
    QMdiSubWindow* subWindow = mdiArea->currentSubWindow();
    if(subWindow!=nullptr){
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->zoomOut();
    }
}

void QtEditor::activatePreviousSubWindow(){
    qDebug("activatePreviousSubWindow");
}
void QtEditor::activateNextSubWindow(){
    qDebug("activateNextSubWindow");
}

void QtEditor::aboutHelp(){
    QMessageBox::question(this, "QMessageBox::showQuestion()", "Question Message",QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
}

void QtEditor::setColor(){
    QTextEdit* textedit = (QTextEdit*)this->mdiArea->currentSubWindow()->widget();
    QColor color = QColorDialog::getColor(textedit->textColor(),this);
    if(color.isValid()){
        textedit->setTextColor(color);
    }
}

void QtEditor::setFont(){
    bool ok;
    QTextEdit* textedit = (QTextEdit*)this->mdiArea->currentSubWindow()->widget();
    QFont font = QFontDialog::getFont(&ok, textedit->currentFont(),this);
    if(ok){
        textedit->setCurrentFont(font);
    }
}

QtEditor::~QtEditor() {}
