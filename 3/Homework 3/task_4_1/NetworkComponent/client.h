#pragma once

#include "networkobject.h"

/*!
 * \brief The Client class for connecting players in Game
 */
class Client : public NetworkObject
{
    Q_OBJECT

public:
    Client(Game* currentGame);
    ~Client();

private slots:
    void connectToServer();
    void sessionOpened();
};
