#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <sys/times.h> 
#include <sys/types.h> 
#include <unistd.h> 

#include "staticList.c"

#define max 3
#define listSize 10000 //Alter here the size (1000 and 10000)

int insertValues(list *ls);

int main()
{
    int i;
    list ls;
    ls.tCount = 0, ls.bCount = 0, ls.rCount = 0, ls.eCount = 0;
    ls.size = listSize; //to set the list size
    runList(&ls);
    
    clock_t tt;
	struct tms time; 
    int tics_per_second; 

    tics_per_second = sysconf(_SC_CLK_TCK);
    
    insertValues(&ls);
    tt = times(&time);
    
    printf("\nBeginning = %d\nRandom Position = %d\nEnd = %d",ls.bCount,ls.rCount,ls.eCount);

    printf("\nCPU TIME: %lf s\n", ( (double)time.tms_utime) / tics_per_second );
    
    return 1;
}

int insertValues(list *ls)
{
    
    int count=0, value, position;
    int insert;
    srand((unsigned) time(NULL));
    do
    {
        insert = (rand() % max);
        value = rand() % (ls->size+1);

        switch (insert)
        {
        case 0:
            if (insertBeginning(ls, value))
            {
                count++;
                ls->bCount++;
            }
            break;
        case 1:
            position = rand() % (ls->size+1);
            if (insertPosition(ls, value,position))
            {
                count++;
                ls->rCount++;
            }
            break;
       case 2:
            if (insertEnd(ls, value))
            {
                count++;
                ls->eCount++;
            }
            break;
        default: 
            break;
        }

    } while (count != ls->size);
    return 1;
}

