#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "queues.h"

int main(void)
{
    struct Cajero
    {
        int razon_atencion;
        int ocupado;
        int t_desocupa;
    } cajeros[8];

    // variables iniciales de entrada
    int r_llegada, n_cajeros, n_cliente, n_atencion, n_atendidos;
    int tiempo, t_total, t_llegada, t_atencion, t_cola, t_suma;
    int c_cola;

    // nodo *tiempos_llegada = NULL;
    nodo *queue = NULL;
    char tiempo_array[34200];
    int tiempo_array_test[30];

    // inicializacion arreglo a 0s
    for (int i = 0; i < 34200; i++)
    {
        tiempo_array[i] = 0;
    }

    srand(time(0));

    // input inicial.
    printf("**ENTRADA**\n\n");
    printf("Razon de llegada Promedio: ");
    // validacion razon llegada
    do
    {
        scanf("%i", &r_llegada);
        if (r_llegada > 0)
        {
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
        if (n_cajeros > 0 && n_cajeros <= 8)
        {
            break;
        }
        else
        {
            printf("Ingrese un numero valido: ");
        }
    } while (n_cajeros <= 0 || n_cajeros > 8);

    // ciclo input razon de cada cajero
    for (int i = 0; i < n_cajeros; i++)
    {
        printf("Razon de atencion del cajero %i: ", i + 1);
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
    t_total = 32400;
    n_atencion = 1;
    n_atendidos = 0;
    t_cola = t_atencion = 0;
    c_cola = 0;
    int dato;

    // ciclo de tiempo principal
    for (tiempo = 0; tiempo < t_total; tiempo++){
        // numero aleatorio de tiempo llegada
        t_llegada = (rand() % r_llegada) + 1;
        // guarda la llegada en el segundo determinado
        tiempo_array[tiempo + t_llegada] += 1;

        // determinar si hay cajeros disponibles y hay gente en la queue
        for (int i = 0; i < n_cajeros; i++) // checa disponibilidad cajeros
        {
            if (cajeros[i].ocupado == 0) // si no esta ocupado
            {
                if (queue != NULL) // si hay gente en la cola
                {
                    queue = remueve(queue, &dato);
                    t_suma += t_cola;
                    t_cola = 0;
                    n_atendidos++;
                    t_atencion = (rand() % cajeros[i].razon_atencion) + 1;
                    cajeros[i].t_desocupa = tiempo + t_atencion;
                    cajeros[i].ocupado = 1; // se ocupa el cajero
                    break;
                }
                else
                {
                    c_cola++;
                    continue;
                }
            }
            else if (tiempo == cajeros[i].t_desocupa)
            {
                cajeros[i].ocupado = 0; // se desocupa el cajero
                continue;
            }
            break;
        }

        // determinar si llega un cliente en este segundo
        if (tiempo_array[tiempo] != 0)
        {
            queue = insert(queue, n_atencion);
            t_cola++;
            n_atencion++;
        }

        //
        if (t_cola >= 1)
            t_cola++;
    }

    float t_promedio = t_suma / (float)n_atendidos;
    // Output final
    printf("Inicio de Actividades: 8:00\n");
    printf("Fin de Actividades: 5:30\n\n");

    printf("Se atendieron %i Clientes.\n", n_atendidos);
    cantidadLista(queue);

    printf("El Cliente permanece en Promedio  %.3f segundos en la cola.\n", t_promedio);
    printf("La cola estuvo vacia %i veces.\n", c_cola);
}