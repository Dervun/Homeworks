#pragma once
#include <QObject>

#include "polinomialhash.h"
#include "hashh37.h"
#include "hashfaq6.h"
#include "hashrot13.h"
#include "hashly.h"

class HashTable : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Конструктор хеш-таблицы
     * \param newSize Размер новой хеш-таблицы
     */
    HashTable(int newSize);
    HashTable();
    int getSize()
    {
        return size;
    }
    double getLoadFactor()
    {
        return loadFactor;
    }
    bool addToTable(const QString &string);
    bool remove(const QString &string);
    bool search(const QString &string);
    int quantityOfConflicts();
    void setHashFunction(HashFunction *newHash);
    int quantityOfFilledNodes();
    int getQuantityOfStrings()
    {
        return quantity;
    }
    int maxLengthOfList();
    void clearTable();
    ~HashTable();
private:
    int size = 103; ///< Размер хеш-таблицы.
    double loadFactor = 0; ///< Среднее количество строк на один список таблицы.
    int quantity = 0; ///< Количество слов в хеш-таблице.
    QList<QString> *table; ///< Сама таблица, состоящая из списков, состоящих из строк.
    HashFunction *hashFunction = new PolinomialHash(); ///< Хэш-функция, работающая в таблице.
signals:
    void needRebuildingTable();
private slots:
    void rebuildTable();
};
