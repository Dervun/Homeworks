#pragma once
#include <QWidget>
#include <QString>

/*!
 * \brief Класс, представляющий окно, которое показывает победителя.
 */
class WinnerWindow : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief Конструктор создаёт окно с данным сообщением о том, кто победил
     * \param message Сообщение о том, кто победил.
     */
    explicit WinnerWindow(const QString &message, QWidget *parent = 0);

private:
    QString message;
};
