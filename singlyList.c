#ifndef singlyList_c
#define singlyList_c

#include <stdio.h>
#include <stdlib.h>

typedef struct singlyList
{
    int value;
    int size;
    struct singlyList *next;
} sList;

int emptylist(sList **sl)
{
    if ((*sl) == NULL)
        return 1;
    return 0;
}

sList *listAllocation(int value)
{
    sList *alloc;
    alloc = (sList *) malloc (sizeof(sList)*1);
    if (alloc == NULL)
        printf("Error");
    else
    {
        alloc->value = value;
        alloc->next = NULL;
    }
    return (alloc);
}

int insertBeginning(sList **sl, int value, int tCount) 
{
    sList *aux, *new;


    new = listAllocation(value);

    if (emptylist(sl))
        (*sl) = new;
    else
    {
        aux = (*sl);
        new->next = aux;
        (*sl) = new;
    }

    return 1;  
}

int insertEnd(sList **sl, int value, int tCount, int listSize) 
{
    if(tCount >= listSize)
        return 0;
    sList *aux, *new;
    new = listAllocation(value);
    
    if (emptylist(sl))
        (*sl) = new;
    else
    {
        aux = (*sl);
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = new;
    }
    
    return 1;   
}


int insertPosition(sList **sl, int position, int value, int tCount, int listSize) 
{     
    if ((position > tCount) || (tCount >= listSize))
        return 0;
    else
    {
        sList *aux1, *aux2, *new;
        new =listAllocation(value);

        if(emptylist(sl) && (position == 0))
            (*sl) = new;
        else if ((position <= tCount) && (tCount!=0))
        {   
            int i = 0;
            aux1 = (*sl);
            while (i < position)
            {
                aux2 = aux1;
                aux1 = aux1->next;
                i++;
            }

            aux2->next = new;
            new->next = aux1;
        }
        
        return 1;
    }
    return 0;
}


#endif