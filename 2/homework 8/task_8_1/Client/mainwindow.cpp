#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Client");
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    ui->ipLineEdit->setText("127.0.0.1");
    client = new Client();

    connect(ui->connectButton, &QPushButton::clicked,
            this, &MainWindow::connectToServer);
    connect(ui->sendButton, &QPushButton::clicked,
            this, &MainWindow::sendMessage);
    connect(ui->messageLineEdit, &QLineEdit::returnPressed,
            this, &MainWindow::sendMessage);

    connect(client, &Client::newMessage,
            this, &MainWindow::getMessage);
    connect(client, &Client::connected,
            this, &MainWindow::successfulConnection);
    connect(client, &Client::serverDisconnected,
            this, &MainWindow::serverDisconnected);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete client;
}

QString MainWindow::getServerHost()
{
    return client->getServerIp() + ":" + QString::number(client->getServerPort());
}

void MainWindow::addMessage(const QString &sender, const QString &message)
{
    ui->chatTextEdit->append(sender + ":");
    ui->chatTextEdit->append(message + "\n");
}

void MainWindow::connectToServer()
{
    this->setCursor(QCursor(Qt::CursorShape::WaitCursor));
    try
    {
        client->connectToServer(ui->ipLineEdit->text(), ui->portLineEdit->text().toInt());
        successfulConnection();
    }
    catch (QString &message)
    {
        ui->chatTextEdit->append(message);
    }
    this->setCursor(QCursor());
}

void MainWindow::sendMessage()
{
    QString message = ui->messageLineEdit->text();
    if (message == "")
        return;
    try
    {
        client->sendMessage(message);
        ui->messageLineEdit->clear();
        addMessage("You", message);
    }
    catch (QString &message)
    {
        ui->chatTextEdit->append(message);
    }
}

void MainWindow::getMessage(QString message)
{
    addMessage("Server (" + getServerHost() + ")", message);
}

void MainWindow::successfulConnection()
{
    ui->chatTextEdit->append("Connected to server " + getServerHost() + " :)\n");
}

void MainWindow::serverDisconnected()
{
    ui->chatTextEdit->append("Connection with server was lost :(");
}
