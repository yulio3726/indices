//
// Created by cesar on 21/09/16.
//

#include "../../basics.h"
#include "../../index.h"

/*Estructuras*/

typedef struct {

    Obj o; //tenia tipo Obj
    int distanciaQ;

}consulta;

typedef struct {

    Obj o;
    float distanciaQ;

}consultaReal;

typedef struct{

    Obj po1; //pivote 1
    Obj po2; //pivote 2

} pivot;

typedef struct{

    pivot *pivots; //arreglo de los pivotes
    unsigned int *sketches; //arreglo de los sketches el unsigned int tiene 4 bytes de tamaño por lo que tiene 32 bits
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
    int nHiperPlanos; //numero de hiperplanos, longitud del sketch
    char *descr; // nombre de la BD
    int nBaseDatos; //tamaño de la base de datos

}rbbf1;

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

}sketchQ;

/*definiciones*/


/* Funciones */
int cmpfunc(const void *a, const void *b){

    const consulta *c1 = (consulta *) a;
    const consulta *c2 = (consulta *) b;

    return ( c1 -> distanciaQ - c2 -> distanciaQ);
}


int cmpfuncFloat(const void *a, const void *b){

    const consultaReal *c1 = (consultaReal *) a;
    const consultaReal *c2 = (consultaReal *) b;

    if (c1 -> distanciaQ < c2 -> distanciaQ) return -1;
    else if (c1 -> distanciaQ > c2 -> distanciaQ) return 1;

    return 0;

}


int compara(const void *x, const void *y){

    return( *( int* )x - *( int* )y);

}


void generaConsultas(Obj* objetosConsulta, int n, int rango){

    int i;

    srand ( time ( NULL));

    for(i = 0; i < n; i++){
        objetosConsulta[i] = rand() %rango +1;
    }

}


void muestraObjetosConsulta( Obj* objetosConsulta, int n){

    int i;

    for(i = 0; i < n; i++){
        printf("objeto[%d]: %d \n", i, objetosConsulta[i]);
    }
}

void generaSketch(sketchQ* sQ, Obj u, pivot* pivots, int nHiperPlanos) {

    Tdist d1;
    Tdist d2;

    int dimension;
    int posicion = 0;

    unsigned int s = 0;


    for (dimension = 0; dimension < nHiperPlanos; dimension++) {

        d1 = distance(u, pivots[dimension].po1);
        d2 = distance(u, pivots[dimension].po2);

        if (d1 <= d2) {

            if (dimension < 32) {
                s ^= (-1 ^ s) & (1 << dimension);
                sQ->sketches = s;
            }

            if (dimension == 32)//hay que reiniciar
                s = 0;
            if ((dimension >= 32) && (dimension < 64)) {
                posicion = dimension - 32;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart2 = s;
            }

            if (dimension == 64)//hay que reiniciar
                s = 0;
            if ((dimension >= 64) && (dimension < 96)) {
                posicion = dimension - 64;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart3 = s;
            }

            if (dimension == 96)//hay que reiniciar
                s = 0;
            if ((dimension >= 96) && (dimension < 128)) {
                posicion = dimension - 96;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart4 = s;
            }

            if (dimension == 128)//hay que reiniciar
                s = 0;
            if ((dimension >= 128) && (dimension < 160)) {
                posicion = dimension - 128;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart5 = s;
            }

            if (dimension == 160)//hay que reiniciar
                s = 0;
            if ((dimension >= 160) && (dimension < 192)) {
                posicion = dimension - 160;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart6 = s;
            }

            if (dimension == 192)//hay que reiniciar
                s = 0;
            if ((dimension >= 192) && (dimension < 224)) {
                posicion = dimension - 192;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart7 = s;
            }

            if (dimension == 224)//hay que reiniciar
                s = 0;
            if ((dimension >= 224) && (dimension < 256)) {
                posicion = dimension - 224;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart8 = s;
            }

            if (dimension == 256)//hay que reiniciar
                s = 0;
            if ((dimension >= 256) && (dimension < 288)) {
                posicion = dimension - 256;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart9 = s;
            }

            if (dimension == 288)//hay que reiniciar
                s = 0;
            if ((dimension >= 288) && (dimension < 320)) {
                posicion = dimension - 288;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ->sketchesPart10 = s;
            }

            if (dimension == 320)//hay que reiniciar
                s = 0;
            if ((dimension >= 320) && (dimension < 352)) {
                posicion = dimension - 320;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart11 = s;
            }

            if (dimension == 352)//hay que reiniciar
                s = 0;
            if ((dimension >= 352) && (dimension < 384)) {
                posicion = dimension - 352;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart12 = s;
            }

            if (dimension == 384)//hay que reiniciar
                s = 0;
            if ((dimension >= 384) && (dimension < 416)) {
                posicion = dimension - 384;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart13 = s;
            }

            if (dimension == 416)//hay que reiniciar
                s = 0;
            if ((dimension >= 416) && (dimension < 448)) {
                posicion = dimension - 416;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart14 = s;
            }

            if (dimension == 448)//hay que reiniciar
                s = 0;
            if ((dimension >= 448) && (dimension < 480)) {
                posicion = dimension - 448;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart15 = s;
            }

            if (dimension == 480)//hay que reiniciar
                s = 0;
            if ((dimension >= 480) && (dimension < 512)) {
                posicion = dimension - 480;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart16 = s;
            }

            if (dimension == 512)//hay que reiniciar
                s = 0;
            if ((dimension >= 512) && (dimension < 544)) {
                posicion = dimension - 512;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart17 = s;
            }

            if (dimension == 544)//hay que reiniciar
                s = 0;
            if ((dimension >= 544) && (dimension < 576)) {
                posicion = dimension - 544;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart18 = s;
            }

            if (dimension == 576)//hay que reiniciar
                s = 0;
            if ((dimension >= 576) && (dimension < 608)) {
                posicion = dimension - 576;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart19 = s;
            }

            if (dimension == 608)//hay que reiniciar
                s = 0;
            if ((dimension >= 608) && (dimension < 640)) {
                posicion = dimension - 608;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart20 = s;
            }

            if (dimension == 640)//hay que reiniciar
                s = 0;
            if ((dimension >= 640) && (dimension < 672)) {
                posicion = dimension - 640;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart21 = s;
            }

            if (dimension == 672)//hay que reiniciar
                s = 0;
            if ((dimension >= 672) && (dimension < 704)) {
                posicion = dimension - 672;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart22 = s;
            }

            if (dimension == 704)//hay que reiniciar
                s = 0;
            if ((dimension >= 704) && (dimension < 736)) {
                posicion = dimension - 704;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart23 = s;
            }

            if (dimension == 736)//hay que reiniciar
                s = 0;
            if ((dimension >= 736) && (dimension < 768)) {
                posicion = dimension - 736;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart24 = s;
            }

            if (dimension == 768)//hay que reiniciar
                s = 0;
            if ((dimension >= 768) && (dimension < 800)) {
                posicion = dimension - 768;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart25 = s;
            }

            if (dimension == 800)//hay que reiniciar
                s = 0;
            if ((dimension >= 800) && (dimension < 832)) {
                posicion = dimension - 800;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart26 = s;
            }

            if (dimension == 832)//hay que reiniciar
                s = 0;
            if ((dimension >= 832) && (dimension < 864)) {
                posicion = dimension - 832;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart27 = s;
            }

            if (dimension == 864)//hay que reiniciar
                s = 0;
            if ((dimension >= 864) && (dimension < 896)) {
                posicion = dimension - 864;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart28 = s;
            }

            if (dimension == 896)//hay que reiniciar
                s = 0;
            if ((dimension >= 896) && (dimension < 928)) {
                posicion = dimension - 896;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart29 = s;
            }

            if (dimension == 928)//hay que reiniciar
                s = 0;
            if ((dimension >= 928) && (dimension < 960)) {
                posicion = dimension - 928;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart30 = s;
            }

            if (dimension == 960)//hay que reiniciar
                s = 0;
            if ((dimension >= 960) && (dimension < 992)) {
                posicion = dimension - 960;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart31 = s;
            }

            if (dimension == 992)//hay que reiniciar
                s = 0;
            if ((dimension >= 992) && (dimension < 1024)) {
                posicion = dimension - 992;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart32 = s;
            }

            if (dimension == 1024)//hay que reiniciar
                s = 0;
            if ((dimension >= 1024) && (dimension < 1056)) {
                posicion = dimension - 1024;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart33 = s;
            }

            if (dimension == 1056)//hay que reiniciar
                s = 0;
            if ((dimension >= 1056) && (dimension < 1088)) {
                posicion = dimension - 1056;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart34 = s;
            }

            if (dimension == 1088)//hay que reiniciar
                s = 0;
            if ((dimension >= 1088) && (dimension < 1120)) {
                posicion = dimension - 1088;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart35 = s;
            }

            if (dimension == 1120)//hay que reiniciar
                s = 0;
            if ((dimension >= 1120) && (dimension < 1152)) {
                posicion = dimension - 1120;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart36 = s;
            }

            if (dimension == 1152)//hay que reiniciar
                s = 0;
            if ((dimension >= 1152) && (dimension < 1184)) {
                posicion = dimension - 1152;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart37 = s;
            }

            if (dimension == 1184)//hay que reiniciar
                s = 0;
            if ((dimension >= 1184) && (dimension < 1216)) {
                posicion = dimension - 1184;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart38 = s;
            }

            if (dimension == 1216)//hay que reiniciar
                s = 0;
            if ((dimension >= 1216) && (dimension < 1248)) {
                posicion = dimension - 1216;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart39 = s;
            }

            if (dimension == 1248)//hay que reiniciar
                s = 0;
            if ((dimension >= 1248) && (dimension < 1280)) {
                posicion = dimension - 1248;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart40 = s;
            }

            if (dimension == 1280)//hay que reiniciar
                s = 0;
            if ((dimension >= 1280) && (dimension < 1312)) {
                posicion = dimension - 1280;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart41 = s;
            }

            if (dimension == 1312)//hay que reiniciar
                s = 0;
            if ((dimension >= 1312) && (dimension < 1344)) {
                posicion = dimension - 1312;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart42 = s;
            }

            if (dimension == 1344)//hay que reiniciar
                s = 0;
            if ((dimension >= 1344) && (dimension < 1376)) {
                posicion = dimension - 1344;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart43 = s;
            }

            if (dimension == 1376)//hay que reiniciar
                s = 0;
            if ((dimension >= 1376) && (dimension < 1408)) {
                posicion = dimension - 1376;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart44 = s;
            }

            if (dimension == 1408)//hay que reiniciar
                s = 0;
            if ((dimension >= 1408) && (dimension < 1440)) {
                posicion = dimension - 1408;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart45 = s;
            }

            if (dimension == 1440)//hay que reiniciar
                s = 0;
            if ((dimension >= 1440) && (dimension < 1472)) {
                posicion = dimension - 1440;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart46 = s;
            }

            if (dimension == 1472)//hay que reiniciar
                s = 0;
            if ((dimension >= 1472) && (dimension < 1504)) {
                posicion = dimension - 1472;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart47 = s;
            }

            if (dimension == 1504)//hay que reiniciar
                s = 0;
            if ((dimension >= 1504) && (dimension < 1536)) {
                posicion = dimension - 1504;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart48 = s;
            }

            if (dimension == 1536)//hay que reiniciar
                s = 0;
            if ((dimension >= 1536) && (dimension < 1568)) {
                posicion = dimension - 1536;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart49 = s;
            }

            if (dimension == 1568)//hay que reiniciar
                s = 0;
            if ((dimension >= 1568) && (dimension < 1600)) {
                posicion = dimension - 1568;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart50 = s;
            }

            if (dimension == 1600)//hay que reiniciar
                s = 0;
            if ((dimension >= 1600) && (dimension < 1632)) {
                posicion = dimension - 1600;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart51 = s;
            }

            if (dimension == 1632)//hay que reiniciar
                s = 0;
            if ((dimension >= 1632) && (dimension < 1664)) {
                posicion = dimension - 1632;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart52 = s;
            }

            if (dimension == 1664)//hay que reiniciar
                s = 0;
            if ((dimension >= 1664) && (dimension < 1696)) {
                posicion = dimension - 1664;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart53 = s;
            }

            if (dimension == 1696)//hay que reiniciar
                s = 0;
            if ((dimension >= 1696) && (dimension < 1728)) {
                posicion = dimension - 1696;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart54 = s;
            }

            if (dimension == 1728)//hay que reiniciar
                s = 0;
            if ((dimension >= 1728) && (dimension < 1760)) {
                posicion = dimension - 1728;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart55 = s;
            }

            if (dimension == 1760)//hay que reiniciar
                s = 0;
            if ((dimension >= 1760) && (dimension < 1792)) {
                posicion = dimension - 1760;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart56 = s;
            }

            if (dimension == 1792)//hay que reiniciar
                s = 0;
            if ((dimension >= 1792) && (dimension < 1824)) {
                posicion = dimension - 1792;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart57 = s;
            }

            if (dimension == 1824)//hay que reiniciar
                s = 0;
            if ((dimension >= 1824) && (dimension < 1856)) {
                posicion = dimension - 1824;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart58 = s;
            }

            if (dimension == 1856)//hay que reiniciar
                s = 0;
            if ((dimension >= 1856) && (dimension < 1888)) {
                posicion = dimension - 1856;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart59 = s;
            }

            if (dimension == 1888)//hay que reiniciar
                s = 0;
            if ((dimension >= 1888) && (dimension < 1920)) {
                posicion = dimension - 1888;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart60 = s;
            }

            if (dimension == 1920)//hay que reiniciar
                s = 0;
            if ((dimension >= 1920) && (dimension < 1952)) {
                posicion = dimension - 1920;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart61 = s;
            }

            if (dimension == 1952)//hay que reiniciar
                s = 0;
            if ((dimension >= 1952) && (dimension < 1984)) {
                posicion = dimension - 1952;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart62 = s;
            }

            if (dimension == 1984)//hay que reiniciar
                s = 0;
            if ((dimension >= 1984) && (dimension < 2016)) {
                posicion = dimension - 1984;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart63 = s;
            }

            if (dimension == 2016)//hay que reiniciar
                s = 0;
            if ((dimension >= 2016) && (dimension < 2048)) {
                posicion = dimension - 2016;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart64 = s;
            }

            if (dimension == 2048)//hay que reiniciar
                s = 0;
            if ((dimension >= 2048) && (dimension < 2080)) {
                posicion = dimension - 2048;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart65 = s;
            }

            if (dimension == 2080)//hay que reiniciar
                s = 0;
            if ((dimension >= 2080) && (dimension < 2112)) {
                posicion = dimension - 2080;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart66 = s;
            }
        }
    }
}


void muestraArregloEntero(consulta* distanciaUQ, int nBaseDatos){

    int i;

    for(i = 0; i < nBaseDatos ; i++){
        printf("[%d]  distancia: %d  objeto: %d\n", i, distanciaUQ[i].distanciaQ, distanciaUQ[i].o);
    }

}


void calculaDistanciaReal(consultaReal* distanciaReal, int n, Obj q){

    int i;
    Obj u;

    for(i = 0; i < n; i++) {
        u = i + 1;
        distanciaReal[i].distanciaQ = distance(q,u);
        distanciaReal[i].o = u;
    }

}


void muestraArregloFlotante(consultaReal* distanciaReal, int n){

    int i;

    for(i = 0; i < n; i++){
        printf("[%d]  distancia: %f  objeto: %d\n", i, distanciaReal[i].distanciaQ, distanciaReal[i].o);
    }

}


void calculaCandidatos(consultaReal* distanciaReal, consultaReal* distanciaRealAprox, int* kCandidatosAprox, int* kCandidatosReal , int k){

    int i;

    for(i = 0; i < k; i++){
        // printf("i [%d] aprox %d real %d\n",i, distanciaHamming[i].o,distanciaReal[i].o);
        kCandidatosAprox[i] = distanciaRealAprox[i].o;
        kCandidatosReal[i] = distanciaReal[i].o;
        //printf("i [%d] aprox %d real %d\n\n",i, kCandidatosAprox[i], kCandidatosReales[i]);
    }

}


void muestraCandidatos(int* kCandidatosAprox, int* kCandidatosReal, int k){

    int i;

    for(i = 0; i < k; i++){

        printf("[%d]  Aprox: %d Real: %d\n",i ,kCandidatosAprox[i], kCandidatosReal[i]);

    }
}


void workload(int kPorcentaje, Obj q, consultaReal* distanciaRealAprox, consulta* distanciaHamming){

    int i;

    for(i = 0; i < kPorcentaje; i++){
        distanciaRealAprox[i].distanciaQ = distance( distanciaHamming[i].o, q);
        distanciaRealAprox[i].o = distanciaHamming[i].o;
    }

}


void muestraSketch(unsigned int s){

    //printf(" lo que quiero mostrar tiene el tañamo de: %d", sizeof(s));
    int g = 0;
    for( g ; g < sizeof(s)*8; g++){
        printf( "%u", ( s >> g) & 1 );
    }

    printf("\n");

}


void muestraPivotes(rbbf1* N){

    int i = 0;

    printf("Los pivotes son: \n\n");

    for(i; i < N -> nHiperPlanos; i++){
        printf("%i po1: %d ", i, N -> pivots[i].po1);
        printf( "po2: %d", N -> pivots[i].po2);
    }

}

void seleccionaPivotes(rbbf1* N){

    int i;
    srand( time( NULL ) );

    for(i = 0; i < N -> nHiperPlanos; i++){
        N -> pivots[i].po1 = rand() %N -> nBaseDatos + 1;
        N -> pivots[i].po2 = rand() %N -> nBaseDatos +1;
    }

}

/*void inicializaRecallPorcentaje(float* recallPorcentaje, int nPorcentajes){

    int i = 0;

    for(i = 0; i < nPorcentajes; i++){
        recallPorcentaje[i] = 0;
    }
}*/