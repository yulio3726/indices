//
// Created by cesar on 3/3/17.
//

#include <time.h>

#ifndef SBEP3_IMPLEMENTACIONES_H
#define SBEP3_IMPLEMENTACIONES_H

void seleccionaPivotesAleatorio(Obj* p, int k, int np){

    int i;

    for(i = 0; i < k; i++){
        p[i] = rand()% np + 1;
    }
}

void calculaDistanciaOP(Obj o, ARRAYTEMPORAL* permutacionI , int nPivotes, Obj* pivotes){
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

void showPivots(Obj** tablaPermutantes, int filas, int columnas){

    int i = 0;
    int j = 0;
    printf("\n\tLOS PIVOTES SON \n");

    for(i=0; i < filas; i++){
        for(j=0; j < columnas; j++){
            printf("%d ", tablaPermutantes[i][j]);
        }
        printf("\n");
    }

}

int hamming(unsigned int a, unsigned int b){

    return ( __builtin_popcount( a ^ b ) );

}
#endif //SBEP3_IMPLEMENTACIONES_H
