#include "simpleshot.h"

SimpleShot::SimpleShot(QGraphicsItem* cannon)
{
    myCannon = cannon;
    QPixmap newShell;
    newShell.convertFromImage(QImage(":/new/prefix1/images/shell.png").scaled(shellSize, shellSize));
    shell = new QGraphicsPixmapItem(newShell);
}

void SimpleShot::checkCollisionsWithCannons()
{
    QList<QGraphicsItem*> collidingItems(shell->collidingItems());
    for (QGraphicsItem* currentItem : collidingItems)
    {
        if (currentItem != myCannon && currentItem->data(0).toString() == "Cannon")
        {
            emit enemyDestroyed();
            break;
        }
    }
}
