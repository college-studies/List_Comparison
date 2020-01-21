#include <stdio.h>
#include <stdlib.h>

#include "staticList.c"

int main()
{
    int i;
    list ls;
    ls.tCount = 0;
    //ls.size = 10; to set the list size

    runList(&ls);

    /*for(i=0; i<=ls.tCount-1;i++)
    {
        printf("\n[%d]%d",i,ls.array[i]);
    }*/

    return 1;
}
