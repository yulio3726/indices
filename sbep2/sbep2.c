#include "sbep2.h"
#include "implementaciones.h"
#include <sys/times.h>

float kNN(SBEP2* S, int k, int porcentaje, Obj q, SKETCHQ* sQ, CONSULTAREAL* distanciaReal);
CONSULTAREAL* kNNTiempo( SBEP2* S , int k, int porcentaje, Obj q, SKETCHQ*  sQ);

Index build (char *dbname, int n, int *argc, char ***argv){

    if(*argc < 1){
        fprintf(stderr, "Usage_ <args> ARITY\n");
        exit(1);
    }
    
    int i = 0;
    int u = 0;
    int posicion = 0;
    int dimension = 0;
    int m = 0;

    ARRAYTEMPORAL* permutacionI;
    int* permutacionIInvertida;

    SBEP2* I;
    I = (SBEP2* )malloc( sizeof( SBEP2 ) );

    I -> descr = (char*)malloc(strlen (dbname) + 1);
    strcpy(I -> descr, dbname);

    I -> np = openDB( I -> descr);
    if (n && (n < I -> np)) I -> np = n;

    I -> k = atoi( ( *argv[0] ) ); (*argc)--; (*argv)++;

    //pruebasFuncionamiento(I);

    I -> p = (Obj*)malloc( sizeof(Obj) * I -> k );
    seleccionaPivotesAleatorio(I -> p, I -> k, I -> np);

    I -> sketches = (unsigned int*)malloc( sizeof ( unsigned int ) * I -> np);
    if (I -> k > 32)
        I -> sketchesPart2 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);

    if ((I -> k > 64))
        I -> sketchesPart3 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);

    if ((I -> k > 96)) {
        I -> sketchesPart4 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 128)) {
        I -> sketchesPart5 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 160)) {
        I -> sketchesPart6 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 192)) {
        I -> sketchesPart7 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 224)) {
        I -> sketchesPart8 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I->k > 256)) {
        I->sketchesPart9 = (unsigned int*) malloc(sizeof(unsigned int) * I->np);
    }

    if ((I->k > 288)) {
        I->sketchesPart10 = (unsigned int*)malloc(sizeof(unsigned int) * I->np);
    }

    if ((I -> k > 320)) {
        I -> sketchesPart11 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 352)) {
        I -> sketchesPart12 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 384)) {
        I -> sketchesPart13 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 416)) {
        I -> sketchesPart14 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 448)) {
        I -> sketchesPart15 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 480)) {
        I -> sketchesPart16 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 512)) {
        I -> sketchesPart17 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 544)) {
        I -> sketchesPart18 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 576)) {
        I -> sketchesPart19 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 608)) {
        I -> sketchesPart20 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 640)) {
        I -> sketchesPart21 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 672)) {
        I -> sketchesPart22 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 704)) {
        I -> sketchesPart23 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 736)) {
        I -> sketchesPart24 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 768)) {
        I -> sketchesPart25 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 800)) {
        I -> sketchesPart26 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 832)) {
        I -> sketchesPart27 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 864)) {
        I -> sketchesPart28 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 896)) {
        I -> sketchesPart29 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 928)) {
        I -> sketchesPart30 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 960)) {
        I -> sketchesPart31 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 992)) {
        I -> sketchesPart32 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1024)) {
        I -> sketchesPart33 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1056)) {
        I -> sketchesPart34 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1088)) {
        I -> sketchesPart35 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1120)) {
        I -> sketchesPart36 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1152)) {
        I -> sketchesPart37 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1184)) {
        I -> sketchesPart38 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1216)) {
        I -> sketchesPart39 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1248)) {
        I -> sketchesPart40 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1280)) {
        I -> sketchesPart41 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1312)) {
        I -> sketchesPart42 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1314)) {
        I -> sketchesPart43 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1376)) {
        I -> sketchesPart44 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1408)) {
        I -> sketchesPart45 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1440)) {
        I -> sketchesPart46 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1472)) {
        I -> sketchesPart47 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1504)) {
        I -> sketchesPart48 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1536)) {
        I -> sketchesPart49 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1568)) {
        I -> sketchesPart50 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1600)) {
        I -> sketchesPart51 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1632)) {
        I -> sketchesPart52 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1664)) {
        I -> sketchesPart53 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1696)) {
        I -> sketchesPart54 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1728)) {
        I -> sketchesPart55 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1760)) {
        I -> sketchesPart56 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1792)) {
        I -> sketchesPart57 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1824)) {
        I -> sketchesPart58 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1856)) {
        I -> sketchesPart59 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1888)) {
        I -> sketchesPart60 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1920)) {
        I -> sketchesPart61 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1952)) {
        I -> sketchesPart62 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 1984)) {
        I -> sketchesPart63 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 2016)) {
        I -> sketchesPart64 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 2048)) {
        I -> sketchesPart65 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }

    if ((I -> k > 2080)) {
        I -> sketchesPart66 = (unsigned int*)malloc(sizeof(unsigned int) * I -> np);
    }
    permutacionI  = (ARRAYTEMPORAL*)malloc(sizeof(ARRAYTEMPORAL)* I->k);
    permutacionIInvertida = (int*)malloc(sizeof(int) * I->k);

    i = 0;
    posicion = 0;

    m = I->k /2;

    while(i < I  -> np) {
        
        i++;//objeto de la base de datos
        u = i;

        I->sketches[u - 1] = 0;
        if (I->k > 32)
            I->sketchesPart2[u - 1] = 0;
        if (I->k > 64)
            I->sketchesPart3[u - 1] = 0;
        if (I->k > 96)
            I->sketchesPart4[u - 1] = 0;
        if (I->k > 128)
            I->sketchesPart5[u - 1] = 0;
        if (I->k > 160)
            I->sketchesPart6[u - 1] = 0;
        if (I->k > 192)
            I->sketchesPart7[u - 1] = 0;
        if (I->k > 224)
            I->sketchesPart8[u - 1] = 0;
        if (I->k > 256)
            I->sketchesPart9[u-1] = 0;
        if (I->k > 288)
            I->sketchesPart10[u-1] = 0;
        if (I->k > 320)
            I->sketchesPart11[u - 1] = 0;
        if (I->k > 352)
            I->sketchesPart12[u - 1] = 0;
        if (I->k > 384)
            I->sketchesPart13[u - 1] = 0;
        if (I->k > 416)
            I->sketchesPart14[u - 1] = 0;
        if (I->k > 448)
            I->sketchesPart15[u - 1] = 0;
        if (I->k > 480)
            I->sketchesPart16[u - 1] = 0;
        if (I->k > 512)
            I->sketchesPart17[u - 1] = 0;
        if (I->k > 544)
            I->sketchesPart18[u - 1] = 0;
        if (I->k > 576)
            I->sketchesPart19[u - 1] = 0;
        if (I->k > 608)
            I->sketchesPart20[u - 1] = 0;
        if (I->k > 640)
            I->sketchesPart21[u - 1] = 0;
        if (I->k > 672)
            I->sketchesPart22[u - 1] = 0;
        if (I->k > 704)
            I->sketchesPart23[u - 1] = 0;
        if (I->k > 736)
            I->sketchesPart24[u - 1] = 0;
        if (I->k > 768)
            I->sketchesPart25[u - 1] = 0;
        if (I->k > 800)
            I->sketchesPart26[u - 1] = 0;
        if (I->k > 832)
            I->sketchesPart27[u - 1] = 0;
        if (I->k > 864)
            I->sketchesPart28[u - 1] = 0;
        if (I->k > 896)
            I->sketchesPart29[u - 1] = 0;
        if (I->k > 928)
            I->sketchesPart30[u - 1] = 0;
        if (I->k > 960)
            I->sketchesPart31[u - 1] = 0;
        if (I->k > 992)
            I->sketchesPart32[u - 1] = 0;
        if (I->k > 1024)
            I->sketchesPart33[u - 1] = 0;
        if (I->k > 1056)
            I->sketchesPart34[u - 1] = 0;
        if (I->k > 1088)
            I->sketchesPart35[u - 1] = 0;
        if (I->k > 1120)
            I->sketchesPart36[u - 1] = 0;
        if (I->k > 1152)
            I->sketchesPart37[u - 1] = 0;
        if (I->k > 1184)
            I->sketchesPart38[u - 1] = 0;
        if (I->k > 1216)
            I->sketchesPart39[u - 1] = 0;
        if (I->k > 1248)
            I->sketchesPart40[u - 1] = 0;
        if (I->k > 1280)
            I->sketchesPart41[u - 1] = 0;
        if (I->k > 1312)
            I->sketchesPart42[u - 1] = 0;
        if (I->k > 1344)
            I->sketchesPart43[u - 1] = 0;
        if (I->k > 1376)
            I->sketchesPart44[u - 1] = 0;
        if (I->k > 1408)
            I->sketchesPart45[u - 1] = 0;
        if (I->k > 1440)
            I->sketchesPart46[u - 1] = 0;
        if (I->k > 1472)
            I->sketchesPart47[u - 1] = 0;
        if (I->k > 1504)
            I->sketchesPart48[u - 1] = 0;
        if (I->k > 1536)
            I->sketchesPart49[u - 1] = 0;
        if (I->k > 1568)
            I->sketchesPart50[u - 1] = 0;
        if (I->k > 1600)
            I->sketchesPart51[u - 1] = 0;
        if (I->k > 1632)
            I->sketchesPart52[u - 1] = 0;
        if (I->k > 1664)
            I->sketchesPart53[u - 1] = 0;
        if (I->k > 1696)
            I->sketchesPart54[u - 1] = 0;
        if (I->k > 1728)
            I->sketchesPart55[u - 1] = 0;
        if (I->k > 1760)
            I->sketchesPart56[u - 1] = 0;
        if (I->k > 1792)
            I->sketchesPart57[u - 1] = 0;
        if (I->k > 1824)
            I->sketchesPart58[u - 1] = 0;
        if (I->k > 1856)
            I->sketchesPart59[u - 1] = 0;
        if (I->k > 1888)
            I->sketchesPart60[u - 1] = 0;
        if (I->k > 1920)
            I->sketchesPart61[u - 1] = 0;
        if (I->k > 1952)
            I->sketchesPart62[u - 1] = 0;
        if (I->k > 1984)
            I->sketchesPart63[u - 1] = 0;
        if (I->k > 2016)
            I->sketchesPart64[u - 1] = 0;
        if (I->k > 2048)
            I->sketchesPart65[u - 1] = 0;
        if (I->k > 2080)
            I->sketchesPart66[u - 1] = 0;

        calculaDistanciaReferenciasConsulta(i, permutacionI, I->k, I->p);
        qsort(permutacionI, I->k, sizeof(ARRAYTEMPORAL), cmpFloat);
        guardaInversaI(permutacionI, permutacionIInvertida, I->k);

        //bit = 0;
        for( dimension = 0; dimension < I -> k; dimension++){

            if( permutacionIInvertida[dimension]<= m ){
                //bit = 1;
                if (dimension < 32) {
                    I -> sketches[i - 1] ^= (-1 ^ I -> sketches[i - 1]) & (1 << dimension);
                }

                if ((dimension >= 32) && (dimension < 64)) {
                    posicion = dimension - 32;
                    I -> sketchesPart2[i - 1] ^= (-1 ^ I -> sketchesPart2[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 64) && (dimension < 96)) {
                    posicion = dimension - 64;
                    I -> sketchesPart3[i - 1] ^= (-1 ^ I -> sketchesPart3[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 96) && (dimension < 128)) {
                    posicion = dimension - 96;
                    I -> sketchesPart4[i - 1] ^= (-1 ^ I -> sketchesPart4[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 128) && (dimension < 160)) {
                    posicion = dimension - 128;
                    I -> sketchesPart5[i - 1] ^= (-1 ^ I -> sketchesPart5[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 160) && (dimension < 192)) {
                    posicion = dimension - 160;
                    I -> sketchesPart6[i - 1] ^= (-1 ^ I -> sketchesPart6[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 192) && (dimension < 224)) {
                    posicion = dimension - 192;
                    I -> sketchesPart7[i - 1] ^= (-1 ^ I -> sketchesPart7[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 224) && (dimension < 256)) {
                    posicion = dimension - 224;
                    I -> sketchesPart8[i - 1] ^= (-1 ^ I -> sketchesPart8[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 224) && (dimension < 256)) {
                    posicion = dimension - 224;
                    I->sketchesPart8[i - 1] ^= (-1 ^ I->sketchesPart8[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 256) && (dimension < 288)) {
                    posicion = dimension - 256;
                    I->sketchesPart9[i - 1] ^= (-1 ^ I->sketchesPart9[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 288) && (dimension < 320)) {
                    posicion = dimension - 288;
                    I->sketchesPart10[i - 1] ^= (-1 ^ I->sketchesPart10[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 320) && (dimension < 352)) {
                    posicion = dimension - 320;
                    I -> sketchesPart11[i - 1] ^= (-1 ^ I -> sketchesPart11[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 352) && (dimension < 384)) {
                    posicion = dimension - 352;
                    I -> sketchesPart12[i - 1] ^= (-1 ^ I -> sketchesPart12[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 384) && (dimension < 416)) {
                    posicion = dimension - 384;
                    I -> sketchesPart13[i - 1] ^= (-1 ^ I -> sketchesPart13[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 416) && (dimension < 448)) {
                    posicion = dimension - 416;
                    I -> sketchesPart14[i - 1] ^= (-1 ^ I -> sketchesPart14[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 448) && (dimension < 480)) {
                    posicion = dimension - 448;
                    I -> sketchesPart15[i - 1] ^= (-1 ^ I -> sketchesPart15[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 480) && (dimension < 512)) {
                    posicion = dimension - 480;
                    I -> sketchesPart16[i - 1] ^= (-1 ^ I -> sketchesPart16[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 512) && (dimension < 544)) {
                    posicion = dimension - 512;
                    I -> sketchesPart17[i - 1] ^= (-1 ^ I -> sketchesPart17[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 544) && (dimension < 576)) {
                    posicion = dimension - 544;
                    I -> sketchesPart18[i - 1] ^= (-1 ^ I -> sketchesPart18[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 576) && (dimension < 608)) {
                    posicion = dimension - 576;
                    I -> sketchesPart19[i - 1] ^= (-1 ^ I -> sketchesPart19[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 608) && (dimension < 640)) {
                    posicion = dimension - 608;
                    I -> sketchesPart20[i - 1] ^= (-1 ^ I -> sketchesPart20[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 640) && (dimension < 672)) {
                    posicion = dimension - 640;
                    I -> sketchesPart21[i - 1] ^= (-1 ^ I -> sketchesPart21[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 672) && (dimension < 704)) {
                    posicion = dimension - 672;
                    I -> sketchesPart22[i - 1] ^= (-1 ^ I -> sketchesPart22[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 704) && (dimension < 736)) {
                    posicion = dimension - 704;
                    I -> sketchesPart23[i - 1] ^= (-1 ^ I -> sketchesPart23[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 736) && (dimension < 768)) {
                    posicion = dimension - 736;
                    I -> sketchesPart24[i - 1] ^= (-1 ^ I -> sketchesPart24[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 768) && (dimension < 800)) {
                    posicion = dimension - 768;
                    I -> sketchesPart25[i - 1] ^= (-1 ^ I -> sketchesPart25[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 800) && (dimension < 832)) {
                    posicion = dimension - 800;
                    I -> sketchesPart26[i - 1] ^= (-1 ^ I -> sketchesPart26[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 832) && (dimension < 864)) {
                    posicion = dimension - 832;
                    I -> sketchesPart27[i - 1] ^= (-1 ^ I -> sketchesPart27[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 864) && (dimension < 896)) {
                    posicion = dimension - 864;
                    I -> sketchesPart28[i - 1] ^= (-1 ^ I -> sketchesPart28[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 896) && (dimension < 928)) {
                    posicion = dimension - 896;
                    I -> sketchesPart29[i - 1] ^= (-1 ^ I -> sketchesPart29[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 928) && (dimension < 960)) {
                    posicion = dimension - 928;
                    I -> sketchesPart30[i - 1] ^= (-1 ^ I -> sketchesPart30[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 960) && (dimension < 992)) {
                    posicion = dimension - 960;
                    I -> sketchesPart31[i - 1] ^= (-1 ^ I -> sketchesPart31[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 992) && (dimension < 1024)) {
                    posicion = dimension - 992;
                    I -> sketchesPart32[i - 1] ^= (-1 ^ I -> sketchesPart32[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1024) && (dimension < 1056)) {
                    posicion = dimension - 1024;
                    I -> sketchesPart33[i - 1] ^= (-1 ^ I -> sketchesPart33[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1056) && (dimension < 1088)) {
                    posicion = dimension - 1056;
                    I -> sketchesPart34[i - 1] ^= (-1 ^ I -> sketchesPart34[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1088) && (dimension < 1120)) {
                    posicion = dimension - 1088;
                    I -> sketchesPart35[i - 1] ^= (-1 ^ I -> sketchesPart35[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1120) && (dimension < 1152)) {
                    posicion = dimension - 1120;
                    I -> sketchesPart36[i - 1] ^= (-1 ^ I -> sketchesPart36[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 1152) && (dimension < 1184)){
                    posicion = dimension - 1152;
                    I -> sketchesPart37[i - 1] ^= (-1 ^ I -> sketchesPart37[i - 1]) & (1 << posicion);
                }

                if ((dimension >= 1184) && (dimension < 1216)) {
                    posicion = dimension - 1184;
                    I -> sketchesPart38[i - 1] ^= (-1 ^ I -> sketchesPart38[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1216) && (dimension < 1248)) {
                    posicion = dimension - 1216;
                    I -> sketchesPart39[i - 1] ^= (-1 ^ I -> sketchesPart39[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1248) && (dimension < 1280)) {
                    posicion = dimension - 1248;
                    I -> sketchesPart40[i - 1] ^= (-1 ^ I -> sketchesPart40[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1280) && (dimension < 1312)) {
                    posicion = dimension - 1280;
                    I -> sketchesPart41[i - 1] ^= (-1 ^ I -> sketchesPart41[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1312) && (dimension < 1344)) {
                    posicion = dimension - 1312;
                    I -> sketchesPart42[i - 1] ^= (-1 ^ I -> sketchesPart42[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1344) && (dimension < 1376)) {
                    posicion = dimension - 1344;
                    I -> sketchesPart43[i - 1] ^= (-1 ^ I -> sketchesPart43[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1376) && (dimension < 1408)) {
                    posicion = dimension - 1376;
                    I -> sketchesPart44[i - 1] ^= (-1 ^ I -> sketchesPart44[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1408) && (dimension < 1440)) {
                    posicion = dimension - 1408;
                    I -> sketchesPart45[i - 1] ^= (-1 ^ I -> sketchesPart45[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1440) && (dimension < 1472)) {
                    posicion = dimension - 1440;
                    I -> sketchesPart46[i - 1] ^= (-1 ^ I -> sketchesPart46[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1472) && (dimension < 1504)) {
                    posicion = dimension - 1472;
                    I -> sketchesPart47[i - 1] ^= (-1 ^ I -> sketchesPart47[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1504) && (dimension < 1536)) {
                    posicion = dimension - 1504;
                    I -> sketchesPart48[i - 1] ^= (-1 ^ I -> sketchesPart48[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1536) && (dimension < 1568)) {
                    posicion = dimension - 1536;
                    I -> sketchesPart49[i - 1] ^= (-1 ^ I -> sketchesPart49[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1568) && (dimension < 1600)) {
                    posicion = dimension - 1568;
                    I -> sketchesPart50[i - 1] ^= (-1 ^ I -> sketchesPart50[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1600) && (dimension < 1632)) {
                    posicion = dimension - 1600;
                    I -> sketchesPart51[i - 1] ^= (-1 ^ I -> sketchesPart51[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1632) && (dimension < 1664)) {
                    posicion = dimension - 1632;
                    I -> sketchesPart52[i - 1] ^= (-1 ^ I -> sketchesPart52[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1664) && (dimension < 1696)) {
                    posicion = dimension - 1664;
                    I -> sketchesPart53[i - 1] ^= (-1 ^ I -> sketchesPart53[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1696) && (dimension < 1728)) {
                    posicion = dimension - 1696;
                    I -> sketchesPart54[i - 1] ^= (-1 ^ I -> sketchesPart54[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1728) && (dimension < 1760)) {
                    posicion = dimension - 1728;
                    I -> sketchesPart55[i - 1] ^= (-1 ^ I -> sketchesPart55[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1760) && (dimension < 1792)) {
                    posicion = dimension - 1760;
                    I -> sketchesPart56[i - 1] ^= (-1 ^ I -> sketchesPart56[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1792) && (dimension < 1824)) {
                    posicion = dimension - 1792;
                    I -> sketchesPart57[i - 1] ^= (-1 ^ I -> sketchesPart57[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1824) && (dimension < 1856)) {
                    posicion = dimension - 1824;
                    I -> sketchesPart58[i - 1] ^= (-1 ^ I -> sketchesPart58[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1856) && (dimension < 1888)) {
                    posicion = dimension - 1856;
                    I -> sketchesPart59[i - 1] ^= (-1 ^ I -> sketchesPart59[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1888) && (dimension < 1920)) {
                    posicion = dimension - 1888;
                    I -> sketchesPart60[i - 1] ^= (-1 ^ I -> sketchesPart60[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1920) && (dimension < 1952)) {
                    posicion = dimension - 1920;
                    I -> sketchesPart61[i - 1] ^= (-1 ^ I -> sketchesPart61[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1952) && (dimension < 1984)) {
                    posicion = dimension - 1952;
                    I -> sketchesPart62[i - 1] ^= (-1 ^ I -> sketchesPart62[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 1984) && (dimension < 2016)) {
                    posicion = dimension - 1984;
                    I -> sketchesPart63[i - 1] ^= (-1 ^ I -> sketchesPart63[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 2016) && (dimension < 2048)) {
                    posicion = dimension - 2016;
                    I -> sketchesPart64[i - 1] ^= (-1 ^ I -> sketchesPart64[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 2048) && (dimension < 2080)) {
                    posicion = dimension - 2048;
                    I -> sketchesPart65[i - 1] ^= (-1 ^ I -> sketchesPart65[i - 1]) & (1 << posicion);

                }

                if ((dimension >= 2080) && (dimension < 2112)) {
                    posicion = dimension - 2080;
                    I -> sketchesPart66[i - 1] ^= (-1 ^ I -> sketchesPart66[i - 1]) & (1 << posicion);

                }
            }
        }
    }

    //pruebasVelocidad(I);
    pruebas(I);

    free(permutacionI);
    free(permutacionIInvertida);

    return (Index) I;

}

void pruebas(Index S){

    printf("\n\t INICIAN LAS PRUEBAS\n");
    SBEP2* I = (SBEP2*)S;

    int i;
    int j;
    int k = 2; //los k vecinos mas cercanos que quiero
    int nObjetosPrueba = 300; //numero de veces que se va a repetir las pruebas
    int porcentaje[] = {1, 3, 5, 7, 10}; //porcentaje que se va a revisar de la base de datos
    int nPorcentaje = 5;
    int m = I->k /2;

    Obj* objetosConsulta;

    CONSULTAREAL* distanciaReal = NULL;
    float recall;
    float sumaRecall[nPorcentaje];
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    objetosConsulta = (Obj*) malloc( sizeof (Obj) * nObjetosPrueba);
    generaConsultas(objetosConsulta, nObjetosPrueba, I -> np);

    SKETCHQ sQ;

    distanciaReal = ( CONSULTAREAL* ) malloc( sizeof( CONSULTAREAL ) * I -> np);

    /*printf("\n\tK = %d\n", k);
    for(j = 0; j < nObjetosPrueba; j++){

        generaSketch(&sQ, objetosConsulta[j] , I -> p, I->k, m); //se genera el sketch de la consulta

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &sQ, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }*/

    /***********************************************************************************************************/

    /*k = 4;
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    printf("\n\tK = %d\n", k);
    for(j = 0; j < nObjetosPrueba; j++){

        generaSketch(&sQ, objetosConsulta[j] , I -> p, I->k, m); //se genera el sketch de la consulta

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &sQ, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }*/

    /***********************************************************************************************************/

    k = 8;
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    printf("\n\tK = %d\n", k);
    for(j = 0; j < nObjetosPrueba; j++){

        generaSketch(&sQ, objetosConsulta[j] , I -> p, I->k, m); //se genera el sketch de la consulta

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

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

        generaSketch(&sQ, objetosConsulta[j] , I -> p, I->k, m); //se genera el sketch de la consulta

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

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

    /*k = 32;
    iniciaSumaRecall(&sumaRecall, nPorcentaje);

    printf("\n\tK = %d\n", k);
    for(j = 0; j < nObjetosPrueba; j++){

        generaSketch(&sQ, objetosConsulta[j] , I -> p, I->k, m); //se genera el sketch de la consulta

        calculaDistanciaReal(distanciaReal, I -> np, objetosConsulta[j]);
        qsort( distanciaReal, I -> np, sizeof( CONSULTAREAL ), cmpfuncFloat);

        for(i = 0; i < nPorcentaje; i++){
            recall = kNN( S , k, porcentaje[i], objetosConsulta[j], &sQ, distanciaReal);
            sumaRecall[i] = sumaRecall[i] + recall;
        }
    }

    printf("\tPromedio recall\n");
    for(i = 0; i < nPorcentaje; i++){
        printf(" porcentaje %d %f\n", porcentaje[i], sumaRecall[i]/nObjetosPrueba);
    }*/

    free(objetosConsulta);
    free(distanciaReal);
    free(S);
}

float kNN(SBEP2* S, int k, int porcentaje,Obj q, SKETCHQ* sQ, CONSULTAREAL* distanciaReal){

    CONSULTA* distanciaHamming = NULL;

    CONSULTAREAL* distanciaRealAprox = NULL;

    int kPorcentaje;
    int i;
    int interseccion = 0;
    int objetivo = 0;
    int dist;

    int* kCandidatosAprox = NULL;
    int* kCandidatosReal = NULL;
    int* resultado = NULL;

    float recall=0;

    distanciaHamming = ( CONSULTA* ) malloc( sizeof(CONSULTA) * S -> np);

    for( i = 0 ;i < S -> np; i++){
        dist = hamming( sQ->sketches , S -> sketches[i]);//el que se calcula por defecto
        
        if( S ->  k > 32 )
            dist = dist + hamming( sQ->sketchesPart2 , S -> sketchesPart2[i]);

        if( S ->  k > 64 )
            dist = dist + hamming( sQ->sketchesPart3 , S -> sketchesPart3[i]);

        if( S ->  k > 96 )
            dist = dist + hamming( sQ->sketchesPart4 , S -> sketchesPart4[i]);

        if( S ->  k > 128 )
            dist = dist + hamming( sQ->sketchesPart5 , S -> sketchesPart5[i]);

        if( S ->  k > 160 )
            dist = dist + hamming( sQ->sketchesPart6 , S -> sketchesPart6[i]);

        if( S ->  k > 192 )
            dist = dist + hamming( sQ->sketchesPart7 , S -> sketchesPart7[i]);

        if( S ->  k > 224 )
            dist = dist + hamming( sQ->sketchesPart8 , S -> sketchesPart8[i]);

        if( S -> k > 256 )
            dist = dist + hamming( sQ->sketchesPart9 , S -> sketchesPart9[i]);

        if( S -> k > 288 )
            dist = dist + hamming( sQ->sketchesPart10 , S -> sketchesPart10[i]);

        if (S -> k > 320)
            dist = dist + hamming( sQ->sketchesPart11 , S -> sketchesPart11[i]);

        if (S -> k > 352)
            dist = dist + hamming( sQ->sketchesPart12 , S -> sketchesPart12[i]);

        if (S -> k > 384)
            dist = dist + hamming( sQ->sketchesPart13 , S -> sketchesPart13[i]);
        if (S -> k > 416)
            dist = dist + hamming( sQ->sketchesPart14 , S -> sketchesPart14[i]);
        if (S->k > 448)
            dist = dist + hamming( sQ->sketchesPart15 , S -> sketchesPart15[i]);
        if (S->k > 480)
            dist = dist + hamming( sQ->sketchesPart16 , S -> sketchesPart16[i]);
        if (S->k > 512)
            dist = dist + hamming( sQ->sketchesPart17 , S -> sketchesPart17[i]);
        if (S->k > 544)
            dist = dist + hamming( sQ->sketchesPart18 , S -> sketchesPart18[i]);
        if (S->k > 576)
            dist = dist + hamming( sQ->sketchesPart19 , S -> sketchesPart19[i]);
        if (S->k > 608)
            dist = dist + hamming( sQ->sketchesPart20 , S -> sketchesPart20[i]);
        if (S->k > 640)
            dist = dist + hamming( sQ->sketchesPart21 , S -> sketchesPart21[i]);
        if (S->k > 672)
            dist = dist + hamming( sQ->sketchesPart22 , S -> sketchesPart22[i]);
        if (S->k > 704)
            dist = dist + hamming( sQ->sketchesPart23 , S -> sketchesPart23[i]);
        if (S->k > 736)
            dist = dist + hamming( sQ->sketchesPart24 , S -> sketchesPart24[i]);
        if (S->k > 768)
            dist = dist + hamming( sQ->sketchesPart25 , S -> sketchesPart25[i]);
        if (S->k > 800)
            dist = dist + hamming( sQ->sketchesPart26 , S -> sketchesPart26[i]);
        if (S->k > 832)
            dist = dist + hamming( sQ->sketchesPart27 , S -> sketchesPart27[i]);
        if (S->k > 864)
            dist = dist + hamming( sQ->sketchesPart28 , S -> sketchesPart28[i]);
        if (S->k > 896)
            dist = dist + hamming( sQ->sketchesPart29 , S -> sketchesPart29[i]);
        if (S->k > 928)
            dist = dist + hamming( sQ->sketchesPart30 , S -> sketchesPart30[i]);
        if (S->k > 960)
            dist = dist + hamming( sQ->sketchesPart31 , S -> sketchesPart31[i]);
        if (S->k > 992)
            dist = dist + hamming( sQ->sketchesPart32 , S -> sketchesPart32[i]);
        if (S->k > 1024)
            dist = dist + hamming( sQ->sketchesPart33 , S -> sketchesPart33[i]);
        if (S->k > 1056)
            dist = dist + hamming( sQ->sketchesPart34 , S -> sketchesPart34[i]);
        if (S->k > 1088)
            dist = dist + hamming( sQ->sketchesPart35 , S -> sketchesPart35[i]);
        if (S->k > 1120)
            dist = dist + hamming( sQ->sketchesPart36 , S -> sketchesPart36[i]);
        if (S->k > 1152)
            dist = dist + hamming( sQ->sketchesPart37 , S -> sketchesPart37[i]);
        if (S->k > 1184)
            dist = dist + hamming( sQ->sketchesPart38 , S -> sketchesPart38[i]);
        if (S->k > 1216)
            dist = dist + hamming( sQ->sketchesPart39 , S -> sketchesPart39[i]);
        if (S->k > 1248)
            dist = dist + hamming( sQ->sketchesPart40 , S -> sketchesPart40[i]);
        if (S->k > 1280)
            dist = dist + hamming( sQ->sketchesPart41 , S -> sketchesPart41[i]);
        if (S->k > 1312)
            dist = dist + hamming( sQ->sketchesPart42 , S -> sketchesPart42[i]);
        if (S->k > 1344)
            dist = dist + hamming( sQ->sketchesPart43 , S -> sketchesPart43[i]);
        if (S->k > 1376)
            dist = dist + hamming( sQ->sketchesPart44 , S -> sketchesPart44[i]);
        if (S->k > 1408)
            dist = dist + hamming( sQ->sketchesPart45 , S -> sketchesPart45[i]);
        if (S->k > 1440)
            dist = dist + hamming( sQ->sketchesPart46 , S -> sketchesPart46[i]);
        if (S->k > 1472)
            dist = dist + hamming( sQ->sketchesPart47 , S -> sketchesPart47[i]);
        if (S->k > 1504)
            dist = dist + hamming( sQ->sketchesPart48 , S -> sketchesPart48[i]);
        if (S->k > 1536)
            dist = dist + hamming( sQ->sketchesPart49 , S -> sketchesPart49[i]);
        if (S->k > 1568)
            dist = dist + hamming( sQ->sketchesPart50 , S -> sketchesPart50[i]);
        if (S->k > 1600)
            dist = dist + hamming( sQ->sketchesPart51 , S -> sketchesPart51[i]);
        if (S->k > 1632)
            dist = dist + hamming( sQ->sketchesPart52 , S -> sketchesPart52[i]);
        if (S->k > 1664)
            dist = dist + hamming( sQ->sketchesPart53 , S -> sketchesPart53[i]);
        if (S->k > 1696)
            dist = dist + hamming( sQ->sketchesPart54 , S -> sketchesPart54[i]);
        if (S->k > 1728)
            dist = dist + hamming( sQ->sketchesPart55 , S -> sketchesPart55[i]);
        if (S->k > 1760)
            dist = dist + hamming( sQ->sketchesPart56 , S -> sketchesPart56[i]);
        if (S->k > 1792)
            dist = dist + hamming( sQ->sketchesPart57 , S -> sketchesPart57[i]);
        if (S->k > 1824)
            dist = dist + hamming( sQ->sketchesPart58 , S -> sketchesPart58[i]);
        if (S->k > 1856)
            dist = dist + hamming( sQ->sketchesPart59 , S -> sketchesPart59[i]);
        if (S->k > 1888)
            dist = dist + hamming( sQ->sketchesPart60 , S -> sketchesPart60[i]);
        if (S->k > 1920)
            dist = dist + hamming( sQ->sketchesPart61 , S -> sketchesPart61[i]);
        if (S->k > 1952)
            dist = dist + hamming( sQ->sketchesPart62 , S -> sketchesPart62[i]);
        if (S->k > 1984)
            dist = dist + hamming( sQ->sketchesPart63 , S -> sketchesPart63[i]);
        if (S->k > 2016)
            dist = dist + hamming( sQ->sketchesPart64 , S -> sketchesPart64[i]);
        if (S->k > 2048)
            dist = dist + hamming( sQ->sketchesPart65 , S -> sketchesPart65[i]);
        if (S->k > 2080)
            dist = dist + hamming( sQ->sketchesPart66 , S -> sketchesPart66[i]);

        distanciaHamming[i].distanciaQ = dist;
        distanciaHamming[i].o = i + 1;
    }

    qsort( distanciaHamming, S -> np, sizeof( CONSULTA ) , cmpfunc);

    kPorcentaje = porcentaje * (S -> np / 100);

    distanciaRealAprox = ( CONSULTAREAL* ) malloc( sizeof( CONSULTAREAL ) * kPorcentaje );
    workload(kPorcentaje, q, distanciaRealAprox, distanciaHamming);
    qsort( distanciaRealAprox, kPorcentaje, sizeof( CONSULTAREAL ) , cmpfuncFloat);

    kCandidatosAprox = ( int* ) malloc( sizeof( int ) * k);
    kCandidatosReal = ( int* ) malloc( sizeof( int ) * k);

    calculaCandidatos(distanciaReal, distanciaRealAprox, kCandidatosAprox, kCandidatosReal, k);
    qsort( kCandidatosReal, k, sizeof( int ) , compara);

    for(i = 0; i < k; i++){

        objetivo = kCandidatosAprox[i];
        resultado = (int*) bsearch( &objetivo, kCandidatosReal, k, sizeof( int ), compara);
        if( resultado != NULL){
            interseccion++;
        }
    }

    recall = ((float) interseccion / (float) k) * 100;

    //printf("\trecall : %f\n", recall);

    free(distanciaRealAprox);
    free(kCandidatosAprox);
    free(kCandidatosReal);
    free(distanciaHamming);

    return recall;
}

void pruebasFuncionamiento(SBEP2* I){

    int k = 67;
    int m = k/2;

    //int* permutacionIInvertida;

    //int* permutacionIInvertida2;

    int permutacionIInvertida[] = {2, 5, 55, 9, 52, 27, 10, 43, 48,	20,
                               45,	65,	31,	36,	33,	30,	28,	58,	19,	3,
                               6,	1,	41,	22,	59,	42,	32,	54,	23,	63,
                               21,	39,	38,	14,	25,	44,	26,	51,	11,	18,
                               7,	66,	16,	50,	49,	56,	8,	37,	12,	34,
                               24,	40,	53,	57,	60,	61,	4,	15,	62,	17,
                               47,	67,	13,	35,	64,	46,	29 };

    int permutacionIInvertida2[] ={46,	4,	64,	16,	56,	20,	17,	52,	6,
                                   14,	43,	35,	32,	31,	55,	8,	9,	33,
                                   11,	47,	54,	41,	29,	27,	24,	66,	37,
                                   67,	61,	48,	15,	42,	30,	13,	12,	57,
                                   22,	19,	18,	38,	53,	51,	49,	25,	21,
                                   1,	34,	2,	23,	40,	62,	5,	44,	10,
                                   50,	3,	26,	60,	39,	45,	65,	36,	58,
                                   7,	63,	59,	28  };

    I -> sketches = (unsigned int*)malloc( sizeof ( unsigned int ) * 2);
    if (k > 32)
        I -> sketchesPart2 = (unsigned int*)malloc(sizeof(unsigned int) * 2);

    if ((k > 64))
        I -> sketchesPart3 = (unsigned int*)malloc(sizeof(unsigned int) * 2);


    int dimension = 0;
    int i = 0;
    int posicion = 0;


    I->sketches[0] = 0;
    if (k > 32)
        I->sketchesPart2[0] = 0;
    if (k > 64)
        I->sketchesPart3[0] = 0;

    I->sketches[1] = 0;
    if (k > 32)
        I->sketchesPart2[1] = 0;
    if (k > 64)
        I->sketchesPart3[1] = 0;

    printf("\n m=%d \n", m);

    int sum = 0;
    for( dimension = 0; dimension < k; dimension++){

        if( permutacionIInvertida[dimension] <= m ){
            //bit = 1;
            sum++;
            if (dimension < 32) {
                I -> sketches[0] ^= (-1 ^ I -> sketches[0]) & (1 << dimension);
            }

            if ((dimension >= 32) && (dimension < 64)) {
                posicion = dimension - 32;
                I -> sketchesPart2[0] ^= (-1 ^ I -> sketchesPart2[0]) & (1 << posicion);
            }

            if ((dimension >= 64) && (dimension < 96)) {
                posicion = dimension - 64;
                I -> sketchesPart3[0] ^= (-1 ^ I -> sketchesPart3[0]) & (1 << posicion);
            }

        }
    }

    printf("\n sum = %d\n", sum);
    sum = 0;

    for( dimension = 0; dimension < k; dimension++){

        if( permutacionIInvertida2[dimension] <= m ){
            //bit = 1;
            sum++;
            if (dimension < 32) {
                I -> sketches[1] ^= (-1 ^ I -> sketches[1]) & (1 << dimension);
            }

            if ((dimension >= 32) && (dimension < 64)) {
                posicion = dimension - 32;
                I -> sketchesPart2[1] ^= (-1 ^ I -> sketchesPart2[1]) & (1 << posicion);
            }

            if ((dimension >= 64) && (dimension < 96)) {
                posicion = dimension - 64;
                I -> sketchesPart3[1] ^= (-1 ^ I -> sketchesPart3[1]) & (1 << posicion);
            }

            if ((dimension >= 96) && (dimension < 128)) {
                posicion = dimension - 96;
                I -> sketchesPart4[1] ^= (-1 ^ I -> sketchesPart4[1]) & (1 << posicion);
            }
        }
    }

    printf("\n sum = %d\n", sum);

    int dist = 0;

    dist = hamming( I->sketches[0], I -> sketches[1]);
    printf("\n\tLadistancia del ejemplo es de : %d\n", dist);

    if( k > 32 )
        dist = dist + hamming( I->sketchesPart2[0] , I-> sketchesPart2[1]);

    printf("\n\tLadistancia del ejemplo es de : %d\n", dist);

    if( k > 64 )
        dist = dist + hamming( I->sketchesPart3[0] , I -> sketchesPart3[1]);

    printf("\n\tLadistancia del ejemplo es de : %d\n", dist);

    free(I);
    dist = 0;
    scanf("%d",&dist);

}

CONSULTAREAL* kNNTiempo(SBEP2* S, int k, int porcentaje,Obj q, SKETCHQ* sQ){

    CONSULTA* distanciaHamming = NULL;

    CONSULTAREAL* distanciaRealAprox = NULL;

    int kPorcentaje;
    int i;
    int dist;

    distanciaHamming = ( CONSULTA* ) malloc( sizeof(CONSULTA) * S -> np);

    for( i = 0 ;i < S -> np; i++){
        dist = hamming( sQ->sketches , S -> sketches[i]);//el que se calcula por defecto

        if( S ->  k > 32 )
            dist = dist + hamming( sQ->sketchesPart2 , S -> sketchesPart2[i]);

        if( S ->  k > 64 )
            dist = dist + hamming( sQ->sketchesPart3 , S -> sketchesPart3[i]);

        if( S ->  k > 96 )
            dist = dist + hamming( sQ->sketchesPart4 , S -> sketchesPart4[i]);

        if( S ->  k > 128 )
            dist = dist + hamming( sQ->sketchesPart5 , S -> sketchesPart5[i]);

        if( S ->  k > 160 )
            dist = dist + hamming( sQ->sketchesPart6 , S -> sketchesPart6[i]);

        if( S ->  k > 192 )
            dist = dist + hamming( sQ->sketchesPart7 , S -> sketchesPart7[i]);

        if( S ->  k > 224 )
            dist = dist + hamming( sQ->sketchesPart8 , S -> sketchesPart8[i]);

        if( S -> k > 256 )
            dist = dist + hamming( sQ->sketchesPart9 , S -> sketchesPart9[i]);

        if( S -> k > 288 )
            dist = dist + hamming( sQ->sketchesPart10 , S -> sketchesPart10[i]);

        if (S -> k > 320)
            dist = dist + hamming( sQ->sketchesPart11 , S -> sketchesPart11[i]);

        if (S -> k > 352)
            dist = dist + hamming( sQ->sketchesPart12 , S -> sketchesPart12[i]);

        if (S -> k > 384)
            dist = dist + hamming( sQ->sketchesPart13 , S -> sketchesPart13[i]);
        if (S -> k > 416)
            dist = dist + hamming( sQ->sketchesPart14 , S -> sketchesPart14[i]);
        if (S->k > 448)
            dist = dist + hamming( sQ->sketchesPart15 , S -> sketchesPart15[i]);
        if (S->k > 480)
            dist = dist + hamming( sQ->sketchesPart16 , S -> sketchesPart16[i]);
        if (S->k > 512)
            dist = dist + hamming( sQ->sketchesPart17 , S -> sketchesPart17[i]);
        if (S->k > 544)
            dist = dist + hamming( sQ->sketchesPart18 , S -> sketchesPart18[i]);
        if (S->k > 576)
            dist = dist + hamming( sQ->sketchesPart19 , S -> sketchesPart19[i]);
        if (S->k > 608)
            dist = dist + hamming( sQ->sketchesPart20 , S -> sketchesPart20[i]);
        if (S->k > 640)
            dist = dist + hamming( sQ->sketchesPart21 , S -> sketchesPart21[i]);
        if (S->k > 672)
            dist = dist + hamming( sQ->sketchesPart22 , S -> sketchesPart22[i]);
        if (S->k > 704)
            dist = dist + hamming( sQ->sketchesPart23 , S -> sketchesPart23[i]);
        if (S->k > 736)
            dist = dist + hamming( sQ->sketchesPart24 , S -> sketchesPart24[i]);
        if (S->k > 768)
            dist = dist + hamming( sQ->sketchesPart25 , S -> sketchesPart25[i]);
        if (S->k > 800)
            dist = dist + hamming( sQ->sketchesPart26 , S -> sketchesPart26[i]);
        if (S->k > 832)
            dist = dist + hamming( sQ->sketchesPart27 , S -> sketchesPart27[i]);
        if (S->k > 864)
            dist = dist + hamming( sQ->sketchesPart28 , S -> sketchesPart28[i]);
        if (S->k > 896)
            dist = dist + hamming( sQ->sketchesPart29 , S -> sketchesPart29[i]);
        if (S->k > 928)
            dist = dist + hamming( sQ->sketchesPart30 , S -> sketchesPart30[i]);
        if (S->k > 960)
            dist = dist + hamming( sQ->sketchesPart31 , S -> sketchesPart31[i]);
        if (S->k > 992)
            dist = dist + hamming( sQ->sketchesPart32 , S -> sketchesPart32[i]);
        if (S->k > 1024)
            dist = dist + hamming( sQ->sketchesPart33 , S -> sketchesPart33[i]);
        if (S->k > 1056)
            dist = dist + hamming( sQ->sketchesPart34 , S -> sketchesPart34[i]);
        if (S->k > 1088)
            dist = dist + hamming( sQ->sketchesPart35 , S -> sketchesPart35[i]);
        if (S->k > 1120)
            dist = dist + hamming( sQ->sketchesPart36 , S -> sketchesPart36[i]);
        if (S->k > 1152)
            dist = dist + hamming( sQ->sketchesPart37 , S -> sketchesPart37[i]);
        if (S->k > 1184)
            dist = dist + hamming( sQ->sketchesPart38 , S -> sketchesPart38[i]);
        if (S->k > 1216)
            dist = dist + hamming( sQ->sketchesPart39 , S -> sketchesPart39[i]);
        if (S->k > 1248)
            dist = dist + hamming( sQ->sketchesPart40 , S -> sketchesPart40[i]);
        if (S->k > 1280)
            dist = dist + hamming( sQ->sketchesPart41 , S -> sketchesPart41[i]);
        if (S->k > 1312)
            dist = dist + hamming( sQ->sketchesPart42 , S -> sketchesPart42[i]);
        if (S->k > 1344)
            dist = dist + hamming( sQ->sketchesPart43 , S -> sketchesPart43[i]);
        if (S->k > 1376)
            dist = dist + hamming( sQ->sketchesPart44 , S -> sketchesPart44[i]);
        if (S->k > 1408)
            dist = dist + hamming( sQ->sketchesPart45 , S -> sketchesPart45[i]);
        if (S->k > 1440)
            dist = dist + hamming( sQ->sketchesPart46 , S -> sketchesPart46[i]);
        if (S->k > 1472)
            dist = dist + hamming( sQ->sketchesPart47 , S -> sketchesPart47[i]);
        if (S->k > 1504)
            dist = dist + hamming( sQ->sketchesPart48 , S -> sketchesPart48[i]);
        if (S->k > 1536)
            dist = dist + hamming( sQ->sketchesPart49 , S -> sketchesPart49[i]);
        if (S->k > 1568)
            dist = dist + hamming( sQ->sketchesPart50 , S -> sketchesPart50[i]);
        if (S->k > 1600)
            dist = dist + hamming( sQ->sketchesPart51 , S -> sketchesPart51[i]);
        if (S->k > 1632)
            dist = dist + hamming( sQ->sketchesPart52 , S -> sketchesPart52[i]);
        if (S->k > 1664)
            dist = dist + hamming( sQ->sketchesPart53 , S -> sketchesPart53[i]);
        if (S->k > 1696)
            dist = dist + hamming( sQ->sketchesPart54 , S -> sketchesPart54[i]);
        if (S->k > 1728)
            dist = dist + hamming( sQ->sketchesPart55 , S -> sketchesPart55[i]);
        if (S->k > 1760)
            dist = dist + hamming( sQ->sketchesPart56 , S -> sketchesPart56[i]);
        if (S->k > 1792)
            dist = dist + hamming( sQ->sketchesPart57 , S -> sketchesPart57[i]);
        if (S->k > 1824)
            dist = dist + hamming( sQ->sketchesPart58 , S -> sketchesPart58[i]);
        if (S->k > 1856)
            dist = dist + hamming( sQ->sketchesPart59 , S -> sketchesPart59[i]);
        if (S->k > 1888)
            dist = dist + hamming( sQ->sketchesPart60 , S -> sketchesPart60[i]);
        if (S->k > 1920)
            dist = dist + hamming( sQ->sketchesPart61 , S -> sketchesPart61[i]);
        if (S->k > 1952)
            dist = dist + hamming( sQ->sketchesPart62 , S -> sketchesPart62[i]);
        if (S->k > 1984)
            dist = dist + hamming( sQ->sketchesPart63 , S -> sketchesPart63[i]);
        if (S->k > 2016)
            dist = dist + hamming( sQ->sketchesPart64 , S -> sketchesPart64[i]);
        if (S->k > 2048)
            dist = dist + hamming( sQ->sketchesPart65 , S -> sketchesPart65[i]);
        if (S->k > 2080)
            dist = dist + hamming( sQ->sketchesPart66 , S -> sketchesPart66[i]);

        distanciaHamming[i].distanciaQ = dist;
        distanciaHamming[i].o = i + 1;
    }

    qsort( distanciaHamming, S -> np, sizeof( CONSULTA ) , cmpfunc);

    kPorcentaje = porcentaje * (S -> np / 100);

    distanciaRealAprox = ( CONSULTAREAL* ) malloc( sizeof( CONSULTAREAL ) * kPorcentaje );
    workload(kPorcentaje, q, distanciaRealAprox, distanciaHamming);
    qsort( distanciaRealAprox, kPorcentaje, sizeof( CONSULTAREAL ) , cmpfuncFloat);

    //printf("Los resultados son:\n");
    //for(i=0; i < k; i++){
     //   printf("%d\n", distanciaRealAprox[i].o);
    //}

    //printf("\trecall : %f\n", recall);

    free(distanciaHamming);
    //
    return (distanciaRealAprox);
}

void pruebasVelocidad(SBEP2* I){

    SBEP2* S = (SBEP2*)I;

    int j;
    int i;
    int k = 2; //los k vecinos mas cercanos que quiero
    int nObjetosPrueba = 1000; //numero de veces que se va a repetir las pruebas
    int porcentaje[] = {1, 3, 5, 7, 10}; //porcentaje que se va a revisar de la base de datos
    int nPorcentaje = 5;
    int m = I->k /2;

    struct tms t1,t2;

    Obj* objetosConsulta;

    CONSULTAREAL* respuesta;

    objetosConsulta = (Obj*) malloc( sizeof (Obj) * nObjetosPrueba);
    generaConsultas(objetosConsulta, nObjetosPrueba, I -> np);

    SKETCHQ sQ;

    printf("\n\t INICIAN LAS PRUEBAS de velocidad\n");
    printf("\n\tK = %d\n", k);

    for(i = 0; i < nPorcentaje; i++){

        printf("Porcentaje [%d]\n", porcentaje[i]);

        times (&t1);
        for(j = 0; j < nObjetosPrueba; j++){
            generaSketch(&sQ, objetosConsulta[j] , I -> p, I->k, m); //se genera el sketch de la consulta
            respuesta = kNNTiempo( S , k, porcentaje[i], objetosConsulta[j], &sQ);
        }
        times (&t2);
        printf ("Promedio tiempo user: %0.2f, system: %0.2f\n",
                ((t2.tms_utime-t1.tms_utime)/60.0) / nObjetosPrueba,
                ((t2.tms_stime-t1.tms_stime)/60.0)) / nObjetosPrueba;

    }

}

void saveIndex (Index S, char *fname) {
    FILE *f = fopen(fname,"w+");
    SBEP2 *I = (SBEP2*)S;

    fclose (f);
}

Index loadIndex (char *fname) {
    FILE *f = fopen(fname,"r");

    SBEP2 *I = malloc (sizeof(SBEP2));

    fclose (f);
    return (Index)I;
}