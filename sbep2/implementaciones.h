//
// Created by cesar on 2/16/17.
//

#include <time.h>

#ifndef SBEP2_IMPLEMENTACIONES_H
#define SBEP2_IMPLEMENTACIONES_H

void seleccionaPivotesAleatorio(Obj* p, int k, int np){

    int i;

    srand( time( NULL ) );

    for(i = 0; i < k; i++){
        p[i] = rand()% np + 1;
    }
}

void calculaDistanciaReferenciasConsulta(Obj o, ARRAYTEMPORAL* permutacionI , int nPivotes, Obj* pivotes){
    int i;

    for(i = 0; i < nPivotes; i++){
        permutacionI[i].distancia = distance(o, pivotes[i]);
        permutacionI[i].indice = i;
    }

}

int cmpFloat(const void *a, const void *b){

    ARRAYTEMPORAL *x = (ARRAYTEMPORAL *) a;
    ARRAYTEMPORAL *y = (ARRAYTEMPORAL *) b;

    if((*x).distancia > (*y).distancia){
        return 1;
    }else{
        if((*x).distancia < (*y).distancia){
            return -1;
        }else{
            return 0;
        }
    }

}

void guardaInversaI(ARRAYTEMPORAL* permutacionI, int* permutacionIInvertida, int n){

    int i;

    for(i = 0; i < n; i++){
        permutacionIInvertida[permutacionI[i].indice] = i;
    }

}

void iniciaSumaRecall(float* sumaRecall, int n){

    int i;
    for(i = 0; i < n; i++){
        sumaRecall[i]=0;
    }

}

void generaConsultas(Obj* objetosConsulta, int n, int rango){

    int i;

    //srand ( time ( NULL));

    for(i = 0; i < n; i++){
        objetosConsulta[i] = rand() %rango + 1;
    }

}

void generaSketch(SKETCHQ* sQ, Obj u, Obj* pivotes, int nPivotes, int m){

    int dimension = 0;
    int posicion = 0;

    ARRAYTEMPORAL* permutacionQ;
    int* permutacionQInvertida;

    unsigned int s = 0;

    permutacionQ  = (ARRAYTEMPORAL*)malloc(sizeof(ARRAYTEMPORAL)* nPivotes);
    permutacionQInvertida = (int*)malloc(sizeof(int) * nPivotes);
    calculaDistanciaReferenciasConsulta(u, permutacionQ, nPivotes, pivotes);
    qsort(permutacionQ, nPivotes, sizeof(ARRAYTEMPORAL), cmpFloat);
    guardaInversaI(permutacionQ, permutacionQInvertida, nPivotes);

    for( dimension = 0; dimension < nPivotes; dimension++){
        // bit = 0;
        if( permutacionQInvertida[dimension] <= m ){
            // bit = 1;

            if (dimension < 32) {
                s ^= (-1 ^ s) & (1 << dimension);
                sQ -> sketches = s;
            }

            if (dimension == 32)//hay que reiniciar
                s = 0;
            if ((dimension >= 32) && (dimension < 64)) {
                posicion = dimension - 32;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart2 = s;
            }

            if (dimension == 64)//hay que reiniciar
                s = 0;
            if ((dimension >= 64) && (dimension < 96)) {
                posicion = dimension - 64;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart3 = s;
            }

            if (dimension == 96)//hay que reiniciar
                s = 0;
            if ((dimension >= 96) && (dimension < 128)) {
                posicion = dimension - 96;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart4 = s;
            }

            if (dimension == 128)//hay que reiniciar
                s = 0;
            if ((dimension >= 128) && (dimension < 160)) {
                posicion = dimension - 128;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart5 = s;
            }

            if (dimension == 160)//hay que reiniciar
                s = 0;
            if ((dimension >= 160) && (dimension < 192)) {
                posicion = dimension - 160;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart6 = s;
            }

            if (dimension == 192)//hay que reiniciar
                s = 0;
            if ((dimension >= 192) && (dimension < 224)) {
                posicion = dimension - 192;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart7 = s;
            }

            if (dimension == 224)//hay que reiniciar
                s = 0;
            if ((dimension >= 224) && (dimension < 256)) {
                posicion = dimension - 224;
                s ^= (-1 ^ s) & (1 << posicion);
                sQ -> sketchesPart8 = s;
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

void calculaDistanciaReal(CONSULTAREAL* distanciaReal, int n, Obj q){

    int i;

    Obj u;

    for(i = 0; i < n; i++) {
        u = i + 1;
        distanciaReal[i].distanciaQ = distance(q,u);
        distanciaReal[i].o = u;
    }

}

int cmpfuncFloat(const void *a, const void *b){

    const CONSULTAREAL*c1 = (CONSULTAREAL *) a;
    const CONSULTAREAL *c2 = (CONSULTAREAL *) b;

    if (c1 -> distanciaQ < c2 -> distanciaQ) return -1;
    else if (c1 -> distanciaQ > c2 -> distanciaQ) return 1;

    return 0;

}

int hamming(unsigned int a, unsigned int b){

    return ( __builtin_popcount( a ^ b ) );

}

int cmpfunc(const void *a, const void *b){

    const CONSULTA *c1 = (CONSULTA *) a;
    const CONSULTA *c2 = (CONSULTA *) b;

    return ( c1 -> distanciaQ - c2 -> distanciaQ);
}

void workload(int kPorcentaje, Obj q, CONSULTAREAL* distanciaRealAprox, CONSULTA* distanciaHamming){

    int i;

    for(i = 0; i < kPorcentaje; i++){
        distanciaRealAprox[i].distanciaQ = distance( distanciaHamming[i].o, q);
        distanciaRealAprox[i].o = distanciaHamming[i].o;
    }

}

void calculaCandidatos(CONSULTAREAL* distanciaReal, CONSULTAREAL* distanciaRealAprox, int* kCandidatosAprox, int* kCandidatosReal , int k){

    int i;

    for(i = 0; i < k; i++){
        kCandidatosAprox[i] = distanciaRealAprox[i].o;
        kCandidatosReal[i] = distanciaReal[i].o;
    }

}

int compara(const void *x, const void *y){

    return( *( int* )x - *( int* )y);
}

#endif //SBEP2_IMPLEMENTACIONES_H
