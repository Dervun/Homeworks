#include <QHBoxLayout>
#include <QString>
#include <QPushButton>
#include <QLabel>

#include "winnerwindow.h"

WinnerWindow::WinnerWindow(const QString &message, QWidget *parent) : QWidget(parent), message(message)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    auto okButton = new QPushButton("OK");
    auto label = new QLabel(message);
    layout->addWidget(label);
    layout->addWidget(okButton);
    connect(okButton, &QPushButton::clicked, /// При нажатии на кнопку "OK" окно закроется.
            this, &WinnerWindow::close);
}
