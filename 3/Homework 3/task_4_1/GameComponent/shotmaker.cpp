#include "shotmaker.h"

#include <QPixmap>
#include <QtMath>
#include <QGraphicsScene>

ShotMaker::~ShotMaker()
{
    if (!shellInScene)
        delete shell;
}

void ShotMaker::makeShot(bool rightSide)
{
    if (!this->canShot())
        return;
    this->updatePatametrs(rightSide);

    myCannon->scene()->addItem(shell);
    shellInScene = true;

    connect(&timer, SIGNAL(timeout()), this, SLOT(updatePosition()));
    timer.start(updateFrequency);

    updatePosition();
}

bool ShotMaker::canShot()
{
    return !shellInScene;
}

void ShotMaker::updatePatametrs(bool rightSide)
{
    t = 0;
    if (rightSide)
        direction = 1;
    else
        direction = -1;

    float angle = qDegreesToRadians(30 - myCannon->rotation());
    xSpeed = initialSpeed * qCos(angle);
    ySpeed = initialSpeed * qSin(angle);

    int xDeviation = 60;
    int yDeviation = 20;
    if (!rightSide)
        xDeviation = 30;
    QPoint initialPlace(xDeviation, yDeviation);
    x = myCannon->mapToScene(initialPlace).x();
    y = myCannon->mapToScene(initialPlace).y();
}

bool ShotMaker::needDestroy()
{
    return shell->x() < 0 || shell->x() > myCannon->scene()->width() ||
           (!shell->collidesWithItem(myCannon) && !shell->collidingItems().empty());
}

void ShotMaker::updatePosition()
{
    t += (float) updateFrequency / 300;

    shell->setPos(x + t * xSpeed * direction - shift, y - (ySpeed - (g / 2) * t) * t - shift);

    if (needDestroy())
    {
        timer.stop();
        checkCollisionsWithCannons();
        shell->scene()->removeItem(shell);
        shellInScene = false;
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(updatePosition()));
    }
}
