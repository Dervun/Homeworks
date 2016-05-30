#pragma once
#include <QObject>
#include <QList>

#include "../Messenger/messenger.h"

/*!
 * \brief Класс, представляющий собой клиента, который связывается и взаимодействует с сервером.
 */
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    ~Client();
    QString getServerIp();
    quint16 getServerPort();
    bool isConnected();

signals:
    /*!
     * \brief Испускается, когда получено новое сообщение от сервера
     */
    void newMessage(const QString message);
    void serverDisconnected();
    void connected();

public slots:
    void connectToServer(const QString &ip, quint16 port) throw(QString);
    void sendMessage(const QString &message) throw (QString);

private:
    QTcpSocket *serverSocket = nullptr;
    Messenger *messenger = nullptr;

private slots:
    void deleteSocket();
    void getMessage() throw(QString);
};
