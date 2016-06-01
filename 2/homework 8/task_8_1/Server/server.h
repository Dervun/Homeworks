#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QNetworkInterface>
#include <QAbstractSocket>
#include <QString>
#include <QList>

#include "../Messenger/messenger.h"

/*!
 * \brief Класс, представляющий собой сервер, общающийся с клиентом.
 */
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0) throw(QString);
    ~Server();

    QString getMyIp();
    quint16 getMyPort();
    QString getClientIp();
    quint16 getClientPort();
    bool isConnected();

signals:
    /*!
     * \brief Испускается, когда получено новое сообщение
     */
    void newMessage(const QString message);
    void newClient();
    void clientDisconnected();

public slots:
    void sendMessage(const QString message) throw(QString);

private:
    QTcpServer *server = nullptr;
    QTcpSocket *clientSocket = nullptr;
    Messenger *messenger = nullptr;
    /*!
     * \return Если сервер не может прослушивать входящий адрес, возвращает false, иначе начинает прослушивание.
     */
    bool tryToListen(const QHostAddress &address);

private slots:
    /*!
     * \brief Вызывается, когда клиент подключился.
     */
    void newConnection();
    void getMessage() throw(QString);
    void deleteClient();
};
