#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "staticList.c"

int insertValues(list *ls);

int main()
{
    int i;
    list ls;
    ls.tCount = 0, ls.bCount = 0, ls.rCount = 0, ls.eCount = 0;
    ls.size = 50; //to set the list size
    printf("teste");
    runList(&ls);

    insertValues(&ls);
    printf("\n%d\n",ls.tCount);
    for(i = 0; i <= ls.tCount - 1; i++)
    {
        printf("\n[%d]%d", i, ls.array[i]);
    }

    printf("\nBeginning = %d\nRandom Position = %d\nEnd = %d",ls.bCount,ls.rCount,ls.eCount);

    return 1;
}

int insertValues(list *ls)
{
    int count=0, value, flag, insert, max = 3, position;
    srand(time(NULL));

    while (count != ls->size)
    {
        flag = 0;
        insert = rand() % max;
        value = rand() % ls->size+1;

        switch (insert)
        {
        case 0:
            if (insertBeginning(ls, value));
            {
                flag = 1;
                ls->bCount++;
            }
            break;
        case 1://incomplete
            position = rand() % (ls->size-1);
            if (insertPosition(ls, value,position));
            {
                flag = 1;
                ls->rCount++;
            }
            break;
       case 2:
            if (insertEnd(ls, value));
            {
                flag = 1;
                ls->eCount++;
            }
            break;
        }

        if (flag)
            count++;
    }
}

