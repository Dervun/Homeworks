#pragma once
#include "shotmaker.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>


enum CannonColor{
    black,
    green,
    red,
    gray,
    blue
};

enum ShotType{
    simple,
    other
};

/*!
 * \brief This class is the cannon in the Game
 * Cannon can move left and right, direct gun and take shot
 */
class Cannon
{
public:
    Cannon(QGraphicsScene* onwerScene, CannonColor cannonColour = black, ShotType shotType = simple);
    void makeShot();
    /// \brief Move the cannon left at moveStep
    void moveLeft();
    void moveRight();
    void setPosition(int x);
    /// \brief Rotate the cannon up at rotationStep
    void rotateUp();
    void rotateDown();
    void mirror();
    ~Cannon();

private:
    void correctVerticalPosition();

    QGraphicsPixmapItem* myCannon = nullptr;
    QGraphicsScene* scene = nullptr;
    ShotMaker *shotMaker = nullptr;
    CannonColor color;
    bool rightOrientation = true;
    const int size = 50; ///< = width = height of cannon
    const int minAngle = -45;
    const int maxAngle = 30;
    const int rotationStep = 3;
    const int moveStep = 3;
};

