/*****************************************************
Arxeio ylopoihshs	: TStoixeioyListasE.c
Syggrafeas			: Nikolas Begetis
Skopos				: Ylopoihsh Typou Stoixeioy listas gia TSstoixeioyListas struct
*****************************************************/

#include "TStoixeioyListasE.h"


int TSlist_iso (TStoixeioyListasE Elem1, TStoixeioyListasE Elem2)
{   if(strcmp(Elem1.string,Elem2.string)==0)
      return 1;
   else
      return 0; 
}

int TSlist_mikrotero(TStoixeioyListasE Elem1, TStoixeioyListasE Elem2)
{
    if(strcmp(Elem1.string,Elem2.string)<0)
       return 1;
    else
       return 0;
}

int TSlist_megalytero(TStoixeioyListasE Elem1, TStoixeioyListasE Elem2)
{
    if(strcmp(Elem1.string,Elem2.string)>0)
       return 1;
    else
       return 0;
}

void TSlist_setValue (TStoixeioyListasE *target, TStoixeioyListasE source)
{    
    target->integer=source.integer;
    strncpy(target->string,source.string, CPLITHOS);
}

int TSlist_readValue (FILE *from, TStoixeioyListasE * Elem)
{    int fd;
     fd=fscanf(from,"%s",Elem->string); 
     Elem->integer=NULL;
     if(fd==1)
      return 1;
     else
      return 0;  
}

int TSlist_writeValue (FILE *to, TStoixeioyListasE Elem)
{   int fd;
	fd=fprintf(to, "%s-- ", Elem.string);
	return fd;
}

