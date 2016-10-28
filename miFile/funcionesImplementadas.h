//
// Created by cesar on 10/23/16.
//

#ifndef FUNCIONESIMPLEMENTADASINCLUDED
#define FUNCIONESIMPLEMENTADASINCLUDED

#include <time.h>
#include "miFile.h"

void seleccionaPivotesAleatorio(Obj* pivotes, int nPivotes, int np){

    int i;

    int pivotes2[] = {18,4,1,3,13}; //los hago constantes para las pruebas

    srand( time( NULL ) );

    for(i = 0; i < nPivotes; i++){
        pivotes[i] = pivotes2[i];//rand()% np + 1;
    }

}


void muestraPivotes(Obj* pivotes, int n){

    int i;

    for(i = 0; i < n; i++){
        printf("pivote [%d] : %d \n", i, pivotes[i]);
    }
}


void construyeTablaDistancias(Tdist** tablaTemporal, int columnas, int filas, Obj* pivotes){  //colummnas = nPivotes  // filas = np

    int i;
    int j;

    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            tablaTemporal[i][j] = distance(i,pivotes[j]);
        }
    }

   // muestraTablaflotante(tablaTemporal, columnas, filas);

}


void muestraTablaflotante(Tdist** tabla, int columnas, int filas){

    int i;
    int j;

    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            printf("  %f", tabla[i][j]);
        }
        printf("  [%d]\n",i);
    }
}


void copiaArregloTemporal(Tdist** tabla, int filaCopiar, int columnas, arregloTemporal* temporal){

    int i;

    for(i = 0; i < columnas; i++){
        temporal[i].distancia = tabla[filaCopiar][i];
        temporal[i].indice = i;
    }
}


void muestraArregloTemporal(arregloTemporal* temporal, int n){

    int i;

    for(i = 0; i < n; i++){
        printf(" %f %d\n", temporal[i].distancia, temporal[i].indice);
    }

}


int cmpFloat(const void *a, const void *b){

    arregloTemporal *x = (arregloTemporal *) a;
    arregloTemporal *y = (arregloTemporal *) b;

    if((*x).distancia > (*y).distancia){
        return 1;
    }else{
        if((*x).distancia < (*y).distancia){
            return -1;
        }else{
            return 0;
        }
    }

}


void guardaInversa(arregloTemporal* temporal, int** tabla, int fila, int columna){

    int i;

    for(i = 0; i < columna; i++){
        tabla[fila][temporal[i].indice] = i;
    }

}


void muestraTablaEntera(int** tabla, int filas, int columnas){

    int i;
    int j;

    printf("\n");
    for( i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            printf("%d ", tabla[i][j]);
        }
        printf("[%d]\n", i);
    }
    printf("\n");
}

void inicializaLista(Lista* lista){

    /*int i = 0;
    for(i = 0; i < n; i++ ){
        lista[i].fin = NULL;
        lista[i].inicio = NULL;
    }*/

    lista->inicio = NULL;
    lista->fin = NULL;

}

Nodo* creaNodo(Obj o, int pivotePosicionCercania){

    Nodo* nuevoNodo;
    nuevoNodo = (Nodo *)malloc(sizeof( Nodo ));

    nuevoNodo->o = o;
    nuevoNodo->pivotePosicionCercania = pivotePosicionCercania;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

void insertaNodoLista(Lista* lista, Nodo* nodo){

    if(lista->inicio == NULL){
        lista->inicio = nodo;
        lista->fin = nodo;
    }else{
        lista->fin->siguiente = nodo;
        lista->fin = nodo;
    }

}

void muestraLista(Lista* lista){

    Nodo* aux = lista->inicio;

    while(aux != NULL){
        printf("(%d,%d)", aux->o, aux->pivotePosicionCercania);
        aux = aux->siguiente;
        if(aux != NULL)
            printf("->");
    }
    printf("\n");
}

/*
int eliminaNodo(lista *listaModificar, nodo nodoEliminar){

    int x = 0;
    nodo borrarNodo = NULL;

    if(nodoEliminar != NULL){
        if(nodoEliminar->siguiente != NULL){
            borrarNodo = nodoEliminar->siguiente;
            nodoEliminar->siguiente = borrarNodo->siguiente;
        }
    }else{
        if(*listaModificar != NULL){
            borrarNodo = *listaModificar;
            *listaModificar = borrarNodo->siguiente;
        }
    }

    if(borrarNodo != NULL){
        x = borrarNodo->pivotePosicionCercania; //solo se regresa la posicion, falta regresar el objeto
        free(borrarNodo);
    }else{
        printf("No se pudo borrar el elemento\n");
    }

    return x;
}*/

#endif