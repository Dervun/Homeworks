#include "messenger.h"
#include <QDataStream>

void Messenger::sendMessage(QTcpSocket *socket, const QString &message)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0 << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    socket->write(block);
}

void Messenger::getMessage(QTcpSocket *socket)
{
    QDataStream in(socket);

    if (blockSize == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }
    if (socket->bytesAvailable() < blockSize)
        return;
    QString message;
    in >> message;
    blockSize = 0;
    emit newMessage(message);
}
