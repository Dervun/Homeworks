/*!
 * > Реализовать синтаксический анализатор, разбирающий арифметические выражения методом рекурсивного спуска.
 * > Входной поток составляют числа, разбираемые лексическим анализатором из прошлого задания, и знаки операций {+, -, /, *}.
 */
#include <cstdio>
#include "lexicalAnalyser.h"
#include "parser.h"

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
    char name[] = "expression.txt";
    FILE* stream = fopen(name, "rt");
    if(!checkOpen(stream, name))
        return 1;
    if (E(stream))
        printf("true :)\n");
    else
        printf("false :(\n");
    return 0;
}
