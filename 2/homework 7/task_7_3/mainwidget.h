#pragma once
#include <QGridLayout>
#include <QWidget>
#include <QString>
#include <QPushButton>

#include "gamefield.h"
#include "choosegamesize.h"


/*!
 * \brief Класс представляет собой окно с игровым полем и соответствующим интерфейсом.
 */
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    /*!
     * \brief XsAndOsButton кнопка для X и O
     */
    class XsAndOsButton : public QPushButton
    {
    public:
        void setX(int value)
        {
            x = value;
        }
        void setY(int value)
        {
            y = value;
        }
        int getX()
        {
            return x;
        }
        int getY()
        {
            return y;
        }
    private:
        int x;
        int y;
    };
    int lengthToWin = 3; ///< По умолчанию длина для победы равна трём
    QGridLayout *layout = nullptr; ///< Компоновщик
    bool isNull = false;
    const int startSize = 3;
    ChooseGameSize *chooseGameSize = nullptr;
    QList<QPushButton *> listOfButtons;
    QPushButton *newGameButton = nullptr;
    QPushButton *changeSizeButton = nullptr;
    GameField *field = nullptr;
    /*!
     * \brief Добавление кнопок
     * \param n Размер поля
     * Добавляет все нужные кнопки.
     * Создаёт поле из размера n * n.
     */
    void addButtons(const int n);

private slots:
    void clicked(QWidget *button);
    void changeSize(const int size, const int length);
    /*!
     * \brief Новая игра
     * Очищает поле, обновляет клетки.
     */
    void newGame();
    /*!
     * \brief Выключает кнопки, выводит massage.
     * \param message Сообщение о победителе.
     */
    void gameEnded(const QString &message);
};
