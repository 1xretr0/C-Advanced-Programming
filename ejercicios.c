#include <stdio.h>
#include <ctype.h>

void removeSpaces(char *str);

int main()
{
    char cadena[50];
    char *pointer;
    int i = 0, cont = 0;

    printf("Escribe una cadena: ");
    gets(cadena);
    printf("\n");

    // ejercicio 1 imprime caracter x caracter
    pointer = cadena; // inicializa al elemento 0 de la cadena
    while (*pointer != '\0')
    {
        putchar(*pointer);
        pointer++;
        cont++;
    }
    printf("\n");

    // ejercicio 2 numero caracteres
    printf("La cadena tiene %d caracteres.\n", cont);

    // ejercicio 3 invertida
    pointer = cadena;
    char *pointer2;
    pointer2 = cadena;

    while (*pointer2 != '\0')
    {
        pointer2++;
    }
    pointer2--;

    while (pointer2 != pointer)
    {
        putchar(*pointer2);
        pointer2--;
    }
    if (pointer2 == pointer)
        putchar(*pointer2);
    printf("\n");

    // ejercicio 4 ascii
    int sumatoria = 0;

    pointer = cadena;
    while (*pointer != '\0')
    {
        int ascii = (int)*pointer;
        sumatoria += ascii;
        pointer++;
    }
    float promedio = (float)sumatoria / cont;
    printf("La sumatoria del ASCII es %d\n", sumatoria);
    printf("El promedio del ASCII es %f\n", promedio);

    // ejercicio 5 palindromo
    removeSpaces(cadena);
    pointer = cadena;
    pointer2 = cadena;

    while (*pointer2 != '\0')
    {
        pointer2++;
    }
    pointer2--;

    int flag;

    while (*pointer != '\0')
    {
        if (tolower(*pointer) == tolower(*pointer2))
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }

        pointer++;
        pointer2--;
    }

    if (flag == 1)
    {
        printf("La cadena es palindromo.\n");
    }
    else
    {
        printf("La cadena no es palindromo.\n");
    }
    return 0;
}

void removeSpaces(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] != ' ')
            str[count++] = str[i];
    }
    str[count] = '\0';
}