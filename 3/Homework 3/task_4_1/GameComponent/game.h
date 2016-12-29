#pragma once
#include "cannon.h"

#include <QObject>
#include <QGraphicsScene>

/*!
 * \brief Game with cannons
 * Simple version of the Scorched Earch (goo.gl/HpZ6wP)
 */
class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    QGraphicsScene* getScene();
    void changeEnemy();
    ~Game();

signals:
    // for current cannon
    void cannonShot();
    void movedLeft();
    void movedRight();
    void rotatedUp();
    void rotatedDown();
    void turned();
    void changedShotType();
    void startedNewGame();

    void lockScene();
    void unlockScene();

private slots:
    // for current cannon
    void makeShot();
    void moveLeft();
    void moveRight();
    void rotateUp();
    void rotateDown();
    void mirror();
    void changeShotType();

    void changeCurrent();
    void displayResultOfGame();
    void startNewGame();
    void updateSceneLocking();
private:
    void addLandscapeAndCannonsAtScene();

    QGraphicsScene* scene;
    Cannon* blackCannon;
    Cannon* redCannon;
    Cannon* currentCannon;
    Cannon* enemy;
};
