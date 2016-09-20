/*!
 * Смоделировать работу локальной сети:
 *   a) в сети есть несколько компьютеров, связанных друг с другом (каким образом - можно задавать, например,
 *      матрицей смежности);
 *   b) на каждом компе стоит ОС (Windows, Linux, etc...);
 *   c) в сети гуляют вирусы, так что для каждой машины есть ненулевая вероятность заразиться
 *      (вероятность зависит от типа ОС), заражаются компьютеры, непосредственно соединённые с заражёнными;
 *   d) заражения (и проверки, заразился компьютер или нет) происходят дискретно - по ходам.
 * Требуется периодически выводить состояние сети. Нужны тесты, проверяющие правильность процесса заражения.
 */
#include "localareanetwork.h"


int main()
{
    FILE* informationFile = fopen("Computers.txt", "rt");
    if (!informationFile)
    {
        printf("File 'Computers.txt' wasn't found :(");
        return 1;
    }
    LocalAreaNetwork* myNetwork = new LocalAreaNetwork(informationFile);
    printf("An attempt to view state:\n");
    myNetwork->viewState();
    printf("An attempt to make a step:\n");
    myNetwork->makeStep();
    delete myNetwork;
    return 0;
}

