/*!
 * Написать программу, которая переставляет цифры натурального числа таким образом, чтобы образовалось наименьшее число, записанное этими же цифрами.
 */
#include <cstdio>

main()
{
    unsigned long long number = 0;
    printf("Enter your number:\n");
    scanf("%llu", &number);
    const int sizeOfArray = 10;
    int array[sizeOfArray];                          //Массив, в котором хранится количество цифр.
    for (int i = 0; i < sizeOfArray; i++)            //Зануляем.
        array[i] = 0;
    if (number > 0)
    {
        while (number > 0)
        {
            array[number % 10]++;
            number /= 10;
        }                                            //Узнали количество цифр.
        for (int i = 1; i < sizeOfArray; i++)
        {
            if (array[i] > 0)
            {
                array[i]--;
                printf("Minimal number:\n%d", i);                   //Нашли и вывели минимальную цифру, но не 0.
                break;
            }
        }
        for (int i = 0; i < sizeOfArray; i++)       //Выводим оставшиеся цифры, сначала меньшие.
        {
            if (array[i] > 0)
            {
                for (int j = 0; j < array[i]; j++)
                    printf("%d", i);
            }
        }
        printf("\n");
    }
    else
        printf("Error. Enter positiv number.");
}
