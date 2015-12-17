/*!
 * > Реализовать консольную игру "Быки и коровы" (http://goo.gl/J1LKti).
 */
#include <cstdio>
#include <ctime>
#include <cstdlib>

main()
{
    const int quantityOfNumeral = 4;
    int array[quantityOfNumeral];
    srand (time(NULL));
    array[0] = 1 + rand() % 9;
    for (int i = 1; i < quantityOfNumeral; i++)                           //Сгененировал
    {                                                                     //цифры
        array[i] = rand() % 10;                                           //случайного
        bool equivalence = true;                                          //числа
        do                                                                //
        {                                                                 //
            equivalence = true;                                           //
            for (int n = i - 1; n >= 0; n--)                              //
            {                                                             //
                if (array[i] == array[n])                                 //
                {                                                         //
                    equivalence = false;                                  //
                    array[i] = rand() % 10;                               //
                }                                                         //
            }                                                             //
        }                                                                 //
        while (!equivalence);                                             //
    }
    for (int i = 0; i < quantityOfNumeral; i++)
        printf("%d", array[i]);
    printf("\n");
    const int numberOfAttampts = 10;
    int currentNumber;
    int bulls = 0;
    int cows = 0;
    printf("You have %d attemps to guess number:\n", numberOfAttampts);
    for (int i = 0; i < numberOfAttampts; i++)
    {
        scanf("%d", &currentNumber);
        int arr[quantityOfNumeral];
        arr[0] = currentNumber / 1000;
        arr[1] = (currentNumber / 100) % 10;
        arr[2] = (currentNumber / 10) % 10;
        arr[3] = currentNumber % 10;
        for (int j = 0; j < quantityOfNumeral; j++)
        {
            for (int k = 0; k < quantityOfNumeral; k++)
            {
                if (array[j] == arr[k])
                {
                    if (j == k)
                        bulls++;
                    else
                        cows++;
                    break;
                }
            }
        }
        if (bulls == quantityOfNumeral)
        {
            printf("Guessed!");
            break;
        }
        else
        {
            printf("Bulls:\n%d\n", bulls);
            printf("Cows:\n%d\n", cows);
        }
        bulls = 0;
        cows = 0;
    }
}
