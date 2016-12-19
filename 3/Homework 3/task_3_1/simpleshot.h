#pragma once
#include "shotmaker.h"

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>

/*!
 * \brief It's simple implementation of shot maker
 */
class SimpleShot : public ShotMaker
{
    Q_OBJECT
public:
    SimpleShot(QGraphicsItem* cannon);
    ~SimpleShot();
    void makeShot(bool rightSide = true);
private:
    bool canShot();
    void updatePatametrs(bool rightSide);
    bool needDestroy();

    bool shellInScene = false;
    const int g = 10; ///< Gravitational acceleration
    const int initialSpeed = 70; ///< Initial speed, m/s
    int x = 0; ///< Initial horizontal coordinate
    int y = 0; ///< Initial vertical coordinate
    int xSpeed = 0; ///< Initial horizontal speed
    int ySpeed = 0; ///< Initial vertical speed
    float t = 0; ///< Current time of flight of shell
    int direction = 1; ///< 1 for right, -1 for left
    const int updateFrequency = 10; ///< Frequency of update of shell position, ms
    const int shift = 20; ///< For correct display
    const int shellSize = 20; ///< = width = height

    QGraphicsItem* myCannon;
    QGraphicsPixmapItem* shell;
    QTimer timer;


private slots:
    void updatePosition();
};

