#ifndef __Evr__
#define __Evr__

#include <stdlib.h>
#include <stdio.h>
#include "TSDDA.h"

#define Simple 0/* 0 for AVL - any other integer for Simple  */

#if (Simple)
   #include "BST/ch8_BSTpointer.h" /* gia Simple Ylopoihsh */
#else
   #include "AVL/ch8_AVLpointer.h" /* gia AVL Ylopoihsh */
#endif

typedef struct EvrNode *EvrPtr;

EvrPtr Evr_dimiourgia();
int Evr_katastrofi(EvrPtr *E);

int Evr_Insert(EvrPtr E, TStoixeiouDDA stoixeio);
int Evr_Find(EvrPtr E, TStoixeiouDDA stoixeio);
int Evr_PrintInOrder(EvrPtr E, FILE *out);
int Evr_PrintPreOrder(EvrPtr E, FILE *out);
int Evr_PrintPostOrder(EvrPtr E, FILE *out);

void metadiataksi(typos_deikti tree,FILE* out, int *error);
void episkepsi(typos_deikti tree,FILE* out);
void endodiataksi(typos_deikti tree,FILE* out, int *error); 
void prodiataksi(typos_deikti tree,FILE* out, int *error);

void AVLmetadiataksi(typos_deikti tree,FILE* out, int *error);
void AVLepiskepsi(typos_deikti tree,FILE* out);
void AVLendodiataksi(typos_deikti tree,FILE* out, int *error); 
void AVLprodiataksi(typos_deikti tree,FILE* out, int *error);

#endif
