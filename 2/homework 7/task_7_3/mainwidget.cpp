#include <QSignalMapper>

#include "winnerwindow.h"
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);
    chooseGameSize = new ChooseGameSize();
    addButtons(startSize);
    layout->setSizeConstraint(QLayout::SetFixedSize);
}

MainWidget::~MainWidget()
{
    delete chooseGameSize;
}

void MainWidget::addButtons(const int n)
{
    field = new GameField(n, lengthToWin);
    connect(field, &GameField::winner,
            this, &MainWidget::gameEnded);  /// Завершает игру, когда выбран победитель.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            XsAndOsButton *button = new XsAndOsButton();
            layout->addWidget(button, 2 * i, 2 * j, 1, 1);
            button->setMinimumSize(65, 65);
            button->setMaximumSize(65, 65);
            button->setX(i);
            button->setY(j);
        }
    listOfButtons = this->findChildren<QPushButton *>();
    QSignalMapper *buttonsMapper = new QSignalMapper(this);
    for (int i = 0; i < listOfButtons.size(); i++)
    {
        QPushButton *button = listOfButtons[i];
        connect(button, &QPushButton::clicked,
                buttonsMapper, static_cast<void(QSignalMapper::*)()>(&QSignalMapper::map));
        buttonsMapper->setMapping(button, button);
    }
    connect(buttonsMapper, static_cast<void(QSignalMapper::*)(QWidget *)>(&QSignalMapper::mapped),
            this, &MainWidget::clicked);

    newGameButton = new QPushButton("New game!");
    changeSizeButton = new QPushButton("Change size");
    connect(changeSizeButton, &QPushButton::clicked,
            chooseGameSize, &ChooseGameSize::chooseSize);
    connect(chooseGameSize, &ChooseGameSize::changeSize,
            this, &MainWidget::changeSize);
    connect(newGameButton, &QPushButton::clicked,
            this, &MainWidget::newGame);
    layout->addWidget(changeSizeButton, n * 2, n, 2, n);
    layout->addWidget(newGameButton,  n * 2, 0, 2, n);
}


void MainWidget::clicked(QWidget *button)
{
    XsAndOsButton *xsAnsOsButton = static_cast<XsAndOsButton *>(button);
    field->cellChanged(xsAnsOsButton->getX(), xsAnsOsButton->getY(), isNull);
    if (!isNull)
    {
         xsAnsOsButton->setText("X");
         isNull = true;
    }
    else
    {
        xsAnsOsButton->setText("O");
        isNull = false;
    }
    xsAnsOsButton->setEnabled(false);
}

void MainWidget::changeSize(const int size, const int length)
{
    for (auto i : listOfButtons)
        delete i;
    delete changeSizeButton;
    delete newGameButton;
    delete field;
    lengthToWin = length;
    addButtons(size);
}

void MainWidget::newGame()
{
    field->clear();
    for (auto i : listOfButtons)
    {
        i->setEnabled(true);
        i->setText("");
    }
    isNull = false;
}

void MainWidget::gameEnded(const QString &message)
{
    WinnerWindow *winnerWindow = new WinnerWindow(message);
    for (auto i : listOfButtons)
        i->setEnabled(false);
    winnerWindow->show();
}
