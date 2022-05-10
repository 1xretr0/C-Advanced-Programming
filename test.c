#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "queues.h"

int main(void)
{
    int arreglo[5];

    for (int i = 0; i < 5; i++){
        arreglo[i] = 0;
    }

    arreglo[2] = 1;
    for (int i = 0; i < 5; i ++){
        printf("%i, ", arreglo[i]);
    }
}