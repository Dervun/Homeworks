#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./NetworkComponent/client.h"
#include "./NetworkComponent/server.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    game = new Game;
    ui->gameField->setScene(game->getScene());

    ui->connectButton->setVisible(false);
    ui->serverLabel->setVisible(false);
    ui->portLabel->setVisible(false);
    ui->lineEditForPort->setVisible(false);

    setKeys();
    activateKeys();
    connect(keyNewGame, SIGNAL(activated()), game, SLOT(startNewGame()));

    connectButtons();

    connect(game, SIGNAL(lockScene()), this, SLOT(deactivateKeys()));
    connect(game, SIGNAL(unlockScene()), this, SLOT(activateKeys()));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete keyNewGame;
    delete keyEnter;
    delete keySpace;
    delete keyTab;

    delete keyLeft;
    delete keyRight;
    delete keyUp;
    delete keyDown;

    delete keyW;
    delete keyA;
    delete keyS;
    delete keyD;

    if (network != nullptr)
        delete network;
}

void MainWindow::createClient()
{
    network = new Client(game);
    connect(network, SIGNAL(connectedOtherNetworkObject()), this, SLOT(hideNetworkSettings()));
    connect(ui->connectButton, SIGNAL(clicked(bool)), this, SLOT(tryToConnectToServer()));
    connect(this, SIGNAL(connectToServer(int)), network, SLOT(connectToServer(int)));

    disconnect(ui->clientButton, SIGNAL(clicked(bool)), this, SLOT(createClient()));
}

void MainWindow::createServer()
{
    network = new Server(game, this);
    connect(network, SIGNAL(connectedOtherNetworkObject()), this, SLOT(hideNetworkSettings()));
    game->changeEnemy();

    disconnect(ui->serverButton, SIGNAL(clicked(bool)), this, SLOT(createServer()));
}

void MainWindow::hideNetworkSettings()
{
    ui->connectButton->setVisible(false);
    ui->serverButton->setVisible(false);
    ui->clientButton->setVisible(false);
    ui->lineEditForPort->setVisible(false);
    ui->portLabel->setVisible(false);
    setFixedHeight(400);
}

void MainWindow::activateKeys()
{
    connect(keyEnter, SIGNAL(activated()), game, SLOT(makeShot()));
    connect(keySpace, SIGNAL(activated()), game, SLOT(mirror()));
    connect(keyTab, SIGNAL(activated()), game, SLOT(changeShotType()));

    connect(keyLeft, SIGNAL(activated()), game, SLOT(moveLeft()));
    connect(keyRight, SIGNAL(activated()), game, SLOT(moveRight()));
    connect(keyUp, SIGNAL(activated()), game, SLOT(rotateUp()));
    connect(keyDown, SIGNAL(activated()), game, SLOT(rotateDown()));

    connect(keyW, SIGNAL(activated()), game, SLOT(rotateUp()));
    connect(keyA, SIGNAL(activated()), game, SLOT(moveLeft()));
    connect(keyS, SIGNAL(activated()), game, SLOT(rotateDown()));
    connect(keyD, SIGNAL(activated()), game, SLOT(moveRight()));
}

void MainWindow::deactivateKeys()
{
    disconnect(keyEnter, SIGNAL(activated()), game, SLOT(makeShot()));
    disconnect(keySpace, SIGNAL(activated()), game, SLOT(mirror()));
    disconnect(keyTab, SIGNAL(activated()), game, SLOT(changeShotType()));

    disconnect(keyLeft, SIGNAL(activated()), game, SLOT(moveLeft()));
    disconnect(keyRight, SIGNAL(activated()), game, SLOT(moveRight()));
    disconnect(keyUp, SIGNAL(activated()), game, SLOT(rotateUp()));
    disconnect(keyDown, SIGNAL(activated()), game, SLOT(rotateDown()));

    disconnect(keyW, SIGNAL(activated()), game, SLOT(rotateUp()));
    disconnect(keyA, SIGNAL(activated()), game, SLOT(moveLeft()));
    disconnect(keyS, SIGNAL(activated()), game, SLOT(rotateDown()));
    disconnect(keyD, SIGNAL(activated()), game, SLOT(moveRight()));
}

void MainWindow::showPort(char* port)
{
    ui->serverLabel->setText(QString(" Your port: ") + QString(port));
    ui->serverLabel->setVisible(true);
}

void MainWindow::tryToConnectToServer()
{
    int port = ui->lineEditForPort->text().toInt();
    emit connectToServer(port);
}

void MainWindow::showPortSettings()
{
    ui->portLabel->setVisible(true);
    ui->lineEditForPort->setVisible(true);
}

void MainWindow::setKeys()
{
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
}

void MainWindow::connectButtons()
{
    connect(ui->clientButton, SIGNAL(clicked(bool)), ui->connectButton, SLOT(show()));

    connect(ui->clientButton, SIGNAL(clicked(bool)), this, SLOT(createClient()));
    connect(ui->clientButton, SIGNAL(clicked(bool)), ui->clientButton, SLOT(setEnabled(bool)));
    connect(ui->clientButton, SIGNAL(clicked(bool)), ui->serverButton, SLOT(setVisible(bool)));
    connect(ui->clientButton, SIGNAL(clicked(bool)), ui->label, SLOT(setVisible(bool)));
    connect(ui->clientButton, SIGNAL(clicked(bool)), this, SLOT(showPortSettings()));

    connect(ui->serverButton, SIGNAL(clicked(bool)), this, SLOT(createServer()));
    connect(ui->serverButton, SIGNAL(clicked(bool)), ui->serverButton, SLOT(setEnabled(bool)));
    connect(ui->serverButton, SIGNAL(clicked(bool)), ui->clientButton, SLOT(setVisible(bool)));
    connect(ui->serverButton, SIGNAL(clicked(bool)), ui->label, SLOT(setVisible(bool)));
}
