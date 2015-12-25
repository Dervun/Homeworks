/*!
 * > Реализовать кодирование текста с помощью алгоритма Хаффмана (http://habrahabr.ru/post/144200/).
 * > На входе программы файл с текстом из латинских букв, пробелов и знаков препинания.
 * > На выходе текстовый файл, состоящих из двух строк.
 * > Первая строка содержит в себе представление дерева, которое строится в ходе работы алгоритма (например, в отладочном варианте из задачи 6.1), вторая строка — последовательность нулей и единиц, в которую кодируется входной текст.
 */
#include "huffman.h"
#include <cstdio>

/*!
 * \brief Проверка открытия файла
 * \param stream Указатель на открываемый файл
 * \param name Имя открываемого файла
 * \return В случае неудавшегося открытия файла печатает, что файл с именем name не удалось открыть и возвращает false, иначе true.
 */
bool checkOpen(const FILE* stream, const char* name)
{
    if (stream == NULL)
    {
        printf("Can't open file '%s' :(\n", name);
        return false;
    }
    return true;
}

int main()
{
    char name[] = "inputText.txt";
    FILE* stream = fopen(name, "rt");
    if(!checkOpen(stream, name))
        return 1;
    archive(stream, name);
    return 0;
}
