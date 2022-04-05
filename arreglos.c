#include <stdio.h>  // Para las funciones de i/o
#include <stdlib.h> // Para el usoi de system()

void porValor(int variable);
void porReferencia(int *variable);

void porValor(int variable)
{
    variable += 5;
    printf("Variable = %d\n", variable);
}

void porReferencia(int *variable)
{
    *variable += 5;
    printf("Variable = %d\n", *variable);
}

int main()
{
    int costo = 60;                   // Declaro una variable de tipo entero llamada costo
    int *pointer = NULL;              // Declaro un ap.untador a enteros llamado pointer
    int arreglo[5] = {0, 1, 2, 3, 4}; // declaro un arreglo de 5 enteros
    int *ptrArreglo[5];               // declaro un arreglo de 5 apuntadores a entero

    printf("La direccion de memoria de costo es: %p y hay %d\n", &costo, costo);

    pointer = &costo;
    printf("La direccion de memoria de pointer es: %p y hay %p\n", &pointer, pointer);

    printf("El contenido (*) de pointer es %d\n", *pointer);

    *pointer = 50;
    printf("La direccion de memoria de costo es: %p y hay %d\n", &costo, costo);

    ////====================================================================
    // printf("La direccion del arreglo[0] es %p\n", &arreglo[0]);
    // printf("La direccion del arreglo[1] es %p\n", &arreglo[1]);
    // printf("La direccion del arreglo[2] es %p\n", &arreglo[2]);
    // printf("La direccion del arreglo[3] es %p\n", &arreglo[3]);
    // printf("La direccion del arreglo[4] es %p\n", &arreglo[4]);

    ////------------------- apuntadores a arreglos----------
    // pointer = arreglo;
    // printf("La direccion de memoria de pointer es: %p y hay %d\n", pointer, *pointer);

    //// ------------------ arreglos de apuntadores -----------

    // ptrArreglo[2] = &arreglo[2];
    // printf("La direccion de memoria de ptrArreglo[2] es: %p y hay %d\n", ptrArreglo[2], *ptrArreglo[2]);

    porValor(costo);
    printf("Costo = %d\n", costo);
    porReferencia(&costo);
    printf("Costo = %d\n", costo);

    // scanf("%d", &costo)

    system("pause");
    return 0;
}