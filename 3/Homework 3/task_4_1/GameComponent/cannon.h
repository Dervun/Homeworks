#pragma once
#include "simpleshot.h"
#include "megashot.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>


enum CannonColor{
    black,
    green,
    red,
    gray,
    blue
};

enum ShotType{
    simple,
    mega
};

/*!
 * \brief This class is the cannon in the Game
 * Cannon can move left and right, direct gun and take shot
 */
class Cannon : public QObject
{
    Q_OBJECT
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
    void changeShotType();
    void setSimpleShotType();
    ~Cannon();

signals:
    void hasWon();

private slots:
    void setWinner();
    void alertAboutWinner();

private:
    void correctVerticalPosition();
    void convertMyCannonFromImage();

    QGraphicsPixmapItem* myCannon = nullptr;
    QGraphicsScene* scene = nullptr;
    ShotMaker* shotMaker;
    ShotMaker* simpleShotMaker;
    ShotMaker* megaShotMaker;
    CannonColor color;
    ShotType type;
    QTimer timer;
    bool rightOrientation = true;
    const int size = 50; ///< = width = height of cannon
    const int minAngle = -45;
    const int maxAngle = 30;
    const int rotationStep = 3;
    const int moveStep = 3;
};
