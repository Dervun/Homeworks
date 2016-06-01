#pragma once
#include <QMainWindow>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QLineEdit>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
  /*QSpinBox* firstValue;
    QSpinBox* secondValue;
    QLineEdit* result;
    QComboBox* operation;*/
    QHBoxLayout* hlayout;
private slots:
    void recalculate();
};
