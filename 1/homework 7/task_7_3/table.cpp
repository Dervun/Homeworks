#include "table.h"
/*!
 * \brief hash-таблица
 * Данная структура является hash-таблицей, коллизии разрешаются с помощью деревьев
 * Структура содержит в себе указатель на массив указателей на деревья, размер массива
 * \param tree Массив указателей на деревья, в которых содержатся элементы, помещённые в hash-таблицу
 * \param size Размер массива (hash-таблицы)
 * \param loadFactor Сколько в среднем элементов приходится на одну ячейку таблицы
 * \param quantity Количество элементов в таблице
 */
struct Table{
    Tree** tree;
    int size;
    double loadFactor;
    int quantity;
};
struct Data{
    String* word;
    int quantity;
};
struct ElementsOfTree{
    String* value;
    int heignt;
    int quantity;
};
/*!
 * Создаёт пустую hash-таблицу заданного размера
 * \brief Создаёт hash-таблицу
 * \param sizeOfTable Размер создаваемой таблицы
 * \return Указатель на созданную таблицу
 */
Table* createTable(int sizeOfTable);
/*!
 * Создаёт новую таблицу нового размера (новый размер - простое число), копирует все элементы в новую таблицу,
 * удаляет старую, изменяет указатель, теперь указатель указывает на новую таблицу, которая в 11 раз больше
 * \brief Перестраивает таблицу
 * \param t Указатель на таблицу, которую надо перестроить (увеличить)
 */
void rebuildTable(Table* &t);
/*!
 * Принимает строку, генерирует целое значение по первым её 10-ти символам
 * \brief hash-функция
 * \param word Строка (в данном случае - слово)
 * \param module Предел значений функции
 * \return Псевдорандомное число от 0 до module - 1
 */
int hashFunction(char* word, int module);
/*!
 * Функция нужна для перестройки таблицы. Она добавляет в новую таблицу слово и частоту его употребления в тексте
 * \brief Добавляет в таблицу слово
 * \param t Таблица
 * \param word Слово
 * \param quantity Сколько раз слово встречалось в предыдущей таблице
 */
void addToTable(Table* &t1, char* word, int quantity);


Table* createTable()
{
    return createTable(103);
}

Table* createTable(int sizeOfTable)
{
    Table* t = new Table;
    t->loadFactor = 0;
    t->quantity = 0;
    t->size = sizeOfTable;
    Tree** trees = new Tree*[sizeOfTable];
    for (int i = 0; i < sizeOfTable; i++)
        trees[i] = createTree();
    t->tree = trees;
    return t;
}

int hashFunction(char* word, int module)
{
    int length = strlen(word);
    unsigned long long result = 0;
    for (int i = 0; i < length && i < 20; i++)
    {
        unsigned long long add = ((int) word[i]) * 7;
        for (int j = 0; j < i; j++)
        {
            add *= 7;
        }
        result += add;
    }
    int result1 = result % module;
    result1 = abs(result1);
    return result1;
}

void rebuildTable(Table* &t)
{
    printf("Rebilding table is begining..!\n");
    Table *t1 = NULL;
    if (t->size < 103333 || t->size >= 10333333)
        t1 = createTable(t->size * 10 + 3);
    else if (t->size == 103333)
        t1 = createTable(1033313);
    else
        t1 = createTable(10333333);
    for (int i = 0; i < t->size; i++)
    {
        if (!emptyTree(t->tree[i]))
        {
            ElementsOfTree* array = treeToArray(t->tree[i]);
            for (int i = 0; array[i].value != NULL; i++)
            {
                char* buffer = stringToChar(array[i].value);
                addToTable(t1, buffer, array[i].quantity);
                delete []buffer;
            }
            for (int i = 0; array[i].value != NULL; i++)
                removeString(array[i].value);
            delete []array;
        }
    }
    clearTable(t);
    t = t1;
    printf("Rebilding table has been made :)\n");
}

void addToTable(Table* &t, char* word)
{
    String* x = createGivenString(word);
    Tree* detectedTree = findTree(t, word);
    if (search(detectedTree, x) == NULL)
        t->quantity++;
    addTreeNode(detectedTree, x);
    t->loadFactor = (double) t->quantity / t->size;
    if (t->loadFactor > 3)
        rebuildTable(t);
}

void addToTable(Table* &t1, char* word, int quantity)
{
    int length = strlen(word);
    char *clone = new char[length + 1];
    strcpy(clone, word);
    String* x = createGivenString(clone);
    unsigned long long index = hashFunction(clone, t1->size);
    delete []clone;
    t1->quantity++;
    addTreeNode(t1->tree[index], x, quantity);
    t1->loadFactor = (double) t1->quantity / t1->size;
}

void clearTable(Table *t)
{
    for (int i = 0; i < t->size; i++)
    {
        if (!emptyTree(t->tree[i]))
        clearTree(t->tree[i]);
    }
    delete []t;
}

Tree* findTree(Table* t, char* buffer)
{
    int index = hashFunction(buffer, t->size);
    return t->tree[index];
}

void processTable(Table* t)
{
    FILE* stream = fopen("Statistics.txt", "wt");
    FILE* stream1 = fopen("Frequency of using words.txt", "wt");
    char* theMostFrequent = NULL;
    int maxFrequency = 0;
    int maxLength = 0;
    char* theLongestWord = NULL;
    int maxHeight = 0;
    int sumOfLength = 0;
    int sumOfHeights = 0;
    int quantityOfTrees = 0;
    int quantityOfWords = 0;
    Tree* maxTree = NULL;
    int sizeOfList = t->quantity;
    Data* list = new Data[sizeOfList];
    int k = 0;
    for (int i = 0; i < t->size; i++)
    {
        Tree* currentTree = t->tree[i];
        if (!emptyTree(currentTree))
        {
            int treeHeight = heightOfTree(currentTree);
            if (treeHeight > maxHeight)
            {
                maxHeight = treeHeight;
                maxTree = currentTree;
            }
            ElementsOfTree* array = treeToArray(currentTree);
            for (int i = 0; array[i].value != NULL; i++)
            {
                String* currentString = array[i].value;
                int currentLengthOfString = lengthString(currentString);
                int currentFrequencyOfString = array[i].quantity;
                if (currentFrequencyOfString > maxFrequency)
                {
                    maxFrequency = currentFrequencyOfString;
                    char* string = stringToChar(currentString);
                    if (theMostFrequent != NULL)
                        delete []theMostFrequent;
                    theMostFrequent = string;
                }
                if (currentLengthOfString > maxLength)
                {
                    maxLength = currentLengthOfString;
                    char* string = stringToChar(currentString);
                    if (theLongestWord != NULL)
                        delete []theLongestWord;
                    theLongestWord = string;
                }
                sumOfLength += currentLengthOfString * currentFrequencyOfString;
                quantityOfWords += currentFrequencyOfString;
                String* cloneString = clone(currentString);
                list[k].word = cloneString;
                list[k].quantity = currentFrequencyOfString;
                k++;
            }
            for (int i = 0; array[i].value != NULL; i++)
                removeString(array[i].value);
            delete []array;
            sumOfHeights += treeHeight;
            quantityOfTrees++;
        }
    }
    double middleLength = (double) sumOfLength / quantityOfWords;
    double middleHeight = (double) sumOfHeights / quantityOfTrees;
    qsortWords(list, 0, sizeOfList - 1);
    fprintf(stream1, "Word - quantity of using this word:\n");
    for (int i = 0; i < sizeOfList; i++)
    {
        char* string = stringToChar(list[i].word);
        fprintf(stream1, "%s - %d\n", string, list[i].quantity);
        delete []string;
    }
    for (int i = 0; i < sizeOfList; i++)
        removeString(list[i].word);
    delete []list;
    fclose(stream1);
    printf("File 'Frequency of using words.txt' was made :)\n");
    fprintf(stream, "Load factor = %g\nMiddle height of tree = %g\n", t->loadFactor, middleHeight);
    fprintf(stream, "Max height of tree = %d\nWords from this tree:\n{\n", maxHeight);
    fprintfTree(maxTree, stream);
    fprintf(stream, "}\n");
    fprintf(stream, "Quantity of differents words = %d\nTotal words - %d\n", t->quantity, quantityOfWords);
    fprintf(stream, "The most frequent word - %s\nIt was used in text %d times\n", theMostFrequent, maxFrequency);
    fprintf(stream, "The longest word - %s (%d symbols)\n", theLongestWord, maxLength);
    fprintf(stream, "Middle height of words - %g\n", middleLength);
    fprintf(stream, "Quantity of empty nodes = %d", t->size - quantityOfTrees);
    fclose(stream);
    printf("File 'Statistics.txt' was made :)\n");
    delete []theMostFrequent;
}
