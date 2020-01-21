#ifndef staticList_c
#define staticList_c

#include <stdio.h>
#include <stdlib.h>

typedef struct staticList
{
    int *array;
    int size;
    int tCount, bCount, rCount, eCount;

}list;

int runList(list *ls)
{
    ls->array = (int *) malloc(sizeof(int)*ls->size);

    return 1;
}

int emptyList(list *ls)
{
    if (ls->tCount == 0)
        return 1;
    else
        return 0;
}

int insertBeginning(list *ls, int value) 
{
    if (emptyList(ls))
        ls->array[0] = value;
    else
    {
        if (ls->tCount < ls->size)
        {
            int i;
            for (i = ls->tCount + 1; i >= 1; i--)
                {
                    ls->array[i] = ls->array[i-1];
                }            
            ls->array[0] = value;
        }
        else
            return 0;
    }
    ls->tCount++;
    return 1;
}

int insertPosition(list *ls,int value, int position)
{
    if(emptyList(ls))
    {
        insertBeginning(ls,value);
        return 1;
    }
    else
    {
        if ( (ls->tCount >= ls->size) || (position > ls->tCount) )
            return 0;
        else
        {
            int i;
            for (i = ls->tCount; i >= position ; i--)
                ls->array[i] = ls->array[i-1];
            
            ls->array[position] = value;

            ls->tCount++;
            return 1;
        }
    }
}

int insertEnd(list *ls, int value)
{
    if(emptyList(ls))
    {
        insertBeginning(ls,value);
        return 1;
    }
    else
    {
        if(ls->tCount >= ls->size)
            return 0;
        else
        {
            printf("ok");
            ls->array[ls->tCount] = value;
        }
        ls->tCount++;
        return 1;
    }            
}
#endif