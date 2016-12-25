#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gameField->setScene(game.getScene());

    keyEnter->setKey(Qt::Key_Return);
    keySpace->setKey(Qt::Key_Space);
    keyTab->setKey(Qt::Key_Tab);

    keyLeft->setKey(Qt::Key_Left);
    keyRight->setKey(Qt::Key_Right);
    keyUp->setKey(Qt::Key_Up);
    keyDown->setKey(Qt::Key_Down);

    keyW->setKey(Qt::Key_W);
    keyA->setKey(Qt::Key_A);
    keyS->setKey(Qt::Key_S);
    keyD->setKey(Qt::Key_D);

    connect(keyEnter, SIGNAL(activated()), &game, SLOT(makeShot()));
    connect(keySpace, SIGNAL(activated()), &game, SLOT(mirror()));
    connect(keyTab, SIGNAL(activated()), &game, SLOT(changeMove()));

    connect(keyLeft, SIGNAL(activated()), &game, SLOT(moveLeft()));
    connect(keyRight, SIGNAL(activated()), &game, SLOT(moveRight()));
    connect(keyUp, SIGNAL(activated()), &game, SLOT(rotateUp()));
    connect(keyDown, SIGNAL(activated()), &game, SLOT(rotateDown()));

    connect(keyW, SIGNAL(activated()), &game, SLOT(rotateUp()));
    connect(keyA, SIGNAL(activated()), &game, SLOT(moveLeft()));
    connect(keyS, SIGNAL(activated()), &game, SLOT(rotateDown()));
    connect(keyD, SIGNAL(activated()), &game, SLOT(moveRight()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
