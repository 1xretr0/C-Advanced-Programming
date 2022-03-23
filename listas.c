// pointers

#include <stdio.h>
#include <stdlib.h>

void porValor(int variable){
    variable += 5;
    printf("Variable = %d\n", variable);
}

void porReferencia(int *variable){
    *variable += 5;
    printf("Variable = %d\n", *variable);
}

int main(){
    int costo = 60;  // variable de tipo entero
    int *pointer; // pointer a variable de tipo entero
    int arreglo[5] = {1,2,3,4,5};
    int *ptrArreglo[5];

    /*costo = 60;
    printf("la direccion de memoria de costo es %p y hay %i\n", &costo, costo);

    pointer = &costo;
    printf("la direccion de memoria de pointer es %p y hay %p\n", &pointer, pointer);

    printf("El contenido (*) de pointer es %i\n", *pointer);

    *pointer = 50;
    printf("El contenido (*) de pointer es %i\n", *pointer);

    printf("El contenido de costo es %i\n", costo);

    // arreglos
    printf("la direccion del arreglo[0] es %p\n", &arreglo[0]);
    printf("la direccion del arreglo[1] es %p\n", &arreglo[1]);
    printf("la direccion del arreglo[2] es %p\n", &arreglo[2]);
    printf("la direccion del arreglo[3] es %p\n", &arreglo[3]);
    printf("la direccion del arreglo[4] es %p\n", &arreglo[4]);

    pointer = &arreglo[2];
    printf("la direccion de memoria del pointer es %p y hay %d\n", pointer, *pointer);

    ptrArreglo[2] = &arreglo[2];
    printf("la direccion de memoria del ptrArreglo es %p y hay %d\n", ptrArreglo[2], *ptrArreglo[2]);*/

    /* porValor(costo);
    printf("Costo = %d\n", costo);

    porReferencia(&costo);
    printf("Costo = %d\n", costo);*/

    printf("la direccion del arreglo[0] es %p\n", &arreglo[0]);
    printf("la direccion del arreglo[1] es %p\n", &arreglo[1]);
    printf("la direccion del arreglo[2] es %p\n", &arreglo[2]);
    printf("la direccion del arreglo[3] es %p\n", &arreglo[3]);
    printf("la direccion del arreglo[4] es %p\n\n", &arreglo[4]);

    pointer = &arreglo[2];
    printf("la direccion guardada en pointer - 2 es: %p\n", pointer - 2);
    printf("la direccion guardada en pointer - 1 es: %p\n", pointer - 1);
    printf("la direccion guardada en pointer es: %p\n", pointer);
    printf("la direccion guardada en pointer + 1 es: %p\n", pointer + 1);
    printf("la direccion guardada en pointer + 2 es: %p\n", pointer + 2);

    // OFFSET no se mueve apuntador, solo referencia direccion
    *(pointer +2) = 10;

    // apuntador si se mueve y cambia valor
    pointer = &arreglo[4];
    *pointer = 10;

    pointer += 2;
    *pointer = 10;
    // system("pause");
    return 0;
}