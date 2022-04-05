#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
    // int a, b, c;
    int *pa, *pb, *pc;

    pa = (int) malloc(sizeof(int));
    pb = (int) malloc(sizeof(int));
    pc = (int) malloc(sizeof(int));

    printf("Dama un número: ");
    scanf("%d", pa);
    printf("Dame un número: ");
    scanf("%d", pb);

    *pc = *pa + *pb;
    printf("la suma de %d mas %d es igual a: %d", *pa, *pb, *pc);
    return 0;
}