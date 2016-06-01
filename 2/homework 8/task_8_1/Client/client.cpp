#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    messenger = new Messenger();
    connect(messenger, &Messenger::newMessage,
            this, &Client::newMessage);
}

Client::~Client()
{
    delete serverSocket;
    delete messenger;
}

QString Client::getServerIp()
{
    if (!isConnected())
        return "";
    return serverSocket->peerAddress().toString();
}

quint16 Client::getServerPort()
{
    if (!isConnected())
            return 0;
    return serverSocket->peerPort();
}

bool Client::isConnected()
{
    return serverSocket != nullptr;
}

void Client::connectToServer(const QString &ip, quint16 port) throw(QString)
{
    if (isConnected())
        serverSocket->disconnectFromHost();
    serverSocket = new QTcpSocket();
    serverSocket->connectToHost(QHostAddress(ip), port);
    if (!serverSocket->waitForConnected())
        throw QString("Can not connect to the server :(");
    connect(serverSocket, &QTcpSocket::readyRead,
            this, &Client::getMessage);
    connect(serverSocket, &QTcpSocket::disconnected,
            this, &Client::serverDisconnected);
    connect(serverSocket, &QTcpSocket::disconnected,
            serverSocket, &QTcpSocket::deleteLater);
    connect(serverSocket, &QTcpSocket::destroyed,
            this, &Client::deleteSocket);
}

void Client::sendMessage(const QString &message) throw(QString)
{
    if (!isConnected())
        throw QString("You are not connected to server");
    messenger->sendMessage(serverSocket, message);
}

void Client::deleteSocket()
{
    serverSocket = nullptr;
}

void Client::getMessage() throw(QString)
{
    if (!isConnected())
        throw QString("You are not connected to server");
    messenger->getMessage(serverSocket);
}
