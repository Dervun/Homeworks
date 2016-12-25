#include "cannon.h"
#include "simpleshot.h"
#include "othershot.h"

#include <QTransform>
#include <QPixmap>

Cannon::Cannon(QGraphicsScene* onwerScene, CannonColor cannonColour, ShotType shotType)
{
    scene = onwerScene;
    color = cannonColour;

    QPixmap newCannon;

    switch (color)
    {
    case black:
    {
        newCannon.convertFromImage(QImage(":/new/prefix1/images/cannons/black_cannon.png").scaled(size, size));
        break;
    }
    case green:
    {
        newCannon.convertFromImage(QImage(":/new/prefix1/images/cannons/green_cannon.png").scaled(size, size));
        break;
    }
    case red:
    {
        newCannon.convertFromImage(QImage(":/new/prefix1/images/cannons/red_cannon.png").scaled(size, size));
        break;
    }
    case gray:
    {
        newCannon.convertFromImage(QImage(":/new/prefix1/images/cannons/gray_cannon.png").scaled(size, size));
        break;
    }
    case blue:
    {
        newCannon.convertFromImage(QImage(":/new/prefix1/images/cannons/blue_cannon.png").scaled(size, size));
        break;
    }
    }

    myCannon = new QGraphicsPixmapItem(newCannon);
    myCannon->setTransformOriginPoint(size * 9 / 20, size * 5 / 7);
    scene->addItem(myCannon);
    setPosition(0);

    switch (shotType)
    {
    case simple:
    {
        shotMaker = new SimpleShot(myCannon);
        break;
    }
    case other:
    {
        shotMaker = new OtherShot;
        break;
    }
    }
}

void Cannon::makeShot()
{
    shotMaker->makeShot(rightOrientation);
}

void Cannon::moveLeft()
{
    this->setPosition(myCannon->x() - moveStep);
}

void Cannon::moveRight()
{
    this->setPosition(myCannon->x() + moveStep);
}

void Cannon::setPosition(int x)
{
    const int maxWidth = scene->width() - myCannon->boundingRect().width();
    if (x < 0 || x > maxWidth)
        return;
    myCannon->setX(x);
    this->correctVerticalPosition();
}

void Cannon::rotateUp()
{
    if (myCannon->rotation() < minAngle)
        return;
    myCannon->setRotation(myCannon->rotation() - rotationStep);
}

void Cannon::rotateDown()
{
    if (myCannon->rotation() > maxAngle)
        return;
    myCannon->setRotation(myCannon->rotation() + rotationStep);
}

Cannon::~Cannon()
{
    delete myCannon;
    delete shotMaker;
}

void Cannon::mirror()
{
    QTransform mirroring;
    mirroring.scale(-1, 1);
    mirroring.translate(-(myCannon->boundingRect().width()), 0);
    myCannon->setTransform(mirroring, true);
    rightOrientation = !rightOrientation;
}

void Cannon::correctVerticalPosition()
{
    qreal y = myCannon->y();
    if (myCannon->collidingItems().isEmpty())
    {
        while (myCannon->collidingItems().isEmpty())
        {
            y++;
            myCannon->setY(y);
        }
    }
    else
    {
        while (!myCannon->collidingItems().isEmpty())
        {
            y--;
            myCannon->setY(y);
        }
    }
}

