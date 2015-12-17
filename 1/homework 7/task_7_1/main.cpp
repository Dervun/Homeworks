/*!
 * Получив домашнее задание по программированию, группа студентов приступила к решению задач.
 * Три студента с номерами 1, 2 и 3 честно сделали все задание самостоятельно,
 * другие решили списать с кого-нибудь, кто уже имеет готовое решение — либо решенное самостоятельно,
 * либо уже списанное с другого. При проверке выяснилось, что некоторых студентов следует немедленно отчислить,
 * т.к. они не только не написали решение сами, но и поленились списать.
 * Задача: Определить, какой студент какое решение сдавал, и кого надо отчислить.
 * На входе: количество студентов и список пар чисел, где первое число — номер студента,
 * второе — номер того, с кого было списано решение.
 * Требуется вывести список пар чисел, где первое число — номер студента, второе — 1, 2 или 3 — сданный вариант.
*/
#include <cstdio>

int expose(int *student, int i)
{
    if (student[i] <= 3)
        return student[i];
    return expose(student, student[i]);
}

main()
{
    printf("Enter the quantity of stidents:\n");
    int quantityOfStudents = 0;
    scanf("%d", &quantityOfStudents);
    quantityOfStudents++;
    int *student = new int[quantityOfStudents];
    for (int i = 0; i < quantityOfStudents; i++)
        student[i] = 0;
    for (int i = 1; i < 4; i++)
        student[i] = i;
    printf("For ending enter '0 0'\nEnter pairs (student from_whom_copied):\n");
    int numberOfStudent = 0;
    int fromWhomCopied = 0;
    scanf("%d %d", &numberOfStudent, &fromWhomCopied);
    while (numberOfStudent != 0)
    {
        student[numberOfStudent] = fromWhomCopied;
        scanf("%d %d", &numberOfStudent, &fromWhomCopied);
    }
    for (int i = 1; i < quantityOfStudents; i++)
    {
        if (student[i] > 3)
            student[i] = expose(student, i);
    }
    printf("Send down:\n");
    for (int i = 1; i < quantityOfStudents; i++)
    {
        if (student[i] == 0)
            printf("#%d\n", i);
    }
    printf("Copied:\n");
    for (int i = 1; i < quantityOfStudents; i++)
    {
        if (student[i] > 0)
            printf("#%d get by version %d\n", i, student[i]);
    }
    delete []student;
}
