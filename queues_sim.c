#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// #include <queues.h>

int main(void)
{
    // variables iniciales de entrada
    int r_llegada, n_cajeros, r_cajeros[8];

    // input inicial. faltan valids
    printf("**ENTRADA**\n\n");
    printf("Razon de llegada Promedio: ");
    do{
        scanf("%i", &r_llegada);
        if (r_llegada > 0)
        {
            break;
        }
        else
        {
            printf("Ingrese una razon valida: ");
        }
    }while (r_llegada <= 0);

    printf("Numero de cajeros: ");
    do
    {
        scanf("%i", &n_cajeros);
        if (n_cajeros > 0)
        {
            break;
        }
        else
        {
            printf("Ingrese un numero valido: ");
        }
    } while (n_cajeros <= 0);


    // ciclo input razon de cada cajero
    for (int i = 0; i < n_cajeros; i++){
        printf("Razon de atencion del cajero %i: ", i+1);
        scanf("%i", &r_cajeros[i]);
    }
    system("cls");
}