#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");

    ui->operation->addItem("+");
    ui->operation->addItem("-");
    ui->operation->addItem("*");
    ui->operation->addItem("/");

    connect(ui->firstValue, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &MainWindow::recalculate);
    connect(ui->secondValue, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &MainWindow::recalculate);
    connect(ui->operation, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::recalculate);
}

void MainWindow::recalculate()
{
    double result = Calculator::recalculate(ui->firstValue->value(), ui->secondValue->value(), ui->operation->currentText().at(0).unicode());
    ui->result->setText(QString::number(result, 'g', 6));
}

MainWindow::~MainWindow()
{
    delete ui;
}
