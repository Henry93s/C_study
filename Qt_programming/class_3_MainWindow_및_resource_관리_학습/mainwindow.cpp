#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    newAct = new QAction(QIcon(":/resource/new.png"),tr("New"),this);
    // 단축키 set, 미리 지정된 qt 시퀀스 사용 - 마우스 올리고 f1 시 키 확인 가능
    newAct->setShortcut(QKeySequence::New);
    // 설명 set
    newAct->setStatusTip("Create a new file");
    // signal slot 연결
    connect(newAct, SIGNAL(triggered()), this, SLOT(slot_newFile()));

    openAct = new QAction(QIcon(":/resource/open.png"),tr("Open"),this);
    // 단축키 set, 미리 지정된 qt 시퀀스 사용 - 마우스 올리고 f1 시 키 확인 가능
    openAct->setShortcut(QKeySequence::Open);
    // 설명 set
    openAct->setStatusTip("Open file");
    // signal slot 연결
    connect(openAct, SIGNAL(triggered()), this, SLOT(slot_open()));

    // menuBar, addToolBar 는 메인윈도우의 기본 메소드로 바로 사용
    // 메뉴 주소 를 File 로 생성
    fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);

    // 메뉴 File 주소에 툴바 추가하고 action 을 부여함
    fileToolBar = addToolBar("File");
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);


    // QDockWidget
    dock = new QDockWidget("target", this);
    // 허용 dock 의 위치 설정
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);


    // 독에 등록하기 위한 QListWidget
    customerList = new QListWidget();
    list << "one" << "two" << "three" << "four" << "five";
    customerList->addItems(list);
    dock->setWidget(customerList);
    addDockWidget(Qt::RightDockWidgetArea, dock);


    // mdi area
    area = new QMdiArea();
    area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    subWindow1 = new QMdiSubWindow();
    subWindow1->resize(300,200);
    btn = new QPushButton("Button");
    subWindow1->setWidget(btn);

    subWindow2 = new QMdiSubWindow();
    subWindow2->resize(300,200);

    area->addSubWindow(subWindow1);
    area->addSubWindow(subWindow2);

    setCentralWidget(area);

}

void MainWindow::slot_newFile(){
    qDebug() << Q_FUNC_INFO;
}

void MainWindow::slot_open(){
    qDebug() << Q_FUNC_INFO;
}

MainWindow::~MainWindow() {}
