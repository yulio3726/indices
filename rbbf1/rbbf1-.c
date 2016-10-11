//
// Created by cesar on 21/09/16.
//

#include <time.h>
#include <stdlib.h>
#include "rbbf1.h"

Index build (char *dbname, int n, int *argc, char ***argv){

    rbbf1 *G;
    int i;
    int dimension;

    if(*argc < 1){
        fprintf(stderr, "Usage: <program> <args> ARITY\n");
        exit(1);
    }

    G = malloc (sizeof(rbbf1));

    G -> descr = malloc( strlen( dbname ) + 1 );
    strcpy( G -> descr, dbname );

    G -> nBaseDatos = openDB( G -> descr );

    if( n && (n < G -> nBaseDatos ) ) G -> nBaseDatos = n;

    G -> nHiperPlanos = atoi( (*argv[0]) ); ( *argc )--; ( *argv)++;

    G -> pivots =  malloc( sizeof( pivot ) * G -> nHiperPlanos);
    G -> sketches = malloc( sizeof( unsigned int ) * G -> nBaseDatos); //los primeros 32 bits

    if( (G -> nHiperPlanos > 32) ){
        printf("activoPart2\n");
        G -> sketchesPart2 = malloc( sizeof( unsigned int ) * G -> nBaseDatos);
    }

    if( (G -> nHiperPlanos > 64) ){
        printf("activoPart3\n");
        G -> sketchesPart3 = malloc( sizeof( unsigned int ) * G -> nBaseDatos);
    }

    if( (G -> nHiperPlanos > 96) ){
        printf("activoPart4\n");
        G -> sketchesPart4 = malloc( sizeof( unsigned int ) * G -> nBaseDatos);
    }

    if( (G -> nHiperPlanos > 128) ) {
        printf("activoPart5\n");
        G -> sketchesPart5 = malloc( sizeof( unsigned int ) * G -> nBaseDatos);
    }

    if( (G -> nHiperPlanos > 160) ){
        printf("activoPart6\n");
        G -> sketchesPart6 = malloc( sizeof( unsigned int ) * G -> nBaseDatos);
    }

    if( (G -> nHiperPlanos > 192) ){
        printf("activoPart7\n");
        G -> sketchesPart7 = malloc( sizeof( unsigned int ) * G -> nBaseDatos);
    }

    if( (G -> nHiperPlanos > 224) ){
        printf("activoPart8\n");
        G -> sketchesPart8 = malloc( sizeof( unsigned int ) * G -> nBaseDatos);
    }

    if( (G -> nHiperPlanos > 256) ) {
        printf("activoPart9\n");
        G -> sketchesPart9 = malloc( sizeof( unsigned int ) * G -> nBaseDatos);
    }

    if( (G -> nHiperPlanos > 288) ){
        printf("activoPart10\n");
        G -> sketchesPart10 = malloc( sizeof( unsigned int ) * G -> nBaseDatos);
    }


    i = 0;
    Obj u;
    Tdist d1;
    Tdist d2;
    int posicion = 0;

    seleccionaPivotes(G);

    printf("nHiperplanos %d\n", G -> nHiperPlanos);

    while(i <  2 ){ //G -> nBaseDatos
        //printf("entro while\n");
        i++;
        u = i;

        //printf("inicializando\n");

        G -> sketches[u-1] = 0;
        if( G -> nHiperPlanos > 32 )
            G -> sketchesPart2[u-1] = 0;
        if( G -> nHiperPlanos > 64 )
            G -> sketchesPart3[u-1] = 0;
        if( G -> nHiperPlanos > 96 )
            G -> sketchesPart4[u-1] = 0;
        if( G -> nHiperPlanos > 128 )
            G -> sketchesPart5[u-1] = 0;
        if( G -> nHiperPlanos > 160 )
            G -> sketchesPart6[u-1] = 0;
        if( G -> nHiperPlanos > 192 )
            G -> sketchesPart7[u-1] = 0;
        if( G -> nHiperPlanos > 224 )
            G -> sketchesPart8[u-1] = 0;
        if( G -> nHiperPlanos > 256 )
            G -> sketchesPart9[u-1] = 0;
        if( G -> nHiperPlanos > 288 )
            G -> sketchesPart10[u-1] = 0;

        printf("calculando la firma para el objeto u\n");

        for( dimension = 0; dimension < G -> nHiperPlanos; dimension++){

            d1 = distance(u, G -> pivots[dimension].po1);
            d2 = distance(u, G -> pivots[dimension].po2);

            if( d1 <= d2 ){

                if( dimension < 32  ){
                    G -> sketches[i-1] ^= (-1 ^ G -> sketches[i-1]) & (1 << dimension);
                }

                if ((dimension >= 32) && ( dimension < 64)){
                    //printf("2primer bit del part2\n");
                    posicion = dimension - 32;
                    G -> sketchesPart2[i-1] ^= ( -1 ^ G -> sketchesPart2[i-1] ) & (1 << posicion);
                }

                if ((dimension >= 64) && ( dimension < 96)){
                    //printf("2primer bit del part3\n");
                    posicion = dimension - 64;
                    G -> sketchesPart3[i-1] ^= ( -1 ^ G -> sketchesPart3[i-1] ) & (1 << posicion);
                }

                if ((dimension >= 96) && ( dimension < 128)){
                    //printf("2primer bit del part4\n");
                    posicion = dimension - 96;
                    G -> sketchesPart4[i-1] ^= ( -1 ^ G -> sketchesPart4[i-1] ) & (1 << posicion);
                }

                if ((dimension >= 128) && ( dimension < 160)){
                    //printf("2primer bit del part5\n");
                    posicion = dimension - 128;
                    G -> sketchesPart5[i-1] ^= ( -1 ^ G -> sketchesPart5[i-1] ) & (1 << posicion);
                }

                if ((dimension >= 160) && ( dimension < 192)){
                    //printf("2primer bit del part6\n");
                    posicion = dimension - 160;
                    G -> sketchesPart6[i-1] ^= ( -1 ^ G -> sketchesPart6[i-1] ) & (1 << posicion);
                }

                if ((dimension >= 192) && ( dimension < 224)){
                    //printf("2primer bit del part7\n");
                    posicion = dimension - 192;
                    G -> sketchesPart7[i-1] ^= ( -1 ^ G -> sketchesPart7[i-1] ) & (1 << posicion);
                }

                if ((dimension >= 224) && ( dimension < 256)){
                    //printf("2primer bit del part8\n");
                    posicion = dimension - 224;
                    G -> sketchesPart8[i-1] ^= ( -1 ^ G -> sketchesPart8[i-1] ) & (1 << posicion);
                }

                if ((dimension >= 256) && ( dimension < 288)){
                    //printf("2primer bit del part9\n");
                    posicion = dimension - 256;
                    G -> sketchesPart9[i-1] ^= ( -1 ^ G -> sketchesPart9[i-1] ) & (1 << posicion);
                }

                if ((dimension >= 288) && ( dimension < 320)){
                    //printf("2primer bit del part10\n");
                    posicion = dimension - 288;
                    G -> sketchesPart10[i-1] ^= ( -1 ^ G -> sketchesPart10[i-1] ) & (1 << posicion);
                }
            }
        }

    }

    printf("termine de calcular las firmas\n");
    /*int k = 20;
    int porcentaje = 10;

    kNN( G , k, porcentaje);*/

    free(G -> sketches);
    free(G -> sketchesPart2);
    free(G -> sketchesPart3);
    free(G -> sketchesPart4);
    free(G -> sketchesPart5);
    free(G -> sketchesPart6);
    free(G -> sketchesPart7);
    free(G -> sketchesPart8);
    free(G -> sketchesPart9);
    free(G -> sketchesPart10);
    free(G -> pivots);
    free(G);
    closeDB();

    return (Index) G;

}

void seleccionaPivotes(rbbf1* N){

    int i;
    srand( time( NULL ) );

    for(i = 0; i < N -> nHiperPlanos; i++){
        N -> pivots[i].po1 = rand() %N -> nBaseDatos + 1;
        N -> pivots[i].po2 = rand() %N -> nBaseDatos +1;
    }

}

int hamming(unsigned int a, unsigned int b){

    return ( __builtin_popcount( a ^ b ) );

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

/*
void saveIndex (Index S, char *fname)
{
    printf("saveindex");
    rbbf1 *G = (rbbf1*)S;
    FILE *f = fopen (fname,"w");
    fwrite (G->descr,strlen(G->descr)+1,1,f);
    fwrite (&G -> nHiperPlanos,sizeof(int),1,f);
    //savenode (&G -> tree,f);
    fclose (f);

}
*/

void freeIndex (Index S, bool libobj)

{
    printf("freeindex\n");
    rbbf1 *G = (rbbf1*)S;
    free (G->descr);
    free (G);
    if (libobj) closeDB();
}

void kNN(rbbf1* S, int k, int porcentaje){

    consulta *distanciaHamming = NULL;

    consultaReal* distanciaRealAprox = NULL;
    consultaReal *distanciaReal = NULL;

    int numeroPruebas = 100;
    int kPorcentaje;
    int i;
    int rep;
    int *kCandidatosAprox = NULL;
    int *kCandidatosReal = NULL;

    float recall;
    float sumaRecall = 0;

    Tdist  dist;

    sketchQ sQ;

    for(rep = 0; rep < numeroPruebas; rep++){

        srand( time(NULL) );
        Obj q = rand()% S -> nBaseDatos + 1; //si fuera nuevo se usa NewObj ya que no esta en la BD original
        generaSketch( &sQ, q, S -> pivots, S -> nHiperPlanos);

        distanciaHamming = ( consulta* ) malloc( sizeof(consulta) * S -> nBaseDatos);

        /*se calculan todas las distancia de hamming */

        for( i = 0 ;i < S -> nBaseDatos; i++){
            //dist = 0;

            //el que se calcula por defecto
            dist =  hamming( sQ.sketches , S -> sketches[i]);

            if( S -> nHiperPlanos > 32 )
                dist = dist + hamming( sQ.sketchesPart2 , S -> sketchesPart2[i]);

            if( S -> nHiperPlanos > 64 )
                dist = dist + hamming( sQ.sketchesPart3 , S -> sketchesPart3[i]);

            if( S -> nHiperPlanos > 96 )
                dist = dist + hamming( sQ.sketchesPart4 , S -> sketchesPart4[i]);

            if( S -> nHiperPlanos > 128 )
                dist = dist + hamming( sQ.sketchesPart5 , S -> sketchesPart5[i]);

            if( S -> nHiperPlanos > 160 )
                dist = dist + hamming( sQ.sketchesPart6 , S -> sketchesPart6[i]);

            if( S -> nHiperPlanos > 192 )
                dist = dist + hamming( sQ.sketchesPart7 , S -> sketchesPart7[i]);

            if( S -> nHiperPlanos > 224 )
                dist = dist + hamming( sQ.sketchesPart8 , S -> sketchesPart8[i]);

            if( S -> nHiperPlanos > 256 )
                dist = dist + hamming( sQ.sketchesPart9 , S -> sketchesPart9[i]);

            if( S -> nHiperPlanos > 288 )
                dist = dist + hamming( sQ.sketchesPart10 , S -> sketchesPart10[i]);


            distanciaHamming[i].distanciaQ = dist;
            distanciaHamming[i].o = i+1;
        }

        qsort( distanciaHamming, S -> nBaseDatos, sizeof( consulta ) , cmpfunc);

        kPorcentaje = porcentaje * (S -> nBaseDatos / 100) ;
        distanciaRealAprox = ( consultaReal* ) malloc( sizeof( consultaReal ) * kPorcentaje );
        workload(kPorcentaje, q, distanciaRealAprox, distanciaHamming);
        qsort( distanciaRealAprox, kPorcentaje, sizeof( consultaReal ) , cmpfuncFloat);

        distanciaReal = ( consultaReal* ) malloc( sizeof( consultaReal ) * S -> nBaseDatos);
        calculaDistanciaReal(distanciaReal, S -> nBaseDatos, q);
        qsort( distanciaReal, S -> nBaseDatos, sizeof( consultaReal ) , cmpfuncFloat);

        kCandidatosAprox = ( int* ) malloc( sizeof( int ) * k);
        kCandidatosReal = ( int* ) malloc( sizeof( int ) * k);

        calculaCandidatos(distanciaReal, distanciaRealAprox, kCandidatosAprox, kCandidatosReal, k);


        qsort( kCandidatosReal, k, sizeof( int ) , compara);

        int interseccion = 0;
        int objetivo = 0;
        int *resultado;

        for(i = 0; i < k; i++){

            objetivo = kCandidatosAprox[i];
            resultado = (int*) bsearch( &objetivo, kCandidatosReal, k, sizeof( int ), compara);

            if( resultado != NULL){
                interseccion++;
            }else{
                //printf ( " Couldn't find %d \n", objetivo);
            }
        }

        recall = ((float) interseccion / (float) k) * 100;
        sumaRecall = sumaRecall + recall;

        printf("rep %d recall %f\n", rep, recall);

        free(distanciaRealAprox)
        free(kCandidatosAprox);
        free(kCandidatosReal);
        free(distanciaHamming);
        free(distanciaReal);
    }

    printf("promedioRecall %f\n", sumaRecall/numeroPruebas);
}

void generaSketch(sketchQ* sQ, Obj q, pivot* pivots, int nHiperPlanos){

    Tdist d1;
    Tdist d2;
    int dimension;
    int posicion = 0;
    unsigned int s = 0;

    for( dimension = 0; dimension < nHiperPlanos; dimension++){

        d1 = distance( q, pivots[dimension].po1 );
        d2 = distance( q, pivots[dimension].po2 );

        if( d1 <= d2 ) {

            if( dimension < 32  ){
                sQ -> sketches ^= (-1 ^ sQ -> sketches) & (1 << dimension);
            }

            if ((dimension >= 32) && ( dimension < 64)){
                //printf("2primer bit del part2\n");
                posicion = dimension - 32;
                sQ -> sketchesPart2 ^= ( -1 ^ sQ -> sketchesPart2 ) & (1 << posicion);
            }

            if ((dimension >= 64) && ( dimension < 96)){
                //printf("2primer bit del part3\n");
                posicion = dimension - 64;
                sQ -> sketchesPart3 ^= ( -1 ^ sQ -> sketchesPart3 ) & (1 << posicion);
            }

            if ((dimension >= 96) && ( dimension < 128)){
                //printf("2primer bit del part4\n");
                posicion = dimension - 96;
                sQ -> sketchesPart4 ^= ( -1 ^ sQ -> sketchesPart4) & (1 << posicion);
            }

            if ((dimension >= 128) && ( dimension < 160)){
                //printf("2primer bit del part5\n");
                posicion = dimension - 128;
                sQ -> sketchesPart5 ^= ( -1 ^ sQ -> sketchesPart5 ) & (1 << posicion);
            }

            if ((dimension >= 160) && ( dimension < 192)){
                //printf("2primer bit del part6\n");
                posicion = dimension - 160;
                sQ -> sketchesPart6 ^= ( -1 ^ sQ -> sketchesPart6 ) & (1 << posicion);
            }

            if ((dimension >= 192) && ( dimension < 224)){
                //printf("2primer bit del part7\n");
                posicion = dimension - 192;
                sQ -> sketchesPart7 ^= ( -1 ^ sQ -> sketchesPart7 ) & (1 << posicion);
            }

            if ((dimension >= 224) && ( dimension < 256)){
                //printf("2primer bit del part8\n");
                posicion = dimension - 224;
                sQ -> sketchesPart8 ^= ( -1 ^ sQ -> sketchesPart8 ) & (1 << posicion);
            }

            if ((dimension >= 256) && ( dimension < 288)){
                //printf("2primer bit del part9\n");
                posicion = dimension - 256;
                sQ -> sketchesPart9 ^= ( -1 ^ sQ -> sketchesPart9 ) & (1 << posicion);
            }

            if ((dimension >= 288) && ( dimension < 320)){
                //printf("2primer bit del part10\n");
                posicion = dimension - 288;
                sQ -> sketchesPart10 ^= ( -1 ^ sQ -> sketchesPart10 ) & (1 << posicion);
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
