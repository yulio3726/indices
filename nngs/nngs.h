//
// Created by cesar on 9/30/16.
//

#include "../../basics.h"
#include "../../index.h"

#ifndef SWE_SWE_H
#define SWE_SWE_H

float calculaMediana(float* temporal, int n);

typedef struct{

    float **M;

    Tdist **coordenadas; //vectores que representan a los objetos originales

    Obj *pivotes; //pivotes seleccinonados

    char * descr; //nombre de la BD

    int m; // numero de pivotes
    int nBD; //tamaño de la base de datos
    int l; //logitud de los sketches

    float *b;

    unsigned int *sketches;
    unsigned int *sketchesPart2;
    unsigned int *sketchesPart3;
    unsigned int *sketchesPart4;
    unsigned int *sketchesPart5;
    unsigned int *sketchesPart6;
    unsigned int *sketchesPart7;
    unsigned int *sketchesPart8;
    unsigned int *sketchesPart9;
    unsigned int *sketchesPart10;

}swe;

typedef struct {

    Obj o;
    int distanciaQ;

}consulta;

typedef struct {

    Obj o;
    float distanciaQ;

}consultaReal;

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
/* funciones */

void seleccionaPivotesAleatorio(swe* G) {

    int i;

    for (i = 0; i < G -> m; i++){
        G -> pivotes[i] = rand() %G -> nBD + 1;
    }
}


void construyeCoordenadas(swe* G){

    int i;
    int j;

    // m representa el numero de dimenciones del vector

    G -> coordenadas = (Tdist **)malloc( sizeof( Tdist* ) * G -> nBD ); //respacio para el numero de coordenadas o filas

    for(i = 0; i < G -> nBD; i++){
        G -> coordenadas[i] = (Tdist*)malloc( sizeof( Tdist ) * G -> m);//espacio para las dimenciones de cada fila
    }

    /*se construyen las nuevas representaciones de los objetos*/
    for(i = 0; i < G -> nBD;  i++){
        for(j = 0; j <  G -> m ; j++){
            G -> coordenadas[i][j] = distance(i+1 , G -> pivotes[j]);
        }
        //printf("obj %d coordenada %d\n", i, j);
    }

}


void construyeMHeuristica1(swe* G){

    int i;
    int j;

    srand48(time(NULL));

    for (i = 0; i < G -> l; i++){
        for( j = 0; j < G -> m; j++){
            G -> M[i][j] = drand48(); //dran48() numeros aleatorios entre [0,1] con una distribucion uniforme
        }
    }

}


int cmpFloat(const void *a, const void *b){

    float *c1 = (float *) a;
    float *c2 = (float *) b;

    if( *c1 < *c2)
        return -1;
    else
        if(*c1 > *c2)
            return 1;

    return 0;

}


void construyeB(swe* G){

    int i;
    int j;
    int k;

    float *temporal;

    float suma;

    temporal = (float*)malloc( sizeof( float ) * G -> nBD);

    //printf("\n\n/*******************************************/\n\n");
    //printf("\ncalculando las medias para construir B\n");

    for(i = 0; i < G -> l; i++){ // G - > l filas de M
      //  printf("l [%d]\n", i);
        for(j = 0; j < G -> nBD; j++){ //G -> nBD n filas de la base de datos
            suma = 0;
            for(k = 0; k < G -> m; k++) { //para que multiplique las dimensiones
                suma = suma + (G -> M[i][k] * G -> coordenadas[j][k] );
            }
            temporal[j] = suma;
        }

        //printf("\ntemporal no ordenado\n");
        //for(j = 0; j < G -> nBD; j++){
        //    printf("%f\n", temporal[j]);
        //}

        qsort( temporal, G -> nBD, sizeof(float), cmpFloat);

        //printf("\ntemporal ordenado\n");
        //for(j = 0; j < G -> nBD; j++){
        //    printf("%f\n", temporal[j]);
        //}

        G -> b[i] = calculaMediana(temporal, G -> nBD);
        //printf("selecciono %f\n", G -> b[i]);
    }

    free(temporal);
}


float calculaMediana(float* temporal, int n){

    float mediana;

    int indice;

    indice = n/2;

    if( n % 2 == 0 )
        mediana = (temporal[indice - 1] + temporal[indice]) / 2;
    else
        mediana = temporal[indice];

    return mediana;
}


void generaConsultas(Obj* objetosConsulta, int n, int rango){

    int i;
    srand(time(NULL));
    for( i = 0; i < n; i++){
        objetosConsulta[i] = rand() %rango + 1;
    }

}


void muestraObjetosConsulta(Obj* objetosConsulta, int n ){

    int i;
    printf("\n/**************************************/\n");
    printf("se seleccionaron los siguientes objetos para las consultas:\n");

    for(i = 0; i < n; i++){
        printf("objeto[%d]: %d \n", i, objetosConsulta[i]);
    }

}


int hamming(unsigned int a, unsigned int b){

    return ( __builtin_popcount( a ^ b ) );

}


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

void construyeMHeuristica2(swe* G){

    int i;
    int j;

    srand48(time(NULL));

    for (i = 0; i < G -> l; i++){
        for( j = 0; j < G -> m; j++){
            if(drand48() > 0.5)
                G -> M[i][j] = 1;
            else
                G -> M[i][j] = 0;
        }
    }

    /*for( j = 0; j < G -> m; j++){
        printf("%d - %f\n", j, G->M[0][j]);
    }*/

}


void generaSketch(sketchQ* sQ, float* vectorConsulta, swe* G){

    int j;
    int dimension;
    int posicion = 0;

    float sumaProductoPunto=0;
    unsigned int s = 0;


   // printf("\n\n/************************************/\n\n");
  //  printf("\n el sketh que le corresponde a la consulta es:\n");
    for(dimension = 0; dimension < G -> l; dimension++) {

        sumaProductoPunto = 0;

        for (j = 0; j < G -> m; j++) {
            sumaProductoPunto = sumaProductoPunto + (G -> M[dimension][j] * vectorConsulta[j]);
        }
          //  printf(" a");
        //printf("Suma producto punto %f\n", sumaProductoPunto);

        if( (sumaProductoPunto - G -> b[dimension]) > 0){

        //   printf(" 1 ");

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

        }else{
          //  printf(" 0 ");
        }

    }
    //printf(" \n");
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


void calculaVectorConsulta(swe* G, Obj q, float* vectorConsulta){

    int i;

    float *temp;
    float sumaCuadrados;

    for(i = 0; i < G -> m; i++){
        vectorConsulta[i] = distance(G -> pivotes[i], q);
    }

    temp = (float*) malloc(sizeof ( float ) * G -> m);
    sumaCuadrados = 0 ;

    for(i = 0; i < G -> m; i++){
        sumaCuadrados = sumaCuadrados + pow(vectorConsulta[i],2);
    }

    sumaCuadrados = sqrt(sumaCuadrados);

    for(i = 0; i < G -> m; i++){
        temp[i] = vectorConsulta[i] / sumaCuadrados;
    }

    for(i = 0; i < G -> m; i++){
        vectorConsulta[i] = temp[i];
    }

    free(temp);
}


void muestraVectorConsulta(float* vectorConsulta, int n){

    int i;

    printf("\n\n/********************************/\n\n");
    printf("el vector que le corresponde a la consulta (ya normalizada) es:\n\n");

    for( i = 0 ; i < n ; i++){
        printf(" %f ", vectorConsulta[i]);
    }

    printf("\n\n n vale %d\n", n);
}


void normalizaCoordenadas(swe* G){

    int i;
    int j;

    float **temp;
    float sumaCuadrados;

   // printf("\n\n/************************/\n");
    //printf("Cada linea se normaliza con :\n\n");

    temp = (float **)malloc(sizeof(float*) * G -> nBD);
    for(i = 0; i < G -> nBD; i++){
        temp[i] = (float *)malloc( sizeof (float) * G -> m);
    }


    for(i = 0; i < G -> nBD; i++){
        sumaCuadrados = 0;

        //printf("1\n");
        for(j = 0; j < G -> m; j++){
            sumaCuadrados = sumaCuadrados + pow( G -> coordenadas[i][j], 2);
        }

        sumaCuadrados = sqrt(sumaCuadrados);

      //  printf("[%d] norma: %f\n", i, sumaCuadrados );

        // printf("2\n");
        for(j = 0; j < G-> m; j++){
            temp[i][j] = G -> coordenadas[i][j] / sumaCuadrados;
        }

        /* sumaCuadrados = 0;
         printf("3\n");
         for(j = 0; j < G -> m; j++){
             sumaCuadrados = sumaCuadrados + pow( temp[i][j], 2);
         }

         sumaCuadrados = sqrt(sumaCuadrados);

         printf("la norma %d es : %f\n", i, sumaCuadrados);*/

    }

    for( i = 0; i < G -> nBD; i++){
        for(j = 0; j < G -> m; j++){
            G -> coordenadas[i][j] = temp[i][j];
        }
    }

    free(temp);

}

#endif //SWE_SWE_H
