#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <sys/times.h> 
#include <sys/types.h> 
#include <unistd.h> 

#include "singlyList.c"

#define max 3
#define listSize 10000 //Alter here the size (1000 and 10000)

int insertValues(sList *sl);

int main()
{
    sList *sl = NULL;
    int i;
    
    clock_t tt;
	struct tms time; 
    int tics_per_second; 
    tics_per_second = sysconf(_SC_CLK_TCK);

    insertValues(sl);
    
    tt = times(&time);
    printf("\nCPU TIME: %lf s\n", ( (double)time.tms_utime) / tics_per_second );
    
    return 1;
}

int insertValues(sList *sl)
{
    int bCount = 0, rCount = 0, eCount = 0;


    int count = 0, value, flag, position;
    int insert;
    srand((unsigned) time(NULL));
    
    do
    {

        insert = (rand() % max);
        value = rand() % (listSize+1);

        switch (insert)
        {
        case 0:
            if (insertBeginning(&sl, value, count))
            {
                bCount++;
                count++;
            }
            break;
        case 1:
            position = rand() % (listSize+1);
            if(insertPosition(&sl, value, position, count, listSize))
            {
                rCount++;
                count++;                
            }
            break;
       case 2:
            if(insertEnd(&sl, value, count, listSize))
            {
                eCount++;
                count++;
            }
        default: 
            break;
        }


    } while (count != listSize);
    
    printf("\nBeginning = %d\nRandom Position = %d\nEnd = %d", bCount, rCount, eCount);

    return 1;
}