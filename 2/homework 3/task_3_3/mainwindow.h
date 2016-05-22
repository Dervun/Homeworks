#pragma once
#include <QSignalMapper>
#include <QLineEdit>
#include <QMainWindow>

#include "calculator.h"

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
    QSignalMapper *signalMapper;
    QLineEdit *lineEdit;

private slots:
    /*!
     * \brief Нажатие
     * \param text Текст кнопки.
     * Вызывается при нажатии любой кнопки, кроме C и =. Вставляет текст, написанный на кнопке в поле ввода.
     */
    void clicked(const QString &text);
    /*!
     * \brief Счёт
     * Слот вызывается при нажатии на кнопку =, считает выражение, выводит на экран.
     */
    void calculate();
    /*!
     * \brief Очистка экрана
     * Слот вызывается при нажатии кнопки C. Очищает экран.
     */
    void clear();
};

