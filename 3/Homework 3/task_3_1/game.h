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
    ~Game();

private:
    QGraphicsScene* scene;
    Cannon* blackCannon;
    Cannon* redCannon;
    Cannon* currentCannon;
    bool movesBlackCannon = true;

private slots:
    /// Current cannon make shot
    void makeShot();
    void moveLeft();
    void moveRight();
    void rotateUp();
    void rotateDown();
    void mirror();

    void changeMove();
};

