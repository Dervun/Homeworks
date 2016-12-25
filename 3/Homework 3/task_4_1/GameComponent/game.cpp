#include "game.h"

#include <QPixmap>
#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsItem>


Game::Game(QObject *parent) : QObject(parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(QRect(0, 0, 677, 371));
    QPixmap newLandscape;
    newLandscape.convertFromImage(QImage(":/new/prefix1/images/landscape.png").scaled(679, 379));
    QGraphicsPixmapItem* landscape = new QGraphicsPixmapItem(newLandscape);
    scene->addItem(landscape);

    blackCannon = new Cannon(scene);
    blackCannon->setPosition(50);
    redCannon = new Cannon(scene, red);
    currentCannon = blackCannon;

    redCannon->mirror();
    redCannon->setPosition(550);
}

QGraphicsScene* Game::getScene()
{
    return scene;
}

Game::~Game()
{
    delete blackCannon;
    delete redCannon;
}

void Game::makeShot()
{
    currentCannon->makeShot();
}

void Game::moveLeft()
{
    currentCannon->moveLeft();
}

void Game::moveRight()
{
    currentCannon->moveRight();
}

void Game::rotateUp()
{
    currentCannon->rotateUp();
}

void Game::rotateDown()
{
    currentCannon->rotateDown();
}

void Game::mirror()
{
    currentCannon->mirror();
}

void Game::changeMove()
{
    if (movesBlackCannon)
        currentCannon = redCannon;
    else
        currentCannon = blackCannon;
    movesBlackCannon = !movesBlackCannon;
}
