#include <stdio.h>

#define PR(fmt, val) printf(#val " = %"#fmt "\t", (val))

#define NL putchar('\n')

#define PRINT1(fmt, x1) PR(fmt, x1), NL
#define PRINT2(fmt, x1, x2) PR(fmt, x1), PRINT1(fmt, x2)
#define PRINT3(fmt, x1, x2, x3) PR(fmt, x1), PRINT2(fmt, x2, x3)
#define PRINT4(fmt, x1, x2, x3, x4) PR(fmt, x1), PRINT3(fmt, x2, x3, x4)
#define PRINT5(fmt, x1, x2, x3, x4, x5) PR(fmt, x1), PRINT4(fmt, x2, x3, x4, x5)

int arreglo[15];

struct Persona{
    char nombre[30];
    int edad;
} juanito, *ptrJuanito;

char car;
int a, b, c, d;
float e, f, g;
double h;
int *ptr;