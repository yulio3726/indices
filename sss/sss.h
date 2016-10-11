//
// Created by cesar on 9/28/16.
//

#include "../../basics.h"
#include "../../index.h"

#ifndef SSSS_SSSS_H
#define SSSS_SSSS_H

/*Estructuras*/

typedef struct {

    Obj o;
    int distanciaQ;

}consulta;

typedef struct {

    Obj o;
    float distanciaQ;

}consultaReal;

typedef struct{

    Obj po1; //pivote 1
    Obj po2; //pivote 2

} pivot;

typedef struct{

    pivot *pivots; //arreglo de los parres de pivotes
    unsigned int *sketches; //arreglo de los sketches el unsigned int tiene 4 bytes de tamaño por lo que tiene 32 bits
    unsigned int *sketchesPart2; // 64 bits
    unsigned int *sketchesPart3; // 96 bits
    unsigned int *sketchesPart4; // 128 bits
    unsigned int *sketchesPart5; // 160 bits
    unsigned int *sketchesPart6; // 192 bits
    unsigned int *sketchesPart7; // 224 bits
    unsigned int *sketchesPart8; // 256 bits
    unsigned int *sketchesPart9; // 288 bits
    unsigned int *sketchesPart10; // 320 bits
    int nHiperPlanos; //numero de hiperplanos, longitud del sketch
    char *descr; // nombre de la BD
    int nBaseDatos; //tamaño de la base de datos

}ssss;

typedef struct{

    unsigned int sketches;      // 32 bits
    unsigned int sketchesPart2; // 64 bits
    unsigned int sketchesPart3; // 96 bits
    unsigned int sketchesPart4; // 128 bits
    unsigned int sketchesPart5; // 160 bits
    unsigned int sketchesPart6; // 192 bits
    unsigned int sketchesPart7; // 224 bits
    unsigned int sketchesPart8; // 256 bits
    unsigned int sketchesPart9; // 288 bits
    unsigned int sketchesPart10; // 320 bits

}sketchQ;

/*definiciones*/
float kNN(ssss* S, int k, int porcentaje, Obj q);

/* Funciones */

int cmpfunc(const void *a, const void *b){

    const consulta *c1 = (consulta *) a;
    const consulta *c2 = (consulta *) b;

    return ( c1 -> distanciaQ - c2 -> distanciaQ);
}


int cmpfuncFloat(const void *a, const void *b){

    const consultaReal *c1 = (consultaReal *) a;
    const consultaReal *c2 = (consultaReal *) b;

    if (c1 -> distanciaQ < c2 -> distanciaQ) return -1;
    else if (c1 -> distanciaQ > c2 -> distanciaQ) return 1;

    return 0;

}


int compara(const void *x, const void *y){

    return( *( int* )x - *( int* )y);

}

void generaConsultas(Obj* objetosConsulta, int n, int rango){

    int i;

    srand ( time ( NULL));

    for(i = 0; i < n; i++){
        objetosConsulta[i] = rand() %rango +1;
    }

}

void muestraObjetosConsulta( Obj* objetosConsulta, int n){

    int i;

    for(i = 0; i < n; i++){
        printf("objeto[%d]: %d \n", i, objetosConsulta[i]);
    }
}


#endif //SSSS_SSSS_H
