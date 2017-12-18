/*****************************************************
Arxeio ylopoihshs	: TStoixeioyListasTA.c
Syggrafeas			: Nikolas Begetis
Skopos				: Ylopoihsh Typou Stoixeioy listas gia TSstoixeioyListas struct
*****************************************************/

#include "TStoixeioyListasTA.h"

int TSlist_isoTA (TStoixeioyListasTA  Elem1, TStoixeioyListasTA  Elem2)
{   if((Elem1.integer==Elem2.integer) &&(strcmp(Elem1.string,Elem2.string)==0))
      return 1;
   else
      return 0; 
}

int TSlist_mikroteroTA (TStoixeioyListasTA  Elem1, TStoixeioyListasTA  Elem2)
{
    if((Elem1.integer < Elem2.integer) || ((Elem1.integer==Elem2.integer) &&(strcmp(Elem1.string,Elem2.string)<0)))
       return 1;
    else
       return 0;
}

int TSlist_megalyteroTA (TStoixeioyListasTA  Elem1, TStoixeioyListasTA  Elem2)
{
    if((Elem1.integer > Elem2.integer) || ((Elem1.integer==Elem2.integer) &&(strcmp(Elem1.string,Elem2.string)>0)))
       return 1;
    else
       return 0;
}

void TSlist_setValueTA (TStoixeioyListasTA  *target, TStoixeioyListasTA  source)
{    target->integer=source.integer;
     strncpy(target->string,source.string, CPLITHOS);
}

int TSlist_readValueTA (FILE *from, TStoixeioyListasTA  * Elem)
{    int fd;
     fd=fscanf(from,"%d %s",&(Elem->integer),Elem->string);    
     if(fd==2)
      return 1;
     else
      return 0;  
}

int TSlist_writeValueTA(FILE *to, TStoixeioyListasTA  Elem)
{   int fd;
	fd=fprintf(to, "%d %s-- ", Elem.integer,Elem.string);
	return fd;
}

