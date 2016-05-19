#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lineEdit = new QLineEdit;
    ui->gridLayout->addWidget(lineEdit, 0, 0, 1, 4);
    signalMapper = new QSignalMapper(this);

    QPushButton *button = new QPushButton("0");
    connect(button, SIGNAL(clicked()),
            signalMapper, SLOT(map()));
    signalMapper->setMapping(button, "0");
    ui->gridLayout->addWidget(button, 4, 0, 1, 2);

    for (int i = 0; i < 9; i++)
    {
        button = new QPushButton(QString::number(i + 1));
        connect(button, SIGNAL(clicked()),
                signalMapper, SLOT(map()));
        signalMapper->setMapping(button, QString::number(i + 1));
        ui->gridLayout->addWidget(button, i / 3 + 1, i % 3);
    }

    QChar operators[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; i++)
    {
        button = new QPushButton(operators[i]);
        connect(button, SIGNAL(clicked()),
                signalMapper, SLOT(map()));
        signalMapper->setMapping(button, operators[i]);
        ui->gridLayout->addWidget(button, 4 - i, 3);
    }

    button = new QPushButton("C");
    connect(button, SIGNAL(clicked()),
            this, SLOT(clear()));
    ui->gridLayout->addWidget(button, 5, 3);

    button = new QPushButton(")");
    connect(button, SIGNAL(clicked()),
            signalMapper, SLOT(map()));
    signalMapper->setMapping(button, ")");
    ui->gridLayout->addWidget(button, 5, 2);

    button = new QPushButton("(");
    connect(button, SIGNAL(clicked()),
            signalMapper, SLOT(map()));
    signalMapper->setMapping(button, "(");
    ui->gridLayout->addWidget(button, 5, 1);

    button = new QPushButton("=");
    connect(button, SIGNAL(clicked()),
            this, SLOT(calculate()));
    ui->gridLayout->addWidget(button, 5, 0);

    button = new QPushButton(".");
    connect(button, SIGNAL(clicked()),
            signalMapper, SLOT(map()));
    signalMapper->setMapping(button, ".");
    ui->gridLayout->addWidget(button, 4, 2);

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(clicked(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clicked(const QString &text)
{
    lineEdit->insert(text);
}

void MainWindow::calculate()
{
    QByteArray expression = lineEdit->text().toLocal8Bit();
    QString incorrectExpression("Expression is not correct :(");
    double result = 0;
    try
    {
        result = Calculator::calculate(expression.data());
    }
    catch (LinkedStack<char>::EmptyStackExeption const &)
    {
        lineEdit->setText(incorrectExpression);
        return;
    }
    catch (LinkedStack<double>::EmptyStackExeption const &)
    {
        lineEdit->setText(incorrectExpression);
        return;
    }

    QString outputString;
    lineEdit->setText(outputString.setNum(result, 'g', 6));
}

void MainWindow::clear()
{
    lineEdit->clear();
}
