#include "simpleshot.h"

#include <QGraphicsScene>

SimpleShot::SimpleShot(QGraphicsItem* cannon)
{
    myCannon = cannon;
    QPixmap newShell;
    newShell.convertFromImage(QImage(":/new/prefix1/images/shell.png").scaled(shellSize, shellSize));
    shell = new QGraphicsPixmapItem(newShell);

    QPixmap newBang;
    newBang.convertFromImage(QImage(":/new/prefix1/images/bang.png").scaled(60, 60));
    bang = new QGraphicsPixmapItem(newBang);
    bang->setData(0, "Bang");
}

void SimpleShot::checkCollisionsWithCannons()
{
    QList<QGraphicsItem*> collidingItems(shell->collidingItems());
    for (QGraphicsItem* currentItem : collidingItems)
    {
        if (currentItem != myCannon && currentItem->data(0).toString() == "Cannon")
        {
            bang->setX(shell->x() - 30);
            bang->setY(shell->y() - 30);
            shell->scene()->addItem(bang);
            emit enemyDestroyed();
            break;
        }
    }
}
