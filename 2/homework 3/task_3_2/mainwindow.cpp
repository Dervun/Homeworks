#include "mainwindow.h"
#include "ui_calculator.h"
#include "calculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Calculator* calc = new Calculator;
    ui->setupUi(this);
    connect(ui->firstValue, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            calc, Calculator::recalculate(this));
    connect(ui->secondValue, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            calc, Calculator::recalculate(this));
    connect(ui->operation, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            calc, Calculator::recalculate(this));
    delete calc;
}

MainWindow::~MainWindow()
{
    delete ui;
}
