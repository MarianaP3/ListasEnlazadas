#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ERROR_PILA_VACIA -1
typedef struct nodo{
    int dato;
    struct nodo *sig;
}TNodo;
typedef struct pila{
    TNodo *tope;
}TPila;
void inicializa_pila(TPila *Pila);
bool esta_vacia(TPila *Pila);
TNodo *CreaNodo(int Dato);
void push(TPila *Pila, int dato);
int pop(TPila *Pila);
void limpiar_pila(TPila *Pila);
void imprimir_pila(TPila *Pila);

int main(){
    printf("Hello World\n");
}

void inicializa_pila(TPila *Pila){
    Pila->tope=NULL;
}
bool esta_vacia(TPila *Pila){
    return(Pila->tope==NULL);
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
void push(TPila *Pila, int dato){
    TNodo *nuevo=CreaNodo(dato);
    nuevo->sig=Pila->tope;
    Pila->tope=nuevo;
}
int pop(TPila *Pila){
    if(esta_vacia(Pila)){
        return ERROR_PILA_VACIA;
    }
    int dato=Pila->tope->dato;
    TNodo *aux=Pila->tope;
    Pila->tope=Pila->tope->sig;
    free(aux);
    return dato;
}
void limpiar_pila(TPila *Pila){
    while(!esta_vacia){
        pop(Pila);
    }
}
void imprimir_pila(TPila *Pila){
    TNodo *aux=Pila;
    while(aux!=NULL){
        printf("%d\n", Pila->dato);
        aux=aux->sig;
    }
}