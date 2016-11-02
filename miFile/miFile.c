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

    miFile *I;

    Tdist **tablaTemporal; //guarda las distancias a los pivotes

    arregloTemporal *temporal;

    int i;
    int j;
    int nObjetosPrueba = 1;

    int **dominioTransformado; //guarda las permutaciones inversas

    int *dominioTransformadoQ;

    Obj *objetosPrueba;

    Lista *postingList;

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

    tablaTemporal = (Tdist**) malloc( sizeof( Tdist* ) * I->np);
    for(i = 0; i < I->np; i++){
        tablaTemporal[i] = (Tdist*) malloc( sizeof(Tdist) * I->nPivotes);
    }
    construyeTablaDistancias(tablaTemporal, I -> nPivotes, I -> np, I -> pivotes);
    printf("\nLa tabla de distancias es: \n");
    muestraTablaflotante(tablaTemporal, I -> nPivotes, I -> np);

    dominioTransformado = (int**)malloc(sizeof(int*) * I->np);
    for(i = 0; i < I->np; i++){
        dominioTransformado[i] = (int*)malloc(sizeof(int) * I->nPivotes);
    }

    temporal = (arregloTemporal*) malloc( sizeof(arregloTemporal) * I->nPivotes);

    for(i = 0; i < I->np; i++){
        copiaArregloTemporal(tablaTemporal, i, I->nPivotes, temporal);
        qsort(temporal, I->nPivotes, sizeof(arregloTemporal), cmpFloat);
        guardaInversa(temporal,dominioTransformado,i, I->nPivotes);
    }

    muestraTablaEntera(dominioTransformado, I->np, I->nPivotes);


    postingList = (Lista *)malloc(sizeof(Lista) * I->nPivotes);
    for(i = 0; i < I->nPivotes; i++){
        inicializaLista(&postingList[i]);
    }

    nuevoNodo = (Nodo * )malloc(sizeof( Nodo));

    for(j = 0; j < I->nPivotes; j++){
        for( i = 0; i < I->np; i++){
            nuevoNodo = creaNodo(i, dominioTransformado[i][j]);
            insertaNodoLista(&postingList[j],nuevoNodo);
        }

    }

    printf("Los objetos en el posting list son:\n");
    for(i = 0; i < I->nPivotes; i++){
        muestraLista(&postingList[i]);
    }

    objetosPrueba = (Obj *)malloc(sizeof(Obj)*nObjetosPrueba);
    dominioTransformadoQ = (int *)malloc(sizeof(int) * I->nPivotes);

    seleccionaObjetosPrueba(objetosPrueba, nObjetosPrueba, I->np);

    for(i = 0; i < nObjetosPrueba; i++){
        printf("\nse calcula el indice invertido de la consulta %d\n",objetosPrueba[i]);
        calculaDistanciaReferenciasConsulta(objetosPrueba[i], temporal, I->nPivotes, I->pivotes);
        printf("\tLas distancias no ordenadas entre la consulta y las referencias son:\n");
        muestraArregloTemporal(temporal, I->nPivotes);
        qsort(temporal, I->nPivotes, sizeof(arregloTemporal), cmpFloat);
        printf("\tLas distancias ordenadas entre la consulta y las referencias son:\n");
        muestraArregloTemporal(temporal, I->nPivotes);
        guardaInversaQ(temporal, dominioTransformadoQ, I->nPivotes);
        printf("La inversa de q es:\n");
        muestraDominioTransformadoQ(dominioTransformadoQ, I->nPivotes);
    }

    free(I);
    free(temporal);
    free(dominioTransformado);
    free(dominioTransformadoQ);
    closeDB();
    return (Index) I;
}
