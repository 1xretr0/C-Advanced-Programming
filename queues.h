#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>		// Para el manejo de memoria dinámica

struct Nodo
{
	int info;
	struct Nodo *sig;
};
typedef struct Nodo nodo;


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

nodo *remueve(nodo *raiz, int *dato)
{
	nodo *anterior = raiz;
	if( raiz == NULL)
	{
		printf("La lista está vacía.");  //  _Underflow:
		return NULL;
	}
	*dato = anterior -> info;
	raiz = anterior ->sig;
	free(anterior);
	return raiz;
}

void imprimeLista(nodo *raiz)
{
	nodo *recorre = raiz;
	while( recorre  != NULL) {
		printf("%i, ", recorre->info);
		recorre = recorre ->sig;
	}
	printf("\n");
}