//
// Created by cesar on 9/30/16.
//

#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "nngs.h"

Index build (char *dbname, int n, int *argc, char ***argv){

    if (*argc < 1){
        fprintf(stderr, "Usage_ <program> <args> ARITY\n");
        exit(1);
    }

    swe *G;

    int i = 0;
    int j = 0;
    int dimension = 0;
    int k = 10;
    int posicion;
    int nObjetoConsulta = 150;
    int porcentaje[] = { 1, 3, 5, 7, 9};
    int nPorcentaje = 5;

    Obj *objetosConsulta;
    Obj u;

    float recallPorcentaje[]={0,0,0,0,0};
    float sumaProductoPunto = 0;

    G = malloc( sizeof ( swe ) );

    G -> descr = malloc( strlen ( dbname) +1 );
    strcpy( G -> descr, dbname);
    //printf("\n\t name db");

    G -> nBD = openDB( G -> descr);
    //printf("\n\t open db");

    if( n && (n < G -> nBD) ) G -> nBD = n;

    G -> m = atoi( *argv[0] );
    //printf("\n\t parametro m = numero de pivotes");

    (*argc) --;
    (*argv)++;

    G -> l = atoi( *argv[0] );
    (*argc) --;
    (*argv)++;
    //printf("\n\t parametro l = longitud de los sketches");

    G -> pivotes = malloc( sizeof(Obj) * G -> m);
    G -> sketches = malloc( sizeof( unsigned int ) * G -> nBD );

    if (G -> l > 32)
        G -> sketchesPart2 = malloc( sizeof( unsigned int ) * G -> nBD );

    if(G -> l > 64)
        G -> sketchesPart3 = malloc( sizeof( unsigned int ) * G -> nBD );

    if( G -> l > 96)
        G -> sketchesPart4 = malloc( sizeof( unsigned int ) * G -> nBD );

    if( G -> l > 128)
        G -> sketchesPart5 = malloc( sizeof( unsigned int ) * G -> nBD );

    if( G -> l > 160)
        G -> sketchesPart6 = malloc( sizeof( unsigned int ) * G -> nBD );

    if( G -> l > 192)
        G -> sketchesPart7 = malloc( sizeof( unsigned int ) * G -> nBD );

    if( G -> l > 224)
        G -> sketchesPart8 = malloc( sizeof( unsigned int ) * G -> nBD );

    if( G -> l > 256)
        G -> sketchesPart9 = malloc( sizeof( unsigned int ) * G -> nBD );

    if( G -> l > 288)
        G -> sketchesPart10 = malloc( sizeof( unsigned int ) * G -> nBD);

    srand( time (NULL) );

    //printf("\n\nlos valores para l: %d, m: %d\n", G ->l, G -> m);

    //muestraObjetosBD(G);

    seleccionaPivotesAleatorio(G);
    //muestraPivotes(G);

    construyeCoordenadas(G);
    //muestraCoordenadas(G);
    normalizaCoordenadas(G);
    //muestraCoordenadasNormales(G);

    G -> M = (int **) malloc( sizeof ( int* ) * G -> l); // numero de filas
    for(i = 0; i < G -> l; i++){ // se reservan los espacios para cada fila
        G -> M[i]  = (float*)malloc( sizeof ( float ) * G -> m);

    }

    mCeros(G);
    //construyeMHeuristica1(G); //seleccionar valores en el intervalo [1,0]
    //construyeMHeuristica2(G); //seleccionar valores en (0 y 1)
    //construyeMHeuristica3(G); //ninimo m/2 unos por renglon
    construyeMHeuristica4(G);//el min de {m/2. log(n)+ log(m/2)}

    G -> b = (float*) malloc( sizeof (float) * G -> l);
    construyeB(G);

    i = 0;

    while( i < G -> nBD){ //G -> nBD
        i++;
        u = i;

            G -> sketches[u-1] = 0;
        if( G -> l > 32)
            G -> sketchesPart2[u-1] = 0;
        if(G -> l > 64)
            G -> sketchesPart3[u-1] = 0;
        if (G -> l > 96)
            G -> sketchesPart4[u-1] = 0;
        if (G -> l > 128)
            G -> sketchesPart5[u-1] = 0;
        if (G -> l > 160)
            G -> sketchesPart6[u-1] = 0;
        if (G -> l > 192)
            G -> sketchesPart7[u-1] = 0;
        if (G -> l > 224)
            G -> sketchesPart8[u-1] = 0;
        if (G -> l > 256)
            G -> sketchesPart9[u-1] = 0;
        if (G -> l > 288)
            G -> sketchesPart10[u-1] = 0;

        for(dimension = 0; dimension < G -> l; dimension++){
            sumaProductoPunto = 0;
            for(j = 0 ; j < G -> m; j++){
                sumaProductoPunto = sumaProductoPunto + (G -> M[dimension][j] * G -> coordenadas[i-1][j]);
            }

            if( (sumaProductoPunto - G -> b[dimension]) > 0){
                if (dimension < 32) {
                    G -> sketches[i - 1] ^= (-1 ^ G -> sketches[i - 1]) & (1 << dimension);
                }

                if ((dimension >= 32) && (dimension < 64)) {
                    posicion = dimension - 32;
                    G -> sketchesPart2[i - 1] ^= (-1 ^ G -> sketchesPart2[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 64) && (dimension < 96)) {
                    posicion = dimension - 64;
                    G -> sketchesPart3[i - 1] ^= (-1 ^ G -> sketchesPart3[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 96) && (dimension < 128)) {
                    posicion = dimension - 96;
                    G -> sketchesPart4[i - 1] ^= (-1 ^ G -> sketchesPart4[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 128) && (dimension < 160)) {
                    posicion = dimension - 128;
                    G -> sketchesPart5[i - 1] ^= (-1 ^ G -> sketchesPart5[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 160) && (dimension < 192)) {
                    posicion = dimension - 160;
                    G -> sketchesPart6[i - 1] ^= (-1 ^ G -> sketchesPart6[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 192) && (dimension < 224)) {
                    posicion = dimension - 192;
                    G -> sketchesPart7[i - 1] ^= (-1 ^ G -> sketchesPart7[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 224) && (dimension < 256)) {
                    posicion = dimension - 224;
                    G -> sketchesPart8[i - 1] ^= (-1 ^ G -> sketchesPart8[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 256) && (dimension < 288)) {
                    posicion = dimension - 256;
                    G -> sketchesPart9[i - 1] ^= (-1 ^ G -> sketchesPart9[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 288) && (dimension < 320)) {
                    posicion = dimension - 288;
                    G -> sketchesPart10[i - 1] ^= (-1 ^ G -> sketchesPart10[i - 1]) & (1 << posicion);

                }
            }
        }

    }

    printf("\n\t EMPIEZAN LAS PRUEBAS\n");
    objetosConsulta = (Obj *)malloc( sizeof(Obj) * nObjetoConsulta);
    generaConsultas(objetosConsulta, nObjetoConsulta, G -> nBD);

    for(i = 0; i < nObjetoConsulta; i++){
        kNN(G, k, objetosConsulta[i], &recallPorcentaje);
    }

    printf("\n\tresultados finales\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" %d.- %d promedio recall %f\n",i, porcentaje[i], recallPorcentaje[i]/nObjetoConsulta);
    }

    /*
    for(i = 0; i < nProcentaje; i++){

        sumaRecall = 0;

        for(j = 0; j < nObjetoConsulta; j++){//
           // printf("\n objeto consulta %d se  evalua el porcentaje %d\n", objetosConsulta[j], porcentaje[i]);
            recall = kNN( G , k, porcentaje[i], objetosConsulta[j]);
            //recall = 0;
            sumaRecall = sumaRecall + recall;
        }
        printf("\n");

        printf("\t %d Promedio recall %f\n\n", porcentaje[i], sumaRecall/nObjetoConsulta);
    }*/

/*    sumaRecall = 0;

    for(j = 0; j < nObjetoConsulta; j++){//
        // printf("\n objeto consulta %d se  evalua el porcentaje %d\n", objetosConsulta[j], porcentaje[i]);
        recall = kNN( G , k, porcentaje[2], objetosConsulta[j]);
        //recall = 0;
        sumaRecall = sumaRecall + recall;
    }
    printf("\n");

    printf("\t %d Promedio recall %f\n\n", porcentaje[2], sumaRecall/nObjetoConsulta);
*/

    free(G);
    //printf("ya libere\n");
    //closeDB();
    return (Index) G;
}

void muestraObjetosBD(swe* G){

    int i;

    printf("\n/********************************/\n");
    printf("Los objetos de la base de datos son:\n");

    for(i = 0 ; i < G -> nBD; i++){
        printf("[%d]: ", i+1);
        printobj(i+1);
    }

}

void muestraPivotes(swe* G){

    int i;

    printf("\n/********************************/\n");
    printf("Los m (%d) pivotes son:\n", G -> m);

    for(i = 0 ; i < G -> m; i++){
        printf("[%d] pivote: %d\n", i, G -> pivotes[i]);
    }

}

void muestraCoordenadas(swe* G){

    int i;
    int j;

    printf("\n/********************************/\n");

    printf("Las coordenadas son\n");

    for(i = 0; i < G -> nBD;  i++){
        printf("[%d] ", i+1);
        for(j = 0; j <  G -> m ; j++){
            printf(" %f ", G -> coordenadas[i][j]);
        }
        printf("\n");
    }

    printf("\nSolo para verificar la ultima coordenada debe de ser %f\n\n", distance(G -> nBD, G -> pivotes[G->m-1]) );

}

void muestraCoordenadasNormales(swe* G){

    int i;
    int j;

    printf("\n/********************************/\n");

    printf("Las coordenadas normalizadas son\n");

    for(i = 0; i < G -> nBD;  i++){
        printf("[%d] ", i+1);
        for(j = 0; j <  G -> m ; j++){
            printf(" %f ", G -> coordenadas[i][j]);
        }
        printf("\n");
    }

}

void muestraM(swe* G){

    int i;
    int j;
    printf("\n\n/*********************************************/");
    printf("\nMatriz de pesos:\n\n");

    for (i = 0; i < G -> l; i++){
        printf("\n[%d] ", i);
        for( j = 0; j < G -> m; j++){
            printf(" %f", G -> M[i][j]);
        }
    }

   // printf("\nverica parametro l : %d\n\n", G->l);
}

void muestraB(swe* G){

    int i;

    printf("\n\n/***************************************/\n\n");
    printf("los valores del vector b son: \n\n");

    for(i = 0; i < G -> l; i++){
        printf("[%d]  %f\n", i, G -> b[i]);
    }

}

void kNN(swe* G, int k, Obj q, float* recallPorcentaje){

    consulta *distanciaHamming = NULL;
    float *vectorConsulta;

    consultaReal* distanciaRealAprox = NULL;
    consultaReal *distanciaReal = NULL;

    int kPorcentaje;
    int i;
    int interseccion = 0;
    int objetivo = 0;
    int porcentaje[] = {1, 3, 5, 7, 9};
    int nPorcentaje = 5;

    int *kCandidatosAprox = NULL;
    int *kCandidatosReal = NULL;
    int *resultado = NULL;

    float recall = 0;

    sketchQ sQ;

    int dist = 0;

    vectorConsulta = (float*)malloc( sizeof ( float ) * G -> m);
    calculaVectorConsulta(G, q, vectorConsulta);
    //muestraVectorConsulta(vectorConsulta, G -> m);

    generaSketch(&sQ, vectorConsulta, G);
    //printf("\n\nya genere el S de la consulta\n");

    distanciaHamming = ( consulta* ) malloc( sizeof(consulta) * G -> nBD);

    for( i = 0 ;i < G -> nBD; i++){

        dist = hamming( sQ.sketches , G -> sketches[i]);//el que se calcula por defecto

        if( G ->  l > 32 )
            dist = dist + hamming( sQ.sketchesPart2 , G -> sketchesPart2[i]);

        if( G ->  l > 64 )
            dist = dist + hamming( sQ.sketchesPart3 , G -> sketchesPart3[i]);

        if( G ->  l > 96 )
            dist = dist + hamming( sQ.sketchesPart4 , G -> sketchesPart4[i]);

        if( G ->  l > 128 )
            dist = dist + hamming( sQ.sketchesPart5 , G -> sketchesPart5[i]);

        if( G ->  l > 160 )
            dist = dist + hamming( sQ.sketchesPart6 , G -> sketchesPart6[i]);

        if( G ->  l > 192 )
            dist = dist + hamming( sQ.sketchesPart7 , G -> sketchesPart7[i]);

        if( G ->  l > 224 )
            dist = dist + hamming( sQ.sketchesPart8 , G -> sketchesPart8[i]);

        if( G ->  l > 256 )
            dist = dist + hamming( sQ.sketchesPart9 , G -> sketchesPart9[i]);

        if( G ->  l > 288 )
            dist = dist + hamming( sQ.sketchesPart10 , G -> sketchesPart10[i]);

        distanciaHamming[i].distanciaQ = dist;
        distanciaHamming[i].o = i + 1;

        //printf("objeto %d distancia %d\n", distanciaHamming[i].o, distanciaHamming[i].distanciaQ);

    }


    qsort( distanciaHamming, G -> nBD, sizeof( consulta ) , cmpfunc);

    int a = 0;

    distanciaReal = ( consultaReal* ) malloc( sizeof( consultaReal ) * G -> nBD);
    calculaDistanciaReal(distanciaReal, G -> nBD, q);
    qsort( distanciaReal, G -> nBD, sizeof( consultaReal ), cmpfuncFloat);

    for (a = 0; a < nPorcentaje; a++) {
        kPorcentaje = porcentaje[a] * (G -> nBD / 100);
        distanciaRealAprox = ( consultaReal* ) malloc( sizeof( consultaReal ) * kPorcentaje );
        workload(kPorcentaje, q, distanciaRealAprox, distanciaHamming);
        qsort( distanciaRealAprox, kPorcentaje, sizeof( consultaReal ) , cmpfuncFloat);

        kCandidatosAprox = ( int* ) malloc( sizeof( int ) * k);
        kCandidatosReal = ( int* ) malloc( sizeof( int ) * k);

        calculaCandidatos(distanciaReal, distanciaRealAprox, kCandidatosAprox, kCandidatosReal, k);
        qsort( kCandidatosReal, k, sizeof( int ) , compara);

        interseccion = 0;
        resultado = 0;
        recall = 0;

        for(i = 0; i < k; i++){

            objetivo = kCandidatosAprox[i];
            resultado = (int*) bsearch( &objetivo, kCandidatosReal, k, sizeof( int ), compara);
            if( resultado != NULL){
                interseccion++;
            }
        }

        recall = ((float) interseccion / (float) k) * 100;
        recallPorcentaje[a]=recallPorcentaje[a] + recall;

        free(distanciaRealAprox)
        free(kCandidatosAprox);
        free(kCandidatosReal);
    }

    free(distanciaHamming);
    free(distanciaReal);

}

void muestraDistanciasRealesAprox(consultaReal* distanciaRealAprox, int kPorcentaje){
    int i;

    for(i = 0; i < kPorcentaje; i++){
        printf("Objeto %d distancia %f\n", distanciaRealAprox[i].o, distanciaRealAprox[i].distanciaQ);
    }

}

void muestraDistanciaHamming(consulta* distanciaHamming, swe* G){


    int i;

     for(i = 0; i < G -> nBD; i++){
         printf("objeto %d distancia %d\n", distanciaHamming[i].o, distanciaHamming[i].distanciaQ);
     }

}

void muestraDistanciasReales(consultaReal* distanciasReales, int n){

    int i;

    for(i = 0 ; i < n; i++){
        printf("objeto %d distancia %f\n", distanciasReales[i].o, distanciasReales[i].distanciaQ);
    }

}

void muestraCandidatos(int* candidatos, int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d\n", candidatos[i]);
    }

}

void construyeMHeuristica3(swe* G){

    int i;
    int j;
    int cont;
    int a =  G -> m /2;
    int residuo = G -> m % 2;

    if(residuo == 0){

    }else{
        a = a + 1;
    }

    for(i = 0; i < G -> l; i++){
        cont = 0;
        while(cont != a){
            j = rand() %G -> m;
            if(G -> M[i][j] == 0){
                G -> M[i][j] = 1;
                cont++;
            }
        }
    }

}

void mCeros(swe* G){

    int i;
    int j;

    for (i = 0; i < G -> l; i++){
        for( j = 0; j < G -> m; j++){
            G -> M[i][j] = 0;
        }
    }
}

void construyeMHeuristica4(swe* G){

    int i;
    int j;
    int cont;
    float a = (float) G -> m / 2;
    float b = log( G -> nBD ) + log( G -> m / 2);
    int x;
    int menor;

   // printf("a %f\n", a);
    //printf("b %f\n", b);

    if(a < b){
        x = a;
        if( ( a - x ) > 0)
            a++;
        menor = a;
    }else{
        x = b;
        if( ( b - x ) > 0)
            b++;
        menor = b;
    }

    //printf("menor %d\n", menor);
    for(i = 0; i < G -> l; i++){
        cont = 0;
        while(cont != menor){
            j = rand() %G -> m;
            if(G -> M[i][j] == 0){
                G -> M[i][j] = 1;
                cont++;
            }
        }
    }

}