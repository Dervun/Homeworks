#pragma once

#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

/*!
 * \brief It's interface of various shot makers
 */
class ShotMaker : public QObject
{
    Q_OBJECT
public:
    void makeShot(bool rightSide);
    ~ShotMaker();

signals:
    void enemyDestroyed();

private slots:
    void updatePosition();

protected:
    QGraphicsItem* myCannon;
    QGraphicsPixmapItem* shell;
    QGraphicsPixmapItem* bang;
    int initialSpeed = 70; ///< Initial speed, m/s
    int shellSize = 20; ///< = width = height

private:
    virtual void checkCollisionsWithCannons() = 0;
    bool canShot();
    void updatePatametrs(bool rightSide);
    bool needDestroy();

    QTimer timer;
    bool shellInScene = false;

    const int g = 10; ///< Gravitational acceleration
    int x = 0; ///< Initial horizontal coordinate
    int y = 0; ///< Initial vertical coordinate
    int xSpeed = 0; ///< Initial horizontal speed
    int ySpeed = 0; ///< Initial vertical speed
    float t = 0; ///< Current time of flight of shell
    int direction = 1; ///< 1 for right, -1 for left

    const int updateFrequency = 10; ///< Frequency of update of shell position, ms
    const int shift = 20; ///< For correct display
};
