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
TNodo *CreaNodo(int Dato);
void inicializar(TConjunto *Conj);
bool agregar(TConjunto **Conj, int dato);
bool eliminar(TConjunto *Conj, int dato);
bool existe(TConjunto *Conj, int dato);
size_t cardinalidad(TConjunto *Conj);

int main(){
    printf("Hello World\n");
}

TNodo *CreaNodo(int Dato){
    TNodo *nodo=(TNodo*)malloc(sizeof(TNodo));
    if(nodo==NULL){
        printf("Error de memoria\n");
        exit(EXIT_FAILURE);
    }
    nodo->dato=Dato;
    nodo->sig=NULL;
    return nodo;
}
void inicializar(TConjunto *Conj){
    Conj->cab=NULL;
}
bool agregar(TConjunto **Conj, int dato){
    TNodo *nuevo_nodo=CreaNodo(dato);
    if((*Conj)->cab==NULL){
        (*Conj)->cab=nuevo_nodo;
        nuevo_nodo=NULL;
        (*Conj)->tam=((*Conj)->tam)+1;
        return true;
    }
    if((((*Conj)->cab)->dato)>dato){//agrega al inicio
        nuevo_nodo->sig=(*Conj)->cab;
        (*Conj)->cab=nuevo_nodo;
        ((*Conj)->tam)++;
    }
    TNodo *previo=(*Conj)->cab;
    TNodo *ultimo=(*Conj)->cab->sig;
    while(ultimo->sig!=NULL){
        if(dato<ultimo->sig->dato){
            penultimo=nuevo_nodo;
            nuevo_nodo=ultimo;
        }
    }
}