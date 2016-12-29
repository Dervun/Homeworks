#include "megashot.h"

#include <QGraphicsScene>

MegaShot::MegaShot(QGraphicsItem* cannon)
{
    myCannon = cannon;
    QPixmap newShell;
    newShell.convertFromImage(QImage(":/new/prefix1/images/mega_shell.png").scaled(shellSize, shellSize));
    shell = new QGraphicsPixmapItem(newShell);
}

void MegaShot::checkCollisionsWithCannons()
{
    QRect rect(shell->pos().x() - radius, shell->pos().y() - radius, radius * 2, radius * 2);
    QList<QGraphicsItem*> itemsInRect(shell->scene()->items(rect));

    for (QGraphicsItem* currentItem : itemsInRect)
    {
        if (currentItem != myCannon && currentItem->data(0).toString() == "Cannon")
        {
            emit enemyDestroyed();
            break;
        }
    }
}
