#include "game.h"

#include <QPixmap>
#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsItem>


Game::Game(QObject *parent) : QObject(parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(QRect(0, 0, 677, 371));
    blackCannon = new Cannon(scene);
    blackCannon->setPosition(109);
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
