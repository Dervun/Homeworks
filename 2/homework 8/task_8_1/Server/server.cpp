#include "server.h"

Server::Server(QObject *parent) throw (QString): QObject(parent)
{
    server = new QTcpServer(this);
    QList<QHostAddress> adresses = QNetworkInterface::allAddresses();
    for (auto adress : adresses)
    {
        if (adress.protocol() == QAbstractSocket::IPv4Protocol)
            if (tryToListen(adress))
                break;
    }
    if (!server->isListening())
        throw QString("Server is not listening");
    messenger = new Messenger();
    connect(messenger, &Messenger::newMessage,
            this, &Server::newMessage);
}

Server::~Server()
{
    delete messenger;
    delete server;
    delete clientSocket;
}

QString Server::getMyIp()
{
    return server->serverAddress().toString();
}

quint16 Server::getMyPort()
{
    return server->serverPort();
}

QString Server::getClientIp()
{
    if (!isConnected())
        return "";
    return clientSocket->peerAddress().toString();
}

quint16 Server::getClientPort()
{
    if (!isConnected())
        return 0;
    return clientSocket->peerPort();
}

bool Server::isConnected()
{
    return clientSocket != nullptr;
}

void Server::sendMessage(const QString message) throw(QString)
{
    if (!isConnected())
        throw QString("Client is not connected :(");
    messenger->sendMessage(clientSocket, message);
}

bool Server::tryToListen(const QHostAddress &address)
{
    if (!server->listen(address))
        return false;
    connect(server, &QTcpServer::newConnection,
            this, &Server::newConnection);
    return true;
}

void Server::newConnection()
{
    if (!server->hasPendingConnections())
        return;
    clientSocket = server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead,
            this, &Server::getMessage);
    connect(clientSocket, &QTcpSocket::disconnected,
            this, &Server::clientDisconnected);
    connect(clientSocket, &QTcpSocket::disconnected,
            clientSocket, &QTcpSocket::deleteLater);
    connect(clientSocket, &QTcpSocket::destroyed,
            this, &Server::deleteClient);
    emit newClient();
}

void Server::getMessage() throw(QString)
{
    if (!isConnected())
        throw QString("Client is not connected :(");
    messenger->getMessage(clientSocket);
}

void Server::deleteClient()
{
    clientSocket = nullptr;
}
