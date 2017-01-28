//
// Created by cesar on 9/28/16.
//

#include <time.h>
#include <stdlib.h>
#include "sss.h"

float calculaM(int nBD);

Index build (char *dbname, int n, int *argc, char ***argv) {

    if (*argc < 1) {
        fprintf(stderr, "Usage: <program> <args> ARITY\n");
        exit(1);
    }

    ssss *G;
    int i;
    int dimension;
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

    float recall=0;
    float sumaRecall=0;

    G = malloc (sizeof(ssss));

    G->descr = malloc(strlen(dbname) + 1);
    strcpy(G->descr, dbname);
    printf("\n\t nombre de la bd");

    G->nBaseDatos = openDB(G->descr);

    if (n && (n < G->nBaseDatos)) G->nBaseDatos = n;
    printf("\n\t se sabe cuantos elementos indexar");

    G->nHiperPlanos = atoi((*argv[0]));
    (*argc)--;
    (*argv)++;

    printf("\n\t se reserva la memoria necesaria");
    G->pivots = (pivot*)malloc(sizeof(pivot) * G->nHiperPlanos);
    printf("\n\t se reserva el espacio para los pivotes");
    G -> sketches = (unsigned int*)malloc(sizeof(unsigned int) * G->nBaseDatos); //los primeros 32 bits
    printf("\n\t se reserva memoria para los primeros sketches");
    if (G->nHiperPlanos > 32)
        G->sketchesPart2 = (unsigned int*)malloc(sizeof(unsigned int) * G->nBaseDatos);
    printf("1");

    if (G->nHiperPlanos > 64)
        G->sketchesPart3 = (unsigned int*)malloc(sizeof(unsigned int) * G->nBaseDatos);

    printf(" 2");
    if (G->nHiperPlanos > 96)
        G->sketchesPart4 = (unsigned int*)malloc(sizeof(unsigned int) * G->nBaseDatos);

    printf(" 3");
    if (G->nHiperPlanos > 128){
        G->sketchesPart5 = (unsigned int*)malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    printf(" 4");
    if (G->nHiperPlanos > 160){
        G->sketchesPart6 = (unsigned int*)malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    printf(" 5");
    if (G->nHiperPlanos > 192) {
        G->sketchesPart7 = (unsigned int*)malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    printf(" 6");
    if (G->nHiperPlanos > 224) {
        G->sketchesPart8 = (unsigned int*)malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    printf(" 7");
    if (G->nHiperPlanos > 256) {
        G->sketchesPart9 = (unsigned int*)malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    printf(" 8");
    if (G->nHiperPlanos > 288) {
        G->sketchesPart10 = (unsigned int*)malloc(sizeof(unsigned int) * G->nBaseDatos);
    }

    printf("\n\t se han reservado el espacio de memoria\n");
    seleccionaPivotes(G);
    printf("\n\t se han seleccionado los pivotes\n");

    i = 0;
    posicion = 0;
    while (i < G->nBaseDatos) {

        i++;
        u = i;

        G->sketches[u-1] = 0;
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

    objetosConsulta = (Obj*) malloc( sizeof (Obj) * nObjetoConsulta);
    generaConsultas(objetosConsulta, nObjetoConsulta, G -> nBaseDatos);

    //printf("empiezan las consultas");
    for(i = 0; i < nPorcentaje; i++){

        sumaRecall = 0;

        for(j = 0; j < nObjetoConsulta; j++){
            recall = kNN( G , k, porcentaje[i], objetosConsulta[j]);
            sumaRecall = sumaRecall + recall;
        }

        printf("\t %d Promedio recall %f\n", porcentaje[i], sumaRecall/nObjetoConsulta);
    }

    free(G -> sketches);
    free(G -> pivots);
    free(G);
    closeDB();

    return (Index) G;

}

void seleccionaPivotes(ssss* N){

    printf("\n\t entro a selecciona pivotes");
    int i = 0;
    int j = 0;
    int tArregloPivotes = 1500;
    int encontrados=0;
    int temp = 0;

    printf("\n\t 1");
    Obj *arregloPivotes; //arreglo de objetos pivotes

    printf("\n\t 2");
    float m = 0;
    float alfa = 0.4;
    float mAlfa = 0;

    printf("\n\t 3");
    Tdist d = 0;
    printf("\n\t 4");
    m = calculaM(N -> nBaseDatos);
    printf("\n\t salgo calcula m");
    mAlfa = m * alfa;

    arregloPivotes = (Obj*)malloc(sizeof(Obj) * tArregloPivotes);
    srand( time( NULL ) );
    arregloPivotes[0] = rand() %N -> nBaseDatos + 1; //incializo el arreglo
    encontrados = 1;

    for(i = 1; i <= N -> nBaseDatos; i++){
        if(i < 100)
            printf("\n\t encontrados = %i i = %d", encontrados, i );
        for(j = 0; j < encontrados; j++){
            d = distance( i, arregloPivotes[j]);
            if( d >= mAlfa){
               //temp = encontrados + 1;
                //arregloPivotes[temp-1] = i;
                arregloPivotes[encontrados] = i;
                encontrados = encontrados + 1;
                j = encontrados;//para que rompa el ciclo
            }
        }

        //encontrados = temp;
        if(encontrados == (tArregloPivotes)) //por si ya encontre los t objetos lejanos que buscaba
            i = N ->nBaseDatos + 1; //para que rompa el ciclo
    }

    printf("\nencontrados %d",encontrados);

    for(i = 0; i < N -> nHiperPlanos; i++){
        N -> pivots[i].po1 = arregloPivotes[rand() % encontrados];
        N -> pivots[i].po2 = arregloPivotes[rand() % encontrados];
    }

    free(arregloPivotes);

}


float calculaM(int nBD){
    printf("\n\t entro a calcula m");
    float dLejana=0;

    int iteraciones = 4000;
    int i;
    int j;

    Obj x1;
    Obj uLejano;

    Tdist d;
    srand( time( NULL ) );
    x1 = rand() %nBD + 1;

    for(j = 0; j < iteraciones; j++){
        dLejana = 0;
        for(i = 1; i <= nBD; i++){ // 1 porque es como empieza la base de datos

            d = distance( x1, i);

            if(dLejana < d){
                dLejana = d;
                uLejano = i;
                //printf("i[%d] dLejana %f\n", i, dLejana);
            }

        }

        x1 = uLejano;
        //printf("dlenana %f\n", dLejana);
        //printf("\n******\n");
    }


    return (dLejana);
}


int hamming(unsigned int a, unsigned int b){

    return ( __builtin_popcount( a ^ b ) );

}


void muestraPivotes(ssss* N){

    int i = 0;

    printf("Los pivotes son: \n\n");

    for(i; i < N -> nHiperPlanos; i++){
        printf("%i po1: %d ", i, N -> pivots[i].po1);
        printf( "po2: %d\ns", N -> pivots[i].po2);
    }

}


float kNN(ssss* S, int k, int porcentaje, Obj q){

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

    return  recall;
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
        // printf("i [%d] aprox %d real %d\n",i, distanciaHamming[i].o,distanciaReal[i].o);
        kCandidatosAprox[i] = distanciaRealAprox[i].o;
        kCandidatosReal[i] = distanciaReal[i].o;
        //printf("i [%d] aprox %d real %d\n\n",i, kCandidatosAprox[i], kCandidatosReales[i]);
    }

}


void workload(int kPorcentaje, Obj q, consultaReal* distanciaRealAprox, consulta* distanciaHamming){

    int i;

    for(i = 0; i < kPorcentaje; i++){
        distanciaRealAprox[i].distanciaQ = distance( distanciaHamming[i].o, q);
        distanciaRealAprox[i].o = distanciaHamming[i].o;
    }

}