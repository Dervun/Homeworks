/*!
 * > Посчитать число "счастливых билетов" (билет считается "счастливым", если сумма первых трёх цифр его номера равна сумме трёх последних).
 */
#include <stdio.h>
main()
{
    const int nine = 9;
    const int sizeOfArray = 28;
    int array[sizeOfArray];
    for (int n = 0; n < sizeOfArray; n++)
        array[n] = 0;
    for (int i = 0; i <= nine; i++)
    {
        for (int j = 0; j <= nine; j++)
        {
            for (int k = 0; k <= nine; k++)
                array[i + j + k]++;
        }
    }
    for (int m = 0; m < sizeOfArray; m++)
        array[m] = array[m] * array[m];
    int result = 0;
    for (int l = 0; l < sizeOfArray; l++)
        result += array[l];
    printf("Total happy tickets: %d\n", result);
}
