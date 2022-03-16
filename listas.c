// pointers

#include <stdio.h>
#include <stdlib.h>

int main(){
    int costo;  // variable de tipo entero
    int *pointer; // pointer a variable de tipo entero
    int arreglo[5];

    costo = 60;
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

    // system("pause");
    return 0;
}