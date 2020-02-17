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
    alloc = (sList *) malloc (sizeof(sList));
    if (alloc == NULL)
        printf("Error");
    else
    {
        alloc->value = value;
        alloc->next = NULL;
    }
    return (alloc);
}

int insertBeginning(sList **sl, int value) //counter missing
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

int insertLast(sList **sl, int value) //counter missing
{
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


int insertPosition(sList **sl, int position, int value) //counter missing
{
    sList *aux1, *aux2, *new;
    
    if (position > 10)
        return 0;
    else
    {
        new =listAllocation(value);

        if(emptylist(sl))
            (*sl) = new;
        else
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
        //counter here
        return 1;
    }
}

#endif