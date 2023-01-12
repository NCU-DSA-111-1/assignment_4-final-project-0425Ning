#include <stdio.h>
#include "history.h"


void show_history( history * ptr_front )
{
    printf("\n\t\tHistory:");
    while(ptr_front->ptr != NULL)
    {
        ptr_front = ptr_front->ptr;
        printf("\n\t\t%d -> %d %d", ptr_front->count, ptr_front->col, ptr_front->row);
    }
    printf("\n");
    return;
}
