#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
    // int a, b, c;
    int *pa, *pb, *pc;

    pa = (int *) malloc(sizeof(int));
    pb = (int *) malloc(sizeof(int));
    pc = (int *) malloc(sizeof(int));

    printf("Dame un numero: ");
    scanf("%d", pa);
    printf("Dame un numero: ");
    scanf("%d", pb);

    *pc = *pa + *pb;
    printf("la suma de %d + %d es igual a: %d\n", *pa, *pb, *pc);

    free(pa);
    free(pb);
    free(pc);
    return 0;
}