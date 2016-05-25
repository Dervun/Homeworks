#include <cstdio>

class A
{
public:
    ~A()
    {
        printf("Deleting of element of class A\n");
    }
};

void functionForCheck()
{
    A element;
    throw 0;
}

int main()
{
    try
    {
        functionForCheck();
    }
    catch (...)
    {
        printf("Exception cached!\n");
    }
    return 0;
}

