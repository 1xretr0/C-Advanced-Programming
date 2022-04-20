#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> // Para el manejo de memoria dinámica

struct Nodo{
    char info;
    struct Nodo *sig;
};
typedef struct Nodo nodo;

nodo *raiz = NULL; // La lista vacía

// inserta al final de la lista
void insert(char dato){
    nodo *nuevo = NULL;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if (nuevo == NULL){
        printf("No hay memoria suficiente! \n");
        exit(1);
    }
    nuevo->info = dato;
    nuevo->sig = NULL;

    if (raiz == NULL){  // lista vacia
        raiz = nuevo;
    }
    else{   // lista no vacia
        nodo *recorre = raiz;
        while (recorre->sig != NULL)
            recorre = recorre->sig;
        recorre->sig = nuevo;
    }
}

// inserta al inicio de la lista
void insert1(char dato){
    nodo *nuevo = NULL;
    nuevo = (nodo *) malloc(sizeof(nodo));
    if (nuevo == NULL){
        printf("No hay memoria suficiente! \n");
        exit(1);
    }
    nuevo->info = dato;
    nuevo->sig = NULL;

    nuevo->sig = raiz;
    raiz = nuevo;
}

// inserta en la posicion n
void insertN(char dato, int n)
{
    nodo *nuevo = NULL;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if (nuevo == NULL){
        printf("No hay memoria suficiente! \n");
        exit(1);
    }
    nuevo->info = dato;
    nuevo->sig = NULL;

    if (raiz == NULL)
    { // lista vacia
        raiz = nuevo;
    }
    else
    { // lista no vacia.
        int cont = 1;
        nodo *anterior = raiz;
        nodo *siguiente = NULL;

        while (anterior->sig != NULL && cont != n-1){
            anterior = anterior->sig;
            cont++;
        }
        siguiente = anterior->sig;
        anterior->sig = nuevo;
        nuevo->sig = siguiente;
    }
}

void imprimeLista(){
    nodo *recorre = raiz;
    while (recorre != NULL)
    {
        printf("%c, ", recorre->info);
        recorre = recorre->sig;
    }
    printf("\n");
}

int main(){
    insert('S');
    insert('E');
    insert('B');
    insert('A');
    insert('S');
    insertN('X', 2);

    imprimeLista();
    return 0;
}