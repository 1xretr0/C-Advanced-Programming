#include "defs.h"
#include <stdlib.h>

void bases();

int main(void){
    a = 179;
    printf("179 base 10 es %o en base 8\n", a);
    printf("179 base 10 es %X en base 16\n", a);

    b = 0263;   //base ocho
    printf("263 base 8 es %d en base 10\n", b);
    printf("263 base 8 es %x en base 16\n", b);

    c = 0xB3;   //base 16
    printf("B3 base 16 es %d en base 10\n", c);
    printf("B3 base 16 es %d en base 8\n", c);
}