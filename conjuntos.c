#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ERROR_PILA_VACIA -1
typedef struct nodo{
    int dato;
    struct nodo *sig;
}TNodo;
typedef struct conjunto{
    TNodo *cab;
    unsigned int tam;
}TConjunto;
void inicializar(TConjunto *Conj);
bool agregar(TConjunto *Conj, int dato);
bool eliminar(TConjunto *Conj, int dato);
bool existe(TConjunto *Conj, int dato);
size_t cardinalidad(TConjunto *Conj);

int main(){
    printf("Hello World\n");
}