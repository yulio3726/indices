#include "permutations.h"
#include "implementaciones.h"

float kNN(PERMUTATIONS* S, int k, int porcentaje,Obj q, int* permutacionInvertida, CONSULTAREAL* distanciaReal);

Index build (char *dbname, int n, int *argc, char ***argv){

    if(*argc < 1){
        fprintf(stderr, "Usage_ <args> ARITY\n");
        exit(1);
    }

    int i = 0;
    int j = 0;

    ARRAYTEMPORAL* permutacionI;
    //int* permutacionIInvertida;


    PERMUTATIONS* I;
    I = (PERMUTATIONS* )malloc( sizeof( PERMUTATIONS ) );

    I -> descr = (char*)malloc(strlen (dbname) + 1);
    strcpy(I -> descr, dbname);

    I -> np = openDB( I -> descr);
    if (n && (n < I -> np)) I -> np = n;

    I -> k = atoi( ( *argv[0] ) ); (*argc)--; (*argv)++;

    I -> p = (Obj*)malloc( sizeof(Obj) * I -> k );
    seleccionaPivotesAleatorio(I -> p, I -> k, I -> np);

    //printf("\n\tLos permutantes seleccionados son:\n");
    //muestraPivotes(I->p, I->k);
    //printf("\n");

   // pruebasFuncionamiento(I);

    I -> tabla = (Obj **) malloc( sizeof( Obj*) * I -> np); //filas
    for(i = 0; i < I->np; i++){ //columnas
        I -> tabla[i] = (Obj *) malloc( sizeof(Obj) * I -> k); //columnas
    }

    permutacionI  = (ARRAYTEMPORAL*)malloc(sizeof(ARRAYTEMPORAL)* I->k);
    //permutacionIInvertida = (int*)malloc(sizeof(int) * I->k);

    i = 0;

    while(i < I  -> np ) {

        i++;
        calculaDistanciaReferenciasConsulta(i, permutacionI, I->k, I->p);
        qsort(permutacionI, I->k, sizeof(ARRAYTEMPORAL), cmpFloat);
        guardaInversaI(permutacionI, I->tabla[i-1], I->k);

        //printf("objeto %d\n", i);
        //muestraInversa(I->tabla[i-1], I->k);
    }

    free(permutacionI);

    pruebas(I);

    //free(I->tabla);
    //free(I->p);
    return (Index) I;
}

void pruebas(Index S){

    printf("\n\t INICIAN LAS PRUEBAS\n");

    PERMUTATIONS* I = (PERMUTATIONS*)S;

    //printf("1\n");
    int i;
    int j;
    int k = 2; //los k vecinos mas cercanos que quiero
    int nObjetosPrueba = 300; //numero de veces que se va a repetir las pruebas
    int porcentaje[] = {1, 3, 5, 7, 10}; //porcentaje que se va a revisar de la base de datos
    int nPorcentaje = 5;

    //printf("2\n");
    Obj* objetosConsulta;

    CONSULTAREAL* distanciaReal = NULL;

    float recall;
    float sumaRecall[nPorcentaje];
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    ARRAYTEMPORAL* permutacionQ;
    int* permutacionQInvertida;

    objetosConsulta = (Obj*) malloc( sizeof (Obj) * nObjetosPrueba);
    seleccionaPivotesAleatorio(objetosConsulta, nObjetosPrueba, I -> np); //aca era genera consultas;

    distanciaReal = ( CONSULTAREAL* ) malloc( sizeof( CONSULTAREAL ) * I -> np);

    permutacionQ  = (ARRAYTEMPORAL*)malloc(sizeof(ARRAYTEMPORAL)* I->k);
    permutacionQInvertida = (int*)malloc(sizeof(int) * I->k);

    printf("\n\tK = %d\n", k);
    for(j = 0; j < nObjetosPrueba; j++){

        calculaDistanciaReferenciasConsulta(objetosConsulta[j], permutacionQ, I->k, I->p);
        //printf("2");
        qsort(permutacionQ, I->k, sizeof(ARRAYTEMPORAL), cmpFloat);
        guardaInversaI(permutacionQ, permutacionQInvertida, I->k);

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], permutacionQInvertida, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }

/***********************************************************************************************************/

  /*  k = 4;
    printf("\n\tK = %d\n", k);
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    for(j = 0; j < nObjetosPrueba; j++){

        calculaDistanciaReferenciasConsulta(objetosConsulta[j], permutacionQ, I->k, I->p);
        qsort(permutacionQ, I->k, sizeof(ARRAYTEMPORAL), cmpFloat);
        guardaInversaI(permutacionQ, permutacionQInvertida, I->k);

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &permutacionQInvertida, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }


    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }

    //**********************************************************************************************************

    k = 8;
    printf("\n\tK = %d\n", k);
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    for(j = 0; j < nObjetosPrueba; j++){

        calculaDistanciaReferenciasConsulta(objetosConsulta[j], permutacionQ, I->k, I->p);
        qsort(permutacionQ, I->k, sizeof(ARRAYTEMPORAL), cmpFloat);
        guardaInversaI(permutacionQ, permutacionQInvertida, I->k);

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &permutacionQInvertida, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }

    //**********************************************************************************************************

    k = 16;
    printf("\n\tK = %d\n", k);
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    for(j = 0; j < nObjetosPrueba; j++){

        calculaDistanciaReferenciasConsulta(objetosConsulta[j], permutacionQ, I->k, I->p);
        qsort(permutacionQ, I->k, sizeof(ARRAYTEMPORAL), cmpFloat);
        guardaInversaI(permutacionQ, permutacionQInvertida, I->k);

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &permutacionQInvertida, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }
    //**********************************************************************************************************

    k = 32;
    printf("\n\tK = %d\n", k);
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    for(j = 0; j < nObjetosPrueba; j++){

        calculaDistanciaReferenciasConsulta(objetosConsulta[j], permutacionQ, I->k, I->p);
        qsort(permutacionQ, I->k, sizeof(ARRAYTEMPORAL), cmpFloat);
        guardaInversaI(permutacionQ, permutacionQInvertida, I->k);

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &permutacionQInvertida, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }*/

    free(permutacionQ);
    free(permutacionQInvertida);
    free(objetosConsulta);
    free(distanciaReal);
    free(S);

}

float kNN(PERMUTATIONS* S, int k, int porcentaje,Obj q, int* permutacionQInversa, CONSULTAREAL* distanciaReal) {

    int i=0;
    int dist = 0;
    int kPorcentaje = 0;
    int interseccion = 0;
    int objetivo = 0;

    int* kCandidatosAprox = NULL;
    int* kCandidatosReal = NULL;
    int* resultado = NULL;
    float recall=0;

    CONSULTAREAL* distanciaRealAprox = NULL;
    CONSULTA* distanciaSpearmanRho = NULL;

    distanciaSpearmanRho = ( CONSULTA* ) malloc( sizeof(CONSULTA) * S -> np);

    for( i = 0 ;i < S -> np; i++){
        dist = spearmanRho( permutacionQInversa , S -> tabla[i], S->k);
        distanciaSpearmanRho[i].distanciaQ = dist;
        distanciaSpearmanRho[i].o = i + 1;
    }

    /*printf("Las distancias sp NO ordenas a la consulta %d son:\n", q);
    for(a = 0; a < 10; a++){
        printf("obj %d sp %d\n", distanciaSpearmanRho[a].o, distanciaSpearmanRho[a].distanciaQ);
    }*/

    qsort( distanciaSpearmanRho, S -> np, sizeof( CONSULTA ) , cmpfunc);


    //printf("Las distancias sp ordenas a la consulta %d son:\n", q);
    //for(a = 0; a < 10; a++){
    //    printf("obj %d sp %d\n", distanciaSpearmanRho[a].o, distanciaSpearmanRho[a].distanciaQ);
    //}

    kPorcentaje = porcentaje * (S -> np / 100);

    distanciaRealAprox = ( CONSULTAREAL* ) malloc( sizeof( CONSULTAREAL ) * kPorcentaje );
    workload(kPorcentaje, q, distanciaRealAprox, distanciaSpearmanRho);
    qsort( distanciaRealAprox, kPorcentaje, sizeof( CONSULTAREAL ) , cmpfuncFloat);

    //printf("Las distancias reales aproximadas son:\n");
    //muestraDistanciaRealAprox(distanciaRealAprox,kPorcentaje);

    kCandidatosAprox = ( int* ) malloc( sizeof( int ) * k);
    kCandidatosReal = ( int* ) malloc( sizeof( int ) * k);

    calculaCandidatos(distanciaReal, distanciaRealAprox, kCandidatosAprox, kCandidatosReal, k);

    //printf("muestra candidatos para la consulta %d:\n", q);
    //muestraCandidatos(kCandidatosAprox,kCandidatosReal,k);

    qsort( kCandidatosReal, k, sizeof( int ) , compara);

    for(i = 0; i < k; i++){

        objetivo = kCandidatosAprox[i];
        resultado = (int*) bsearch( &objetivo, kCandidatosReal, k, sizeof( int ), compara);
        if( resultado != NULL){
            interseccion++;
        }
    }

    //int a;
    //scanf("%i",&a);

    recall = ((float) interseccion / (float) k) * 100;

    free(distanciaRealAprox);
    free(kCandidatosAprox);
    free(kCandidatosReal);
    free(distanciaSpearmanRho);

    return recall;
}

void pruebasFuncionamiento(PERMUTATIONS* I){

    //ARRAYTEMPORAL* permutacion1;
    //ARRAYTEMPORAL* permutacion2;
    //ARRAYTEMPORAL* permutacion3;

    int inversa1[]={4, 2, 3, 5, 6, 1};
    int inversa2[]={4, 3, 1, 6, 5, 2};
    //int* inversa3;

    //permutacion1  = (ARRAYTEMPORAL*)malloc(sizeof(ARRAYTEMPORAL)* I->k);
    //permutacion2  = (ARRAYTEMPORAL*)malloc(sizeof(ARRAYTEMPORAL)* I->k);
    //permutacion3 = (ARRAYTEMPORAL*)malloc(sizeof(ARRAYTEMPORAL)* I->k);

    //inversa1 = (int*)malloc(sizeof(int)*I->k);
    //inversa2 = (int*)malloc(sizeof(int)*I->k);
    //inversa3 = (int*)malloc(sizeof(int)*I->k);


    //calculaDistanciaReferenciasConsulta(1, permutacion1, I->k, I->p);
    //qsort(permutacion1, I->k, sizeof(ARRAYTEMPORAL), cmpFloat);
    //muestraPermutacion(permutacion1,I->k);
    //guardaInversaI(permutacion1, inversa1, I->k);
    //muestraInversa(inversa1, I->k);

    //calculaDistanciaReferenciasConsulta(2, permutacion2, I->k, I->p);
    //qsort(permutacion2, I->k, sizeof(ARRAYTEMPORAL), cmpFloat);
    //muestraPermutacion(permutacion2,I->k);
    //guardaInversaI(permutacion2, inversa2, I->k);
    //muestraInversa(inversa2, I->k);

    //calculaDistanciaReferenciasConsulta(3, permutacion3, I->k, I->p);
    //qsort(permutacion3, I->k, sizeof(ARRAYTEMPORAL), cmpFloat);
    //muestraPermutacion(permutacion3,I->k);
    //guardaInversaI(permutacion3, inversa3, I->k);
    //muestraInversa(inversa3, I->k);

    //CONSULTA* distanciaSpearmanRho;

    int dist = 0;
    int i = 0;

    //distanciaSpearmanRho = ( CONSULTA* ) malloc( sizeof(CONSULTA) * 2);

    dist = spearmanRho( inversa1 , inversa2, 6);
    printf("distancia 1-2 = %d\n", dist);
    //distanciaSpearmanRho[0].distanciaQ = dist;
    //distanciaSpearmanRho[0].o = 2;

    //dist = 0;
    //dist = spearmanRho( inversa1 , inversa3, I->k);
    //printf("distancia 1-3 = %f\n", dist);
    //distanciaSpearmanRho[1].distanciaQ = dist;
    //distanciaSpearmanRho[1].o = 3;

    //printf("Las distancias de spearman calculadas son: \n");
    //for(i=0; i < 2; i++){
        //printf("[%d] %f\n",distanciaSpearmanRho[i].o, distanciaSpearmanRho[i].distanciaQ);
    //}

    //qsort( distanciaSpearmanRho, 2, sizeof( CONSULTA ) , cmpfuncFloat);

    //printf("y ordenadas son: \n");
    //for(i=0; i < 2; i++){
     //   printf("[%d] %f\n",distanciaSpearmanRho[i].o, distanciaSpearmanRho[i].distanciaQ);
    //}

    //free(permutacion1);
    //free(permutacion2);
    //free(permutacion3);
    //free(inversa1);
    //free(inversa2);
    //free(inversa3);

    int j = 0;
    scanf("%d",&j);

}