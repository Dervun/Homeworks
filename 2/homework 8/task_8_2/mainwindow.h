#pragma once
#include <QMainWindow>
#include <QString>

#include "bash.h"

namespace Ui
{
    class MainWindow;
}

/*!
 * \brief Класс, который предоставляет возможность взаимодействовать с bash.im
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Bash bash;
    QString currentQuote;
    QString currentNumberOfQuote;
    /*!
     * \brief Включаем / выключаем все кнопки.
     * \param state Состояние кнопок. truu - будут включены, false - выключены.
     */
    void setEnabledButtons(bool state);
    void setRateButtonsDisabled();
    /*!
     * \brief Заполнение окна информацией
     * \param quote Цитата
     */
    void fillContent(QString quote);
    void refreshCurrentNumberOfQuote(const QString &string);
    void refreshCurrentQuote(const QString &string);

private slots:
    void rateUp();
    void rateDown();
    void bayan();
    /*!
     * \brief Переключение на предыдущую цитату
     */
    void nextQuote();
    /*!
     * \brief Переключение на предыдущую цитату
     */
    void previosQuote();
    /*!
     * \brief Обновление цитат
     */
    void refresh();
    /*!
     * \brief Сохранение цитаты
     */
    void saveQuote();
};
