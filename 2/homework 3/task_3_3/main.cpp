/*!
 * Реализовать продвинутый кнопочный калькулятор по аналогии со стандартными калькулятором Windows или KCalc
 * (для решения задачи использовать классы QGridLayout и QSignalMapper, взаимное расположение виджетов может быть другим).
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
