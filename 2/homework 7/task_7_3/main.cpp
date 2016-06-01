#include <QApplication>

#include "gamefieldtest.h"
#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    GameFieldTest test;
    QTest::qExec(&test);
    return a.exec();
}

