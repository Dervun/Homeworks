#include "settest.h"

int main()
{
    SetTest test;
    QTest::qExec(&test);
    return 0;
}

