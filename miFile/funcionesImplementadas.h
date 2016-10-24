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

void construyeTablaDistancias(Tdist** tabla, int columnas, int filas, Obj* pivotes){  //colummnas = nPivotes  // filas = np

    int i;
    int j;

    tabla = (Tdist**) malloc( sizeof( Tdist* ) * filas);
    for(i = 0; i < filas; i++){
        tabla[i] = (Tdist*) malloc( sizeof(Tdist) * columnas);
    }

    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            tabla[i][j] = distance(i,pivotes[j]);
        }
    }

   // muestraTablaflotante(tabla, columnas, filas);

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

#endif

