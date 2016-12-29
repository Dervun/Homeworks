#include "megashot.h"

#include <QGraphicsScene>

MegaShot::MegaShot(QGraphicsItem* cannon)
{
    myCannon = cannon;
    QPixmap newShell;
    newShell.convertFromImage(QImage(":/new/prefix1/images/mega_shell.png").scaled(shellSize, shellSize));
    shell = new QGraphicsPixmapItem(newShell);

    QPixmap newBang;
    newBang.convertFromImage(QImage(":/new/prefix1/images/bang.png").scaled(radius * 2, radius * 2));
    bang = new QGraphicsPixmapItem(newBang);
    bang->setData(0, "Bang");
}

void MegaShot::checkCollisionsWithCannons()
{
    QRect rect(shell->pos().x() - radius, shell->pos().y() - radius, radius * 4, radius * 4);
    QList<QGraphicsItem*> itemsInRect(shell->scene()->items(rect));

    for (QGraphicsItem* currentItem : itemsInRect)
    {
        if (currentItem != myCannon && currentItem->data(0).toString() == "Cannon")
        {
            bang->setX(shell->x() - radius * 2);
            bang->setY(shell->y() - radius * 2);
            shell->scene()->addItem(bang);
            emit enemyDestroyed();
            break;
        }
    }
}
