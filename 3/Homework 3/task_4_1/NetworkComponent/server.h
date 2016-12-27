#pragma once

#include "networkobject.h"

/*!
 * \brief The Server class for connecting players in Game
 */
class Server : public NetworkObject
{
    Q_OBJECT

public:
    Server(Game* currentGame);
    ~Server();

private slots:
    void connectToClient();
    void sessionOpened();

private:
    QTcpServer* tcpServer = nullptr;
    QNetworkSession* networkSession = nullptr;
};
