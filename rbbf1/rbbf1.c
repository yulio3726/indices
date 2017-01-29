//
// Created by cesar on 21/09/16.
//

#include <time.h>
#include <stdlib.h>
#include "rbbf1.h"

//float kNN(rbbf1* S, int k, int porcentaje, Obj q);

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
    int nObjetoConsulta = 150;
    int porcentaje[] = {1,3,5,7,9};
    int nPorcentaje = 5;


    Obj *objetosConsulta;
    Obj u;

    Tdist d1 = 0;
    Tdist d2 = 0;

    float recallPorcentaje[]={0,0,0,0,0}; //0 : error de posicion  1: recall

    G = malloc (sizeof(rbbf1));

    G->descr = malloc( strlen( dbname ) + 1);
    strcpy(G->descr, dbname);

    G -> nBaseDatos = openDB( G -> descr);

    if (n && (n < G -> nBaseDatos) ) G -> nBaseDatos = n;

    G -> nHiperPlanos = atoi( ( *argv[0] ) );
    (*argc)--;
    (*argv)++;

    int f=0;

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

            G -> sketches[u-1] = 0;
        if (G->nHiperPlanos > 32)
            G->sketchesPart2[u-1] = 0;
        if (G->nHiperPlanos > 64)
            G->sketchesPart3[u-1] = 0;
        if (G->nHiperPlanos > 96)
            G->sketchesPart4[u-1] = 0;
        if (G->nHiperPlanos > 128)
            G->sketchesPart5[u-1] = 0;
        if (G->nHiperPlanos > 160)
            G->sketchesPart6[u-1] = 0;
        if (G->nHiperPlanos > 192)
            G->sketchesPart7[u-1] = 0;
        if (G->nHiperPlanos > 224)
            G->sketchesPart8[u-1] = 0;
        if (G->nHiperPlanos > 256)
            G->sketchesPart9[u-1] = 0;
        if (G->nHiperPlanos > 288)
            G->sketchesPart10[u-1] = 0;

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

    printf("Empiezan las consultas\n");
    objetosConsulta = (Obj *) malloc( sizeof (Obj) * nObjetoConsulta); //se seleccionana los objetos para la consulta
    //printf("Se reservan los espacios para los objetos de las consultas\n");
    generaConsultas(objetosConsulta, nObjetoConsulta, G -> nBaseDatos);
    //muestraObjetosConsulta(objetosConsulta, nObjetoConsulta);

    //inicializaRecallPorcentaje(&recallPorcentaje, nPorcentaje);

    for(i = 0; i < nObjetoConsulta; i++){
        kNN(G, k, objetosConsulta[i], &recallPorcentaje);
    }

    printf("\n\tresultados finales\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" %d.- %d promedio recall %f\n",i, porcentaje[i], recallPorcentaje[i]/nObjetoConsulta);
    }


/*    for(i = 0; i < nPorcentaje; i++){ //para que revise todos los porcentajes
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
*/
    free(G -> sketches);
    free(G -> pivots);
    free(G);
    closeDB();

    return (Index) G;

}


int hamming(unsigned int a, unsigned int b){

    return ( __builtin_popcount( a ^ b ) );

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


void kNN(rbbf1* G, int k, Obj q, float* recallPorcentaje){

    consulta *distanciaHamming = NULL;

    consultaReal* distanciaRealAprox = NULL;
    consultaReal *distanciaReal = NULL;

    int kPorcentaje;
    int i;
    int interseccion = 0;
    int objetivo = 0;
    int porcentaje[] = { 1, 3, 5, 7, 9};
    int nPorcentaje = 5;

    int *resultado;
    int *kCandidatosAprox = NULL;
    int *kCandidatosReal = NULL;

    float recall;

    sketchQ sQ;

    Tdist dist;

    generaSketch( &sQ, q, G -> pivots, G -> nHiperPlanos);

    //printf("\nestoy por aca\n el numero de objetos que quiero es del %d\n", G -> nBaseDatos);
    distanciaHamming = (consulta *) malloc( sizeof(consulta)* G -> nBaseDatos);
    //printf("ya termine\n");

    /*se calculan todas las distancia de hamming cd q hacia todos los objetos*/
    for( i = 0 ;i < G -> nBaseDatos; i++){

        dist = hamming( sQ.sketches , G -> sketches[i]);//el que se calcula por defecto

        if( G -> nHiperPlanos > 32 )
            dist = dist + hamming( sQ.sketchesPart2 , G -> sketchesPart2[i]);

        if( G -> nHiperPlanos > 64 )
             dist = dist + hamming( sQ.sketchesPart3 , G -> sketchesPart3[i]);

        if( G -> nHiperPlanos > 96 )
            dist = dist + hamming( sQ.sketchesPart4 , G -> sketchesPart4[i]);

        if( G -> nHiperPlanos > 128 )
            dist = dist + hamming( sQ.sketchesPart5 , G -> sketchesPart5[i]);

        if( G -> nHiperPlanos > 160 )
            dist = dist + hamming( sQ.sketchesPart6 , G -> sketchesPart6[i]);

        if( G -> nHiperPlanos > 192 )
            dist = dist + hamming( sQ.sketchesPart7 , G -> sketchesPart7[i]);

        if( G -> nHiperPlanos > 224 )
            dist = dist + hamming( sQ.sketchesPart8 , G -> sketchesPart8[i]);

        if( G -> nHiperPlanos > 256 )
            dist = dist + hamming( sQ.sketchesPart9 , G -> sketchesPart9[i]);

        if( G -> nHiperPlanos > 288 )
            dist = dist + hamming( sQ.sketchesPart10 , G -> sketchesPart10[i]);

        distanciaHamming[i].distanciaQ = dist;
        distanciaHamming[i].o = i+1;

    }

    qsort( distanciaHamming, G -> nBaseDatos, sizeof( consulta ) , cmpfunc); //se ordenan las distancias de hammign entre el objeto q y ui

    int a = 0;


    distanciaReal = (consultaReal *) malloc(sizeof(consultaReal) * G->nBaseDatos);
    calculaDistanciaReal(distanciaReal, G->nBaseDatos, q);

    qsort(distanciaReal, G->nBaseDatos, sizeof(consultaReal), cmpfuncFloat);

    for(a = 0; a < nPorcentaje; a++) {
        kPorcentaje = porcentaje[a] * (G->nBaseDatos / 100); //se calcula el nemero de objetos a revisar

        distanciaRealAprox = (consultaReal *) malloc(sizeof(consultaReal) * kPorcentaje);
        workload(kPorcentaje, q, distanciaRealAprox, distanciaHamming); // se calculan las distancias reales entre los objetos propuestos y la consulta
        qsort(distanciaRealAprox, kPorcentaje, sizeof(consultaReal), cmpfuncFloat);

        kCandidatosAprox = (int *) malloc(sizeof(int) * k);
        kCandidatosReal = (int *) malloc(sizeof(int) * k);

        calculaCandidatos(distanciaReal, distanciaRealAprox, kCandidatosAprox, kCandidatosReal, k);

        qsort(kCandidatosReal, k, sizeof(int), compara);

        interseccion = 0 ;
        resultado = 0;
        recall = 0;

        for (i = 0; i < k; i++) {

            objetivo = kCandidatosAprox[i];
            resultado = (int *) bsearch(&objetivo, kCandidatosReal, k, sizeof(int), compara);

            if (resultado != NULL) {
                interseccion++;
            }
        }

        recall = ((float) interseccion / (float) k) * 100;

        recallPorcentaje[a] = recallPorcentaje[a] + recall;

        free(distanciaRealAprox)
        free(kCandidatosAprox);
        free(kCandidatosReal);
    }

    free(distanciaReal);
    free(distanciaHamming);

}

