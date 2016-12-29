#pragma once

#include "./GameComponent/game.h"

#include <QObject>
#include <QtNetwork>

enum Event {
    shot,
    leftMove,
    rightMove,
    upRotate,
    downRotate,
    turn,
    changedType,
    newGame
};

/*!
 * \brief The NetworkObject class for connecting players in Game
 */
class NetworkObject : public QObject
{
    Q_OBJECT

signals:
    void connectedOtherNetworkObject();
    void disconnectedOtherNetworkObject();

    void acceptedThatShot();
    void acceptedThatMovedLeft();
    void acceptedThatMovedRight();
    void acceptedThatRotatedUp();
    void acceptedThatRotatedDown();
    void acceptedThatTurned();
    void acceptedThatChangedShotType();
    void acceptedThatNewGame();

protected slots:
    void acceptMessage();
    void sessionClosed();

private slots:
    void notifyThatShot();
    void notifyThatMovedLeft();
    void notifyThatMovedRight();
    void notifyThatRotatedUp();
    void notifyThatRotatedDown();
    void notifyThatTurned();
    void notifyThatChangedShotType();
    void notifyThatNewGame();


protected:
    void connectWithGame();

    QTcpSocket *tcpSocket = new QTcpSocket(this);
    Game* game = nullptr;

private:
    void sendMessage(Event event);
    bool acceptability = true;
};
