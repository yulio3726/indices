//
// Created by cesar on 10/19/16.
//

#include "miFile.h"
#include "funcionesImplementadas.h"

Index build (char *dbname, int n, int *argc, char ***argv){

    if(*argc < 1){
        fprintf(stderr, "Usage_ <args> ARITY\n");
        exit(1);
    }

    miFile* I;

    Tdist** tablaTemporal; //guarda las distancias a los pivotes

    arregloTemporal* temporal;

    int i;
    int j;
    int k = 10; //50
    int nObjetosPrueba = 1;
    int amp = 1;
    int porcentaje = amp*k;

    int** dominioTransformado; //guarda las permutaciones inversas

    int* dominioTransformadoQ;

    float recall;
    float sumaRecall;

    Obj* objetosPrueba;

    //Lista *postingList;

    Nodo* nuevoNodo;

    I = malloc( sizeof( miFile ) );

    I -> descr = malloc(strlen (dbname) + 1);
    strcpy(I -> descr, dbname);

    I -> np = openDB( I -> descr);
    if (n && (n < I -> np)) I -> np = n;

    I -> nPivotes = atoi(*argv[0]); (*argc)--; (*argv)++;

    I -> pivotes = malloc( sizeof(Obj) * I -> nPivotes );
    seleccionaPivotesAleatorio(I -> pivotes, I -> nPivotes, I -> np);
    printf("\nLos seleccionados pivotes son\n");
    muestraPivotes(I -> pivotes, I -> nPivotes);

    tablaTemporal = (Tdist **) malloc( sizeof( Tdist* ) * I->np);
    for(i = 0; i < I->np; i++){
        tablaTemporal[i] = (Tdist *) malloc( sizeof(Tdist) * I->nPivotes);
    }
    construyeTablaDistancias(tablaTemporal, I -> nPivotes, I -> np, I -> pivotes);
    printf("\nLa tabla de distancias es: \n");
    muestraTablaflotante(tablaTemporal, I -> nPivotes, I -> np);

    dominioTransformado = (int **)malloc(sizeof(int*) * I->np);
    for(i = 0; i < I->np; i++){
        dominioTransformado[i] = (int *)malloc(sizeof(int) * I->nPivotes);
    }

    temporal = (arregloTemporal *) malloc( sizeof(arregloTemporal) * I->nPivotes);

    for(i = 0; i < I->np; i++){
        copiaArregloTemporal(tablaTemporal, i, I->nPivotes, temporal);
        qsort(temporal, I->nPivotes, sizeof(arregloTemporal), cmpFloat);
        guardaInversa(temporal,dominioTransformado,i, I->nPivotes);
    }

    muestraTablaEntera(dominioTransformado, I->np, I->nPivotes);


    I->postingList = (Lista *)malloc(sizeof(Lista) * I->nPivotes);
    for(i = 0; i < I->nPivotes; i++){
        inicializaLista(&I->postingList[i]);
    }

    nuevoNodo = (Nodo * )malloc(sizeof( Nodo));

    for(j = 0; j < I->nPivotes; j++){
        for( i = 0; i < I->np; i++){
            nuevoNodo = creaNodo(i, dominioTransformado[i][j]);
            insertaNodoLista(&I->postingList[j],nuevoNodo);
        }

    }

    printf("Los objetos en el posting list son:\n");
    for(i = 0; i < I->nPivotes; i++){
        muestraLista(&I->postingList[i]);
    }

    objetosPrueba = (Obj *)malloc(sizeof(Obj)*nObjetosPrueba);
    dominioTransformadoQ = (int *)malloc(sizeof(int) * I->nPivotes);

    seleccionaObjetosPrueba(objetosPrueba, nObjetosPrueba, I->np);

    for(i = 0; i < nObjetosPrueba; i++){
        printf("\nse calcula el indice invertido de la consulta %d\n",objetosPrueba[i]);
        calculaDistanciaReferenciasConsulta(objetosPrueba[i], temporal, I->nPivotes, I->pivotes);
       //printf("\tLas distancias no ordenadas entre la consulta y las referencias son:\n");
        //muestraArregloTemporal(temporal, I->nPivotes);
        qsort(temporal, I->nPivotes, sizeof(arregloTemporal), cmpFloat);
        //printf("\tLas distancias ordenadas entre la consulta y las referencias son:\n");
        //muestraArregloTemporal(temporal, I->nPivotes);
        guardaInversaQ(temporal, dominioTransformadoQ, I->nPivotes);
        printf("El domio transformado de q es:\n");
        muestraDominioTransformadoQ(dominioTransformadoQ, I->nPivotes);

        sumaRecall = 0;
        recall = kNN(I, k, porcentaje, dominioTransformadoQ, objetosPrueba[i]);
        sumaRecall = sumaRecall + recall;

        printf("promedio recall %f\n\n", sumaRecall/nObjetosPrueba);
    }

    free(I);
    free(temporal);
    free(dominioTransformado);
    free(dominioTransformadoQ);
    closeDB();
    return (Index) I;
}

float kNN(miFile* I, int k, int porcentaje, int* dominioTransformadoQ, Obj q){

    int i;
    int o;
    int interseccion = 0;

    int* inversaQReal;

    float recall = 0;
    float errorDePosicion = 0;

    Nodo* aux = NULL;

    Obj* knnAproximado = NULL;
    Obj* knnReal = NULL;

    Obj objetivo;
    Obj resultado;

    arregloTemporal* distanciaObjetoConsultaAprox;
    arregloTemporal* distanciaRealObjetoConsultaAprox;
    arregloTemporal* distanciaObjetoConsultaReal;


    distanciaObjetoConsultaAprox = (arregloTemporal *)malloc(sizeof(arregloTemporal) * I->np);
    inicializaDistanciasAprox(distanciaObjetoConsultaAprox, I->np);

    //printf("jajaja\n");
    for(i = 0; i < I->nPivotes; i++){
        //printf("\n\nse revisa la lista numero %d\n", i+1);
        aux = I->postingList[i].inicio;
        o = 0;
        while(aux != NULL){
            distanciaObjetoConsultaAprox[o].distancia = distanciaObjetoConsultaAprox[o].distancia + abs(aux->pivotePosicionCercania - dominioTransformadoQ[i]);
            aux = aux->siguiente;
            o = o + 1;
        }
       //muestraArregloTemporal(distanciaObjetoConsultaAprox, I->np);
    }

    //printf("distancias aprox desordenadas\n");
    //muestraArregloTemporal(distanciaObjetoConsultaAprox, I->np);

    qsort(distanciaObjetoConsultaAprox, I->np, sizeof(arregloTemporal), cmpEntero);
    //printf("\ndistancias aprox ordenadas\n");
    //muestraArregloTemporal(distanciaObjetoConsultaAprox, I->np);

    distanciaRealObjetoConsultaAprox = (arregloTemporal *)malloc( sizeof( arregloTemporal ) * porcentaje);
    reRanking(porcentaje, q, distanciaRealObjetoConsultaAprox, distanciaObjetoConsultaAprox);
    qsort(distanciaRealObjetoConsultaAprox, porcentaje, sizeof(arregloTemporal), cmpFloat);
    //printf("Los objetos candidatos aproximados en donde hay que seleccionar los k vecinos as cercanos es:\n");
    //muestraArregloTemporal(distanciaRealObjetoConsultaAprox, porcentaje);

    distanciaObjetoConsultaReal = (arregloTemporal *) malloc(sizeof(arregloTemporal) * I->np);
    //inicializaDistanciasAprox(distanciaObjetoConsultaReal, I->np);
    calculaDistanciaReal(distanciaObjetoConsultaReal, I -> np, q);
    qsort(distanciaObjetoConsultaReal, I->np, sizeof(arregloTemporal), cmpFloat);
    //printf("La consulta real ordenada es :\n");
    //muestraArregloTemporal(distanciaObjetoConsultaReal, I->np);

    knnAproximado = (Obj *)malloc( sizeof(Obj) * k);
    knnReal = (Obj *)malloc(sizeof(Obj) * k);

    calculaCandidatos(distanciaObjetoConsultaReal, distanciaRealObjetoConsultaAprox, knnReal, knnAproximado, k);

    // se calculael errror de posicion

    inversaQReal = (int *)malloc(sizeof(int) * I->np);
    guardaInversaQReal(distanciaObjetoConsultaReal,inversaQReal, I->np);
    //printf("La inversa de La consulta real es:\n");
    //muestraDominioTransformadoQ(inversaQReal, I->np);

    errorDePosicion = calculaErrorDePosicion(knnAproximado, inversaQReal, k, I->np);
    printf("\nEl error de posicion es %f\n", errorDePosicion);
    // se finaliza el calculo del error de posicion

    //printf("Los knn aprox ordenados son:\n");
    qsort(knnAproximado, k, sizeof(Obj), cmpObjEntero);
    //muestraArregloEntero(knnAproximado, k);
    //printf("Los knn reales ordenados son: \n");
    //muestraArregloTemporal(knnReal, k);

    for(i = 0; i < k; i++){

        objetivo = knnReal[i];
        resultado = (int*) bsearch( &objetivo, knnAproximado, k, sizeof( Obj ), cmpObjEntero);
        if( resultado != NULL){
            interseccion++;
        }
    }


    recall = ((float)interseccion / (float) k) * 100;


    free(distanciaObjetoConsultaAprox);
    free(distanciaRealObjetoConsultaAprox);
    free(distanciaObjetoConsultaReal);
    free(knnAproximado);
    free(knnReal);
    free(inversaQReal);
    return recall;
}