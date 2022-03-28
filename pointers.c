#include <stdio.h>
#include "defs.h"

int main(void){
    int a[] = {0, 1, 2, 3, 4};
    int *p;
    int i;

    for (p = a, i = 0; p+i <= a+4; p++, i++){
        PR(d, *(p+i));
    }

    NL;

    for (p = a+4; p >= a; p--)
        PR(d, *p);
}