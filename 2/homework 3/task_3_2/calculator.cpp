#include "calculator.h"

void Calculator::recalculate(MainWindow *window)
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
