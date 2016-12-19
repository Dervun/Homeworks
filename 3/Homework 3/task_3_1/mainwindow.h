#pragma once
#include "game.h"

#include <QMainWindow>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Game game;

    QShortcut* keyEnter = new QShortcut(this);
    QShortcut* keySpace = new QShortcut(this);
    QShortcut* keyTab = new QShortcut(this);

    QShortcut* keyLeft = new QShortcut(this);
    QShortcut* keyRight = new QShortcut(this);
    QShortcut* keyUp = new QShortcut(this);
    QShortcut* keyDown = new QShortcut(this);

    /// Synonyms of left, right, up, down
    QShortcut* keyW = new QShortcut(this);
    QShortcut* keyA = new QShortcut(this);
    QShortcut* keyS = new QShortcut(this);
    QShortcut* keyD = new QShortcut(this);
};


