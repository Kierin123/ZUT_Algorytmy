#include "stdio.h"
#include <stdlib.h>
#include <time.h>
#include "my_sort.h"

int main(int argc, char **argv)
{
    int unsort[10] = {0};
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        unsort[i] = rand()%50 - 20;
    }
    
  

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", unsort[i]);
    }
    printf("\n");

    //selection_sort(unsort,10);
    insertion_sort(unsort,10);
    //bubble_sort(unsort, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", unsort[i]);
    }
    printf("\n");

    return 0;
}
