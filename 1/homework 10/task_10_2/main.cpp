/*!
 * Реализовать раскодирование с помощью алгоритма Хаффмана.
 * На входе файл, генерируемый программой из задачи 1, на выходе — исходный закодированный текст.
 */
#include "unHuffman.h"

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
    char name[] = "Archived.txt";
    FILE* stream = fopen(name, "rt");
    if(!checkOpen(stream, name))
        return 1;
    unarchive(stream);
    return 0;
}