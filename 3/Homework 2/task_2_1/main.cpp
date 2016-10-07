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
#include <ctime>
#include <cstdlib>

#include "localareanetworktest.h"
#include "computertest.h"


int main()
{
    FILE* informationFile = fopen("Computers.txt", "rt");
    if (!informationFile)
    {
        printf("File 'Computers.txt' wasn't found :(");
        return 1;
    }
    LocalAreaNetwork* myNetwork = new LocalAreaNetwork(informationFile);
    fclose(informationFile);
    myNetwork->viewState();
    int numberOfStep = 1;
    while (!myNetwork->allComputersWasInfected())
    {
        printf("\n");
        myNetwork->makeStep();
        printf("%d)Step\n", numberOfStep);
        myNetwork->viewState();
        numberOfStep++;
    }
    delete myNetwork;
    printf("\nPlease, wait...\nThere is the testing...\n\n");
    ComputerTest test1;
    QTest::qExec(&test1);
    printf("\n\n");
    LocalAreaNetworkTest test2;
    QTest::qExec(&test2);
    return 0;
}

