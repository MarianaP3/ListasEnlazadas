#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    int dato;
    struct nodo *sig;
}TNodo;
TNodo *CreaNodo(int Dato);
void imprimir_lista(TNodo *cab);
void libera_lista(TNodo *cab);
void insertar_al_inicio(TNodo **cab, int dato);
void eliminar_al_inicio(TNodo **cab);
void eliminar_al_final(TNodo **cab);
void eliminar_en_cualquier_lugar(TNodo **cab, int x);

int main()
{
    printf("Hello world!\n");
    return 0;
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
void imprimir_lista(TNodo *cab){
    TNodo *aux=cab;
    while(aux!=NULL){
        printf("%d\n", cab->dato);
        aux=aux->sig;
    }
}
void libera_lista(TNodo *cab){
    TNodo *aux=cab;
    while(aux!=NULL){
        TNodo *tmp=aux;
        aux=aux->sig;
        free(tmp);
    }
    cab=NULL;
}
void insertar_al_inicio(TNodo **cab, int dato){
    TNodo *nuevo_nodo=CreaNodo(dato);
    nuevo_nodo->sig=*cab;
    *cab=nuevo_nodo;
}
void insertar_al_final(TNodo **cab, int dato){
    TNodo *nuevo_nodo=CreaNodo(dato);
    if(*cab==NULL){
        nuevo_nodo->sig=NULL;
        *cab=nuevo_nodo;
    }
    TNodo *ultimo=*cab;
    while(ultimo->sig!=NULL){
        ultimo=ultimo->sig;
    }
    ultimo->sig=nuevo_nodo;
    nuevo_nodo->sig=NULL;
}
void eliminar_al_inicio(TNodo **cab){
    if(*cab==NULL){
        return;
    }
    TNodo *aux=*cab;
    *cab=(*cab)->sig;
    free(aux);
    return;
}
void eliminar_al_final(TNodo **cab){
    if(*cab==NULL){
        return;
    }
    if((*cab)->sig==NULL){
        free(*cab);
        *cab=NULL;
    }
    TNodo *ultimo, *previo;
    previo=*cab;
    ultimo=(*cab)->sig;
    while(ultimo->sig!=NULL){
        previo=ultimo;
        ultimo=ultimo->sig;
    }
    free(ultimo);
    previo->sig=NULL;
}
void eliminar_en_cualquier_lugar(TNodo **cab, int x){
    if(*cab==NULL){
        return;
    }
    if((*cab)->sig==NULL){
        if((*cab)->dato==x){
            free(*cab);
            *cab=NULL;
            return;
        } else {
            return;
        }
    }
    TNodo *actual, *previo;
    actual=(*cab)->sig;
    previo=*cab;
    while(actual->sig!=NULL){
        if(actual->dato==x){
            TNodo *aux=actual->sig;
            free(actual);
            actual=NULL;
            previo->sig=aux;
            return;
        }
        previo=actual;
        actual=actual->sig;
    }
    return;
}