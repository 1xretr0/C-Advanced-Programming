#include <stdio.h>

int main(){
    char cadena[50];
    char *pointer;
    int i = 0, cont = 0;

    printf("Escribe una cadena: ");
    gets(cadena);
    printf("\n");

    // ejercicio 1 imprime caracter x caracter
    pointer = cadena;   //inicializa al elemento 0 de la cadena
    while (*pointer != '\0'){
        putchar(*pointer);
        pointer++;
        cont++;
    }
    printf("\n");

    // ejercicio 2 numero caracteres
    printf("La cadena tiene %d caracteres.\n", cont);

    // ejercicio 3 invertida
    pointer = cadena;
    while (*pointer != '\0'){
        pointer++;
    }
    pointer--;

    while (*pointer != '\0'){
        putchar(*pointer);
        pointer--;
    }
    printf("\n");

    // ejercicio 4 ascii
    int sumatoria = 0;

    pointer = cadena;
    while (*pointer != '\0'){
        int ascii = (int) *pointer;
        sumatoria += ascii;
        pointer++;
    }
    float promedio = (float) sumatoria / cont;
    printf("La sumatoria del ASCII es %d\n", sumatoria);
    printf("El promedio del ASCII es %f\n", promedio);

    // ejercicio 5 palindromo
    pointer = cadena;
    char *pointer2 = cadena;
    while (*pointer2 != '\0'){
        pointer2++;
    }
    pointer2--;

    int flag;

    while (*pointer != '\0'){
        while (*pointer2 != '\0'){
            if (*pointer == *pointer2)
            {
                flag = 1;
            } else{
                flag = 0;
            }
            pointer2--;
        }
        pointer++;
    }

    if (flag == 1){
        printf("la cadena es palindromo.\n");
    }
    else{

        printf("la cadena no es palindromo.\n");
    }
    return 0;
}