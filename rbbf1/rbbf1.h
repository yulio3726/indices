//
// Created by cesar on 21/09/16.
//

#include "../../basics.h"
#include "../../index.h"

/*Estructuras*/

typedef struct {

    Obj o; //tenia tipo Obj
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

    pivot *pivots; //arreglo de los pivotes
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

}rbbf1;

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

void generaSketch(sketchQ* sQ, Obj u, pivot* pivots, int nHiperPlanos) {

    Tdist d1;
    Tdist d2;

    int dimension;
    int posicion = 0;

    unsigned int s = 0;


    for (dimension = 0; dimension < nHiperPlanos; dimension++) {

        d1 = distance(u, pivots[dimension].po1);
        d2 = distance(u, pivots[dimension].po2);

        if (d1 <= d2) {

            if (dimension < 32) {
                s ^= (-1 ^ s) & (1 << dimension);
                sQ->sketches = s;
            }

            if (dimension == 32)//hay que reiniciar
                s = 0;
            if ((dimension >= 32) && (dimension < 64)) {
                posicion = dimension - 32;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart2 = s;
            }

            if (dimension == 64)//hay que reiniciar
                s = 0;
            if ((dimension >= 64) && (dimension < 96)) {
                posicion = dimension - 64;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart3 = s;
            }

            if (dimension == 96)//hay que reiniciar
                s = 0;
            if ((dimension >= 96) && (dimension < 128)) {
                posicion = dimension - 96;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart4 = s;
            }

            if (dimension == 128)//hay que reiniciar
                s = 0;
            if ((dimension >= 128) && (dimension < 160)) {
                posicion = dimension - 128;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart5 = s;
            }

            if (dimension == 160)//hay que reiniciar
                s = 0;
            if ((dimension >= 160) && (dimension < 192)) {
                posicion = dimension - 160;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart6 = s;
            }

            if (dimension == 192)//hay que reiniciar
                s = 0;
            if ((dimension >= 192) && (dimension < 224)) {
                posicion = dimension - 192;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart7 = s;
            }

            if (dimension == 224)//hay que reiniciar
                s = 0;
            if ((dimension >= 224) && (dimension < 256)) {
                posicion = dimension - 224;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart8 = s;
            }

            if (dimension == 256)//hay que reiniciar
                s = 0;
            if ((dimension >= 256) && (dimension < 288)) {
                posicion = dimension - 256;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart9 = s;
            }

            if (dimension == 288)//hay que reiniciar
                s = 0;
            if ((dimension >= 288) && (dimension < 320)) {
                posicion = dimension - 288;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart10 = s;
            }

        }
    }
}


void muestraArregloEntero(consulta* distanciaUQ, int nBaseDatos){

    int i;

    for(i = 0; i < nBaseDatos ; i++){
        printf("[%d]  distancia: %d  objeto: %d\n", i, distanciaUQ[i].distanciaQ, distanciaUQ[i].o);
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


void muestraArregloFlotante(consultaReal* distanciaReal, int n){

    int i;

    for(i = 0; i < n; i++){
        printf("[%d]  distancia: %f  objeto: %d\n", i, distanciaReal[i].distanciaQ, distanciaReal[i].o);
    }

}


void calculaCandidatos(consultaReal* distanciaReal, consultaReal* distanciaRealAprox, int* kCandidatosAprox, int* kCandidatosReal , int k){

    int i;

    for(i = 0; i < k; i++){
        // printf("i [%d] aprox %d real %d\n",i, distanciaHamming[i].o,distanciaReal[i].o);
        kCandidatosAprox[i] = distanciaRealAprox[i].o;
        kCandidatosReal[i] = distanciaReal[i].o;
        //printf("i [%d] aprox %d real %d\n\n",i, kCandidatosAprox[i], kCandidatosReales[i]);
    }

}


void muestraCandidatos(int* kCandidatosAprox, int* kCandidatosReal, int k){

    int i;

    for(i = 0; i < k; i++){

        printf("[%d]  Aprox: %d Real: %d\n",i ,kCandidatosAprox[i], kCandidatosReal[i]);

    }
}


void workload(int kPorcentaje, Obj q, consultaReal* distanciaRealAprox, consulta* distanciaHamming){

    int i;

    for(i = 0; i < kPorcentaje; i++){
        distanciaRealAprox[i].distanciaQ = distance( distanciaHamming[i].o, q);
        distanciaRealAprox[i].o = distanciaHamming[i].o;
    }

}


void muestraSketch(unsigned int s){

    //printf(" lo que quiero mostrar tiene el tañamo de: %d", sizeof(s));
    int g = 0;
    for( g ; g < sizeof(s)*8; g++){
        printf( "%u", ( s >> g) & 1 );
    }

    printf("\n");

}


void muestraPivotes(rbbf1* N){

    int i = 0;

    printf("Los pivotes son: \n\n");

    for(i; i < N -> nHiperPlanos; i++){
        printf("%i po1: %d ", i, N -> pivots[i].po1);
        printf( "po2: %d", N -> pivots[i].po2);
    }

}

void seleccionaPivotes(rbbf1* N){

    int i;
    srand( time( NULL ) );

    for(i = 0; i < N -> nHiperPlanos; i++){
        N -> pivots[i].po1 = rand() %N -> nBaseDatos + 1;
        N -> pivots[i].po2 = rand() %N -> nBaseDatos +1;
    }

}

/*void inicializaRecallPorcentaje(float* recallPorcentaje, int nPorcentajes){

    int i = 0;

    for(i = 0; i < nPorcentajes; i++){
        recallPorcentaje[i] = 0;
    }
}*/