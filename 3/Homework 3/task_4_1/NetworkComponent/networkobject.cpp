#include "networkobject.h"

void NetworkObject::acceptMessage()
{
    QDataStream in(tcpSocket);
    int event;
    in >> event;

    acceptability = false;

    switch (event)
    {
    case shot:
    {
        emit acceptedThatShot();
        break;
    }
    case leftMove:
    {
        emit acceptedThatMovedLeft();
        break;
    }
    case rightMove:
    {
        emit acceptedThatMovedRight();
        break;
    }
    case upRotate:
    {
        emit acceptedThatRotatedUp();
        break;
    }
    case downRotate:
    {
        emit acceptedThatRotatedDown();
        break;
    }
    case turn:
    {
        emit acceptedThatTurned();
        break;
    }
    case changedType:
    {
        emit acceptedThatChangedShotType();
        break;
    }
    case newGame:
    {
        emit acceptedThatNewGame();
        break;
    }
    }
}

void NetworkObject::sessionClosed()
{
    emit disconnectedOtherNetworkObject();
}

void NetworkObject::notifyThatShot()
{
    sendMessage(shot);
}

void NetworkObject::notifyThatMovedLeft()
{
    sendMessage(leftMove);
}

void NetworkObject::notifyThatMovedRight()
{
    sendMessage(rightMove);
}

void NetworkObject::notifyThatRotatedUp()
{
    sendMessage(upRotate);
}

void NetworkObject::notifyThatRotatedDown()
{
    sendMessage(downRotate);
}

void NetworkObject::notifyThatTurned()
{
    sendMessage(turn);
}

void NetworkObject::notifyThatChangedShotType()
{
    sendMessage(changedType);
}

void NetworkObject::notifyThatNewGame()
{
    sendMessage(newGame);
}

void NetworkObject::connectWithGame()
{
    connect(game, SIGNAL(cannonShot()), this, SLOT(notifyThatShot()));
    connect(game, SIGNAL(movedLeft()), this, SLOT(notifyThatMovedLeft()));
    connect(game, SIGNAL(movedRight()), this, SLOT(notifyThatMovedRight()));
    connect(game, SIGNAL(rotatedUp()), this, SLOT(notifyThatRotatedUp()));
    connect(game, SIGNAL(rotatedDown()), this, SLOT(notifyThatRotatedDown()));
    connect(game, SIGNAL(turned()), this, SLOT(notifyThatTurned()));
    connect(game, SIGNAL(changedShotType()), this, SLOT(notifyThatChangedShotType()));
    connect(game, SIGNAL(startedNewGame()), this, SLOT(notifyThatNewGame()));

    connect(this, SIGNAL(acceptedThatShot()), game, SLOT(makeShot()));
    connect(this, SIGNAL(acceptedThatMovedLeft()), game, SLOT(moveLeft()));
    connect(this, SIGNAL(acceptedThatMovedRight()), game, SLOT(moveRight()));
    connect(this, SIGNAL(acceptedThatRotatedUp()), game, SLOT(rotateUp()));
    connect(this, SIGNAL(acceptedThatRotatedDown()), game, SLOT(rotateDown()));
    connect(this, SIGNAL(acceptedThatTurned()), game, SLOT(mirror()));
    connect(this, SIGNAL(acceptedThatChangedShotType()), game, SLOT(changeShotType()));
    connect(this, SIGNAL(acceptedThatNewGame()), game, SLOT(startNewGame()));
}

void NetworkObject::sendMessage(Event event)
{
    if (!acceptability)
    {
        acceptability = true;
        return;
    }

    QByteArray outBuffer;
    QDataStream outStream(&outBuffer, QIODevice::WriteOnly);
    outStream << event;
    tcpSocket->write(outBuffer);
}
