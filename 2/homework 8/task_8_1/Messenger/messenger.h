#pragma once
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QNetworkInterface>
#include <QString>

/*!
 * \brief Класс, представляющий собой интерфейс для обмена сообщениями
 */
class Messenger : public QObject
{
    Q_OBJECT
public:
    explicit Messenger(QObject *parent = 0) : QObject(parent) {}
    void sendMessage(QTcpSocket *socket, const QString &message);

signals:
    /*!
     * \brief Испускается, когда все данные получены
     */
    void newMessage(const QString message);

public slots:
    void getMessage(QTcpSocket *socket);

private:
    quint16 blockSize = 0;
};
