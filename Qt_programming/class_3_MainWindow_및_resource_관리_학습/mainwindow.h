#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QListWidget>
#include <QStringList>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QPushButton>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slot_newFile();
    void slot_open();

public:
    QMenu* fileMenu;
    QAction* newAct;
    QAction* openAct;
    QToolBar* fileToolBar;

    QDockWidget* dock;
    QStringList list;
    QListWidget* customerList;

    QMdiArea* area;
    QMdiSubWindow* subWindow1;
    QMdiSubWindow* subWindow2;
    QPushButton* btn;

};
#endif // MAINWINDOW_H
