//
// Created by cesar on 10/19/16.
//



#ifndef MIFILE_MIFILE_H
#define MIFILE_MIFILE_H

#include "../../basics.h"
#include "../../index.h"


typedef struct{

    Tdist distancia;
    int indice;

}arregloTemporal;


typedef struct nodo_s{
    int pivotePosicionCercania;
    Obj o;
    struct nodo_s *siguiente;
}Nodo;


typedef struct ListaIdentificar{

    Nodo* inicio;
    Nodo* fin;
    //int tamano;
}Lista;

typedef struct{

    Obj* pivotes; //pivotes seleccionados

    char* descr; //nombre de la base de datos

    int np; //tamaño de la base de datos
    int nPivotes;

    Lista* postingList;

}miFile;

#endif //MIFILE_MIFILE_H
