//
// Created by cesar on 9/26/16.
//

#include "ghs.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>


Index build(char *dbname, int n, int *argc, char ***argv){

    if(*argc < 1){
        fprintf(stderr, "Usage: <program> <args> ARITY\n");
        exit(1);
    }

    ghs *S;
    
    int i;
    int dimension;
    int l = 2000; //es la muestra que se selecciona para saber como divide el espacio
    int nVeces = 400;//Por
    int k = 10;
    int posicion;
    int nObjetoConsulta = 100;
    int porcentaje[] = { 1, 3, 5, 7, 9};
    int nPorcentaje = 5;
    int j;

    Obj *objetosConsulta;
    Obj u;

    Tdist d1;
    Tdist d2;

    float recall;
    float sumaRecall;

    S = ( ghs* )malloc( sizeof(ghs));
    S -> descr = (char*) malloc( strlen (dbname) + 1 );
    strcpy( S -> descr, dbname);
    S -> nBD = openDB( S -> descr );
    S -> objeto = ( int* ) malloc( sizeof( int* ) * l);

    if( n && ( n < S -> nBD ) ) S -> nBD = n;

    S -> nHiperplanos = atoi( ( *argv[0] ) ); ( * argc ) --; ( *argv)++;
    S -> pivots = (pivot*) malloc( sizeof ( pivot ) * S -> nHiperplanos);
    S -> sketches = (unsigned int*)malloc( sizeof ( unsigned int ) * S -> nBD);

    seleccionaObjetosS( S, l);

    if (S -> nHiperplanos > 32)
        S -> sketchesPart2 = malloc(sizeof(unsigned int) * S -> nBD);

    if ((S -> nHiperplanos > 64))
        S -> sketchesPart3 = malloc(sizeof(unsigned int) * S -> nBD);

    if ((S -> nHiperplanos > 96)) {
        S -> sketchesPart4 = malloc(sizeof(unsigned int) * S -> nBD);
    }

    if ((S -> nHiperplanos > 128)) {
        S -> sketchesPart5 = malloc(sizeof(unsigned int) * S -> nBD);
    }

    if ((S -> nHiperplanos > 160)) {
        S -> sketchesPart6 = malloc(sizeof(unsigned int) * S -> nBD);
    }

    if ((S -> nHiperplanos > 192)) {
        S -> sketchesPart7 = malloc(sizeof(unsigned int) * S -> nBD);
    }

    if ((S -> nHiperplanos > 224)) {
        S -> sketchesPart8 = malloc(sizeof(unsigned int) * S -> nBD);
    }

    if ((S -> nHiperplanos > 256)) {
        S -> sketchesPart9 = malloc(sizeof(unsigned int) * S -> nBD);
    }

    if ((S -> nHiperplanos > 288)) {
        S -> sketchesPart10 = malloc(sizeof(unsigned int) * S -> nBD);
    }

    seleccionaPivotes( S, nVeces, l);

    i = 0;
    posicion = 0;

    while(i < S  -> nBD){

        i++;
        u = i;

        S -> sketches[u] = 0;
        if (S -> nHiperplanos > 32)
            S -> sketchesPart2[u] = 0;
        if (S -> nHiperplanos > 64)
            S -> sketchesPart3[u] = 0;
        if (S -> nHiperplanos > 96)
            S -> sketchesPart4[u] = 0;
        if (S -> nHiperplanos > 128)
            S -> sketchesPart5[u] = 0;
        if (S -> nHiperplanos > 160)
            S -> sketchesPart6[u] = 0;
        if (S -> nHiperplanos > 192)
            S -> sketchesPart7[u] = 0;
        if (S -> nHiperplanos > 224)
            S -> sketchesPart8[u] = 0;
        if (S -> nHiperplanos > 256)
            S -> sketchesPart9[u] = 0;
        if (S -> nHiperplanos > 288)
            S -> sketchesPart10[u] = 0;


        for( dimension = 0; dimension < S -> nHiperplanos; dimension++){
            d1 = distance(u, S -> pivots[dimension].po1);
            d2 = distance(u, S -> pivots[dimension].po2);

            if( d1 <= d2 ){

                if (dimension < 32) {
                    S -> sketches[i - 1] ^= (-1 ^ S -> sketches[i - 1]) & (1 << dimension);
                }

                if ((dimension >= 32) && (dimension < 64)) {
                    posicion = dimension - 32;
                    S -> sketchesPart2[i - 1] ^= (-1 ^ S -> sketchesPart2[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 64) && (dimension < 96)) {
                    posicion = dimension - 64;
                    S -> sketchesPart3[i - 1] ^= (-1 ^ S -> sketchesPart3[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 96) && (dimension < 128)) {
                    posicion = dimension - 96;
                    S -> sketchesPart4[i - 1] ^= (-1 ^ S -> sketchesPart4[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 128) && (dimension < 160)) {
                    posicion = dimension - 128;
                    S -> sketchesPart5[i - 1] ^= (-1 ^ S -> sketchesPart5[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 160) && (dimension < 192)) {
                    posicion = dimension - 160;
                    S -> sketchesPart6[i - 1] ^= (-1 ^ S -> sketchesPart6[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 192) && (dimension < 224)) {
                    posicion = dimension - 192;
                    S -> sketchesPart7[i - 1] ^= (-1 ^ S -> sketchesPart7[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 224) && (dimension < 256)) {
                    posicion = dimension - 224;
                    S -> sketchesPart8[i - 1] ^= (-1 ^ S -> sketchesPart8[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 256) && (dimension < 288)) {
                    posicion = dimension - 256;
                    S -> sketchesPart9[i - 1] ^= (-1 ^ S -> sketchesPart9[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 288) && (dimension < 320)) {
                    posicion = dimension - 288;
                    S -> sketchesPart10[i - 1] ^= (-1 ^ S -> sketchesPart10[i - 1]) & (1 << posicion);

                }

            }
        }

    }

    objetosConsulta = (Obj *) malloc( sizeof (Obj) * nObjetoConsulta); //decia n en luagar de nobjetisconsulta
    generaConsultas(objetosConsulta, nObjetoConsulta, S -> nBD);
    //muestraObjetosConsulta(objetosConsulta, nObjetoConsulta);

    //printf("\nevaluando\n");
    for(i = 0; i < nPorcentaje; i++){

        sumaRecall = 0;

        for(j = 0; j < nObjetoConsulta; j++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j]);
            sumaRecall = sumaRecall + recall;
        }

        printf("\t %d Promedio recall %f\n", porcentaje[i], sumaRecall/nObjetoConsulta);
    }


    free( S -> descr );
    free( S -> objeto );
    free( S -> pivots );
    free( S -> sketches );
    free( S);

}

void seleccionaObjetosS(ghs* S, int l){

    int i;

    srand( time( NULL ) );

    for(i = 0; i < l; i++){
        S -> objeto[i] = rand() %S -> nBD + 1;
    }

}


void muestraObjetosS(ghs* S, int l){

    int i;

    for(i = 0; i < l; i++){
        printf("u[%d] : %d \n", i, S -> objeto[i]);
    }

}


void seleccionaPivotes(ghs* S, int nVeces, int l){

    int i;
    int j;
    int respuesta;

    pivotS P;
    pivotS Q;
    pivotS mejor;

    srand( time (NULL));

    for(i = 0; i < S -> nHiperplanos; i++){

        mejor.stx = 500; // para que considere el peor caso
        for(j = 0; j < nVeces; j ++){

            P.po1 = rand() %S -> nBD + 1;
            P.po2 = rand() %S -> nBD + 1;

            Q.po1 = rand() %S -> nBD + 1;
            Q.po2 = rand() %S -> nBD + 1;

            respuesta = rf01( &P, &Q, S, l );
            if (respuesta == true){

                if(P.stx < mejor.stx){
                    mejor.po1 = P.po1;
                    mejor.po2 = P.po2;
                    mejor.stx = P.stx;
                }

            }else{

                if(Q.stx < mejor.stx){
                    mejor.po1 = Q.po1;
                    mejor.po2 = Q.po2;
                    mejor.stx = Q.stx;
                }

            }

        }

        S -> pivots[i].po1 = mejor.po1;
        S -> pivots[i].po2 = mejor.po2;

    }

}


int rf01( pivotS* P, pivotS* Q, ghs* S, int l){

    int sp0;
    int sp1;
    int sq0;
    int sq1;

    Tdist d1;
    Tdist d2;


        sp0 = calculaParticion( P, S, l);
        sp1 = l - sp0;

        sq0 = calculaParticion( Q, S, l);
        sq1 = l - sq0;

        P -> stx = fabs(sp0 - sp1);
        Q -> stx = fabs(sq0 - sq1);

        if( P -> stx == P -> stx){

            //printf("S y Q generan la misma particion\n");
            d1 = distance( P -> po1, P -> po2);
            d2 = distance( P -> po1, P -> po2);

            if(d1 >= d2)
                return true;
            else
                return false;

        }else{

            if(P -> stx < Q -> stx){
              //  printf("P es mejor\n");
                return true;
            }
            else{
                //printf("Q es mejor\n");
                return false;
            }

        }

}


int calculaParticion(pivotS* X, ghs* S, int l){

    int sp0 = 0;
    int i;

    Tdist d1;
    Tdist d2;

    Obj u;

    for( i = 0; i < l; i++){

        u = S -> objeto[i];

        d1 = distance( u, X -> po1);
        d2 = distance(u, X -> po2);

        if( d1 <= d2)
            sp0++;

    }

    return (sp0);
}


void muestraPivotes(ghs* S){

    int i;

    printf("Los pivotes son\n\n");

    for(i = 0; i < S ->nHiperplanos; i++){
        printf("%i po1:%d ", i, S -> pivots[i].po1);
        printf("po2: %d\n", S -> pivots[i].po2);
    }

}


float kNN(ghs* S, int k, int porcentaje, Obj q){

    consulta *distanciaHamming = NULL;
    //consulta *distanciaHamming2 = NULL;

    consultaReal* distanciaRealAprox = NULL;
    consultaReal *distanciaReal = NULL;

    int kPorcentaje;
    int i;
    int interseccion = 0;
    int objetivo = 0;

    int *kCandidatosAprox = NULL;
    int *kCandidatosReal = NULL;
    int *resultado = NULL;

    float recall;

    sketchQ sQ;

    int dist;

    generaSketch(&sQ, q, S -> pivots, S -> nHiperplanos);

    //printf("\nya genere sketches\n");
    //printf("\ntamaño de la bd %d\n", S -> nBD);

    distanciaHamming = ( consulta* ) malloc( sizeof(consulta) * S -> nBD);

    //distanciaHamming2 = ( consulta* ) malloc( sizeof(consulta) * S -> nBD);
    //printf("\nya estoy por aca\n");
    //printf("\n otra impresion\n");

    for( i = 0 ;i < S -> nBD; i++){

        dist = hamming( sQ.sketches , S -> sketches[i]);//el que se calcula por defecto

        if( S ->  nHiperplanos > 32 )
            dist = dist + hamming( sQ.sketchesPart2 , S -> sketchesPart2[i]);

        if( S ->  nHiperplanos > 64 )
            dist = dist + hamming( sQ.sketchesPart3 , S -> sketchesPart3[i]);

        if( S ->  nHiperplanos > 96 )
            dist = dist + hamming( sQ.sketchesPart4 , S -> sketchesPart4[i]);

        if( S ->  nHiperplanos > 128 )
            dist = dist + hamming( sQ.sketchesPart5 , S -> sketchesPart5[i]);

        if( S ->  nHiperplanos > 160 )
            dist = dist + hamming( sQ.sketchesPart6 , S -> sketchesPart6[i]);

        if( S ->  nHiperplanos > 192 )
            dist = dist + hamming( sQ.sketchesPart7 , S -> sketchesPart7[i]);

        if( S ->  nHiperplanos > 224 )
            dist = dist + hamming( sQ.sketchesPart8 , S -> sketchesPart8[i]);

        if( S ->  nHiperplanos > 256 )
            dist = dist + hamming( sQ.sketchesPart9 , S -> sketchesPart9[i]);

        if( S ->  nHiperplanos > 288 )
            dist = dist + hamming( sQ.sketchesPart10 , S -> sketchesPart10[i]);

        distanciaHamming[i].distanciaQ = dist;
        distanciaHamming[i].o = i+1;

    }

    qsort( distanciaHamming, S -> nBD, sizeof( consulta ) , cmpfunc);

    kPorcentaje = porcentaje * (S -> nBD / 100);

    distanciaRealAprox = ( consultaReal* ) malloc( sizeof( consultaReal ) * kPorcentaje );
    workload(kPorcentaje, q, distanciaRealAprox, distanciaHamming);
    qsort( distanciaRealAprox, kPorcentaje, sizeof( consultaReal ) , cmpfuncFloat);

    distanciaReal = ( consultaReal* ) malloc( sizeof( consultaReal ) * S -> nBD);
    calculaDistanciaReal(distanciaReal, S -> nBD, q);
    qsort( distanciaReal, S -> nBD, sizeof( consultaReal ), cmpfuncFloat);

    kCandidatosAprox = ( int* ) malloc( sizeof( int ) * k);
    kCandidatosReal = ( int* ) malloc( sizeof( int ) * k);

    calculaCandidatos(distanciaReal, distanciaRealAprox, kCandidatosAprox, kCandidatosReal, k);
    qsort( kCandidatosReal, k, sizeof( int ) , compara);

    for(i = 0; i < k; i++){

        objetivo = kCandidatosAprox[i];
        resultado = (int*) bsearch( &objetivo, kCandidatosReal, k, sizeof( int ), compara);
        if( resultado != NULL){
            interseccion++;
        }
    }

    recall = ((float) interseccion / (float) k) * 100;

    free(distanciaRealAprox)
    free(kCandidatosAprox);
    free(kCandidatosReal);
    free(distanciaHamming);
    free(distanciaReal);

    return recall;

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


int hamming(unsigned int a, unsigned int b){

    return ( __builtin_popcount( a ^ b ) );

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