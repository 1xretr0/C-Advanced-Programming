#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "queues.h"

int main(void)
{
    struct Cajero {
        int razon_atencion;
        int ocupado;
        int t_desocupa;
    }cajeros[8];

    // variables iniciales de entrada
    int r_llegada, n_cajeros, n_cliente, n_atencion, n_atendidos;
    int tiempo, t_llegada, t_atencion;

    // nodo *tiempos_llegada = NULL;
    nodo *queue = NULL;
    int tiempo_array[34200], tiempo_array_test[30];

    // inicializacion arreglo a 0s
    for (int i = 0; i < 34200; i++){
        tiempo_array[i] = 0;
    }

    for (int i = 0; i < 20; i++){
        tiempo_array_test[i] = 0;
    }

    srand(time(0));

    // input inicial. faltan valids
    printf("**ENTRADA**\n\n");
    printf("Razon de llegada Promedio: ");
    // validacion razon llegada
    do{
        scanf("%i", &r_llegada);
        if (r_llegada > 0) {
            break;
        }
        else
        {
            printf("Ingrese una razon valida: ");
        }
    } while (r_llegada <= 0);

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
        scanf("%i", &cajeros[i].razon_atencion);
        // inicializacion campos cajeros
        cajeros[i].ocupado = 0;
        cajeros[i].t_desocupa = 0;
    }

    system("cls");

    // procesamiento de input
    // se debe simular el horario completo de 34200 segundos
    // osease de 8 am a 5:30 pm

    // inicializamos variables para ciclo
    n_atencion = 1;
    n_atendidos = 0;
    int dato;

    // ciclo de tiempo principal
    for (tiempo = 0; tiempo < 20; tiempo++){
        // numero aleatorio de tiempo llegada
        t_llegada = (rand() % r_llegada) + 1;
        printf("Segundo %i | t llegada: %i | Posicion: %i\n", tiempo, t_llegada, tiempo+t_llegada);
        // guarda la llegada en el segundo determinado
        tiempo_array[tiempo + t_llegada] += 1;
        tiempo_array_test[tiempo + t_llegada] += 1;

        // determinar si llega un cliente en este segundo
        if (tiempo_array[tiempo]){
            while (tiempo_array[tiempo] > 0){
                queue = insert(queue, n_atencion);
                n_atencion++;
                tiempo_array[tiempo]--;
            }
        }

        // determinar si hay cajeros disponibles y hay gente en la queue
        if (queue != NULL){
            for (int i = 0; i < n_cajeros; i++){
                if (cajeros[i].ocupado == 0){
                    queue = remueve(queue, &dato);
                    n_atendidos++;
                    t_atencion = (rand() % cajeros[i].razon_atencion) + 1;
                    cajeros[i].t_desocupa = tiempo + t_atencion;
                    cajeros[i].ocupado = 1; // se ocupa el cajero
                    printf("Tiempo %i | t atender %i | desocupara %i\n", tiempo, t_atencion, cajeros[i].t_desocupa);
                    break;

                }
                else if (tiempo == cajeros[i].t_desocupa){
                    cajeros[i].ocupado = 0; // se desocupa el cajero
                }
            }
        }
    }

    printf("\n");
    for (int i = 0; i < 30; i++)
    {
        printf("%i, ", i);
    }
    printf("\n");
    printf("\nArreglo Tiempo test\n");
    for (int i = 0; i < 30; i++)
    {
        printf("%i, ", tiempo_array_test[i]);
    }
    printf("\n");
    printf("Arreglo Tiempo real\n");
    for (int i = 0; i < 30; i++)
    {
        printf("%i, ", tiempo_array[i]);
    }
    printf("\n\n");

    printf("Queue:\n");
    imprimeLista(queue);

    printf("\n");
    printf("Inicio de Actividades: 8:00\n");
    printf("Fin de Actividades: 5:30\n\n");

    printf("Se atendieron %i Clientes\n", n_atendidos);
   	cantidadLista(queue);
    printf("Cajeros ocupados: %i\n", cajeros[0].ocupado);


    // printf("El Cliente permanece en Promedio  %f segundos en la cola\n");
    // printf("La cola estuvo vacia %i veces\n");

}