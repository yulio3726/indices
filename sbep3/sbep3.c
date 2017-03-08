//
// Created by cesar on 3/3/17.
//

#include "sbep3.h"
#include "implementaciones.h"

Index build (char *dbname, int n, int *argc, char ***argv){

    if(*argc < 1){
        fprintf(stderr, "Usage_ <args> ARITY\n");
        exit(1);
    }

    int i = 0;
    int u = 0;
    int j = 0;
    int posicion = 0;
    int bit = 0;
    int m = 0;
    //int longBloque = 64;
    int longSketch = 0 ;

    ARRAYTEMPORAL* permutacionI;
    int* permutacionIInvertida;

    SBEP3* I;
    I = (SBEP3* )malloc( sizeof( SBEP3 ) );

    I -> descr = (char*)malloc(strlen (dbname) + 1);
    strcpy(I -> descr, dbname);

    I -> n = openDB( I -> descr);
    if (n && (n < I -> n)) I -> n = n;

    I -> b = atoi( ( *argv[0] ) ); (*argc)--; (*argv)++;
    I->longBloque = 64;

    longSketch = I->b * I->longBloque;

    I -> tablaPermutantes = (Obj **) malloc( sizeof( Obj*) * I->b); //filas
    for(i = 0; i < I->n; i++){ //columnas
        I -> tablaPermutantes[i] = (Obj *) malloc( sizeof(Obj) * I->longBloque); //columnas
    }

    srand( time( NULL ) );
    for(i = 0; i < I->b;i++){
        seleccionaPivotesAleatorio(I -> tablaPermutantes[i], I->longBloque, I -> n);
    }

    //showPivots(I->tablaPermutantes, I->b, I->longBloque);

    i = 1;
    I -> sketches = (unsigned int*)malloc( sizeof ( unsigned int ) * I -> n);
    I -> sketchesPart2 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    i++;

    if (I->b >= i){ //2
        I -> sketchesPart3 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart4 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //3
        I -> sketchesPart5 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart6 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;


    if (I->b >= i){ //4
        I -> sketchesPart7 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart8 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //5
        I->sketchesPart9 = (unsigned int*) malloc(sizeof(unsigned int) * I->n);
        I->sketchesPart10 = (unsigned int*)malloc(sizeof(unsigned int) * I->n);
    }
    i++;

    if (I->b >= i){ //6
        I -> sketchesPart11 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart12 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;


    if (I->b >= i){ //7
        I -> sketchesPart13 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart14 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //8
        I -> sketchesPart15 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart16 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //9
        I -> sketchesPart17 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart18 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //10
        I -> sketchesPart19 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart20 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //11
        I -> sketchesPart21 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart22 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //12
        I -> sketchesPart23 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart24 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //13
        I -> sketchesPart25 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart26 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //14
        I -> sketchesPart27 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart28 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //15
        I -> sketchesPart29 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart30 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //16
        I -> sketchesPart31 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart32 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //17
        I -> sketchesPart33 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart34 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //18
        I -> sketchesPart35 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart36 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //19
        I -> sketchesPart37 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart38 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //20
        I -> sketchesPart39 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart40 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //21
        I -> sketchesPart41 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart42 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //22
        I -> sketchesPart43 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart44 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //23
        I -> sketchesPart45 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart46 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //24
        I -> sketchesPart47 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart48 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //25
        I -> sketchesPart49 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart50 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //26
        I -> sketchesPart51 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart52 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //27
        I -> sketchesPart53 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart54 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //28
        I -> sketchesPart55 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart56 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //29
        I -> sketchesPart57 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart58 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //30
        I -> sketchesPart59 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart60 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //31
        I -> sketchesPart61 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart62 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //32
        I -> sketchesPart63 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart64 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }
    i++;

    if (I->b >= i){ //33
        I -> sketchesPart65 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
        I -> sketchesPart66 = (unsigned int*)malloc(sizeof(unsigned int) * I -> n);
    }

    permutacionI  = (ARRAYTEMPORAL*)malloc(sizeof(ARRAYTEMPORAL)* I->longBloque);
    permutacionIInvertida = (int*)malloc(sizeof(int) * I->longBloque);

    int o = 0;
    int bitIni = 0;
    int bitFin = 0;

    m = I->longBloque / 2;

    while(o < I  -> n) { // 2

        o++;//objeto de la base de datos
        u = o;
        j = 1;

        I->sketches[u - 1] = 0;
        I->sketchesPart2[u - 1] = 0;
        j++;

        if (I->b >= j){//2
            I->sketchesPart3[u - 1] = 0;
            I->sketchesPart4[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//3
            I->sketchesPart5[u - 1] = 0;
            I->sketchesPart6[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//4
            I->sketchesPart7[u - 1] = 0;
            I->sketchesPart8[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//5
            I->sketchesPart9[u-1] = 0;
            I->sketchesPart10[u-1] = 0;
        }
        j++;

        if(I->b >= j){//6
            I->sketchesPart11[u - 1] = 0;
            I->sketchesPart12[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//7
            I->sketchesPart13[u - 1] = 0;
            I->sketchesPart14[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//8
            I->sketchesPart15[u - 1] = 0;
            I->sketchesPart16[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//9
            I->sketchesPart17[u - 1] = 0;
            I->sketchesPart18[u - 1] = 0;
        }
        j++;


        if(I->b >= j){//10
            I->sketchesPart19[u - 1] = 0;
            I->sketchesPart20[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//11
            I->sketchesPart21[u - 1] = 0;
            I->sketchesPart22[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//12
            I->sketchesPart23[u - 1] = 0;
            I->sketchesPart24[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//13
            I->sketchesPart25[u - 1] = 0;
            I->sketchesPart26[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//14
            I->sketchesPart27[u - 1] = 0;
            I->sketchesPart28[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//15
            I->sketchesPart29[u - 1] = 0;
            I->sketchesPart30[u - 1] = 0;
        }
        j++;


        if(I->b >= j){//16
            I->sketchesPart31[u - 1] = 0;
            I->sketchesPart32[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//17
            I->sketchesPart33[u - 1] = 0;
            I->sketchesPart34[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//18
            I->sketchesPart35[u - 1] = 0;
            I->sketchesPart36[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//19
            I->sketchesPart37[u - 1] = 0;
            I->sketchesPart38[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//20
            I->sketchesPart39[u - 1] = 0;
            I->sketchesPart40[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//21
            I->sketchesPart41[u - 1] = 0;
            I->sketchesPart42[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//22
            I->sketchesPart43[u - 1] = 0;
            I->sketchesPart44[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//23
            I->sketchesPart45[u - 1] = 0;
            I->sketchesPart46[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//24
            I->sketchesPart47[u - 1] = 0;
            I->sketchesPart48[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//25
            I->sketchesPart49[u - 1] = 0;
            I->sketchesPart50[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//26
            I->sketchesPart51[u - 1] = 0;
            I->sketchesPart52[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//27
            I->sketchesPart53[u - 1] = 0;
            I->sketchesPart54[u - 1] = 0;
        }
        j++;


        if(I->b >= j){//28
            I->sketchesPart55[u - 1] = 0;
            I->sketchesPart56[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//29
            I->sketchesPart57[u - 1] = 0;
            I->sketchesPart58[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//30
            I->sketchesPart59[u - 1] = 0;
            I->sketchesPart60[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//31
            I->sketchesPart61[u - 1] = 0;
            I->sketchesPart62[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//32
            I->sketchesPart63[u - 1] = 0;
            I->sketchesPart64[u - 1] = 0;
        }
        j++;

        if(I->b >= j){//33
            I->sketchesPart65[u - 1] = 0;
            I->sketchesPart66[u - 1] = 0;
        }

        //printf("\n*****************************************\n");
        for(j = 0; j < I->b; j++){
          //  printf("\nbloque %d\n", j + 1);

            calculaDistanciaOP(o, permutacionI, I->longBloque, I->tablaPermutantes[j]); //logBloque es el numero de pivotes
            qsort(permutacionI, I->longBloque, sizeof(ARRAYTEMPORAL), cmpFloat);
            guardaInversaI(permutacionI, permutacionIInvertida, I->longBloque);

            bitIni = j * I->longBloque;
            bitFin = bitIni + I->longBloque - 1;
            bit = bitIni;
            i = 0;

            while(bit <= bitFin){

                //bit = 0;
                if(permutacionIInvertida[i] < m){
                    //printf("1");
                    //bit = 1;
                    if (bit < 32) {
                        I->sketches[o - 1] ^= (-1 ^ I->sketches[o - 1]) & (1 << bit);
                    }

                    if ((bit >= 32) && (bit < 64)) {
                        posicion = bit - 32;
                        I -> sketchesPart2[o- 1] ^= (-1 ^ I -> sketchesPart2[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 64) && (bit < 96)) {
                        posicion = bit - 64;
                        I -> sketchesPart3[o- 1] ^= (-1 ^ I -> sketchesPart3[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 96) && (bit < 128)) {
                        posicion = bit - 96;
                        I -> sketchesPart4[o- 1] ^= (-1 ^ I -> sketchesPart4[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 128) && (bit < 160)) {
                        posicion = bit - 128;
                        I -> sketchesPart5[o- 1] ^= (-1 ^ I -> sketchesPart5[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 160) && (bit < 192)) {
                        posicion = bit - 160;
                        I -> sketchesPart6[o- 1] ^= (-1 ^ I -> sketchesPart6[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 192) && (bit < 224)) {
                        posicion = bit - 192;
                        I -> sketchesPart7[o- 1] ^= (-1 ^ I -> sketchesPart7[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 224) && (bit < 256)) {
                        posicion = bit - 224;
                        I -> sketchesPart8[o- 1] ^= (-1 ^ I -> sketchesPart8[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 224) && (bit < 256)) {
                        posicion = bit - 224;
                        I->sketchesPart8[o- 1] ^= (-1 ^ I->sketchesPart8[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 256) && (bit < 288)) {
                        posicion = bit - 256;
                        I->sketchesPart9[o- 1] ^= (-1 ^ I->sketchesPart9[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 288) && (bit < 320)) {
                        posicion = bit - 288;
                        I->sketchesPart10[o- 1] ^= (-1 ^ I->sketchesPart10[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 320) && (bit < 352)) {
                        posicion = bit - 320;
                        I -> sketchesPart11[o- 1] ^= (-1 ^ I -> sketchesPart11[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 352) && (bit < 384)) {
                        posicion = bit - 352;
                        I -> sketchesPart12[o- 1] ^= (-1 ^ I -> sketchesPart12[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 384) && (bit < 416)) {
                        posicion = bit - 384;
                        I -> sketchesPart13[o- 1] ^= (-1 ^ I -> sketchesPart13[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 416) && (bit < 448)) {
                        posicion = bit - 416;
                        I -> sketchesPart14[o- 1] ^= (-1 ^ I -> sketchesPart14[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 448) && (bit < 480)) {
                        posicion = bit - 448;
                        I -> sketchesPart15[o- 1] ^= (-1 ^ I -> sketchesPart15[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 480) && (bit < 512)) {
                        posicion = bit - 480;
                        I -> sketchesPart16[o- 1] ^= (-1 ^ I -> sketchesPart16[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 512) && (bit < 544)) {
                        posicion = bit - 512;
                        I -> sketchesPart17[o- 1] ^= (-1 ^ I -> sketchesPart17[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 544) && (bit < 576)) {
                        posicion = bit - 544;
                        I -> sketchesPart18[o- 1] ^= (-1 ^ I -> sketchesPart18[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 576) && (bit < 608)) {
                        posicion = bit - 576;
                        I -> sketchesPart19[o- 1] ^= (-1 ^ I -> sketchesPart19[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 608) && (bit < 640)) {
                        posicion = bit - 608;
                        I -> sketchesPart20[o- 1] ^= (-1 ^ I -> sketchesPart20[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 640) && (bit < 672)) {
                        posicion = bit - 640;
                        I -> sketchesPart21[o- 1] ^= (-1 ^ I -> sketchesPart21[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 672) && (bit < 704)) {
                        posicion = bit - 672;
                        I -> sketchesPart22[o- 1] ^= (-1 ^ I -> sketchesPart22[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 704) && (bit < 736)) {
                        posicion = bit - 704;
                        I -> sketchesPart23[o- 1] ^= (-1 ^ I -> sketchesPart23[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 736) && (bit < 768)) {
                        posicion = bit - 736;
                        I -> sketchesPart24[o- 1] ^= (-1 ^ I -> sketchesPart24[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 768) && (bit < 800)) {
                        posicion = bit - 768;
                        I -> sketchesPart25[o- 1] ^= (-1 ^ I -> sketchesPart25[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 800) && (bit < 832)) {
                        posicion = bit - 800;
                        I -> sketchesPart26[o- 1] ^= (-1 ^ I -> sketchesPart26[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 832) && (bit < 864)) {
                        posicion = bit - 832;
                        I -> sketchesPart27[o- 1] ^= (-1 ^ I -> sketchesPart27[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 864) && (bit < 896)) {
                        posicion = bit - 864;
                        I -> sketchesPart28[o- 1] ^= (-1 ^ I -> sketchesPart28[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 896) && (bit < 928)) {
                        posicion = bit - 896;
                        I -> sketchesPart29[o- 1] ^= (-1 ^ I -> sketchesPart29[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 928) && (bit < 960)) {
                        posicion = bit - 928;
                        I -> sketchesPart30[o- 1] ^= (-1 ^ I -> sketchesPart30[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 960) && (bit < 992)) {
                        posicion = bit - 960;
                        I -> sketchesPart31[o- 1] ^= (-1 ^ I -> sketchesPart31[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 992) && (bit < 1024)) {
                        posicion = bit - 992;
                        I -> sketchesPart32[o- 1] ^= (-1 ^ I -> sketchesPart32[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1024) && (bit < 1056)) {
                        posicion = bit - 1024;
                        I -> sketchesPart33[o- 1] ^= (-1 ^ I -> sketchesPart33[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1056) && (bit < 1088)) {
                        posicion = bit - 1056;
                        I -> sketchesPart34[o- 1] ^= (-1 ^ I -> sketchesPart34[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1088) && (bit < 1120)) {
                        posicion = bit - 1088;
                        I -> sketchesPart35[o- 1] ^= (-1 ^ I -> sketchesPart35[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1120) && (bit < 1152)) {
                        posicion = bit - 1120;
                        I -> sketchesPart36[o- 1] ^= (-1 ^ I -> sketchesPart36[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1152) && (bit < 1184)){
                        posicion = bit - 1152;
                        I -> sketchesPart37[o- 1] ^= (-1 ^ I -> sketchesPart37[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1184) && (bit < 1216)) {
                        posicion = bit - 1184;
                        I -> sketchesPart38[o- 1] ^= (-1 ^ I -> sketchesPart38[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1216) && (bit < 1248)) {
                        posicion = bit - 1216;
                        I -> sketchesPart39[o- 1] ^= (-1 ^ I -> sketchesPart39[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1248) && (bit < 1280)) {
                        posicion = bit - 1248;
                        I -> sketchesPart40[o- 1] ^= (-1 ^ I -> sketchesPart40[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1280) && (bit < 1312)) {
                        posicion = bit - 1280;
                        I -> sketchesPart41[o- 1] ^= (-1 ^ I -> sketchesPart41[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1312) && (bit < 1344)) {
                        posicion = bit - 1312;
                        I -> sketchesPart42[o- 1] ^= (-1 ^ I -> sketchesPart42[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1344) && (bit < 1376)) {
                        posicion = bit - 1344;
                        I -> sketchesPart43[o- 1] ^= (-1 ^ I -> sketchesPart43[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1376) && (bit < 1408)) {
                        posicion = bit - 1376;
                        I -> sketchesPart44[o- 1] ^= (-1 ^ I -> sketchesPart44[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1408) && (bit < 1440)) {
                        posicion = bit - 1408;
                        I -> sketchesPart45[o- 1] ^= (-1 ^ I -> sketchesPart45[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1440) && (bit < 1472)) {
                        posicion = bit - 1440;
                        I -> sketchesPart46[o- 1] ^= (-1 ^ I -> sketchesPart46[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1472) && (bit < 1504)) {
                        posicion = bit - 1472;
                        I -> sketchesPart47[o- 1] ^= (-1 ^ I -> sketchesPart47[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1504) && (bit < 1536)) {
                        posicion = bit - 1504;
                        I -> sketchesPart48[o- 1] ^= (-1 ^ I -> sketchesPart48[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1536) && (bit < 1568)) {
                        posicion = bit - 1536;
                        I -> sketchesPart49[o- 1] ^= (-1 ^ I -> sketchesPart49[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1568) && (bit < 1600)) {
                        posicion = bit - 1568;
                        I -> sketchesPart50[o- 1] ^= (-1 ^ I -> sketchesPart50[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1600) && (bit < 1632)) {
                        posicion = bit - 1600;
                        I -> sketchesPart51[o- 1] ^= (-1 ^ I -> sketchesPart51[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1632) && (bit < 1664)) {
                        posicion = bit - 1632;
                        I -> sketchesPart52[o- 1] ^= (-1 ^ I -> sketchesPart52[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1664) && (bit < 1696)) {
                        posicion = bit - 1664;
                        I -> sketchesPart53[o- 1] ^= (-1 ^ I -> sketchesPart53[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1696) && (bit < 1728)) {
                        posicion = bit - 1696;
                        I -> sketchesPart54[o- 1] ^= (-1 ^ I -> sketchesPart54[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1728) && (bit < 1760)) {
                        posicion = bit - 1728;
                        I -> sketchesPart55[o- 1] ^= (-1 ^ I -> sketchesPart55[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1760) && (bit < 1792)) {
                        posicion = bit - 1760;
                        I -> sketchesPart56[o- 1] ^= (-1 ^ I -> sketchesPart56[o- 1]) & (1 << posicion);

                    }

                    if ((bit >= 1792) && (bit < 1824)) {
                        posicion = bit - 1792;
                        I -> sketchesPart57[o- 1] ^= (-1 ^ I -> sketchesPart57[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1824) && (bit < 1856)) {
                        posicion = bit - 1824;
                        I -> sketchesPart58[o- 1] ^= (-1 ^ I -> sketchesPart58[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1856) && (bit < 1888)) {
                        posicion = bit - 1856;
                        I -> sketchesPart59[o- 1] ^= (-1 ^ I -> sketchesPart59[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1888) && (bit < 1920)) {
                        posicion = bit - 1888;
                        I -> sketchesPart60[o- 1] ^= (-1 ^ I -> sketchesPart60[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1920) && (bit < 1952)) {
                        posicion = bit - 1920;
                        I -> sketchesPart61[o- 1] ^= (-1 ^ I -> sketchesPart61[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1952) && (bit < 1984)) {
                        posicion = bit - 1952;
                        I -> sketchesPart62[o- 1] ^= (-1 ^ I -> sketchesPart62[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 1984) && (bit < 2016)) {
                        posicion = bit - 1984;
                        I -> sketchesPart63[o- 1] ^= (-1 ^ I -> sketchesPart63[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 2016) && (bit < 2048)) {
                        posicion = bit - 2016;
                        I -> sketchesPart64[o- 1] ^= (-1 ^ I -> sketchesPart64[o- 1]) & (1 << posicion);

                    }

                    if ((bit >= 2048) && (bit < 2080)) {
                        posicion = bit - 2048;
                        I -> sketchesPart65[o- 1] ^= (-1 ^ I -> sketchesPart65[o- 1]) & (1 << posicion);
                    }

                    if ((bit >= 2080) && (bit < 2112)) {
                        posicion = bit - 2080;
                        I -> sketchesPart66[o- 1] ^= (-1 ^ I -> sketchesPart66[o- 1]) & (1 << posicion);
                    }

                }else{
                   // printf("0");
                }

                i++;
                bit++;
            }

        }
    }

    //printf("\n la distancia entre las dos cadenas es : %d\n",
    // hamming(I->sketches[0], I->sketches[1]) + hamming(I->sketchesPart2[0], I->sketchesPart2[1]));



    free(permutacionI);
    free(permutacionIInvertida);

    return (Index) I;

}

void saveIndex (Index S, char *fname)
    {
        FILE *f = fopen(fname,"w+");
        SBEP3 *I = (SBEP3*)S;

        int i = 0;
        int j = 0;

        /*fwrite (I->descr,strlen(I->descr)+1,1,f); //el nombre de la base de datos

        fwrite (&I->n,sizeof(int),1,f); //tamaño de la base de datos

        fwrite(&I->b, sizeof(int), 1,f); //numero de bloques

        fwrite (&I->longBloque, sizeof(int),1,f); //longitud de cada bloque

        for(i=0; i < I->b; i++){ //tabla de permutaciones
            fwrite (I->tablaPermutantes[i], I->longBloque , sizeof(Obj),f);
        }*/

        //printf("El sketch en hexadecimal %x\n", I->sketches[0]);
        //printf("El sketch en decimal %d\n", I->sketches[0]);
        //printf("El sketch en unsigned %u\n", I->sketches[0]);
        //printf("El sketchPart2 en unsigned %u\n", I->sketchesPart2[0]);
        //printf("El sketch en entero %i\n", I->sketches[0]);
        //printf("El sketch en octonal %o\n", I->sketches[0]);

        for(i=0; i < I->n; i++){
            j = 1;

            fprintf(f,"%u%u ", I->sketches[i], I->sketchesPart2[i] );
            j++;

            if (I->b >= j)//2
                fprintf(f,"%u%u ", I->sketchesPart3[i], I->sketchesPart4[i] );
            j++;

            if (I->b >= j)//3
                fprintf(f,"%u%u ", I->sketchesPart5[i], I->sketchesPart6[i] );
            j++;

            if (I->b >= j)//4
                fprintf(f,"%u%u ", I->sketchesPart7[i], I->sketchesPart8[i] );
            j++;

            if(I->b >= j)//5
                fprintf(f,"%u%u ", I->sketchesPart9[i], I->sketchesPart10[i] );
            j++;

            if(I->b >= j)//6
                fprintf(f,"%u%u ", I->sketchesPart11[i], I->sketchesPart12[i] );
            j++;

            if(I->b >= j)//7
                fprintf(f,"%u%u ", I->sketchesPart13[i], I->sketchesPart14[i] );
            j++;

            if(I->b >= j)//8
            fprintf(f,"%u%u ", I->sketchesPart15[i], I->sketchesPart16[i] );
            j++;

            if(I->b >= j)//9
                fprintf(f,"%u%u ", I->sketchesPart17[i], I->sketchesPart18[i] );
            j++;

            if(I->b >= j)//10
                fprintf(f,"%u%u ", I->sketchesPart19[i], I->sketchesPart20[i] );
            j++;

            if(I->b >= j)//11
                fprintf(f,"%u%u ", I->sketchesPart21[i], I->sketchesPart22[i] );
            j++;

            if(I->b >= j)//12
                fprintf(f,"%u%u ", I->sketchesPart23[i], I->sketchesPart24[i] );
            j++;

            if(I->b >= j)//13
                fprintf(f,"%u%u ", I->sketchesPart25[i], I->sketchesPart26[i] );
            j++;

            if(I->b >= j)//14
                fprintf(f,"%u%u ", I->sketchesPart27[i], I->sketchesPart28[i] );
            j++;

            if(I->b >= j)//15
                fprintf(f,"%u%u ", I->sketchesPart29[i], I->sketchesPart30[i] );
            j++;

            if(I->b >= j)//16
                fprintf(f,"%u%u ", I->sketchesPart31[i], I->sketchesPart32[i] );
            j++;

            if(I->b >= j)//17
                fprintf(f,"%u%u ", I->sketchesPart33[i], I->sketchesPart34[i] );
            j++;

            if(I->b >= j)//18
                fprintf(f,"%u%u ", I->sketchesPart35[i], I->sketchesPart36[i] );
            j++;

            if(I->b >= j)//19
                fprintf(f,"%u%u ", I->sketchesPart37[i], I->sketchesPart38[i] );
            j++;

            if(I->b >= j)//20
                fprintf(f,"%u%u ", I->sketchesPart39[i], I->sketchesPart40[i] );
            j++;

            if(I->b >= j)//21
                fprintf(f,"%u%u ", I->sketchesPart41[i], I->sketchesPart42[i] );
            j++;

            if(I->b >= j)//22
                fprintf(f,"%u%u ", I->sketchesPart43[i], I->sketchesPart44[i] );
            j++;

            if(I->b >= j)//23
                fprintf(f,"%u%u ", I->sketchesPart45[i], I->sketchesPart46[i] );
            j++;

            if(I->b >= j)//24
                fprintf(f,"%u%u ", I->sketchesPart47[i], I->sketchesPart48[i] );
            j++;

            if(I->b >= j)//25
                fprintf(f,"%u%u ", I->sketchesPart49[i], I->sketchesPart50[i] );
            j++;

            if(I->b >= j)//26
                fprintf(f,"%u%u ", I->sketchesPart51[i], I->sketchesPart52[i] );
            j++;

            if(I->b >= j)//27
                fprintf(f,"%u%u ", I->sketchesPart53[i], I->sketchesPart54[i] );
            j++;

            if(I->b >= j)//28
                fprintf(f,"%u%u ", I->sketchesPart55[i], I->sketchesPart56[i] );
            j++;

            if(I->b >= j)//29
                fprintf(f,"%u%u ", I->sketchesPart57[i], I->sketchesPart58[i] );
            j++;

            if(I->b >= j)//30
                fprintf(f,"%u%u ", I->sketchesPart59[i], I->sketchesPart60[i] );
            j++;

            if(I->b >= j)//31
                fprintf(f,"%u%u ", I->sketchesPart61[i], I->sketchesPart62[i] );
            j++;

            if(I->b >= j)//32
                fprintf(f,"%u%u ", I->sketchesPart63[i], I->sketchesPart64[i] );
            j++;

            if(I->b >= j)//32
                fprintf(f,"%u%u ", I->sketchesPart65[i], I->sketchesPart66[i] );

            fprintf(f,"%i\n", i+1);
        }

        fclose (f);
}

Index loadIndex (char *fname) {

    char str[1024]; char *ptr = str;
    char str2[1024]; char *ptr2 = str2;
    char c;

    FILE *f = fopen(fname,"r");

    SBEP3 *I = malloc (sizeof(SBEP3));

    int i,k, m;

    /*while ((*ptr++ = getc(f)));
    I->descr = malloc (ptr-str);
    strcpy (I->descr,str);

    fread (&I->n,sizeof(int),1,f);
    //printf("I n %d\n", I->n);

    fread (&I->b,sizeof(int),1,f);
    //printf("I ->b %d\n", I->b);

    fread (&I->longBloque,sizeof(int),1,f);
    //printf("I longBloque %d\n", I->longBloque);

    I-> tablaPermutantes = (Obj **) malloc( sizeof( Obj*) * I->b); //filas
    for(i = 0; i < I->n; i++) { //columnas
        I->tablaPermutantes[i] = (Obj *) malloc(sizeof(Obj) * I->longBloque); //columnas
    }

    for(i = 0; i < I->b; i++){
        fread(I->tablaPermutantes[i], I->longBloque, sizeof(Obj),f);
        /*for(k = 0; k < I->longBloque; k++){
            printf("%d ", I->tablaPermutantes[i][k]);
        }
        printf("\n");
    }*/

    printf("leo indices\n");

    while (1){
        c = fgetc(f);
        if(feof(f)){
            printf("\nencontre fin de archivo\n");
            break;
        }
        printf("%c",c);
    }

    fclose (f);
    return (Index)I;
}