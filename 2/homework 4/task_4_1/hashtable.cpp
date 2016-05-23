#include <algorithm>

#include "hashtable.h"
using namespace std;

HashTable::HashTable(int newSize)
{
    size = newSize;
    table = new QList<QString>[size];
    connect(this, SIGNAL(needRebuildingTable()),
            this, SLOT(rebuildTable()));
}

HashTable::HashTable()
{
    table = new QList<QString>[size];
    connect(this, SIGNAL(needRebuildingTable()),
            this, SLOT(rebuildTable()));
}

bool HashTable::addToTable(const QString &string)
{
    int index = hashFunction->hash(string, size);
    if (table[index].contains(string))
        return false;
    table[index] << string;
    quantity++;
    loadFactor = (double) quantity / size;
    if (loadFactor > 3)
        emit needRebuildingTable();
    return true;
}

bool HashTable::remove(const QString &string)
{
    int index = hashFunction->hash(string, size);
    if (table[index].removeOne(string))
    {
        quantity--;
        loadFactor = (double) quantity / size;
        return true;
    }
    return false;
}

bool HashTable::search(const QString &string)
{
    int index = hashFunction->hash(string, size);
    return table[index].contains(string);
}

int HashTable::quantityOfConflicts()
{
    int quantity = 0;
    for (int i = 0; i < size; i++)
        if (table[i].size() > 1)
            quantity++;
    return quantity;
}

void HashTable::setHashFunction(HashFunction *newHash)
{
    QList<QString> *oldTable = table;
    table = new QList<QString>[size];
    delete hashFunction;
    hashFunction = newHash;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < oldTable[i].size(); j++)
            this->addToTable(oldTable[i][j]);
    delete oldTable;
}

int HashTable::quantityOfFilledNodes()
{
    int result = 0;
    for (int i = 0; i < size; i++)
        if (!table[i].isEmpty())
            result++;
    return result;
}

int HashTable::maxLengthOfList()
{
    int maximum = 0;
    for (int i = 0; i < size; i++)
        maximum = max(maximum, table[i].size());
    return maximum;
}

void HashTable::clearTable()
{
    for (int i = 0; i < size; i ++)
        table[i].clear();
    quantity = 0;
    loadFactor = 0;
}

HashTable::~HashTable()
{
    delete []table;
    delete hashFunction;
}

void HashTable::rebuildTable()
{
    //qDebug("Rebilding table is begining..!\n");
    QList<QString> *oldTable = table;
    int oldSize = size;
    quantity = 0;
    if (size < 103333 || size >= 10333333)
        size = size * 10 + 3;
    else if (size == 103333)
        size = 1033313;
    else
        size = size * 10 + 3;
    table = new QList<QString>[size];
    for (int i = 0; i < oldSize; i++)
        for (int j = 0; j < oldTable[i].size(); j++)
            this->addToTable(oldTable[i][j]);
    loadFactor = (double) quantity / size;
    delete oldTable;
    //qDebug("Rebilding table has been made :)\n");
}
