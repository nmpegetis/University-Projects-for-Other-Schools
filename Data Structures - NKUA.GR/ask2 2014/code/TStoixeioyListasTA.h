/*****************************************************
Arxeio epikefalidas	: TStoixeioyListasTA.h
Syggrafeas			: Nikolas Begetis
Skopos				: Ylopoihsh Typou Stoixeioy listas gia TSstoixeioyListasTA struct
*****************************************************/

#ifndef __TStoixeioyListas_TA_H__
#define __TStoixeioyListas_TA_H__
#define CPLITHOS 15
#include <stdio.h>
#include <string.h>

typedef struct 
{   int integer;
	char string[CPLITHOS];
}  TStoixeioyListasTA;

int TSlist_isoTA(TStoixeioyListasTA Elem1, TStoixeioyListasTA Elem2);
int TSlist_mikroteroTA(TStoixeioyListasTA Elem1, TStoixeioyListasTA Elem2);
int TSlist_megalyteroTA(TStoixeioyListasTA Elem1, TStoixeioyListasTA Elem2);

void TSlist_setValueTA (TStoixeioyListasTA *target, TStoixeioyListasTA source);
int TSlist_readValueTA (FILE *from, TStoixeioyListasTA * Elem);
int TSlist_writeValueTA (FILE *to, TStoixeioyListasTA Elem);
#endif
