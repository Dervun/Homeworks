#pragma once
#include <QObject>
#include <QString>
/*!
 * \brief Класс, в котором реализуются правила игры.
 */
class GameField : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Создание игрового поля с заданными размером и длиной.
     * \param size Размер игрового поля.
     * \param winLength Длина игрового поля.
     */
    explicit GameField(const int size, const int lengthToWin, QObject *parent = 0);
    ~GameField();
    /*!
     * \brief Изменяет ячейку по заданным координатам
     * \param x Координата по x
     * \param y Координата по y
     */
    void cellChanged(int x, int y, bool isNull);
    /*!
     * \brief Полная очистка поля.
     */
    void clear();

signals:
    /*!
     * \brief Отправляет сигнал с сообщением того, кто победил
     * \param message Сообщение.
     */
    void winner(const QString &message);

private:
    /*!
     * \brief Ячейка поля
     */
    enum Cell
    {
        X, ///< Крестик
        O, ///< Нолик
        empty ///< Пусто
    };

    Cell **field = nullptr; ///< Само поле, состоящее из ячеек.
    int lengthToWin; ///< Длина, нужная для победы в игре.
    int size; ///< Размер игрового поля.
    int numberOfClickedButtons = 0; ///< Количество нажатых кнопок.

    /*!
     * \brief Проверка количества ячеек с нужным состоянием по горизонтали
     * \param currentState Состояние
     * \param x Координата ячейки по x
     * \param y Координата ячейки по y
     * \return Количество стоящих на горизонтали подряд ячеек с нужным нам состоянием, одна из которых - наша текущая ячейка с координатами x, y.
     */
    int checkHorizontal(Cell currentState, int x, int y);
    /*!
     * \brief Проверка количества ячеек с нужным состоянием по вертикали
     * \param currentState Состояние
     * \param x Координата ячейки по x
     * \param y Координата ячейки по y
     * \return Количество стоящих на вертикали подряд ячеек с нужным нам состоянием, одна из которых - наша текущая ячейка с координатами x, y.
     */
    int checkVertical(Cell currentState, int x, int y);
    /*!
     * \brief Проверка количества ячеек с нужным состоянием на главной диагонали
     * \param currentState Состояние
     * \param x Координата ячейки по x
     * \param y Координата ячейки по y
     * \return Количество стоящих на главной диагонали подряд ячеек с нужным нам состоянием, одна из которых - наша текущая ячейка с координатами x, y.
     */
    int checkMainDiagonal(Cell currentState, int x, int y);
    /*!
     * \brief Проверка количества ячеек с нужным состоянием на побочной диагонали
     * \param currentState Состояние
     * \param x Координата ячейки по x
     * \param y Координата ячейки по y
     * \return Количество стоящих на побочной диагонали подряд ячеек с нужным нам состоянием, одна из которых - наша текущая ячейка с координатами x, y.
     */
    int checkMinorDiagonal(Cell currentState, int x, int y);
};
