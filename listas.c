#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void insert();

struct Nodo{
    char info;
    struct Nodo *sig;
};
typedef struct Nodo nodo;

nodo *raiz = NULL;  // lista vacia

int main(){
    int costo;
    nodo cajaZapato;

    return 0;
}

void insert(char dato){
    nodo *nuevo = NULL;
    nuevo = (nodo *) malloc(sizeof(nodo));
    if (nuevo == NULL){
        printf("No hay memoria suficiente\n");
        exit(1);
    }

    nuevo -> info = dato;
    nuevo -> sig = NULL;
    if (raiz == NULL){
        raiz = nuevo;
    }
    else{
        // no
    }
}