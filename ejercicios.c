#include <stdio.h>

int main(){
    char cadena[50];
    char *pointer;
    int i = 0, cont = 0;

    printf("Escribe una cadena: ");
    gets(cadena);
    // scanf("%s", cadena); es lo mismo a scanf("%s", &cadena[0])
    // esto funciona cuando es el elemento 0

    pointer = cadena;   //inicializa al elemento 0 de la cadena

    while (*pointer != NULL){
        putchar(*pointer);
        pointer++;
        cont++;
    }
    printf("\n");

    printf("La cadena tiene %d caracteres.", cont);

    //printf("%s\n", cadena);

    return 0;
}