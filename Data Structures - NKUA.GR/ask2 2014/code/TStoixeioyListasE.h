/*****************************************************
Arxeio epikefalidas	: TStoixeioyListasE.h
Syggrafeas			: Giota Konstantinou
Skopos				: Ylopoihsh Typou Stoixeioy listas gia TSstoixeioyListas struct
*****************************************************/

#ifndef __TSTOIXEIOYLISTASE_H__
#define __TSTOIXEIOYLISTASE_H__
#define CPLITHOS 15
#include <stdio.h>
#include <string.h>
#include "ListTA.h"
#include "TStoixeioyListasTA.h"

typedef struct 
{   info_deiktiTA integer;
	char string[CPLITHOS];
}  TStoixeioyListasE;

int TSlist_iso (TStoixeioyListasE Elem1, TStoixeioyListasE Elem2);
int TSlist_mikrotero (TStoixeioyListasE Elem1, TStoixeioyListasE Elem2);
int TSlist_megalytero (TStoixeioyListasE Elem1, TStoixeioyListasE Elem2);

void TSlist_setValue (TStoixeioyListasE *target, TStoixeioyListasE source);
int TSlist_readValue (FILE *from, TStoixeioyListasE * Elem);
int TSlist_writeValue (FILE *to, TStoixeioyListasE Elem);
#endif

