#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget calculator;
    calculator.show();

    return a.exec();
}
