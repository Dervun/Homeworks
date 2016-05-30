#pragma once

#include <QMainWindow>

#include "client.h"

namespace Ui
{
    class MainWindow;
}
/*!
 * \brief Класс, представляющий диалоговое окно клиента.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Client *client;
    /*!
     * \return IP и порт в формате "IP:port"
     */
    QString getServerHost();
    /*!
     * \brief Добавление сообщения в окно, где ведётся диалог
     */
    void addMessage(const QString &sender, const QString &message);

private slots:
    /*!
     * \brief Попытка соединиться с сервером
     */
    void connectToServer();
    /*!
     * \brief Отправляет сообщение по запросу пользователя
     */
    void sendMessage();
    /*!
     * \brief Получает и выводит на экран сообщение от сервера.
     */
    void getMessage(const QString message);
    void successfulConnection();
    void serverDisconnected();
};
