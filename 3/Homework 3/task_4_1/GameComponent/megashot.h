#pragma once
#include "shotmaker.h"

/*!
 * \brief It's ShotMaker that make mega super shot
 */
class MegaShot : public ShotMaker
{
    Q_OBJECT
public:
    MegaShot(QGraphicsItem* cannon);

private:
    void checkCollisionsWithCannons();
    int initialSpeed = 50;
    int shellSize = 40;
    const int radius = 50; ///< the radius of destruction of the enemy by shell
};

