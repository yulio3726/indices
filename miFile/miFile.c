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

    I = malloc( sizeof( miFile ) );

    I -> descr = malloc(strlen (dbname) + 1);
    strcpy(I -> descr, dbname);

    I -> np = openDB( I -> descr);
    if (n && (n < I -> np)) I -> np = n;

    I -> nPivotes = atoi(*argv[0]); (*argc)--; (*argv)++;

    I -> pivotes = malloc( sizeof(Obj) * I -> nPivotes );
    seleccionaPivotesAleatorio(I);
    //muestraPivotes(I);

    free(I);
    closeDB();
    return (Index) I;
}
