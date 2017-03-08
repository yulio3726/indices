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
    unsigned int *sketchesPart9; // 288 bits
    unsigned int *sketchesPart10; // 320 bits
    unsigned int *sketchesPart11; // 352 bits
    unsigned int *sketchesPart12; // 384  bits
    unsigned int *sketchesPart13; // 416 bits
    unsigned int *sketchesPart14; // 448 bits
    unsigned int *sketchesPart15; // 480 bits
    unsigned int *sketchesPart16; // 512 bits
    unsigned int *sketchesPart17; // 544 bits
    unsigned int *sketchesPart18; // 576 bits
    unsigned int *sketchesPart19; // 608 bits
    unsigned int *sketchesPart20; // 640 bits
    unsigned int *sketchesPart21; // 672 bits
    unsigned int *sketchesPart22; // 704 bits
    unsigned int *sketchesPart23; // 736 bits
    unsigned int *sketchesPart24; // 768 bits
    unsigned int *sketchesPart25; // 800 bits
    unsigned int *sketchesPart26; // 832 bits
    unsigned int *sketchesPart27; // 864 bits
    unsigned int *sketchesPart28; // 896 bits
    unsigned int *sketchesPart29; // 928 bits
    unsigned int *sketchesPart30; // 960 bits
    unsigned int *sketchesPart31; // 992 bits
    unsigned int *sketchesPart32; // 1024 bits
    unsigned int *sketchesPart33; // 1056 bits
    unsigned int *sketchesPart34; // 1088 bits
    unsigned int *sketchesPart35; // 1120 bits
    unsigned int *sketchesPart36; // 1152 bits
    unsigned int *sketchesPart37; // 1184 bits
    unsigned int *sketchesPart38; // 1216 bits
    unsigned int *sketchesPart39; // 1248 bits
    unsigned int *sketchesPart40; // 1280 bits
    unsigned int *sketchesPart41; // 1312 bits
    unsigned int *sketchesPart42; // 1344 bits
    unsigned int *sketchesPart43; // 1376 bits
    unsigned int *sketchesPart44; // 1408 bits
    unsigned int *sketchesPart45; // 1440 bits
    unsigned int *sketchesPart46; // 1472 bits
    unsigned int *sketchesPart47; // 1504 bits
    unsigned int *sketchesPart48; // 1536 bits
    unsigned int *sketchesPart49; // 1568 bits
    unsigned int *sketchesPart50; // 1600 bits
    unsigned int *sketchesPart51; // 1632 bits
    unsigned int *sketchesPart52; // 1664 bits
    unsigned int *sketchesPart53; // 1696 bits
    unsigned int *sketchesPart54; // 1728 bits
    unsigned int *sketchesPart55; // 1760 bits
    unsigned int *sketchesPart56; // 1792 bits
    unsigned int *sketchesPart57; // 1824 bits
    unsigned int *sketchesPart58; // 1856 bits
    unsigned int *sketchesPart59; // 1888 bits
    unsigned int *sketchesPart60; // 1920 bits
    unsigned int *sketchesPart61; // 1952 bits
    unsigned int *sketchesPart62; // 1984 bits
    unsigned int *sketchesPart63; // 2016 bits
    unsigned int *sketchesPart64; // 2048 bits
    unsigned int *sketchesPart65; // 2080 bits
    unsigned int *sketchesPart66; // 2112 bits
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
    unsigned int sketchesPart9; // 288 bits
    unsigned int sketchesPart10; // 320 bits
    unsigned int *sketchesPart11; // 352 bits
    unsigned int *sketchesPart12; // 384  bits
    unsigned int *sketchesPart13; // 416 bits
    unsigned int *sketchesPart14; // 448 bits
    unsigned int *sketchesPart15; // 480 bits
    unsigned int *sketchesPart16; // 512 bits
    unsigned int *sketchesPart17; // 544 bits
    unsigned int *sketchesPart18; // 576 bits
    unsigned int *sketchesPart19; // 608 bits
    unsigned int *sketchesPart20; // 640 bits
    unsigned int *sketchesPart21; // 672 bits
    unsigned int *sketchesPart22; // 704 bits
    unsigned int *sketchesPart23; // 736 bits
    unsigned int *sketchesPart24; // 768 bits
    unsigned int *sketchesPart25; // 800 bits
    unsigned int *sketchesPart26; // 832 bits
    unsigned int *sketchesPart27; // 864 bits
    unsigned int *sketchesPart28; // 896 bits
    unsigned int *sketchesPart29; // 928 bits
    unsigned int *sketchesPart30; // 960 bits
    unsigned int *sketchesPart31; // 992 bits
    unsigned int *sketchesPart32; // 1024 bits
    unsigned int *sketchesPart33; // 1056 bits
    unsigned int *sketchesPart34; // 1088 bits
    unsigned int *sketchesPart35; // 1120 bits
    unsigned int *sketchesPart36; // 1152 bits
    unsigned int *sketchesPart37; // 1184 bits
    unsigned int *sketchesPart38; // 1216 bits
    unsigned int *sketchesPart39; // 1248 bits
    unsigned int *sketchesPart40; // 1280 bits
    unsigned int *sketchesPart41; // 1312 bits
    unsigned int *sketchesPart42; // 1344 bits
    unsigned int *sketchesPart43; // 1376 bits
    unsigned int *sketchesPart44; // 1408 bits
    unsigned int *sketchesPart45; // 1440 bits
    unsigned int *sketchesPart46; // 1472 bits
    unsigned int *sketchesPart47; // 1504 bits
    unsigned int *sketchesPart48; // 1536 bits
    unsigned int *sketchesPart49; // 1568 bits
    unsigned int *sketchesPart50; // 1600 bits
    unsigned int *sketchesPart51; // 1632 bits
    unsigned int *sketchesPart52; // 1664 bits
    unsigned int *sketchesPart53; // 1696 bits
    unsigned int *sketchesPart54; // 1728 bits
    unsigned int *sketchesPart55; // 1760 bits
    unsigned int *sketchesPart56; // 1792 bits
    unsigned int *sketchesPart57; // 1824 bits
    unsigned int *sketchesPart58; // 1856 bits
    unsigned int *sketchesPart59; // 1888 bits
    unsigned int *sketchesPart60; // 1920 bits
    unsigned int *sketchesPart61; // 1952 bits
    unsigned int *sketchesPart62; // 1984 bits
    unsigned int *sketchesPart63; // 2016 bits
    unsigned int *sketchesPart64; // 2048 bits
    unsigned int *sketchesPart65; // 2080 bits
    unsigned int *sketchesPart66; // 2112 bits
}SKETCHQ;

#endif //SBEP2_SBEP2_H
