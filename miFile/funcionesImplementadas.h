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
            tablaTemporal[i][j] = distance(i+1,pivotes[j]);
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
        printf("  [%d]\n",i+1);
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


void seleccionaObjetosPrueba(Obj* objetosPrueba, int cantidad, int intervalo){
    int i;

    srand(time(NULL));

    printf("\nLos objetos seleccionados para las pruebas son:\n");
    for(i = 0; i < cantidad; i++){
        objetosPrueba[i] = rand() %intervalo + 1;
        printf("%d ", objetosPrueba[i]);
    }

    objetosPrueba[0] = 17; //para fijarlo y usarlo en las pruebas a mano

}

void calculaDistanciaReferenciasConsulta(Obj q, arregloTemporal* temporal, int nPivotes, Obj* pivotes){
    int i;

    for(i = 0; i < nPivotes; i++){
        temporal[i].distancia = distance(q, pivotes[i]);
        temporal[i].indice = i;
    }

}

void guardaInversaQ(arregloTemporal* temporal, int* dominioTransformadoQ, int columna){

    int i;

    for(i = 0; i < columna; i++){
        dominioTransformadoQ[temporal[i].indice] = i;
    }

}

void muestraDominioTransformadoQ(int* dominioTransformadoQ, int n){
    int i;

    for(i = 0; i < n; i++){
        printf(" %d", dominioTransformadoQ[i]);
    }
    printf("\n");
}

float kNN(miFile* I, int k, int porcentaje, int* dominioTransdormadoQ, Obj q);


void inicializaDistanciasAprox(arregloTemporal* distanciasAprox, int n){

    int i;

    for(i = 0; i < n; i++){
        distanciasAprox[i].distancia = 0;
        distanciasAprox[i].indice = i + 1; //este es el objeto por eso le sumo uno a la variable indice
    }

}

int cmpEntero(const void *a, const void *b){

    const arregloTemporal *c1 = (arregloTemporal *) a;
    const arregloTemporal *c2 = (arregloTemporal *) b;

    return ( c1 -> distancia - c2 -> distancia);
}

int cmpObjEntero(const void *a, const void *b){

     int *o1 = *((int *) a);
     int *o2 = *((int *) b);

    if(o1 > o2) return 1;
    if(o1 < o2) return -1;
    return 0;
}


void reRanking(int porcentaje, Obj q, arregloTemporal* distanciaRealObjetoConsultaAprox, arregloTemporal* distanciaObjetoConsultaAprox){

    int i;

    for(i = 0; i < porcentaje; i++){
        distanciaRealObjetoConsultaAprox[i].distancia = distance(distanciaObjetoConsultaAprox[i].indice, q);
        distanciaRealObjetoConsultaAprox[i].indice = distanciaObjetoConsultaAprox[i].indice;
    }

}

void calculaDistanciaReal(arregloTemporal* distanciaObjetoConsultaReal, int n, Obj q){

    int i;

    for(i = 0; i < n; i++){
        distanciaObjetoConsultaReal[i].distancia = distance(i+1, q);
        distanciaObjetoConsultaReal[i].indice = i+1;
    }
}

void calculaCandidatos(arregloTemporal* distanciaObjetoConsultaReal,arregloTemporal* distanciaRealObjetoConsultaAprox, Obj* knnReal, Obj* knnAproximado, int k){

    int i;

    for(i = 0; i < k; i++){
        knnReal[i] = distanciaObjetoConsultaReal[i].indice;
        knnAproximado[i] = distanciaRealObjetoConsultaAprox[i].indice;
    }

}


void muestraArregloEntero(int* arreglo, int n){

    int i;

    for(i = 0; i < n; i++){
        printf("\t %d\n", arreglo[i]);
    }

    printf("\n");
}

void guardaInversaQReal(arregloTemporal* temporal, int* dominioTransformadoQ, int columna){

    int i;

    for(i = 0; i < columna; i++){
        dominioTransformadoQ[temporal[i].indice-1] = i + 1;
    }

}

float calculaErrorDePosicion(int* knnAprox, int* inversaQReal, int k, int nDB){

    float errorDePosicion = 0;
    int sumatoria = 0;
    int i = 0;
    int posOT;
    int posOS;
    int o;

    for(i = 0; i < k; i++){
        posOS = i + 1;
        o = knnAprox[i];
        posOT = inversaQReal[o - 1];
        //printf("el objeto %d esta aproximada en la posicion %d pero se encuentra exactamente en la posicion %d \n", o, posOS, posOT);
        sumatoria = sumatoria + abs(posOT - posOS);
    }

    printf("sumatoria %d k: %d nBD %d\n", sumatoria, k, nDB);
    printf("sumatoria/k %f\n", (float)sumatoria/k );
    printf("1/k: %f\n", (float)1/nDB);

    errorDePosicion = ((float)sumatoria / (float)k) * ((float)1/(float)nDB);
    printf("error : %f\n", errorDePosicion);

    return errorDePosicion;
}
#endif