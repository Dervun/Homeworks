#pragma once
#include <QWidget>
#include <QComboBox>

/*!
 * \brief Класс, представляющий окно, в котором пользователь может выбрать размер игрового поля и длину выигрышной цепи.
 */
class ChooseGameSize : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseGameSize(QWidget *parent = 0);

signals:
    /*!
     * \brief Испускает сигнал о новых размере поля и длины для выигрыша.
     * \param size Новый размер поля.
     * \param winLength Новая длина для выигрыша.
     */
    void changeSize(const int size, const int lengthToWin);

public slots:
    /*!
     * \brief Создаёт окно для выбора размера поля и длины выигрыша (выводит на экран).
     */
    void chooseSize();

private slots:
    void okButtonClicked();
    void changeLengthToWinComboBox();

private:
    QComboBox *size;
    QComboBox *lengthToWin;
};
