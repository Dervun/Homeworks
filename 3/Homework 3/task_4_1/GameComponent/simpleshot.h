#pragma once
#include "shotmaker.h"

/*!
 * \brief It's simple implementation of shot maker
 */
class SimpleShot : public ShotMaker
{
    Q_OBJECT
public:
    SimpleShot(QGraphicsItem* cannon);

private:
    void checkCollisionsWithCannons();
    QGraphicsPixmapItem* bang;
};

