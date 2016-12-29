#include "game.h"

#include <QPixmap>
#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsItem>

Game::Game(QObject *parent) : QObject(parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(QRect(0, 0, 677, 371));
    addLandscapeAndCannonsAtScene();

    connect(redCannon, SIGNAL(hasWon()), this, SLOT(displayResultOfGame()));
    connect(blackCannon, SIGNAL(hasWon()), this, SLOT(displayResultOfGame()));
}

QGraphicsScene* Game::getScene()
{
    return scene;
}

void Game::changeEnemy()
{
    if (enemy == redCannon)
        enemy = blackCannon;
    else
        enemy = redCannon;
    updateSceneLocking();
}

Game::~Game()
{
    delete blackCannon;
    delete redCannon;
    delete scene;
}

void Game::updateSceneLocking()
{
    if (currentCannon == enemy)
        emit lockScene();
    else
        emit unlockScene();
}

void Game::makeShot()
{
    currentCannon->makeShot();
    changeCurrent();
    emit cannonShot();
}

void Game::moveLeft()
{
    currentCannon->moveLeft();
    emit movedLeft();
}

void Game::moveRight()
{
    currentCannon->moveRight();
    emit movedRight();
}

void Game::rotateUp()
{
    currentCannon->rotateUp();
    emit rotatedUp();
}

void Game::rotateDown()
{
    currentCannon->rotateDown();
    emit rotatedDown();
}

void Game::mirror()
{
    currentCannon->mirror();
    emit turned();
}

void Game::changeShotType()
{
    currentCannon->changeShotType();
    emit changedShotType();
}

void Game::changeCurrent()
{
    if (currentCannon == blackCannon)
        currentCannon = redCannon;
    else
        currentCannon = blackCannon;

    updateSceneLocking();
}

void Game::addLandscapeAndCannonsAtScene()
{
    QPixmap newLandscape;
    newLandscape.convertFromImage(QImage(":/new/prefix1/images/landscape.png").scaled(679, 379));
    QGraphicsPixmapItem* landscape = new QGraphicsPixmapItem(newLandscape);
    scene->addItem(landscape);

    blackCannon = new Cannon(scene);
    blackCannon->setPosition(50);
    redCannon = new Cannon(scene, red);
    currentCannon = blackCannon;
    enemy = redCannon;

    redCannon->mirror();
    redCannon->setPosition(550);
}

void Game::displayResultOfGame()
{
    emit lockScene();

    QPixmap newResult;
    if (currentCannon == enemy)
        newResult.convertFromImage(QImage(":/new/prefix1/images/congratulation.jpg").scaled(679, 377));
    else
        newResult.convertFromImage(QImage(":/new/prefix1/images/destroyed.png").scaled(679, 377));

    QGraphicsPixmapItem* result = new QGraphicsPixmapItem(newResult);

    result->setData(0, "Result");
    scene->addItem(result);
}

void Game::startNewGame()
{
    QList<QGraphicsItem*> itemsInScene = scene->items();
    for (QGraphicsItem* currentItem : itemsInScene)
    {
        if (currentItem->data(0).toString() == "Result")
        {
            scene->removeItem(currentItem);
            break;
        }
    }

    blackCannon->setPosition(50);
    redCannon->setPosition(550);

    currentCannon = blackCannon;
    currentCannon->setSimpleShotType();
    updateSceneLocking();
    emit startedNewGame();
}

