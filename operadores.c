#include "defs.h"
#include <stdio.h>
#include <stdlib.h>

void bases(){
    a = 179;
    printf("179 base 10 es %o en base 8\n", a);
    printf("179 base 10 es %X en base 16\n", a);

    b = 0263; // base ocho
    printf("263 base 8 es %d en base 10\n", b);
    printf("263 base 8 es %x en base 16\n", b);

    c = 0xB3; // base 16
    printf("B3 base 16 es %d en base 10\n", c);
    printf("B3 base 16 es %d en base 8\n", c);
}

void primarios(){
    bases();

    PRINT1(f, 5.0 / 9 * 80 - 32);   //error
    PRINT1(f, 5.0 / 9 * (80 - 32)); //correcto
    PRINT1(d, (2+2) - (3+3)); //asociatividad

    // operador indice de arreglo
    PR(d, arreglo[5]); NL;

    // operador punto ( . )
    juanito.edad = 25;

    // operador flecha ->
    ptrJuanito = &juanito;
    ptrJuanito->edad = 26;

    system("pause");
}

int main(){
    // jerarquia segunda

    // operador negación lógica (!)
    a = 0;
    if (a)
        PR(s, "verdadero");
    else
        PR(s, "falso");

    system("pause");
}