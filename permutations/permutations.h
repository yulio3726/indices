//
// Created by cesar on 2/16/17.
//

#include "../../basics.h"
#include "../../index.h"

#ifndef PERMUTATIONS_PERMUTATIONS_H
#define PERMUTATIONS_PERMUTATIONS_H

typedef struct{

    Obj* p; //arreglo de los permutantes
    char* descr; //nombre de la base de datos
    int np; //tamaño de la base de datos
    int k; //numero de hiperplanos, longitud del sketch
    Obj** tabla;

}PERMUTATIONS;

/*typedef struct {

    Obj o;
    Obj* permutation;

}OPermutantion;*/

typedef struct{

    Tdist distancia;
    int indice;

}ARRAYTEMPORAL;

typedef struct {

    Obj o;
    int distanciaQ;

}CONSULTA;

typedef struct {

    Obj o;
    float distanciaQ;

}CONSULTAREAL;


#endif //PERMUTATIONS_PERMUTATIONS_H
