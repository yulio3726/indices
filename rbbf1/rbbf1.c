//
// Created by cesar on 21/09/16.
//

#include <time.h>
#include <stdlib.h>
#include "rbbf1.h"

Index build (char *dbname, int n, int *argc, char ***argv) {

    if (*argc < 1) {
        fprintf(stderr, "Usage: <program> <args> ARITY\n");
        exit(1);
    }

    rbbf1 *G;

    int i;
    int dimension;
    int k = 10;
    int posicion;
    int nObjetoConsulta = 100;
    int porcentaje[] = { 1, 3, 5, 9};
    int j;

    Obj *objetosConsulta;
    Obj u;

    Tdist d1;
    Tdist d2;

    float recall;
    float sumaRecall;

    G = malloc (sizeof(rbbf1));

    G->descr = malloc( strlen( dbname ) + 1);
    strcpy(G->descr, dbname);

    G -> nBaseDatos = openDB( G -> descr);

    if (n && (n < G -> nBaseDatos) ) G -> nBaseDatos = n;

    G -> nHiperPlanos = atoi( ( *argv[0] ) );
    (*argc)--;
    (*argv)++;

    G -> pivots = malloc( sizeof( pivot ) * G -> nHiperPlanos);
    G -> sketches = malloc( sizeof( unsigned int ) * G -> nBaseDatos); //los primeros 32 bits

    if (( G -> nHiperPlanos > 32))
        G -> sketchesPart2 = malloc( sizeof( unsigned int) * G -> nBaseDatos);

    if ((G->nHiperPlanos > 64))
        G->sketchesPart3 = malloc( sizeof( unsigned int ) * G -> nBaseDatos);

    if ((G->nHiperPlanos > 96)) {
        G->sketchesPart4 = malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    if ((G->nHiperPlanos > 128)) {
        G->sketchesPart5 = malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    if ((G->nHiperPlanos > 160)) {
        G->sketchesPart6 = malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    if ((G->nHiperPlanos > 192)) {
        G->sketchesPart7 = malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    if ((G->nHiperPlanos > 224)) {
        G->sketchesPart8 = malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    if ((G->nHiperPlanos > 256)) {
        G->sketchesPart9 = malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    if ((G->nHiperPlanos > 288)) {
        G->sketchesPart10 = malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    seleccionaPivotes(G);

    i = 0;
    posicion = 0;
    while (i < G -> nBaseDatos) {

        i++;
        u = i;

        G->sketches[u] = 0;
        if (G->nHiperPlanos > 32)
            G->sketchesPart2[u] = 0;
        if (G->nHiperPlanos > 64)
            G->sketchesPart3[u] = 0;
        if (G->nHiperPlanos > 96)
            G->sketchesPart4[u] = 0;
        if (G->nHiperPlanos > 128)
            G->sketchesPart5[u] = 0;
        if (G->nHiperPlanos > 160)
            G->sketchesPart6[u] = 0;
        if (G->nHiperPlanos > 192)
            G->sketchesPart7[u] = 0;
        if (G->nHiperPlanos > 224)
            G->sketchesPart8[u] = 0;
        if (G->nHiperPlanos > 256)
            G->sketchesPart9[u] = 0;
        if (G->nHiperPlanos > 288)
            G->sketchesPart10[u] = 0;

        for (dimension = 0; dimension < G->nHiperPlanos; dimension++) {

            d1 = distance(u, G->pivots[dimension].po1);
            d2 = distance(u, G->pivots[dimension].po2);

            if (d1 <= d2) {

                if (dimension < 32) {
                    G->sketches[i - 1] ^= (-1 ^ G->sketches[i - 1]) & (1 << dimension);
                }

                if ((dimension >= 32) && (dimension < 64)) {
                    posicion = dimension - 32;
                    G->sketchesPart2[i - 1] ^= (-1 ^ G->sketchesPart2[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 64) && (dimension < 96)) {
                    posicion = dimension - 64;
                    G->sketchesPart3[i - 1] ^= (-1 ^ G->sketchesPart3[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 96) && (dimension < 128)) {
                    posicion = dimension - 96;
                    G->sketchesPart4[i - 1] ^= (-1 ^ G->sketchesPart4[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 128) && (dimension < 160)) {
                    posicion = dimension - 128;
                    G->sketchesPart5[i - 1] ^= (-1 ^ G->sketchesPart5[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 160) && (dimension < 192)) {
                    posicion = dimension - 160;
                    G->sketchesPart6[i - 1] ^= (-1 ^ G->sketchesPart6[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 192) && (dimension < 224)) {
                    posicion = dimension - 192;
                    G->sketchesPart7[i - 1] ^= (-1 ^ G->sketchesPart7[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 224) && (dimension < 256)) {
                    posicion = dimension - 224;
                    G->sketchesPart8[i - 1] ^= (-1 ^ G->sketchesPart8[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 256) && (dimension < 288)) {
                    posicion = dimension - 256;
                    G->sketchesPart9[i - 1] ^= (-1 ^ G->sketchesPart9[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 288) && (dimension < 320)) {
                    posicion = dimension - 288;
                    G->sketchesPart10[i - 1] ^= (-1 ^ G->sketchesPart10[i - 1]) & (1 << posicion);

                }
            }
        }

    }

    objetosConsulta = (Obj *) malloc( sizeof (Obj) * n); //se seleccionana los objetos para la consulta
    generaConsultas(objetosConsulta, nObjetoConsulta, G -> nBaseDatos);
    //muestraObjetosConsulta(objetosConsulta, nObjetoConsulta);

    for(i = 0; i < 4; i++){ //para que revise todos los porcentajes
        //printf("reviso el porcentaje %d\n", porcentaje[i]);
        sumaRecall = 0;

        for(j = 0; j < nObjetoConsulta; j++){ //para que busque cada uno de los objetos seleccionados para la consulta
          //  printf("\tconsulto objeto consulta num: %d\n", j);
            recall = kNN( G , k, porcentaje[i], objetosConsulta[j]);
            sumaRecall = sumaRecall + recall;
            //printf("\t\ttiene un recall de: %f \n", recall);
        }

        printf("\t %d Promedio recall %f\n", porcentaje[i], sumaRecall/nObjetoConsulta);
    }

    free(G -> sketches);
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


void freeIndex (Index S, bool libobj){
    printf("freeindex\n");
    rbbf1 *G = (rbbf1*)S;
    free (G->descr);
    free (G);
    if (libobj) closeDB();
}


float kNN(rbbf1* S, int k, int porcentaje, Obj q){

    consulta *distanciaHamming = NULL;

    consultaReal* distanciaRealAprox = NULL;
    consultaReal *distanciaReal = NULL;

    int kPorcentaje;
    int i;
    int rep;
    int interseccion = 0;
    int objetivo = 0;

    int *resultado;
    int *kCandidatosAprox = NULL;
    int *kCandidatosReal = NULL;

    float recall;

    sketchQ sQ;

    Tdist dist;

    generaSketch( &sQ, q, S -> pivots, S -> nHiperPlanos);

    distanciaHamming = ( consulta* ) malloc( sizeof(consulta) * S -> nBaseDatos);

    /*se calculan todas las distancia de hamming cd q hacia todos los objetos*/
    for( i = 0 ;i < S -> nBaseDatos; i++){

        dist = hamming( sQ.sketches , S -> sketches[i]);//el que se calcula por defecto

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

    qsort( distanciaHamming, S -> nBaseDatos, sizeof( consulta ) , cmpfunc); //se ordenan las distancias de hammign entre el objeto q y ui

    kPorcentaje = porcentaje * (S -> nBaseDatos / 100) ; //se calcula el nemero de objetos a revisar

    distanciaRealAprox = ( consultaReal* ) malloc( sizeof( consultaReal ) * kPorcentaje );
    workload(kPorcentaje, q, distanciaRealAprox, distanciaHamming); // se calculan las distancias reales entre los objetos propuestos y la consulta
    qsort( distanciaRealAprox, kPorcentaje, sizeof( consultaReal ) , cmpfuncFloat);

    distanciaReal = ( consultaReal* ) malloc( sizeof( consultaReal ) * S -> nBaseDatos);
    calculaDistanciaReal(distanciaReal, S -> nBaseDatos, q);

    qsort( distanciaReal, S -> nBaseDatos, sizeof( consultaReal ) , cmpfuncFloat);;

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
