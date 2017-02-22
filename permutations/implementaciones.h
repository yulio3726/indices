//
// Created by cesar on 2/16/17.
//

#include <time.h>
#include <math.h>
#include "permutations.h"

#ifndef PERMUTATIONS_IMPLEMENTACIONES_H
#define PERMUTATIONS_IMPLEMENTACIONES_H

void seleccionaPivotesAleatorio(Obj* p, int k, int np){

    int i;

    srand( time( NULL ) );

    for(i = 0; i < k; i++){
        p[i] = rand() %np + 1;
    }
}

void muestraPivotes(Obj* pivotes, int n){
    int i;

    for(i = 0; i < n; i++){
        printf(" [%d] %d ", i, pivotes[i]);
    }
    printf("\n");
}

void calculaDistanciaReferenciasConsulta(Obj o, ARRAYTEMPORAL* permutacionI , int nPivotes, Obj* pivotes){
    int i;

    for(i = 0; i < nPivotes; i++){
        permutacionI[i].distancia = distance(o, pivotes[i]);
        permutacionI[i].indice = i;
    }

}

int cmpFloat(const void *a, const void *b){

    ARRAYTEMPORAL *x = (ARRAYTEMPORAL *) a;
    ARRAYTEMPORAL *y = (ARRAYTEMPORAL *) b;

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

void guardaInversaI(ARRAYTEMPORAL* permutacionI, int* permutacionIInvertida, int n){

    int i;

    for(i = 0; i < n; i++){
        permutacionIInvertida[permutacionI[i].indice] = i;
    }

}

void muestraArregloEntero(int* arreglo, int n){

    int i;

    for(i = 0; i < n; i++){
        printf(" %d\n", arreglo[i]);
    }

    printf("\n");
}

void iniciaSumaRecall(float* sumaRecall, int n){

    int i;
    for(i = 0; i < n; i++){
        sumaRecall[i]=0;
    }

}

/*void generaPermutacion(ARRAYTEMPORAL* permutacionQ, int* permutacionQInvertida  Obj u, Obj* pivotes, int nPivotes){

    int posicion = 0;
    int distancia;

    calculaDistanciaReferenciasConsulta(u, permutacionQ, nPivotes, pivotes);
    qsort(permutacionQ, nPivotes, sizeof(ARRAYTEMPORAL), cmpFloat);
    guardaInversaI(permutacionQ, permutacionQInvertida, nPivotes);
    //printf("\tLa permutacion inversa de l consulta %d\n",u);
    //muestraArregloEntero(permutacionQInvertida, nPivotes);
    // printf("\tEl sckecht del objeto consulta %d\n", u);
    //

}*/

int cmpfuncFloat(const void *a, const void *b){

    const CONSULTAREAL *c1 = (CONSULTAREAL *) a;
    const CONSULTAREAL *c2 = (CONSULTAREAL *) b;

    if (c1 -> distanciaQ < c2 -> distanciaQ) return -1;
    else if (c1 -> distanciaQ > c2 -> distanciaQ) return 1;

    return 0;

}

void calculaDistanciaReal(CONSULTAREAL* distanciaReal, int n, Obj q){

    int i;

    Obj u;

    for(i = 0; i < n; i++) {
        u = i + 1;
        distanciaReal[i].distanciaQ = distance(q,u);
        distanciaReal[i].o = u;
    }

}

int spearmanRho(int* permutacionInvertida1, Obj* permutacionInvertida2, int n){ //obj porque el de la tabla es de este tipo

    float dist = 0;
    int sum = 0;
    int i = 0;

    for(i = 0; i < n; i++){
        sum = sum + pow( abs(permutacionInvertida1[i]-permutacionInvertida2[i]), 2);
    }

    //printf("%d\n", sum);
    //dist = sqrt(sum);

    return sum;
}

int cmpfunc(const void *a, const void *b){

    const CONSULTA *c1 = (CONSULTA *) a;
    const CONSULTA *c2 = (CONSULTA *) b;

    return ( c1 -> distanciaQ - c2 -> distanciaQ);
}

void workload(int kPorcentaje, Obj q, CONSULTAREAL* distanciaRealAprox, CONSULTAREAL* distanciaSpearmanRho){

    int i;

    for(i = 0; i < kPorcentaje; i++){
        distanciaRealAprox[i].distanciaQ = distance( distanciaSpearmanRho[i].o, q);
        distanciaRealAprox[i].o = distanciaSpearmanRho[i].o;
    }

}

void calculaCandidatos(CONSULTAREAL* distanciaReal, CONSULTAREAL* distanciaRealAprox, int* kCandidatosAprox, int* kCandidatosReal , int k){

    int i;

    for(i = 0; i < k; i++){
        kCandidatosAprox[i] = distanciaRealAprox[i].o;
        kCandidatosReal[i] = distanciaReal[i].o;
    }

}

int compara(const void *x, const void *y){

    return( *( int* )x - *( int* )y);
}

void muestraPermutacion(ARRAYTEMPORAL* permutacion, int n){
    int i;
    printf("La permutacion es::\n");
    for(i = 0; i < n; i++){
        printf(" %d ", permutacion[i].indice);
    }
    printf("\n");
}

void muestraInversa(int* inversa, int n){
    int i;
    printf("La permutacion inversa es ::\n");
    for(i = 0; i < n; i++){
        printf(" %d ", inversa[i]);
    }
    printf("\n");
}

void muestraCandidatos(int* kCandidatosAprox, int* kCandidatosReal, int k){

    int i;

    for(i = 0; i < k; i++){

        printf("[%d]  Aprox: %d Real: %d\n",i ,kCandidatosAprox[i], kCandidatosReal[i]);

    }
}

#endif //PERMUTATIONS_IMPLEMENTACIONES_H
