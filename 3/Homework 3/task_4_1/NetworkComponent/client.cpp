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

void Client::connectToServer()
{
    QFile port("port");
    port.open(QIODevice::ReadWrite | QIODevice::Text);
    QByteArray data = port.readAll();
    port.remove();
    tcpSocket->connectToHost("localhost", data.toInt());
}

void Client::sessionOpened()
{
    emit connectedOtherNetworkObject();
}
