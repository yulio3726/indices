//
// Created by cesar on 10/19/16.
//



#ifndef MIFILE_MIFILE_H
#define MIFILE_MIFILE_H

#include "../../basics.h"
#include "../../index.h"


typedef struct{

    Obj *pivotes; //pivotes seleccionados

    char *descr; //nombre de la base de datos

    int np; //tamaño de la base de datos
    int nPivotes;

}miFile;

typedef struct{

    Tdist distancia;
    int indice;

}arregloTemporal;

#endif //MIFILE_MIFILE_H
