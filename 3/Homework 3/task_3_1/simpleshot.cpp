#include "simpleshot.h"

#include <QPixmap>
#include <QtMath>
#include <QGraphicsScene>

SimpleShot::SimpleShot(QGraphicsItem *cannon)
{
    myCannon = cannon;
    QPixmap newShell;
    newShell.convertFromImage(QImage(":/new/prefix1/images/shell.png").scaled(shellSize, shellSize));
    shell = new QGraphicsPixmapItem(newShell);
}

SimpleShot::~SimpleShot()
{
    if (!shellInScene)
        delete shell;
}

void SimpleShot::makeShot(bool rightSide)
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

bool SimpleShot::canShot()
{
    return !shellInScene;
}

void SimpleShot::updatePatametrs(bool rightSide)
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

bool SimpleShot::needDestroy()
{
    return shell->x() < 0 || shell->x() > myCannon->scene()->width() ||
           (!shell->collidesWithItem(myCannon) && !shell->collidingItems().empty());
}

void SimpleShot::updatePosition()
{
    t += (float) updateFrequency / 300;

    shell->setPos(x + t * xSpeed * direction - shift, y - (ySpeed - (g / 2) * t) * t - shift);

    if (needDestroy())
    {
        timer.stop();
        shell->scene()->removeItem(shell);
        shellInScene = false;
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(updatePosition()));
    }
}
