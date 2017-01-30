//
// Created by cesar on 9/26/16.
//

#include "../../basics.h"
#include "../../index.h"

#ifndef GHS_GHS_H
#define GHS_GHS_H

typedef struct {

    Obj o;
    int distanciaQ;

}consulta;

typedef struct {

    Obj o;
    float distanciaQ;

}consultaReal;

typedef struct {

    Obj po1;
    Obj po2;
    int stx;

}pivotS;

typedef struct{

    Obj po1;
    Obj po2;

}pivot;

typedef struct{

    pivot *pivots;
    unsigned int *sketches;
    unsigned int *sketchesPart2; // 64 bits
    unsigned int *sketchesPart3; // 96 bits
    unsigned int *sketchesPart4; // 128 bits
    unsigned int *sketchesPart5; // 160 bits
    unsigned int *sketchesPart6; // 192 bits
    unsigned int *sketchesPart7; // 224 bits
    unsigned int *sketchesPart8; // 256 bits
    unsigned int *sketchesPart9; // 288 bits
    unsigned int *sketchesPart10; // 320 bits
    int nHiperplanos;
    int *objeto; //tamaño de la muestra seleccionada para S
    char *descr;
    int nBD; //tamaño de la base de datos completa

}ghs;


/*definiciones*/


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

    //srand ( time ( NULL));

    for(i = 0; i < n; i++){
        objetosConsulta[i] = rand() %rango + 1;
    }

}


void muestraObjetosConsulta( Obj* objetosConsulta, int n){

    int i;

    for(i = 0; i < n; i++){
        printf("objeto[%d]: %d \n", i, objetosConsulta[i]);
    }
}


void workload(int kPorcentaje, Obj q, consultaReal* distanciaRealAprox, consulta* distanciaHamming){

    int i;

    for(i = 0; i < kPorcentaje; i++){
        distanciaRealAprox[i].distanciaQ = distance( distanciaHamming[i].o, q);
        distanciaRealAprox[i].o = distanciaHamming[i].o;
    }

}

void calculaDistanciaReal(consultaReal* distanciaReal, int n, Obj q){

    int i;

    Obj u;

    for(i = 0; i < n; i++) {
        u = i + 1;
        distanciaReal[i].distanciaQ = distance(q,u);
        distanciaReal[i].o = u;
    }

}


void calculaCandidatos(consultaReal* distanciaReal, consultaReal* distanciaRealAprox, int* kCandidatosAprox, int* kCandidatosReal , int k){

    int i;

    for(i = 0; i < k; i++){
        kCandidatosAprox[i] = distanciaRealAprox[i].o;
        kCandidatosReal[i] = distanciaReal[i].o;
    }

}


void generaSketch(sketchQ* sQ, Obj u, pivot* pivots, int nHiperPlanos){

    Tdist d1;
    Tdist d2;

    int dimension;
    int posicion = 0;

    unsigned int s = 0;

    for( dimension = 0; dimension < nHiperPlanos; dimension++){

        d1 = distance( u, pivots[dimension].po1 );
        d2 = distance( u, pivots[dimension].po2 );

        if( d1 <= d2 ){

            if (dimension < 32) {
                s ^= (-1 ^ s) & (1 << dimension);
                sQ -> sketches = s;
            }

            if (dimension == 32)//hay que reiniciar
                s = 0;
            if ((dimension >= 32) && (dimension < 64)) {
                posicion = dimension - 32;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart2 = s;
            }

            if (dimension == 64)//hay que reiniciar
                s = 0;
            if ((dimension >= 64) && (dimension < 96)) {
                posicion = dimension - 64;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart3 = s;
            }

            if (dimension == 96)//hay que reiniciar
                s = 0;
            if ((dimension >= 96) && (dimension < 128)) {
                posicion = dimension - 96;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart4 = s;
            }

            if (dimension == 128)//hay que reiniciar
                s = 0;
            if ((dimension >= 128) && (dimension < 160)) {
                posicion = dimension - 128;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart5 = s;
            }

            if (dimension == 160)//hay que reiniciar
                s = 0;
            if ((dimension >= 160) && (dimension < 192)) {
                posicion = dimension - 160;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart6 = s;
            }

            if (dimension == 192)//hay que reiniciar
                s = 0;
            if ((dimension >= 192) && (dimension < 224)) {
                posicion = dimension - 192;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart7 = s;
            }

            if (dimension == 224)//hay que reiniciar
                s = 0;
            if ((dimension >= 224) && (dimension < 256)) {
                posicion = dimension - 224;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart8 = s;
            }

            if (dimension == 256)//hay que reiniciar
                s = 0;
            if ((dimension >= 256) && (dimension < 288)) {
                posicion = dimension - 256;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart9 = s;
            }

            if (dimension == 288)//hay que reiniciar
                s = 0;
            if ((dimension >= 288) && (dimension < 320)) {
                posicion = dimension - 288;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart10 = s;
            }

        }

    }

}



#endif //GHS_GHS_H
