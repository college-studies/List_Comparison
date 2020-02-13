#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "staticList.c"
#include "singlyLinkedList.c"

#define max 3
#define listSize 10000

double insertValues(list *ls);

int main()
{
    int i;
    list ls;
    ls.tCount = 0, ls.bCount = 0, ls.rCount = 0, ls.eCount = 0;
    ls.size = listSize; //to set the list size
    runList(&ls);
    double timer;

    timer = insertValues(&ls);
    
    printf("\n%d\n",ls.tCount);

    printf("\nBeginning = %d\nRandom Position = %d\nEnd = %d",ls.bCount,ls.rCount,ls.eCount);
    printf("\nCPU use: %lfms",timer);
    return 1;
}

double insertValues(list *ls)
{
    unsigned long timer;
    int count=0, value, flag, position;
    int insert;
    srand((unsigned) time(NULL));
    time_t start, end;
    start = clock();
    do
    {

        flag = 0;
        insert = (rand() % max);
        value = rand() % (ls->size+1);

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
            position = rand() % (ls->size+1);
            if (insertPosition(ls, value,position))
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
        default: 
            break;
        }

        if (flag)
        {
            count++;
        }
    } while (count != ls->size);
    end = clock();
    return (end-start);
}

