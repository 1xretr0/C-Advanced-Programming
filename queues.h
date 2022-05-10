#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>		// Para el manejo de memoria dinámica

struct Nodo
{
	int info;
	struct Nodo *sig;
};
typedef struct Nodo nodo;
int cont_queue = 0;

// insert functions
nodo *insert(nodo *raiz, int dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )
	{
		printf("No hay memoria suficiente! \n");
		exit(1);
	}
	nuevo ->info = dato;
	nuevo ->sig = NULL;

	if(raiz == NULL)
	{
		raiz = nuevo;
	} else {
		nodo *recorre = raiz;
		while( recorre -> sig != NULL)
			recorre = recorre ->sig;
		recorre -> sig = nuevo;
	}
	return raiz;
}

nodo *insertN(nodo *raiz, int dato, int pos){
	nodo *nuevo = NULL;
	nuevo = (nodo *)malloc(sizeof(nodo));
	if (nuevo == NULL)
	{
		printf("No hay memoria suficiente! \n");
		exit(1);
	}
	nuevo->info = dato;
	nuevo->sig = NULL;

	if (raiz == NULL){
		raiz = nuevo;
	}
	if (pos == 1)
	{
		nodo *siguiente = raiz;
		raiz = nuevo;
		nuevo->sig = siguiente;
	}
	else
	{
		int cont = 1;
		nodo *anterior = raiz;
		nodo *siguiente = NULL;
		while (anterior->sig != NULL && cont != pos - 1)
		{
			anterior = anterior->sig;
			cont++;
		}
		siguiente = anterior->sig;
		anterior->sig = nuevo;
		nuevo->sig = siguiente;
	}
	return raiz;
}

// remueve functions
nodo *remueve(nodo *raiz, int *dato)
{
	nodo *anterior = raiz;
	if( raiz == NULL){
		printf("La lista está vacía.");  //  _Underflow:
		return NULL;
	}
	*dato = anterior -> info;
	raiz = anterior ->sig;
	free(anterior);
	return raiz;
}

// order functions
nodo *insertOrdenado(nodo *raiz, int suma, int pos)
{
	return NULL;
}

// print function
void imprimeLista(nodo *raiz)
{
	nodo *recorre = raiz;
	while( recorre  != NULL) {
		printf("%i, ", recorre->info);
		recorre = recorre ->sig;
	}
	printf("\n");
}

//review function
void cantidadLista(nodo *raiz)
{
	nodo *recorre = raiz;
	while( recorre  != NULL) {
		c_queue++;
		recorre = recorre ->sig;
	}
	printf("Quedaron %i Clientes en la cola de espera\n", cont_queue);
}