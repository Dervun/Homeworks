#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->firstValue, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &Calculator::recalculate);
    connect(ui->secondValue, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &Calculator::recalculate);
    connect(ui->operation, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &Calculator::recalculate);

}

void Calculator::recalculate()
{
    int firstValue = ui->firstValue->value();
    int secondValue = ui->secondValue->value();
    char operation = ui->operation->currentText().at(0).unicode();
    double result = 0;
    switch (operation)
    {
    case '+':
    {
        result = firstValue + secondValue;
        break;
    }
    case '-':
    {
        result = firstValue - secondValue;
        break;
    }
    case '*':
    {
        result = firstValue * secondValue;
        break;
    }
    case '/':
    {
        if (secondValue != 0)
            result = (double) firstValue / secondValue;
        break;
    }
    }
    ui->result->setText(QString::number(result, 'g', 6));
}

Calculator::~Calculator()
{
    delete ui;
}
