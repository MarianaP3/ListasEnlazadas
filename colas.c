#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ERROR_PILA_VACIA -1
typedef struct nodo{
    int dato;
    struct nodo *sig;
}TNodo;
typedef struct cola{
    TNodo *ini;
    TNodo *fin;
}TCola;
void inicializar_cola(TCola *Cola);
bool esta_vacia(TCola *Cola);
void encolar(TCola *Cola, int dato);
TNodo *CreaNodo(int Dato);
void desencolar(TCola *Cola);
void vaciar(TCola *Cola);

int main(){
    printf("Hello World\n");
}

void inicializar_cola(TCola *Cola){
    Cola->ini=NULL;
    Cola->fin=NULL;
}
bool esta_vacia(TCola *Cola){
    return(Cola->ini==NULL && Cola->fin==NULL);
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
void encolar(TCola *Cola, int dato){
    if(esta_vacia(Cola)){
        TNodo *nuevo=CreaNodo(dato);
        Cola->ini=Cola->fin=nuevo;
        nuevo->sig=NULL;
        return;
    }
    TNodo *nuevo=CreaNodo(dato);
    Cola->fin->sig=nuevo;
    Cola->fin=nuevo;
    nuevo->sig=NULL;
}
void desencolar(TCola *Cola){
    if(esta_vacia(Cola)){
        return;
    }
    TNodo *aux=Cola->ini;
    Cola->ini=(Cola->ini)->sig;
    free(aux);
    return;
}
void vaciar(TCola *Cola){
    while(!esta_vacia(Cola)){
        desencolar(Cola);
    }
    return;
}