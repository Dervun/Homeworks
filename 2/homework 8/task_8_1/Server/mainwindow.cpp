#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Server");
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    server = new Server();
    ui->ipLineEdit->setText(server->getMyIp());
    ui->portLineEdit->setText(QString::number(server->getMyPort()));

    connect(ui->sendButton, &QPushButton::clicked,
            this, &MainWindow::sendMessage);
    connect(ui->messageLineEdit, &QLineEdit::returnPressed,
            this, &MainWindow::sendMessage);

    connect(server, &Server::newClient,
            this, &MainWindow::newClient);
    connect(server, &Server::newMessage,
            this, &MainWindow::getMessage);
    connect(server, &Server::clientDisconnected,
            this, &MainWindow::clientDisconnected);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete server;
}

QString MainWindow::getClientHost()
{
    return server->getClientIp() + ":" + QString::number(server->getClientPort());
}

void MainWindow::addMessage(const QString &sender, const QString &message)
{
    ui->chatTextEdit->append(sender + ":");
    ui->chatTextEdit->append(message + "\n");
}

void MainWindow::sendMessage()
{
    QString message = ui->messageLineEdit->text();
    if (message == "")
        return;
    try
    {
        server->sendMessage(message);
        ui->messageLineEdit->clear();
        addMessage("You", message);
    }
    catch (QString &message)
    {
        ui->chatTextEdit->append(message + '\n');
    }
}

void MainWindow::getMessage(QString message)
{
    addMessage("Client (" + getClientHost() + ")", message);
}

void MainWindow::newClient()
{
    ui->chatTextEdit->append("New client: " + getClientHost() + " :)\n");
}

void MainWindow::clientDisconnected()
{
    ui->chatTextEdit->append("Connection with client was lost :(\n");
}
