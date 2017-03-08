//
// Created by cesar on 21/09/16.
//

#include <time.h>
#include <stdlib.h>
#include "rbbf1.h"

float kNN(rbbf1* G, int k, int porcentaje, Obj q, sketchQ* sQ, consultaReal* distanciaReal);

Index build (char *dbname, int n, int *argc, char ***argv) {

    if (*argc < 1) {
        fprintf(stderr, "Usage: <program> <args> ARITY\n");
        exit(1);
    }

    rbbf1 *G;

    int i;
    int dimension;
    int k = 2;
    int posicion;
    int nObjetoConsulta = 300;
    int porcentaje[] = {1,3,5,7,10};
    //int porcentaje[] = {9};
    int nPorcentaje = 5;


    Obj *objetosConsulta;
    Obj u;

    Tdist d1 = 0;
    Tdist d2 = 0;

    float recallPorcentaje[]={0,0,0,0,0}; //0 : error de posicion  1: recall

    G = malloc (sizeof(rbbf1));

    G->descr = malloc( strlen( dbname ) + 1);
    strcpy(G->descr, dbname);
    
    G -> n = openDB( G -> descr);

    if (n && (n < G -> n) ) G -> n = n;

    G -> nHiperPlanos = atoi( ( *argv[0] ) );
    (*argc)--;
    (*argv)++;

    int f=0;

    G -> pivots = malloc( sizeof( pivot ) * G -> nHiperPlanos);
    G -> sketches = malloc( sizeof( unsigned int ) * G -> n); //los primeros 32 bits

    if (( G -> nHiperPlanos > 32))
        G -> sketchesPart2 = malloc( sizeof( unsigned int) * G -> n);

    if ((G->nHiperPlanos > 64))
        G->sketchesPart3 = malloc( sizeof( unsigned int ) * G -> n);

    if ((G->nHiperPlanos > 96)) {
        G->sketchesPart4 = malloc(sizeof(unsigned int) * G->n);
    }

    if ((G->nHiperPlanos > 128)) {
        G->sketchesPart5 = malloc(sizeof(unsigned int) * G->n);
    }

    if ((G->nHiperPlanos > 160)) {
        G->sketchesPart6 = malloc(sizeof(unsigned int) * G->n);
    }

    if ((G->nHiperPlanos > 192)) {
        G->sketchesPart7 = malloc(sizeof(unsigned int) * G->n);
    }

    if ((G->nHiperPlanos > 224)) {
        G->sketchesPart8 = malloc(sizeof(unsigned int) * G->n);
    }

    if ((G->nHiperPlanos > 256)) {
        G->sketchesPart9 = malloc(sizeof(unsigned int) * G->n);
    }

    if ((G->nHiperPlanos > 288)) {
        G->sketchesPart10 = malloc(sizeof(unsigned int) * G->n);
    }

    if ((G -> nHiperPlanos > 320)) {
        G -> sketchesPart11 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 352)) {
        G -> sketchesPart12 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 384)) {
        G -> sketchesPart13 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 416)) {
        G -> sketchesPart14 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 448)) {
        G -> sketchesPart15 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 480)) {
        G -> sketchesPart16 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 512)) {
        G -> sketchesPart17 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 544)) {
        G -> sketchesPart18 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 576)) {
        G -> sketchesPart19 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 608)) {
        G -> sketchesPart20 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 640)) {
        G -> sketchesPart21 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 672)) {
        G -> sketchesPart22 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 704)) {
        G -> sketchesPart23 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 736)) {
        G -> sketchesPart24 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 768)) {
        G -> sketchesPart25 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 800)) {
        G -> sketchesPart26 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 832)) {
        G -> sketchesPart27 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 864)) {
        G -> sketchesPart28 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 896)) {
        G -> sketchesPart29 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 928)) {
        G -> sketchesPart30 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 960)) {
        G -> sketchesPart31 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 992)) {
        G -> sketchesPart32 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1024)) {
        G -> sketchesPart33 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1056)) {
        G -> sketchesPart34 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1088)) {
        G -> sketchesPart35 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1120)) {
        G -> sketchesPart36 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1152)) {
        G -> sketchesPart37 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1184)) {
        G -> sketchesPart38 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1216)) {
        G -> sketchesPart39 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1248)) {
        G -> sketchesPart40 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1280)) {
        G -> sketchesPart41 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1312)) {
        G -> sketchesPart42 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1314)) {
        G -> sketchesPart43 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1376)) {
        G -> sketchesPart44 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1408)) {
        G -> sketchesPart45 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1440)) {
        G -> sketchesPart46 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1472)) {
        G -> sketchesPart47 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1504)) {
        G -> sketchesPart48 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1536)) {
        G -> sketchesPart49 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1568)) {
        G -> sketchesPart50 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1600)) {
        G -> sketchesPart51 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1632)) {
        G -> sketchesPart52 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1664)) {
        G -> sketchesPart53 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1696)) {
        G -> sketchesPart54 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1728)) {
        G -> sketchesPart55 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1760)) {
        G -> sketchesPart56 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1792)) {
        G -> sketchesPart57 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1824)) {
        G -> sketchesPart58 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1856)) {
        G -> sketchesPart59 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1888)) {
        G -> sketchesPart60 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1920)) {
        G -> sketchesPart61 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1952)) {
        G -> sketchesPart62 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 1984)) {
        G -> sketchesPart63 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 2016)) {
        G -> sketchesPart64 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 2048)) {
        G -> sketchesPart65 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    if ((G -> nHiperPlanos > 2080)) {
        G -> sketchesPart66 = (unsigned int*)malloc(sizeof(unsigned int) * G -> n);
    }

    seleccionaPivotes(G);

    i = 0;
    posicion = 0;
    while (i < G -> n) {

        i++;
        u = i;

            G -> sketches[u-1] = 0;
        if (G->nHiperPlanos > 32)
            G->sketchesPart2[u-1] = 0;
        if (G->nHiperPlanos > 64)
            G->sketchesPart3[u-1] = 0;
        if (G->nHiperPlanos > 96)
            G->sketchesPart4[u-1] = 0;
        if (G->nHiperPlanos > 128)
            G->sketchesPart5[u-1] = 0;
        if (G->nHiperPlanos > 160)
            G->sketchesPart6[u-1] = 0;
        if (G->nHiperPlanos > 192)
            G->sketchesPart7[u-1] = 0;
        if (G->nHiperPlanos > 224)
            G->sketchesPart8[u-1] = 0;
        if (G->nHiperPlanos > 256)
            G->sketchesPart9[u-1] = 0;
        if (G->nHiperPlanos > 288)
            G->sketchesPart10[u-1] = 0;
        if (G->nHiperPlanos > 320)
            G->sketchesPart11[u - 1] = 0;
        if (G->nHiperPlanos > 352)
            G->sketchesPart12[u - 1] = 0;
        if (G->nHiperPlanos > 384)
            G->sketchesPart13[u - 1] = 0;
        if (G->nHiperPlanos > 416)
            G->sketchesPart14[u - 1] = 0;
        if (G->nHiperPlanos > 448)
            G->sketchesPart15[u - 1] = 0;
        if (G->nHiperPlanos > 480)
            G->sketchesPart16[u - 1] = 0;
        if (G->nHiperPlanos > 512)
            G->sketchesPart17[u - 1] = 0;
        if (G->nHiperPlanos > 544)
            G->sketchesPart18[u - 1] = 0;
        if (G->nHiperPlanos > 576)
            G->sketchesPart19[u - 1] = 0;
        if (G->nHiperPlanos > 608)
            G->sketchesPart20[u - 1] = 0;
        if (G->nHiperPlanos > 640)
            G->sketchesPart21[u - 1] = 0;
        if (G->nHiperPlanos > 672)
            G->sketchesPart22[u - 1] = 0;
        if (G->nHiperPlanos > 704)
            G->sketchesPart23[u - 1] = 0;
        if (G->nHiperPlanos > 736)
            G->sketchesPart24[u - 1] = 0;
        if (G->nHiperPlanos > 768)
            G->sketchesPart25[u - 1] = 0;
        if (G->nHiperPlanos > 800)
            G->sketchesPart26[u - 1] = 0;
        if (G->nHiperPlanos > 832)
            G->sketchesPart27[u - 1] = 0;
        if (G->nHiperPlanos > 864)
            G->sketchesPart28[u - 1] = 0;
        if (G->nHiperPlanos > 896)
            G->sketchesPart29[u - 1] = 0;
        if (G->nHiperPlanos > 928)
            G->sketchesPart30[u - 1] = 0;
        if (G->nHiperPlanos > 960)
            G->sketchesPart31[u - 1] = 0;
        if (G->nHiperPlanos > 992)
            G->sketchesPart32[u - 1] = 0;
        if (G->nHiperPlanos > 1024)
            G->sketchesPart33[u - 1] = 0;
        if (G->nHiperPlanos > 1056)
            G->sketchesPart34[u - 1] = 0;
        if (G->nHiperPlanos > 1088)
            G->sketchesPart35[u - 1] = 0;
        if (G->nHiperPlanos > 1120)
            G->sketchesPart36[u - 1] = 0;
        if (G->nHiperPlanos > 1152)
            G->sketchesPart37[u - 1] = 0;
        if (G->nHiperPlanos > 1184)
            G->sketchesPart38[u - 1] = 0;
        if (G->nHiperPlanos > 1216)
            G->sketchesPart39[u - 1] = 0;
        if (G->nHiperPlanos > 1248)
            G->sketchesPart40[u - 1] = 0;
        if (G->nHiperPlanos > 1280)
            G->sketchesPart41[u - 1] = 0;
        if (G->nHiperPlanos > 1312)
            G->sketchesPart42[u - 1] = 0;
        if (G->nHiperPlanos > 1344)
            G->sketchesPart43[u - 1] = 0;
        if (G->nHiperPlanos > 1376)
            G->sketchesPart44[u - 1] = 0;
        if (G->nHiperPlanos > 1408)
            G->sketchesPart45[u - 1] = 0;
        if (G->nHiperPlanos > 1440)
            G->sketchesPart46[u - 1] = 0;
        if (G->nHiperPlanos > 1472)
            G->sketchesPart47[u - 1] = 0;
        if (G->nHiperPlanos > 1504)
            G->sketchesPart48[u - 1] = 0;
        if (G->nHiperPlanos > 1536)
            G->sketchesPart49[u - 1] = 0;
        if (G->nHiperPlanos > 1568)
            G->sketchesPart50[u - 1] = 0;
        if (G->nHiperPlanos > 1600)
            G->sketchesPart51[u - 1] = 0;
        if (G->nHiperPlanos > 1632)
            G->sketchesPart52[u - 1] = 0;
        if (G->nHiperPlanos > 1664)
            G->sketchesPart53[u - 1] = 0;
        if (G->nHiperPlanos > 1696)
            G->sketchesPart54[u - 1] = 0;
        if (G->nHiperPlanos > 1728)
            G->sketchesPart55[u - 1] = 0;
        if (G->nHiperPlanos > 1760)
            G->sketchesPart56[u - 1] = 0;
        if (G->nHiperPlanos > 1792)
            G->sketchesPart57[u - 1] = 0;
        if (G->nHiperPlanos > 1824)
            G->sketchesPart58[u - 1] = 0;
        if (G->nHiperPlanos > 1856)
            G->sketchesPart59[u - 1] = 0;
        if (G->nHiperPlanos > 1888)
            G->sketchesPart60[u - 1] = 0;
        if (G->nHiperPlanos > 1920)
            G->sketchesPart61[u - 1] = 0;
        if (G->nHiperPlanos > 1952)
            G->sketchesPart62[u - 1] = 0;
        if (G->nHiperPlanos > 1984)
            G->sketchesPart63[u - 1] = 0;
        if (G->nHiperPlanos > 2016)
            G->sketchesPart64[u - 1] = 0;
        if (G->nHiperPlanos > 2048)
            G->sketchesPart65[u - 1] = 0;
        if (G->nHiperPlanos > 2080)
            G->sketchesPart66[u - 1] = 0;

        for (dimension = 0; dimension < G->nHiperPlanos; dimension++) {

            d1 = distance(u, G->pivots[dimension].po1);
            d2 = distance(u, G->pivots[dimension].po2);

            if (d1 <= d2) {

                if (dimension < 32) {
                    G->sketches[i - 1] ^= (-1 ^ G->sketches[i - 1]) & (1 << dimension);
                }

                if ((dimension >= 32) && (dimension < 64)) {
                    posicion = dimension - 32;
                    G->sketchesPart2[i - 1] ^= (-1 ^ G->sketchesPart2[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 64) && (dimension < 96)) {
                    posicion = dimension - 64;
                    G->sketchesPart3[i - 1] ^= (-1 ^ G->sketchesPart3[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 96) && (dimension < 128)) {
                    posicion = dimension - 96;
                    G->sketchesPart4[i - 1] ^= (-1 ^ G->sketchesPart4[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 128) && (dimension < 160)) {
                    posicion = dimension - 128;
                    G->sketchesPart5[i - 1] ^= (-1 ^ G->sketchesPart5[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 160) && (dimension < 192)) {
                    posicion = dimension - 160;
                    G->sketchesPart6[i - 1] ^= (-1 ^ G->sketchesPart6[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 192) && (dimension < 224)) {
                    posicion = dimension - 192;
                    G->sketchesPart7[i - 1] ^= (-1 ^ G->sketchesPart7[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 224) && (dimension < 256)) {
                    posicion = dimension - 224;
                    G->sketchesPart8[i - 1] ^= (-1 ^ G->sketchesPart8[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 256) && (dimension < 288)) {
                    posicion = dimension - 256;
                    G->sketchesPart9[i - 1] ^= (-1 ^ G->sketchesPart9[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 288) && (dimension < 320)) {
                    posicion = dimension - 288;
                    G->sketchesPart10[i - 1] ^= (-1 ^ G->sketchesPart10[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 320) && (dimension < 352)) {
                    posicion = dimension - 320;
                    G -> sketchesPart11[i - 1] ^= (-1 ^ G -> sketchesPart11[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 352) && (dimension < 384)) {
                    posicion = dimension - 352;
                    G -> sketchesPart12[i - 1] ^= (-1 ^ G -> sketchesPart12[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 384) && (dimension < 416)) {
                    posicion = dimension - 384;
                    G -> sketchesPart13[i - 1] ^= (-1 ^ G -> sketchesPart13[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 416) && (dimension < 448)) {
                    posicion = dimension - 416;
                    G -> sketchesPart14[i - 1] ^= (-1 ^ G -> sketchesPart14[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 448) && (dimension < 480)) {
                    posicion = dimension - 448;
                    G -> sketchesPart15[i - 1] ^= (-1 ^ G -> sketchesPart15[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 480) && (dimension < 512)) {
                    posicion = dimension - 480;
                    G -> sketchesPart16[i - 1] ^= (-1 ^ G -> sketchesPart16[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 512) && (dimension < 544)) {
                    posicion = dimension - 512;
                    G -> sketchesPart17[i - 1] ^= (-1 ^ G -> sketchesPart17[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 544) && (dimension < 576)) {
                    posicion = dimension - 544;
                    G -> sketchesPart18[i - 1] ^= (-1 ^ G -> sketchesPart18[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 576) && (dimension < 608)) {
                    posicion = dimension - 576;
                    G -> sketchesPart19[i - 1] ^= (-1 ^ G -> sketchesPart19[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 608) && (dimension < 640)) {
                    posicion = dimension - 608;
                    G -> sketchesPart20[i - 1] ^= (-1 ^ G -> sketchesPart20[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 640) && (dimension < 672)) {
                    posicion = dimension - 640;
                    G -> sketchesPart21[i - 1] ^= (-1 ^ G -> sketchesPart21[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 672) && (dimension < 704)) {
                    posicion = dimension - 672;
                    G -> sketchesPart22[i - 1] ^= (-1 ^ G -> sketchesPart22[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 704) && (dimension < 736)) {
                    posicion = dimension - 704;
                    G -> sketchesPart23[i - 1] ^= (-1 ^ G -> sketchesPart23[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 736) && (dimension < 768)) {
                    posicion = dimension - 736;
                    G -> sketchesPart24[i - 1] ^= (-1 ^ G -> sketchesPart24[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 768) && (dimension < 800)) {
                    posicion = dimension - 768;
                    G -> sketchesPart25[i - 1] ^= (-1 ^ G -> sketchesPart25[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 800) && (dimension < 832)) {
                    posicion = dimension - 800;
                    G -> sketchesPart26[i - 1] ^= (-1 ^ G -> sketchesPart26[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 832) && (dimension < 864)) {
                    posicion = dimension - 832;
                    G -> sketchesPart27[i - 1] ^= (-1 ^ G -> sketchesPart27[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 864) && (dimension < 896)) {
                    posicion = dimension - 864;
                    G -> sketchesPart28[i - 1] ^= (-1 ^ G -> sketchesPart28[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 896) && (dimension < 928)) {
                    posicion = dimension - 896;
                    G -> sketchesPart29[i - 1] ^= (-1 ^ G -> sketchesPart29[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 928) && (dimension < 960)) {
                    posicion = dimension - 928;
                    G -> sketchesPart30[i - 1] ^= (-1 ^ G -> sketchesPart30[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 960) && (dimension < 992)) {
                    posicion = dimension - 960;
                    G -> sketchesPart31[i - 1] ^= (-1 ^ G -> sketchesPart31[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 992) && (dimension < 1024)) {
                    posicion = dimension - 992;
                    G -> sketchesPart32[i - 1] ^= (-1 ^ G -> sketchesPart32[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1024) && (dimension < 1056)) {
                    posicion = dimension - 1024;
                    G -> sketchesPart33[i - 1] ^= (-1 ^ G -> sketchesPart33[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1056) && (dimension < 1088)) {
                    posicion = dimension - 1056;
                    G -> sketchesPart34[i - 1] ^= (-1 ^ G -> sketchesPart34[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1088) && (dimension < 1120)) {
                    posicion = dimension - 1088;
                    G -> sketchesPart35[i - 1] ^= (-1 ^ G -> sketchesPart35[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1120) && (dimension < 1152)) {
                    posicion = dimension - 1120;
                    G -> sketchesPart36[i - 1] ^= (-1 ^ G -> sketchesPart36[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 1152) && (dimension < 1184)){
                    posicion = dimension - 1152;
                    G -> sketchesPart37[i - 1] ^= (-1 ^ G -> sketchesPart37[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 1184) && (dimension < 1216)) {
                    posicion = dimension - 1184;
                    G -> sketchesPart38[i - 1] ^= (-1 ^ G -> sketchesPart38[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1216) && (dimension < 1248)) {
                    posicion = dimension - 1216;
                    G -> sketchesPart39[i - 1] ^= (-1 ^ G -> sketchesPart39[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1248) && (dimension < 1280)) {
                    posicion = dimension - 1248;
                    G -> sketchesPart40[i - 1] ^= (-1 ^ G -> sketchesPart40[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1280) && (dimension < 1312)) {
                    posicion = dimension - 1280;
                    G -> sketchesPart41[i - 1] ^= (-1 ^ G -> sketchesPart41[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1312) && (dimension < 1344)) {
                    posicion = dimension - 1312;
                    G -> sketchesPart42[i - 1] ^= (-1 ^ G -> sketchesPart42[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1344) && (dimension < 1376)) {
                    posicion = dimension - 1344;
                    G -> sketchesPart43[i - 1] ^= (-1 ^ G -> sketchesPart43[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1376) && (dimension < 1408)) {
                    posicion = dimension - 1376;
                    G -> sketchesPart44[i - 1] ^= (-1 ^ G -> sketchesPart44[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1408) && (dimension < 1440)) {
                    posicion = dimension - 1408;
                    G -> sketchesPart45[i - 1] ^= (-1 ^ G -> sketchesPart45[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1440) && (dimension < 1472)) {
                    posicion = dimension - 1440;
                    G -> sketchesPart46[i - 1] ^= (-1 ^ G -> sketchesPart46[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1472) && (dimension < 1504)) {
                    posicion = dimension - 1472;
                    G -> sketchesPart47[i - 1] ^= (-1 ^ G -> sketchesPart47[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1504) && (dimension < 1536)) {
                    posicion = dimension - 1504;
                    G -> sketchesPart48[i - 1] ^= (-1 ^ G -> sketchesPart48[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1536) && (dimension < 1568)) {
                    posicion = dimension - 1536;
                    G -> sketchesPart49[i - 1] ^= (-1 ^ G -> sketchesPart49[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1568) && (dimension < 1600)) {
                    posicion = dimension - 1568;
                    G -> sketchesPart50[i - 1] ^= (-1 ^ G -> sketchesPart50[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1600) && (dimension < 1632)) {
                    posicion = dimension - 1600;
                    G -> sketchesPart51[i - 1] ^= (-1 ^ G -> sketchesPart51[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1632) && (dimension < 1664)) {
                    posicion = dimension - 1632;
                    G -> sketchesPart52[i - 1] ^= (-1 ^ G -> sketchesPart52[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1664) && (dimension < 1696)) {
                    posicion = dimension - 1664;
                    G -> sketchesPart53[i - 1] ^= (-1 ^ G -> sketchesPart53[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1696) && (dimension < 1728)) {
                    posicion = dimension - 1696;
                    G -> sketchesPart54[i - 1] ^= (-1 ^ G -> sketchesPart54[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1728) && (dimension < 1760)) {
                    posicion = dimension - 1728;
                    G -> sketchesPart55[i - 1] ^= (-1 ^ G -> sketchesPart55[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1760) && (dimension < 1792)) {
                    posicion = dimension - 1760;
                    G -> sketchesPart56[i - 1] ^= (-1 ^ G -> sketchesPart56[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1792) && (dimension < 1824)) {
                    posicion = dimension - 1792;
                    G -> sketchesPart57[i - 1] ^= (-1 ^ G -> sketchesPart57[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1824) && (dimension < 1856)) {
                    posicion = dimension - 1824;
                    G -> sketchesPart58[i - 1] ^= (-1 ^ G -> sketchesPart58[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1856) && (dimension < 1888)) {
                    posicion = dimension - 1856;
                    G -> sketchesPart59[i - 1] ^= (-1 ^ G -> sketchesPart59[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1888) && (dimension < 1920)) {
                    posicion = dimension - 1888;
                    G -> sketchesPart60[i - 1] ^= (-1 ^ G -> sketchesPart60[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1920) && (dimension < 1952)) {
                    posicion = dimension - 1920;
                    G -> sketchesPart61[i - 1] ^= (-1 ^ G -> sketchesPart61[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1952) && (dimension < 1984)) {
                    posicion = dimension - 1952;
                    G -> sketchesPart62[i - 1] ^= (-1 ^ G -> sketchesPart62[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1984) && (dimension < 2016)) {
                    posicion = dimension - 1984;
                    G -> sketchesPart63[i - 1] ^= (-1 ^ G -> sketchesPart63[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 2016) && (dimension < 2048)) {
                    posicion = dimension - 2016;
                    G -> sketchesPart64[i - 1] ^= (-1 ^ G -> sketchesPart64[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 2048) && (dimension < 2080)) {
                    posicion = dimension - 2048;
                    G -> sketchesPart65[i - 1] ^= (-1 ^ G -> sketchesPart65[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 2080) && (dimension < 2112)) {
                    posicion = dimension - 2080;
                    G -> sketchesPart66[i - 1] ^= (-1 ^ G -> sketchesPart66[i - 1]) & (1 << posicion);

                }
            }
        }

    }

    /*printf("Empiezan las consultas\n");
    objetosConsulta = (Obj *) malloc( sizeof (Obj) * nObjetoConsulta); //se seleccionana los objetos para la consulta
    //printf("Se reservan los espacios para los objetos de las consultas\n");
    generaConsultas(objetosConsulta, nObjetoConsulta, G -> n);

    //printf("\n\t K = %d \n", k);
    for(i = 0; i < nObjetoConsulta; i++){
        kNN(G, k, objetosConsulta[i], &recallPorcentaje);
    }

    printf("\n\t K = %d \n", k);
    for(i = 0; i < nPorcentaje; i++){
        printf(" %d.- %d promedio recall %f\n",i, porcentaje[i], recallPorcentaje[i]/nObjetoConsulta);
    }*/

    /****************************************/
    /*recallPorcentaje[0] = 0;
    recallPorcentaje[1] = 0;
    recallPorcentaje[2] = 0;
    recallPorcentaje[3] = 0;
    recallPorcentaje[4] = 0;
    k = 4;

    for(i = 0; i < nObjetoConsulta; i++){
        kNN(G, k, objetosConsulta[i], &recallPorcentaje);
    }

    printf("\n\t K = %d \n", k);
    for(i = 0; i < nPorcentaje; i++){
        printf(" %d.- %d promedio recall %f\n",i, porcentaje[i], recallPorcentaje[i]/nObjetoConsulta);
    }*/

    /****************************************/
    /*recallPorcentaje[0] = 0;
    recallPorcentaje[1] = 0;
    recallPorcentaje[2] = 0;
    recallPorcentaje[3] = 0;
    recallPorcentaje[4] = 0;
    k = 8;

    for(i = 0; i < nObjetoConsulta; i++){
        kNN(G, k, objetosConsulta[i], &recallPorcentaje);
    }

    printf("\n\t K = %d \n", k);
    for(i = 0; i < nPorcentaje; i++){
        printf(" %d.- %d promedio recall %f\n",i, porcentaje[i], recallPorcentaje[i]/nObjetoConsulta);
    }*/

    /****************************************/
    /*recallPorcentaje[0] = 0;
    recallPorcentaje[1] = 0;
    recallPorcentaje[2] = 0;
    recallPorcentaje[3] = 0;
    recallPorcentaje[4] = 0;
    k = 16;

    for(i = 0; i < nObjetoConsulta; i++){
        kNN(G, k, objetosConsulta[i], &recallPorcentaje);
    }

    printf("\n\t K = %d \n", k);
    for(i = 0; i < nPorcentaje; i++){
        printf(" %d.- %d promedio recall %f\n",i, porcentaje[i], recallPorcentaje[i]/nObjetoConsulta);
    }*/

    /****************************************/
    /*recallPorcentaje[0] = 0;
    recallPorcentaje[1] = 0;
    recallPorcentaje[2] = 0;
    recallPorcentaje[3] = 0;
    recallPorcentaje[4] = 0;
    k = 32;

    for(i = 0; i < nObjetoConsulta; i++){
        kNN(G, k, objetosConsulta[i], &recallPorcentaje);
    }

    printf("\n\t K = %d \n", k);
    for(i = 0; i < nPorcentaje; i++){
        printf(" %d.- %d promedio recall %f\n",i, porcentaje[i], recallPorcentaje[i]/nObjetoConsulta);
    }*/

    pruebas(G);

    closeDB();

    return (Index) G;

}

void pruebas(Index S){

    printf("\n\t INICIAN LAS PRUEBAS\n");
    rbbf1* I = (rbbf1*)S;

    int i;
    int j;
    int k = 2; //los k vecinos mas cercanos que quiero
    int nObjetosPrueba = 300; //numero de veces que se va a repetir las pruebas
    int porcentaje[] = {1, 3, 5, 7, 10}; //porcentaje que se va a revisar de la base de datos
    int nPorcentaje = 5;

    Obj* objetosConsulta;

    consultaReal* distanciaReal = NULL;
    float recall;
    float sumaRecall[nPorcentaje];
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    objetosConsulta = (Obj*) malloc( sizeof (Obj) * nObjetosPrueba);
    generaConsultas(objetosConsulta, nObjetosPrueba, I -> n);

    sketchQ sQ;

    distanciaReal = ( consultaReal* ) malloc( sizeof( consultaReal ) * I -> n);


    /***********************************************************************************************************/

    k = 8;
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    printf("\n\tK = %d\n", k);
    for(j = 0; j < nObjetosPrueba; j++){

        generaSketch( &sQ, objetosConsulta[j], I -> pivots, I -> nHiperPlanos);
        calculaDistanciaReal(distanciaReal, I->n, objetosConsulta[j]);
        qsort(distanciaReal, I->n, sizeof(consultaReal), cmpfuncFloat);

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

        generaSketch( &sQ, objetosConsulta[j], I -> pivots, I -> nHiperPlanos);
        calculaDistanciaReal(distanciaReal, I->n, objetosConsulta[j]);
        qsort(distanciaReal, I->n, sizeof(consultaReal), cmpfuncFloat);

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

int hamming(unsigned int a, unsigned int b){

    return ( __builtin_popcount( a ^ b ) );

}



void saveIndex (Index S, char *fname)
{
    rbbf1 *G = (rbbf1*)S;
    FILE *f = fopen (fname,"w");

    fclose (f);

}

Index loadIndex (char *fname) {
    FILE *f = fopen(fname,"r");

    rbbf1 *I = malloc (sizeof(rbbf1));

    fclose (f);
    return (Index)I;
}




float kNN(rbbf1* G, int k, int porcentaje, Obj q, sketchQ* sQ, consultaReal* distanciaReal){

    consulta *distanciaHamming = NULL;

    consultaReal* distanciaRealAprox = NULL;

    int kPorcentaje = 0;
    int i = 0;
    int interseccion = 0;
    int objetivo = 0;


    int *resultado = NULL;
    int *kCandidatosAprox = NULL;
    int *kCandidatosReal = NULL;

    float recall;

    Tdist dist;

    distanciaHamming = (consulta *) malloc( sizeof(consulta)* G -> n);

    for( i = 0 ;i < G -> n; i++){

        dist = hamming( sQ->sketches , G -> sketches[i]);//el que se calcula por defecto

        if( G -> nHiperPlanos > 32 )
            dist = dist + hamming( sQ->sketchesPart2 , G -> sketchesPart2[i]);

        if( G -> nHiperPlanos > 64 )
             dist = dist + hamming( sQ->sketchesPart3 , G -> sketchesPart3[i]);

        if( G -> nHiperPlanos > 96 )
            dist = dist + hamming( sQ->sketchesPart4 , G -> sketchesPart4[i]);

        if( G -> nHiperPlanos > 128 )
            dist = dist + hamming( sQ->sketchesPart5 , G -> sketchesPart5[i]);

        if( G -> nHiperPlanos > 160 )
            dist = dist + hamming( sQ->sketchesPart6 , G -> sketchesPart6[i]);

        if( G -> nHiperPlanos > 192 )
            dist = dist + hamming( sQ->sketchesPart7 , G -> sketchesPart7[i]);

        if( G -> nHiperPlanos > 224 )
            dist = dist + hamming( sQ->sketchesPart8 , G -> sketchesPart8[i]);

        if( G -> nHiperPlanos > 256 )
            dist = dist + hamming( sQ->sketchesPart9 , G -> sketchesPart9[i]);

        if( G -> nHiperPlanos > 288 )
            dist = dist + hamming( sQ->sketchesPart10 , G -> sketchesPart10[i]);

        if (G -> nHiperPlanos > 320)
            dist = dist + hamming( sQ->sketchesPart11 , G -> sketchesPart11[i]);

        if (G -> nHiperPlanos > 352)
            dist = dist + hamming( sQ->sketchesPart12 , G -> sketchesPart12[i]);

        if (G -> nHiperPlanos > 384)
            dist = dist + hamming( sQ->sketchesPart13 , G -> sketchesPart13[i]);
        if (G -> nHiperPlanos > 416)
            dist = dist + hamming( sQ->sketchesPart14 , G -> sketchesPart14[i]);
        if (G->nHiperPlanos > 448)
            dist = dist + hamming( sQ->sketchesPart15 , G -> sketchesPart15[i]);
        if (G->nHiperPlanos > 480)
            dist = dist + hamming( sQ->sketchesPart16 , G -> sketchesPart16[i]);
        if (G->nHiperPlanos > 512)
            dist = dist + hamming( sQ->sketchesPart17 , G -> sketchesPart17[i]);
        if (G->nHiperPlanos > 544)
            dist = dist + hamming( sQ->sketchesPart18 , G -> sketchesPart18[i]);
        if (G->nHiperPlanos > 576)
            dist = dist + hamming( sQ->sketchesPart19 , G -> sketchesPart19[i]);
        if (G->nHiperPlanos > 608)
            dist = dist + hamming( sQ->sketchesPart20 , G -> sketchesPart20[i]);
        if (G->nHiperPlanos > 640)
            dist = dist + hamming( sQ->sketchesPart21 , G -> sketchesPart21[i]);
        if (G->nHiperPlanos > 672)
            dist = dist + hamming( sQ->sketchesPart22 , G -> sketchesPart22[i]);
        if (G->nHiperPlanos > 704)
            dist = dist + hamming( sQ->sketchesPart23 , G -> sketchesPart23[i]);
        if (G->nHiperPlanos > 736)
            dist = dist + hamming( sQ->sketchesPart24 , G -> sketchesPart24[i]);
        if (G->nHiperPlanos > 768)
            dist = dist + hamming( sQ->sketchesPart25 , G -> sketchesPart25[i]);
        if (G->nHiperPlanos > 800)
            dist = dist + hamming( sQ->sketchesPart26 , G -> sketchesPart26[i]);
        if (G->nHiperPlanos > 832)
            dist = dist + hamming( sQ->sketchesPart27 , G -> sketchesPart27[i]);
        if (G->nHiperPlanos > 864)
            dist = dist + hamming( sQ->sketchesPart28 , G -> sketchesPart28[i]);
        if (G->nHiperPlanos > 896)
            dist = dist + hamming( sQ->sketchesPart29 , G -> sketchesPart29[i]);
        if (G->nHiperPlanos > 928)
            dist = dist + hamming( sQ->sketchesPart30 , G -> sketchesPart30[i]);
        if (G->nHiperPlanos > 960)
            dist = dist + hamming( sQ->sketchesPart31 , G -> sketchesPart31[i]);
        if (G->nHiperPlanos > 992)
            dist = dist + hamming( sQ->sketchesPart32 , G -> sketchesPart32[i]);
        if (G->nHiperPlanos > 1024)
            dist = dist + hamming( sQ->sketchesPart33 , G -> sketchesPart33[i]);
        if (G->nHiperPlanos > 1056)
            dist = dist + hamming( sQ->sketchesPart34 , G -> sketchesPart34[i]);
        if (G->nHiperPlanos > 1088)
            dist = dist + hamming( sQ->sketchesPart35 , G -> sketchesPart35[i]);
        if (G->nHiperPlanos > 1120)
            dist = dist + hamming( sQ->sketchesPart36 , G -> sketchesPart36[i]);
        if (G->nHiperPlanos > 1152)
            dist = dist + hamming( sQ->sketchesPart37 , G -> sketchesPart37[i]);
        if (G->nHiperPlanos > 1184)
            dist = dist + hamming( sQ->sketchesPart38 , G -> sketchesPart38[i]);
        if (G->nHiperPlanos > 1216)
            dist = dist + hamming( sQ->sketchesPart39 , G -> sketchesPart39[i]);
        if (G->nHiperPlanos > 1248)
            dist = dist + hamming( sQ->sketchesPart40 , G -> sketchesPart40[i]);
        if (G->nHiperPlanos > 1280)
            dist = dist + hamming( sQ->sketchesPart41 , G -> sketchesPart41[i]);
        if (G->nHiperPlanos > 1312)
            dist = dist + hamming( sQ->sketchesPart42 , G -> sketchesPart42[i]);
        if (G->nHiperPlanos > 1344)
            dist = dist + hamming( sQ->sketchesPart43 , G -> sketchesPart43[i]);
        if (G->nHiperPlanos > 1376)
            dist = dist + hamming( sQ->sketchesPart44 , G -> sketchesPart44[i]);
        if (G->nHiperPlanos > 1408)
            dist = dist + hamming( sQ->sketchesPart45 , G -> sketchesPart45[i]);
        if (G->nHiperPlanos > 1440)
            dist = dist + hamming( sQ->sketchesPart46 , G -> sketchesPart46[i]);
        if (G->nHiperPlanos > 1472)
            dist = dist + hamming( sQ->sketchesPart47 , G -> sketchesPart47[i]);
        if (G->nHiperPlanos > 1504)
            dist = dist + hamming( sQ->sketchesPart48 , G -> sketchesPart48[i]);
        if (G->nHiperPlanos > 1536)
            dist = dist + hamming( sQ->sketchesPart49 , G -> sketchesPart49[i]);
        if (G->nHiperPlanos > 1568)
            dist = dist + hamming( sQ->sketchesPart50 , G -> sketchesPart50[i]);
        if (G->nHiperPlanos > 1600)
            dist = dist + hamming( sQ->sketchesPart51 , G -> sketchesPart51[i]);
        if (G->nHiperPlanos > 1632)
            dist = dist + hamming( sQ->sketchesPart52 , G -> sketchesPart52[i]);
        if (G->nHiperPlanos > 1664)
            dist = dist + hamming( sQ->sketchesPart53 , G -> sketchesPart53[i]);
        if (G->nHiperPlanos > 1696)
            dist = dist + hamming( sQ->sketchesPart54 , G -> sketchesPart54[i]);
        if (G->nHiperPlanos > 1728)
            dist = dist + hamming( sQ->sketchesPart55 , G -> sketchesPart55[i]);
        if (G->nHiperPlanos > 1760)
            dist = dist + hamming( sQ->sketchesPart56 , G -> sketchesPart56[i]);
        if (G->nHiperPlanos > 1792)
            dist = dist + hamming( sQ->sketchesPart57 , G -> sketchesPart57[i]);
        if (G->nHiperPlanos > 1824)
            dist = dist + hamming( sQ->sketchesPart58 , G -> sketchesPart58[i]);
        if (G->nHiperPlanos > 1856)
            dist = dist + hamming( sQ->sketchesPart59 , G -> sketchesPart59[i]);
        if (G->nHiperPlanos > 1888)
            dist = dist + hamming( sQ->sketchesPart60 , G -> sketchesPart60[i]);
        if (G->nHiperPlanos > 1920)
            dist = dist + hamming( sQ->sketchesPart61 , G -> sketchesPart61[i]);
        if (G->nHiperPlanos > 1952)
            dist = dist + hamming( sQ->sketchesPart62 , G -> sketchesPart62[i]);
        if (G->nHiperPlanos > 1984)
            dist = dist + hamming( sQ->sketchesPart63 , G -> sketchesPart63[i]);
        if (G->nHiperPlanos > 2016)
            dist = dist + hamming( sQ->sketchesPart64 , G -> sketchesPart64[i]);
        if (G->nHiperPlanos > 2048)
            dist = dist + hamming( sQ->sketchesPart65 , G -> sketchesPart65[i]);
        if (G->nHiperPlanos > 2080)
            dist = dist + hamming( sQ->sketchesPart66 , G -> sketchesPart66[i]);

        distanciaHamming[i].distanciaQ = dist;
        distanciaHamming[i].o = i+1;

    }

    qsort( distanciaHamming, G -> n, sizeof( consulta ) , cmpfunc); //se ordenan las distancias de hammign entre el objeto q y ui

    kPorcentaje = porcentaje * (G->n / 100);

    distanciaRealAprox = (consultaReal *) malloc(sizeof(consultaReal) * kPorcentaje);
    workload(kPorcentaje, q, distanciaRealAprox, distanciaHamming);
    qsort(distanciaRealAprox, kPorcentaje, sizeof(consultaReal), cmpfuncFloat);

    kCandidatosAprox = (int *) malloc(sizeof(int) * k);
    kCandidatosReal = (int *) malloc(sizeof(int) * k);

    calculaCandidatos(distanciaReal, distanciaRealAprox, kCandidatosAprox, kCandidatosReal, k);
    qsort(kCandidatosReal, k, sizeof(int), compara);

    for (i = 0; i < k; i++) {

        objetivo = kCandidatosAprox[i];
        resultado = (int *) bsearch(&objetivo, kCandidatosReal, k, sizeof(int), compara);

        if (resultado != NULL) {
            interseccion++;
        }
    }

    recall = ((float) interseccion / (float) k) * 100;

    free(distanciaRealAprox)
    free(kCandidatosAprox);
    free(kCandidatosReal);
    free(distanciaHamming);

    return recall;

}

void freeIndex (Index S, bool libobj){
    printf("freeindex\n");
    rbbf1 *G = (rbbf1*)S;
    free (G->descr);
    free (G);
    if (libobj) closeDB();
}