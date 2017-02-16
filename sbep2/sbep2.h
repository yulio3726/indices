//
// Created by cesar on 2/16/17.
//

#include "../../basics.h"
#include "../../index.h"

#ifndef SBEP2_SBEP2_H
#define SBEP2_SBEP2_H

typedef struct{

    Obj* p; //arreglo de los permutantes
    char* descr; //nombre de la base de datos
    int np; //tamaño de la base de datos
    int k; //longitud del sketch
    unsigned int *sketches;      //32 bits
    unsigned int *sketchesPart2; // 64 bits
    unsigned int *sketchesPart3; // 96 bits
    unsigned int *sketchesPart4; // 128 bits
    unsigned int *sketchesPart5; // 160 bits
    unsigned int *sketchesPart6; // 192 bits
    unsigned int *sketchesPart7; // 224 bits
    unsigned int *sketchesPart8; // 256 bits
}SBEP2;

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

typedef struct{

    unsigned int sketches;      // 32 bits
    unsigned int sketchesPart2; // 64 bits
    unsigned int sketchesPart3; // 96 bits
    unsigned int sketchesPart4; // 128 bits
    unsigned int sketchesPart5; // 160 bits
    unsigned int sketchesPart6; // 192 bits
    unsigned int sketchesPart7; // 224 bits
    unsigned int sketchesPart8; // 256 bits
}SKETCHQ;

#endif //SBEP2_SBEP2_H
