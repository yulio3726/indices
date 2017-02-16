//
// Created by cesar on 2/16/17.
//

#include <time.h>

#ifndef SBEP2_IMPLEMENTACIONES_H
#define SBEP2_IMPLEMENTACIONES_H

void seleccionaPivotesAleatorio(Obj* p, int k, int np){

    int i;

    srand( time( NULL ) );

    for(i = 0; i < k; i++){
        p[i] = rand()% np + 1;
    }
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

void iniciaSumaRecall(float* sumaRecall, int n){

    int i;
    for(i = 0; i < n; i++){
        sumaRecall[i]=0;
    }

}

void generaConsultas(Obj* objetosConsulta, int n, int rango){

    int i;

    //srand ( time ( NULL));

    for(i = 0; i < n; i++){
        objetosConsulta[i] = rand() %rango + 1;
    }

}

void generaSketch(SKETCHQ* sQ, Obj u, Obj* pivotes, int nPivotes, int m){

    int dimension = 0;
    int posicion = 0;

    ARRAYTEMPORAL* permutacionQ;
    int* permutacionQInvertida;

    unsigned int s = 0;

    permutacionQ  = (ARRAYTEMPORAL*)malloc(sizeof(ARRAYTEMPORAL)* nPivotes);
    permutacionQInvertida = (int*)malloc(sizeof(int) * nPivotes);
    calculaDistanciaReferenciasConsulta(u, permutacionQ, nPivotes, pivotes);
    qsort(permutacionQ, nPivotes, sizeof(ARRAYTEMPORAL), cmpFloat);
    guardaInversaI(permutacionQ, permutacionQInvertida, nPivotes);

    for( dimension = 0; dimension < nPivotes; dimension++){
        // bit = 0;
        if( permutacionQInvertida[dimension] <= m ){
            // bit = 1;

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

            }
        }
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

int cmpfuncFloat(const void *a, const void *b){

    const CONSULTAREAL*c1 = (CONSULTAREAL *) a;
    const CONSULTAREAL *c2 = (CONSULTAREAL *) b;

    if (c1 -> distanciaQ < c2 -> distanciaQ) return -1;
    else if (c1 -> distanciaQ > c2 -> distanciaQ) return 1;

    return 0;

}

int hamming(unsigned int a, unsigned int b){

    return ( __builtin_popcount( a ^ b ) );

}

int cmpfunc(const void *a, const void *b){

    const CONSULTA *c1 = (CONSULTA *) a;
    const CONSULTA *c2 = (CONSULTA *) b;

    return ( c1 -> distanciaQ - c2 -> distanciaQ);
}

void workload(int kPorcentaje, Obj q, CONSULTAREAL* distanciaRealAprox, CONSULTA* distanciaHamming){

    int i;

    for(i = 0; i < kPorcentaje; i++){
        distanciaRealAprox[i].distanciaQ = distance( distanciaHamming[i].o, q);
        distanciaRealAprox[i].o = distanciaHamming[i].o;
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

#endif //SBEP2_IMPLEMENTACIONES_H
