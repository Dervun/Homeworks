#include "bash.h"

Bash::Bash()
{
    page = new QWebPage();
    page->mainFrame()->load(QUrl("http://bash.im/"));
    connect(page, &QWebPage::loadFinished,            /// По окончании загрузки страницы стартует загрузка цитат.
            this, &Bash::loadQuotes);
}

Bash::~Bash()
{
    delete page;
}

QString Bash::getNextQuote()
{
    QString result;
    while (result.isEmpty() || getCurrentRating() == 0)
    {
        quoteNumber++;
        if (quoteNumber == quotes.size())
            quoteNumber = 0;
        result = quotes[quoteNumber].findFirst("div[class=text]").toPlainText();
    }
    return result;
}

QString Bash::getPreviosQuote()
{
    QString result;
    while (result.isEmpty() || getCurrentRating() == 0)
    {
        quoteNumber--;
        if (quoteNumber < 0)
            quoteNumber = quotes.size() - 1;
        result = quotes[quoteNumber].findFirst("div[class=text]").toPlainText();
    }
    return result;
}

int Bash::getCurrentRating()
{
    return quotes[quoteNumber].findFirst("span[class=rating-o]").toPlainText().toInt();
}

void Bash::loadQuotes()
{
    if (quoteNumber == -1)
    {
        quotes = page->mainFrame()->findAllElements("div[class=quote]").toList();  /// Находим цитаты, помещаем их в список
        emit quotesLoaded();
    }
}

void Bash::rateUp()
{
    QString quoteAdress = quotes[quoteNumber].findFirst("a[class=up]").attribute("href");
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("http://bash.im" + quoteAdress)));
}

void Bash::rateDown()
{
    QString quoteAdress = quotes[quoteNumber].findFirst("a[class=down]").attribute("href");
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("http://bash.im" + quoteAdress)));
}

void Bash::bayan()
{
    QString quoteAdress = quotes[quoteNumber].findFirst("a[class=old]").attribute("href");
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("http://bash.im" + quoteAdress)));
}

QString Bash::getId()
{
    return quotes[quoteNumber].findFirst("a[class=id]").toPlainText();;
}

void Bash::refreshQuotes()
{
    quoteNumber = -1;
    page->mainFrame()->load(QUrl("http://bash.im/"));
}
