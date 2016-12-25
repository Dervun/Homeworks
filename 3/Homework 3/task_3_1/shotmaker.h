#pragma once

#include <QObject>
#include <QGraphicsItem>

/*!
 * \brief It's interface of various shot makers
 */
class ShotMaker : public QObject
{
    Q_OBJECT
public:
    virtual void makeShot(bool rightSide) = 0;
};
