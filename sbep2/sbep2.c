#include "sbep2.h"
#include "implementaciones.h"

float kNN(SBEP2* S, int k, int porcentaje, Obj q, SKETCHQ* sQ, CONSULTAREAL* distanciaReal);

Index build (char *dbname, int n, int *argc, char ***argv){

    if(*argc < 1){
        fprintf(stderr, "Usage_ <args> ARITY\n");
        exit(1);
    }
    
    int i = 0;
    int u = 0;
    int posicion = 0;
    int dimension = 0;
    int m = 0;

    ARRAYTEMPORAL* permutacionI;
    int* permutacionIInvertida;

    SBEP2* I;
    I = (SBEP2* )malloc( sizeof( SBEP2 ) );

    I -> descr = (char*)malloc(strlen (dbname) + 1);
    strcpy(I -> descr, dbname);

    I -> np = openDB( I -> descr);
    if (n && (n < I -> np)) I -> np = n;

    I -> k = atoi( ( *argv[0] ) ); (*argc)--; (*argv)++;

    I -> p = (Obj*)malloc( sizeof(Obj) * I -> k );
    seleccionaPivotesAleatorio(I -> p, I -> k, I -> np);

    I -> sketches = (unsigned int*)malloc( sizeof ( unsigned int ) * I -> np);
    if (I -> k > 32)
        I -> sketchesPart2 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);

    if ((I -> k > 64))
        I -> sketchesPart3 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);

    if ((I -> k > 96)) {
        I -> sketchesPart4 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 128)) {
        I -> sketchesPart5 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 160)) {
        I -> sketchesPart6 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 192)) {
        I -> sketchesPart7 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 224)) {
        I -> sketchesPart8 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    permutacionI  = (ARRAYTEMPORAL*)malloc(sizeof(ARRAYTEMPORAL)* I->k);
    permutacionIInvertida = (int*)malloc(sizeof(int) * I->k);

    i = 0;
    posicion = 0;

    m = I->k /2;

    while(i < I  -> np) {
        
        i++;//objeto de la base de datos
        u = i;

        I->sketches[u - 1] = 0;
        if (I->k > 32)
            I->sketchesPart2[u - 1] = 0;
        if (I->k > 64)
            I->sketchesPart3[u - 1] = 0;
        if (I->k > 96)
            I->sketchesPart4[u - 1] = 0;
        if (I->k > 128)
            I->sketchesPart5[u - 1] = 0;
        if (I->k > 160)
            I->sketchesPart6[u - 1] = 0;
        if (I->k > 192)
            I->sketchesPart7[u - 1] = 0;
        if (I->k > 224)
            I->sketchesPart8[u - 1] = 0;

        calculaDistanciaReferenciasConsulta(i, permutacionI, I->k, I->p);
        qsort(permutacionI, I->k, sizeof(ARRAYTEMPORAL), cmpFloat);
        guardaInversaI(permutacionI, permutacionIInvertida, I->k);

        //bit = 0;
        for( dimension = 0; dimension < I -> k; dimension++){
            if( permutacionIInvertida[dimension]<= m ){
                //bit = 1;
                if (dimension < 32) {
                    I -> sketches[i - 1] ^= (-1 ^ I -> sketches[i - 1]) & (1 << dimension);
                }

                if ((dimension >= 32) && (dimension < 64)) {
                    posicion = dimension - 32;
                    I -> sketchesPart2[i - 1] ^= (-1 ^ I -> sketchesPart2[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 64) && (dimension < 96)) {
                    posicion = dimension - 64;
                    I -> sketchesPart3[i - 1] ^= (-1 ^ I -> sketchesPart3[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 96) && (dimension < 128)) {
                    posicion = dimension - 96;
                    I -> sketchesPart4[i - 1] ^= (-1 ^ I -> sketchesPart4[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 128) && (dimension < 160)) {
                    posicion = dimension - 128;
                    I -> sketchesPart5[i - 1] ^= (-1 ^ I -> sketchesPart5[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 160) && (dimension < 192)) {
                    posicion = dimension - 160;
                    I -> sketchesPart6[i - 1] ^= (-1 ^ I -> sketchesPart6[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 192) && (dimension < 224)) {
                    posicion = dimension - 192;
                    I -> sketchesPart7[i - 1] ^= (-1 ^ I -> sketchesPart7[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 224) && (dimension < 256)) {
                    posicion = dimension - 224;
                    I -> sketchesPart8[i - 1] ^= (-1 ^ I -> sketchesPart8[i - 1]) & (1 << posicion);
                }
            }
        }
    }

    pruebas(I);

    free(permutacionI);
    free(permutacionIInvertida);

    return (Index) I;

}

void pruebas(Index S){

    printf("\n\t INICIAN LAS PRUEBAS\n");
    SBEP2* I = (SBEP2*)S;

    int i;
    int j;
    int k = 2; //los k vecinos mas cercanos que quiero
    int nObjetosPrueba = 300; //numero de veces que se va a repetir las pruebas
    int porcentaje[] = {1, 3, 5, 7, 10}; //porcentaje que se va a revisar de la base de datos
    int nPorcentaje = 5;
    int m = I->k /2;

    Obj* objetosConsulta;

    CONSULTAREAL* distanciaReal = NULL;
    float recall;
    float sumaRecall[nPorcentaje];
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    objetosConsulta = (Obj*) malloc( sizeof (Obj) * nObjetosPrueba);
    generaConsultas(objetosConsulta, nObjetosPrueba, I -> np);

    SKETCHQ sQ;

    distanciaReal = ( CONSULTAREAL* ) malloc( sizeof( CONSULTAREAL ) * I -> np);

    printf("\n\tK = %d\n", k);
    for(j = 0; j < nObjetosPrueba; j++){

        generaSketch(&sQ, objetosConsulta[j] , I -> p, I->k, m); //se genera el sketch de la consulta

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &sQ, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }

    /***********************************************************************************************************/

    k = 4;
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    printf("\n\tK = %d\n", k);
    for(j = 0; j < nObjetosPrueba; j++){

        generaSketch(&sQ, objetosConsulta[j] , I -> p, I->k, m); //se genera el sketch de la consulta

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &sQ, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }

    /***********************************************************************************************************/

    k = 8;
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    printf("\n\tK = %d\n", k);
    for(j = 0; j < nObjetosPrueba; j++){

        generaSketch(&sQ, objetosConsulta[j] , I -> p, I->k, m); //se genera el sketch de la consulta

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &sQ, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }

    /***********************************************************************************************************/

    k = 16;
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    printf("\n\tK = %d\n", k);
    for(j = 0; j < nObjetosPrueba; j++){

        generaSketch(&sQ, objetosConsulta[j] , I -> p, I->k, m); //se genera el sketch de la consulta

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &sQ, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }

    /***********************************************************************************************************/

    k = 32;
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    printf("\n\tK = %d\n", k);
    for(j = 0; j < nObjetosPrueba; j++){

        generaSketch(&sQ, objetosConsulta[j] , I -> p, I->k, m); //se genera el sketch de la consulta

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &sQ, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }

    free(objetosConsulta);
    free(distanciaReal);
    free(S);
}

float kNN(SBEP2* S, int k, int porcentaje,Obj q, SKETCHQ* sQ, CONSULTAREAL* distanciaReal){

    CONSULTA* distanciaHamming = NULL;

    CONSULTAREAL* distanciaRealAprox = NULL;

    int kPorcentaje;
    int i;
    int interseccion = 0;
    int objetivo = 0;
    int dist;

    int* kCandidatosAprox = NULL;
    int* kCandidatosReal = NULL;
    int* resultado = NULL;

    float recall=0;

    distanciaHamming = ( CONSULTA* ) malloc( sizeof(CONSULTA) * S -> np);

    for( i = 0 ;i < S -> np; i++){
        dist = hamming( sQ->sketches , S -> sketches[i]);//el que se calcula por defecto
        
        if( S ->  k > 32 )
            dist = dist + hamming( sQ->sketchesPart2 , S -> sketchesPart2[i]);

        if( S ->  k > 64 )
            dist = dist + hamming( sQ->sketchesPart3 , S -> sketchesPart3[i]);

        if( S ->  k > 96 )
            dist = dist + hamming( sQ->sketchesPart4 , S -> sketchesPart4[i]);

        if( S ->  k > 128 )
            dist = dist + hamming( sQ->sketchesPart5 , S -> sketchesPart5[i]);

        if( S ->  k > 160 )
            dist = dist + hamming( sQ->sketchesPart6 , S -> sketchesPart6[i]);

        if( S ->  k > 192 )
            dist = dist + hamming( sQ->sketchesPart7 , S -> sketchesPart7[i]);

        if( S ->  k > 224 )
            dist = dist + hamming( sQ->sketchesPart8 , S -> sketchesPart8[i]);

        distanciaHamming[i].distanciaQ = dist;
        distanciaHamming[i].o = i + 1;
    }

    qsort( distanciaHamming, S -> np, sizeof( CONSULTA ) , cmpfunc);

    kPorcentaje = porcentaje * (S -> np / 100);

    distanciaRealAprox = ( CONSULTAREAL* ) malloc( sizeof( CONSULTAREAL ) * kPorcentaje );
    workload(kPorcentaje, q, distanciaRealAprox, distanciaHamming);
    qsort( distanciaRealAprox, kPorcentaje, sizeof( CONSULTAREAL ) , cmpfuncFloat);

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

    //printf("\trecall : %f\n", recall);

    free(distanciaRealAprox);
    free(kCandidatosAprox);
    free(kCandidatosReal);
    free(distanciaHamming);

    return recall;
}