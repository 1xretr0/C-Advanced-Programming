#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>		// Para el manejo de memoria dinámica

struct Nodo 
{  
	char info;
	struct Nodo *sig;
};

typedef struct Nodo nodo;

nodo *raiz = NULL;		// La lista vacía

nodo *insert(nodo *raiz, char dato)
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

nodo *insertn(nodo *raiz, char dato, int pos)		// insertn('k', 2)
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
	} 
	if(pos == 1)
	{
		nodo *siguiente = raiz;
		raiz = nuevo;
		nuevo -> sig = siguiente;
	}
	else 
	{
		int cont = 1;
		nodo *anterior = raiz;
		nodo *siguiente = NULL;
		while( anterior -> sig != NULL && cont != pos - 1)
		{
			anterior = anterior ->sig;
			cont++;
		}
		siguiente = anterior -> sig;
		anterior -> sig = nuevo;
		nuevo -> sig = siguiente;
	}
    return raiz;
}

nodo *insert1(nodo *raiz, char dato)
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
	nuevo ->sig = raiz;
	raiz = nuevo;

    return raiz;
}



void imprimeLista(nodo *raiz)
{
	nodo *recorre = raiz;
	while( recorre  != NULL) {
		printf("%c, ", recorre->info);
		recorre = recorre ->sig;
	}
	printf("\n");
}


nodo *remueve(nodo *raiz, char *dato)
{
	nodo *anterior = raiz;
	if( raiz == NULL) 
	{
		printf("La lista está vacía.");  //  _Underflow: 
		return '\0';
	}
	if( anterior ->sig == NULL)
	{
		*dato = anterior -> info;
		raiz = NULL;
		free(anterior);
	}
	else
	{
		nodo *siguiente = anterior ->sig;
		while( siguiente->sig != NULL)
		{
			anterior = anterior ->sig;
			siguiente = siguiente->sig;
		}
		*dato = siguiente -> info;
		anterior ->sig = NULL;
		free(siguiente);
	}
	return raiz;
}


nodo *remueve1(nodo *raiz, char *dato)
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


nodo *remueveN(nodo *raiz, char *dato, int pos)
{
	nodo *anterior = raiz;
	if( raiz == NULL) 
	{
		printf("La lista está vacía.");  //  _Underflow: 
		return NULL;
	}
	if(pos == 1)
	{
		nodo *elimina = raiz;
		raiz = raiz -> sig;			// equivale a: raiz = elimna -> sig;
		*dato = elimina ->info;
		free(elimina);
	} else {
		int cont = 1; 
		nodo *elimina = NULL, *siguiente = NULL;
		while(cont != pos - 1) 
		{
			anterior = anterior ->sig;
			cont++;
			if(anterior ->sig == NULL)	// es el ultimo nodo?
			{
				printf("El elemento a borrar no existe.\n");
				return NULL;
			}
		}
		elimina = anterior ->sig;
		siguiente = elimina ->sig;
		*dato = elimina -> info;
		anterior ->sig = siguiente;
		free(elimina);
	}
	return raiz;
}



int main()
{	
	nodo *lista1 = NULL, *lista2 = NULL;
	char dato;

	lista1 = insert(lista1, 'S');
	lista1 = insert(lista1, 'e');
	lista1 = insert(lista1, 'b');
	lista1 = insert(lista1, 'a');
	lista1 = insert(lista1, 's');

	imprimeLista(lista1);
	
	lista1 = insertn(lista1, 'x', 3);
	
	imprimeLista(lista1);
	
	lista1 = remueveN(lista1, &dato, 3);
	
	imprimeLista(lista1);
	return 0;
}