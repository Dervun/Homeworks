/*!
 * По дереву разбора арифметического выражения вычислить его значение.
 * Дерево разбора хранится в файле в виде (<операция> <операнд1> <операнд2>),
 * где <операнд1> и <операнд2> сами могут быть деревьями, либо числами.
 * Например, выражение (1 + 1) * 2 представляется в виде (* (+ 1 1) 2).
 * Должны поддерживаться операции +, -, *, / и целые числа в качестве аргументов.
 * Требуется построить дерево в явном виде, распечатать его (не обязательно так же, как в файле),
 * и посчитать значение выражения обходом дерева. Может быть полезна функция ungetc.
 * Можно считать, что входной файл корректен.
 * Пример: по входному файлу (* (+ 1 1) 2) может печататься ((1 + 1) * 2) и выводиться 4.
 * P.S. Я реализовал для  double
*/
#include "calculator.h"
#include "doubleStack.h"
#include "tree.h"
#include <cstdio>
#include <string.h>
#include <limits.h>


int main()
{
    FILE *stream = fopen("tree.txt", "rt");
    if (stream == NULL)
    {
        printf("Can't open %s\n", "tree.txt");
        return 1;
    }
    char *stringTree = new char[10000];
    fgets(stringTree, 10000, stream);
    fclose(stream);
    Tree* tree = readTree(stringTree);
    printInfix(tree);
    printf("\n");
    delete []stringTree;
    char *postfix = treeToPostfix(tree);
    clearTree(tree);
    double result = calculate(postfix);
    delete []postfix;
    if (result == INT_MAX)
        return 1;
    printf("Result = %g\n", result);
    return 0;
}
