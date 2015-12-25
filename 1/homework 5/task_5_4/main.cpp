/*!
 * > Написать программу-телефонный справочник.
 * > Она должна уметь хранить имена и номера телефонов, в интерактивном режиме осуществлять следующие операции:
 * > 0 - выйти
 * > 1 - добавить запись (имя и телефон)
 * > 2 - найти телефон по имени
 * > 3 - найти имя по телефону
 * > 4 - сохранить текущие данные в файл.
 * > При запуске программа должна читать данные из файла, если файла нет — начинать с пустой базы номеров.
 * > Формат представления данных в файле придумать самостоятельно.
 */
#include "phonebook.h"
#include <string.h>
#include <cstdio>

enum Select{
    exit = 0,
    addNote,
    searchPhone,
    searchName,
    save
};

main()
{
    Select x = addNote;
    List l = fillList();
    printf("0 - Exit\n");
    printf("1 - Add note (name and phone)\n");
    printf("2 - find phone through name\n");
    printf("3 - find name through phone\n");
    printf("4 - save current data to file:\n");
    scanf("%d", &x);
    while (x != exit)
    {
        switch (x)
        {
            case addNote:
            {
                printf("Enter 'Name number' (for example: 'Sergey_Ivanov +79217842312') :\n");
                char name[1000];
                char number[1000];
                scanf("%s", name);
                scanf("%s", number);
                addList(l, name, number);
                printf("Note has added :)\n");
                break;
            }
            case searchPhone:
            {
                char name[1000];
                printf("Enter name:\n");
                scanf("%s", name);
                char *number = findPhone(l, name);
                if (number == NULL)
                {
                    printf("Phone has not found :(");
                }
                else
                {
                    int lengthNumber = strlen(number);
                    for (int i = 0; i < lengthNumber; i++)
                    {
                        printf("%c", number[i]);
                    }
                }
                printf("\n");
                break;
            }
            case searchName:
            {
                char number[1000];
                printf("Enter number:\n");
                scanf("%s", number);
                char *name = findName(l, number);
                if (name == NULL)
                {
                    printf("Name has not found :(");
                }
                else
                {
                    int lengthName = strlen(name);
                    for (int i = 0; i < lengthName; i++)
                    {
                        printf("%c", name[i]);
                    }
                }
                printf("\n");
                break;
            }
            case save:
            {
                saveData(l);
                printf("Data have saved :)\n");
                break;
            }
            default:
            printf("0 - Exit\n");
            printf("1 - Add note (name and phone)\n");
            printf("2 - find phone through name\n");
            printf("3 - find name through phone\n");
            printf("4 - save current data to file:\n");
        }
        scanf("%d", &x);
    }
    clearList(l);
    printf("The program is completed :)\n");
}
