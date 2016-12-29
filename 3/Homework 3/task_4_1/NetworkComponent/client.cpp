#include "client.h"

Client::Client(Game* currentGame)
{
    game = currentGame;
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(sessionOpened()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(sessionClosed()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(acceptMessage()));
    connectWithGame();
}

Client::~Client()
{
    delete tcpSocket;
}

void Client::connectToServer(int port)
{
    tcpSocket->connectToHost("localhost", port);
}

void Client::sessionOpened()
{
    emit connectedOtherNetworkObject();
}
