/*!
 * > Даны 2 текстовых файла. Записать в третий файл только те строки, которые встречаются и в первом, и во втором файлах.
*/
#include "table.h"
#include "tree.h"
#include "myString.h"
#include <ctime>

void checkOpen(const FILE* stream, const char* name)
{
    if (stream == NULL)
    {
        printf("Can't open file '%s' :(\n", name);
        exit(1);
    }
}

int main()
{
    unsigned int startTime =  clock();
    char name1[] = "file1.txt";
    FILE* stream1 = fopen(name1, "rt");
    checkOpen(stream1, name1);
    printf("Reading '%s'...\n", name1);
    char* buffer = new char[10000];
    Table* file1 = createTable();
    while (!feof(stream1))
    {
        fgets(buffer, 10000, stream1);
        addToTable(file1, buffer);
    }
    fclose(stream1);
    char name2[] = "file2.txt";
    FILE* stream2 = fopen(name2, "rt");
    checkOpen(stream2, name2);
    printf("Reading '%s'...\n", name2);
    char name3[] = "file3.txt";
    FILE* stream3 = fopen(name3, "wt");
    while (!feof(stream2))
    {
        fgets(buffer, 10000, stream2);
        String* s = createGivenString(buffer);
        Tree* detectedTree = findTree(file1, buffer);
        if (search(detectedTree, s) != NULL)
            fputs(buffer, stream3);
        removeString(s);
    }
    clearTable(file1);
    delete []buffer;
    fclose(stream2);
    fclose(stream3);
    unsigned int endTime = clock();
    printf("Program was working %g s\n", (endTime - startTime) / 1000.0);
    return 0;
}
