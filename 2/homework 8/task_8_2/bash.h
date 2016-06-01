#pragma once
#include <QObject>
#include <QWebFrame>
#include <QWebElement>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QtNetwork>
#include <QWebPage>
#include <QList>

/*!
 * \brief Класс, представляющий собой интерфейс, позволяющий работать с сайтом bash.im
 */
class Bash : public QObject
{
    Q_OBJECT
public:
    Bash();
    ~Bash();

    /*!
     * \brief Получение следующей цитаты
     * \return Цитата
     */
    QString getNextQuote();
    /*!
     * \brief Получение предыдущей цитаты
     * \return Цитата
     */
    QString getPreviosQuote();
    int getCurrentRating();
    /*!
     * \brief Запрос на поднятие рейтинга.
     */
    void rateUp();
    /*!
     * \brief Запрос на понижение рейтинга.
     */
    void rateDown();
    /*!
     * \brief Запрос поставить посту "баян"
     */
    void bayan();
    /*!
     * \brief Получить Id
     * \return id текущей цитаты
     */
    QString getId();
    /*!
     * \brief Перезагружает страницу и обновляет цитаты.
     */
    void refreshQuotes();

signals:
    void quotesLoaded();

private slots:
    void loadQuotes();

private:
    QWebPage *page = nullptr;
    QList<QWebElement> quotes; ///< Список цитат.
    int quoteNumber = -1;
};
