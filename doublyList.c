#ifndef doublyList_c
#define doublyList_c

#include <stdio.h>
#include <stdlib.h>

typedef struct doublyList
{
    int value;
    int size;
    struct doublyList *next, *back;
} dList;

int emptylist(dList **dl)
{
    if ((*dl) == NULL)
        return 1;
    return 0;
}

dList *listAllocation(int value)
{
    dList *alloc;
    alloc = (dList *) malloc (sizeof(dList)*1);
    if (alloc == NULL)
        printf("Error");
    else
    {
        alloc->value = value;
        alloc->next = NULL;
        alloc->back = NULL;
    }
    return (alloc);
}

int insertBeginning(dList **dl, int value, int tcount)
{
    dList *aux, *new;

    new = listAllocation(value);

    if(emptylist(dl))
        (*dl) = new;
    else
    {
        aux = (*dl);
        new->next = aux;
        aux->back = new;
        (*dl) = new;
    }
    return 1;
}

int insertPosition(dList **dl, int position, int value, int tCount, int listSize)
{
    if ((position > tCount) || (tCount >= listSize))
        return 0;
    else
    {
        dList *aux1, *aux2, *new;
        new =listAllocation(value); 

        if(emptylist(dl) && (position == 0))
            (*dl) = new;
        else if((position <= tCount) && (tCount != 0))
        {
            int i = 0;
            aux1 = (*dl);
            while (i < position)
            {
                aux2 = aux1;
                aux1 = aux1->next;
                i++;
            }

            aux2->next = new;
            new->back = aux2;
            new->next = aux1;            
        }     
        return 1;
    }
    return 0;    
}

int insertEnd(dList **dl, int value, int tCount, int listSize)
{
    if(tCount >= listSize)
        return 0;
    dList *aux, *new;
    new = listAllocation(value);

    if(emptylist(dl))
        (*dl) = new;
    else
    {
        aux = (*dl);
        while(aux->next != NULL)
            aux = aux->next;
        new->back = aux;
        aux->next = new;
    }
    return 1;
}


#endif