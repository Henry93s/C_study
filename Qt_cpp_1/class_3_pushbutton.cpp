#include <QApplication>
#include <QLabel>
#include <QPushbutton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton quit("Quit", 0);
    quit.resize(75, 35);
    quit.show();

    return a.exec();
}
