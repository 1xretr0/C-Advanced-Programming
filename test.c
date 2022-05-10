#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "queues.h"

int main(void)
{
    srand(time(0));
    int arreglo[5];

    for (int i = 0; i < 5; i++){
        arreglo[i] = 0;
    }

    arreglo[2] = 1;
    for (int i = 0; i < 5; i ++){
        printf("%i, ", arreglo[i]);
    }

    int r_llegada = 20;
    int t_llegada = (rand() % r_llegada) + 1;
    printf("\n%i\n", t_llegada);
}