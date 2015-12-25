/*!
 * > "Считалочка" — отряд из 41-го сикария, защищавший галилейскую крепость Массада, не пожелал сдаваться в плен блокировавшим его превосходящим силам римлян.
 * > Сикарии стали в круг и договорились, что каждые два воина будут убивать третьего, пока не погибнут все.
 * > Самоубийство — тяжкий грех, но тот, кто в конце концов останется последним, должен будет его совершить.
 * > Иосиф Флавий, командовавший этим отрядом, якобы быстро рассчитал, где нужно стать ему и его другу, чтобы остаться последними, но не для того, чтобы убить друг друга, а чтобы сдать крепость римлянам.
 * > В нашем случае участвует n воинов и убивают каждого m-го.
 * > Требуется определить номер k начальной позиции воина, который должен будет остаться последним.
 * > Считать с помощью циклического списка, который должен быть оформлен отдельным модулем.
*/
#include "list.h"

void killWarriors(List &l, int quantityOfWarriors, int stepOfKill)
{
    currentToFirst(l);
    for (int j = quantityOfWarriors; j > 1; j--)
    {
        moveCurrent(l, stepOfKill % j);
        removePreviousNode(l);
    }
}

main()
{
    int n = 0;  //quantity of warriors
    int m = 0;  //step of kill
    printf("Enter quantity of warriors, step of kill:\n");
    scanf("%d%d", &n, &m);
    List l = createList();
    for (int i = n; i > 0; i--)
    {
        addListNode(l, i);
    }
    loopList(l);
    killWarriors(l, n, m);
    int k = showFirstNode(l);
    printf("Survive %d warrior\n", k);
}
