#include "widget.h"

#include <QDir> // 디렉터리 조작
#include <QFile> // 파일 조작
#include <QListWidget>
#include <QFileInfo>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QLineEdit>
#include <QTextEdit> // 파일 내용과 결과 표시
#include <QMenu> // 컨텍스트 메뉴를 위함
#include <QContextMenuEvent>
#include <QApplication>

#include <QMessageBox>
#include <QTextStream>
#include <QProcess>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    directory = new QDir("."); // 현재 디렉터리 내용을 저장하는 객체

    // 메뉴를 위한 액션들을 정의
    QAction* mkdirAction = new QAction("&Make Directory", this);
    connect(mkdirAction, SIGNAL(triggered()), SLOT(makeDir()));

    QAction* copyAction = new QAction("&Copy",this);
    connect(copyAction, SIGNAL(triggered()), SLOT(copyFile()));

    QAction* removeAction = new QAction("&Remove", this);
    connect(removeAction, SIGNAL(triggered()), SLOT(removeDir()));

    QAction* renameAction = new QAction("&Rename", this);
    connect(renameAction, SIGNAL(triggered()), SLOT(renameDir()));

    QAction* quitAction = new QAction("&Quit", this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    // 액션을 메뉴에 추가
    m_menu = new QMenu(this);
    m_menu->addSection("&Directory");
    m_menu->addAction("mkdirAction");
    m_menu->addSeparator();
    m_menu->addSection("&File");
    m_menu->addAction("copyAction");
    m_menu->addAction("removeAction");
    m_menu->addAction("renameAction");
    m_menu->addSeparator();
    m_menu->addAction("quitAction");

    // 화면에 표시될 위젯들을 정의하고 레이아웃
    dirListWidget = new QListWidget(this);
    filenameLineEdit = new QLineEdit(this);

    outputEdit = new QTextEdit(this);
    outputEdit->setReadOnly(true);

    QPushButton* actionButton = new QPushButton("Action", this);
    actionButton->setMenu(m_menu); // 팝업 메뉴를 설정

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(dirListWidget);
    layout->addWidget(filenameLineEdit);
    layout->addWidget(actionButton);
    layout->addWidget(outputEdit);

    // 시그널과 슬롯을 연결
    connect(dirListWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(selectItem(QListWidgetItem*)));
    connect(dirListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), SLOT(changeDir()));

    refreshDir(); // 현재 디렉터리의 내용을 QListWidget 에 표시
}

Widget::~Widget() {} // 소멸자

void Widget::refreshDir(){ // 디렉터리 갱신
    dirListWidget->clear(); // 현재 QListWidget 의 내용을 모두 삭제

    // QDir 클래스에 저장된 현재 파일 목록을 QListWidget 에 아이템으로 추가
    for(int index=0;index<directory->entryList().count();index++){
        dirListWidget->addItem(directory->entryList().at(index));
    }
}

// 마우스 오른쪽 버튼을 누르면 컨텍스트 메뉴 표시
void Widget::selectItem(QListWidgetItem* item){
    filenameLineEdit->setText(item->text());
}

// 파일 복사
void Widget::copyFile(){
    QString filename = directory->absoluteFilePath(dirListWidget->currentItem()->text());

    QFileInfo checkDir(filename);
    if(checkDir.isFile() && filenameLineEdit->text().length()){
        QString newFile = directory->absoluteFilePath(filenameLineEdit->text());
        QFile::copy(filename, newFile); // QFile 의 static 메소드 사용
    }
    directory->refresh(); // QDir 클래스는 현재 의 디렉토리 정보를 캐싱
    refreshDir();
}

// QListWidget 을 더블 클릭하면 호출
void Widget::changeDir(){
    // 현재 파일의 경로를 절대 경로로 변경
    QString filename = directory->absoluteFilePath(dirListWidget->currentItem()->text());
    QFileInfo checkDir(filename); // QFileInfo 클래스로 파일 체크
    if(checkDir.isDir()){ // 디렉터리면 파일 이동 후 QListWidget 을 갱신
        directory->cd(filename);
        directory->refresh();
        refreshDir();
    } else if(checkDir.isExecutable()){
        QProcess cmd;
        QStringList arguments;
        cmd.start(filename,arguments);

        outputEdit->clear();
        if(!cmd.waitForStarted()) return;
        QByteArray result = cmd.readAllStandardOutput();
        outputEdit->append(result);
        if(!cmd.waitForFinished()) return;
        result = cmd.readAllStandardOutput();
        outputEdit->append(result);
    } else if(checkDir.isFile()){ // 파일 읽기 추가. 파일 이면
        if(checkDir.isReadable()){ // 읽기 가능하면 파일을 열어서
            QFile file(filename);
            file.open(QFile::ReadOnly);
            QTextStream in(&file); // 읽을 파일에 대한 스트림

            outputEdit->setWindowTitle(filename);
            outputEdit->clear(); // QTextEdit 의 내용을 지우고 표시
            QString line;
            while(in.readLineInto(&line)){ // 파일을 한 줄씩 읽어서 QTextEdit 에 추가
                outputEdit->append(line);
            }
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Can't Read this file");
        }
    }
}

// 디렉터리 생성
void Widget::makeDir(){
    if(filenameLineEdit->text().length()){
        directory->mkdir(filenameLineEdit->text());
        directory->refresh(); // QDir 클래스는 현재 디렉터리 정보를 캐싱
        refreshDir();
    }
}

// 디렉터리나 파일 삭제
void Widget::removeDir(){
    if(filenameLineEdit->text().length() && dirListWidget->currentItem() != NULL){
        QString filename = directory->absoluteFilePath(dirListWidget->currentItem()->text());
        QFileInfo checkDir(filename);
        if(checkDir.isDir()){ // 디렉터리면 디렉터리 삭제
            directory->rmdir(filenameLineEdit->text());
        }else if(checkDir.isFile()){
            QFile::remove(filename);
        }
        directory->refresh();
        refreshDir();
    }
}

// 디렉터리나 파일의 이름 변경
void Widget::renameDir(){
    if(filenameLineEdit->text().length() && dirListWidget->currentItem() != NULL){
        directory->rename(dirListWidget->currentItem()->text(), filenameLineEdit->text());
        directory->refresh();
        refreshDir();
    }
}

// 컨텍스트 메뉴를 오픈
void Widget::contextMenuEvent(QContextMenuEvent* event){
    QWidget::contextMenuEvent(event);
    m_menu->exec(QCursor::pos());
}
