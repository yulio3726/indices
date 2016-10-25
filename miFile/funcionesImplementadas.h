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
        printf("\n");
    }
    printf("\n");
}
#endif

