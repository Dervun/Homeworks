#pragma once

#include <QMainWindow>

#include "server.h"

namespace Ui
{
    class MainWindow;
}
/*!
 * \brief Класс, представляющий диалоговое окно сервера.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Server *server;
    /*!
     * \return IP и порт в формате "IP:port"
     */
    QString getClientHost();
    /*!
     * \brief Добавление сообщения в окно, где ведётся диалог
     */
    void addMessage(const QString &sender, const QString &message);

private slots:
    void sendMessage();
    void getMessage(QString message);
    /*!
     * \brief Вызывается, когда клиент подключился
     */
    void newClient();
    void clientDisconnected();
};
