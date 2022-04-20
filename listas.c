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
    // contar elementos
    int cont = 0;
    nodo *recorre = raiz;
    while (recorre != NULL)
    {
        cont++;
        recorre = recorre->sig;
    }
    printf("Elementos: %i\n", cont);

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
    else if (n > cont)
    { // lista no vacia. posicion a insertar mayor a cont
        nodo *recorre = raiz;
        while (recorre->sig != NULL)
            recorre = recorre->sig;
        recorre->sig = nuevo;
    }
    else if (n <= cont){
        // lista no vacia. posicion a insertar menor a cont
        nodo *recorre = raiz;
        int cont2 = 0;
        while (recorre->sig != NULL){
            cont2++;
            if (cont == n){
                // still working
            }
            recorre = recorre->sig;
        }
        recorre->sig = nuevo;
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
    insertN('X', 6);

    imprimeLista();
    return 0;
}