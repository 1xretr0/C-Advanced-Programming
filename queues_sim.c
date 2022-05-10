#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "queues.h"

int main(void)
{
    // variables iniciales de entrada
    int r_llegada, n_cajeros, r_cajeros[8], n_cliente;
    int tiempo, t_llegada;
    nodo *tiempos_llegada = NULL;

    srand(time(NULL));

    // input inicial. faltan valids
    printf("**ENTRADA**\n\n");
    printf("Razon de llegada Promedio: ");
    // validacion razon llegada
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
    // validacion numero cajeros
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

    // procesamiento de input
    // se debe simular el horario completo de 34200 segundos
    // osease de 8 am a 5:30 pm
    for (tiempo = 0; tiempo < 5; tiempo++){
        t_llegada = (rand() % r_llegada) + 1;
        int suma = tiempo + t_llegada;

        if (tiempos_llegada == NULL){
            // lista vacia
            tiempos_llegada = insert(tiempos_llegada, suma);
        }
        else{
            // lista no vacía
            nodo *recorre = tiempos_llegada;
            int contador = 1;
            while (recorre != NULL)
            {
                if (suma <= recorre->info)
                {
                    recorre = insertN(recorre, suma, contador);
                }

                recorre = recorre->sig;
                contador++;
            }

        }
        tiempos_llegada = insert(tiempos_llegada, suma);
    }

    imprimeLista(tiempos_llegada);
}