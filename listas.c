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

void insertn(char dato, int pos)		// insertn('k', 2)
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
}

void insert1(char dato)
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


char remueve(void)
{
	nodo *anterior = raiz;
	char dato;
	if( raiz == NULL) 
	{
		printf("La lista está vacía.");  //  _Underflow: 
		return '\0';
	}
	if( anterior ->sig == NULL)
	{
		dato = anterior -> info;
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
		dato = siguiente -> info;
		anterior ->sig = NULL;
		free(siguiente);
	}

	return dato;
}


char remueve1(void)
{
	nodo *anterior = raiz;
	char dato;
	if( raiz == NULL) 
	{
		printf("La lista está vacía.");  //  _Underflow: 
		return '\0';
	}
	dato = anterior -> info;
	raiz = anterior ->sig;
	free(anterior);
	return dato;
}


char remueven(int pos)
{
	nodo *anterior = raiz;
	char dato;
	if( raiz == NULL) 
	{
		printf("La lista está vacía.");  //  _Underflow: 
		return '\0';
	}
	if(pos == 1)
	{
		nodo *elimina = raiz;
		raiz = raiz -> sig;			// equivale a: raiz = elimna -> sig;
		dato = elimina ->info;
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
				return;
			}
		}
		elimina = anterior ->sig;
		siguiente = elimina ->sig;
		dato = elimina -> info;
		anterior ->sig = siguiente;
		free(elimina);
	}
	return dato;
}



int main()
{	
	nodo *lista1 = NULL, *lista2 = NULL; 

	lista1 = insert(lista1, 'R');
	lista1 = insert(lista1, 'o');
	lista1 = insert(lista1, 'b');
	lista1 = insert(lista1, 'e');
	lista1 = insert(lista1, 'r');
	lista1 = insert(lista1, 't');
	lista1 = insert(lista1, 'o');

	lista2 = insert(lista2, 'S');
	lista2 = insert(lista2, 'a');
	lista2 = insert(lista2, 'l');
	lista2 = insert(lista2, 'a');
	lista2 = insert(lista2, 'z');
	lista2 = insert(lista2, 'a');
	lista2 = insert(lista2, 'r');


	imprimeLista(lista1);
	imprimeLista(lista2);


	system("pause");
	return 0;
}