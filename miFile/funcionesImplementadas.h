//
// Created by cesar on 10/23/16.
//

#ifndef FUNCIONESIMPLEMENTADASINCLUDED
#define FUNCIONESIMPLEMENTADASINCLUDED

#include <time.h>
#include "miFile.h"

void seleccionaPivotesAleatorio(miFile* I){

    int i;

    srand( time( NULL ) );

    for(i = 0; i < I -> nPivotes; i++){
        I -> pivotes[i] = rand()% I->np +1;
    }

}

void muestraPivotes(miFile* I){

    int i;

    for(i = 0; i < I -> nPivotes; i++){
        printf("pivote [%d] : %d \n", i, I -> pivotes[i]);
    }
}

#endif

