#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <QLabel>

#include "choosegamesize.h"

ChooseGameSize::ChooseGameSize(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout(this);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    auto okButton = new QPushButton("OK");
    size = new QComboBox();
    for (int i = 3; i < 15; i++)
        size->addItem(QString::number(i));
    lengthToWin = new QComboBox();
    for (int i = 3; i < 6; i++)
        lengthToWin->addItem(QString::number(i));
    connect(size, &QComboBox::currentTextChanged,
            this, &ChooseGameSize::changeLengthToWinComboBox);
    QLabel *sizeLabel = new QLabel("Select size:");
    QLabel *lengthToWinLabel = new QLabel("Select winning length:");
    layout->addWidget(sizeLabel, 0, 0);
    layout->addWidget(lengthToWinLabel, 1, 0);
    layout->addWidget(size, 0, 1);
    layout->addWidget(lengthToWin, 1, 1);
    layout->addWidget(okButton, 2, 0, 1, 2);
    okButton->setMaximumSize(300, 50);
    connect(okButton, &QPushButton::clicked,        /// При нажатии на кнопку "OK" обновятся данные и закроется окно.
            this, &ChooseGameSize::okButtonClicked);
}

void ChooseGameSize::chooseSize()
{
    this->show();
}

void ChooseGameSize::okButtonClicked()
{
    emit changeSize(size->currentText().toInt(), lengthToWin->currentText().toInt());
    this->close();
}

void ChooseGameSize::changeLengthToWinComboBox()
{
    lengthToWin->clear();
    for (int i = 2; i < size->currentText().toInt() + 1; i++)
    {
        lengthToWin->addItem(QString::number(i));
    }
}
