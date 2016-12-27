#include "server.h"

Server::Server(Game *currentGame)
{
    game = currentGame;

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));
        networkSession->open();
    }
    else
        sessionOpened();
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(connectToClient()));

    connectWithGame();
}

Server::~Server()
{
    if (networkSession != nullptr)
        delete networkSession;
    if (tcpServer != nullptr)
        delete tcpServer;
}

void Server::connectToClient()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(acceptMessage()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(sessionClosed()));
    emit connectedOtherNetworkObject();
}

void Server::sessionOpened()
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen();

    QFile port("port");
    port.open(QIODevice::WriteOnly);
    port.write(QString::number(tcpServer->serverPort()).toLocal8Bit().data());
    port.close();
}
