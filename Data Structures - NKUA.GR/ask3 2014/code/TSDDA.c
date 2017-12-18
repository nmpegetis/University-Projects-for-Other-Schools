#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "TSDDA.h"
#define SIZE 256	// maximum size per line

int TSDDA_setValue (TStoixeiouDDA *target, TStoixeiouDDA source){
	target->key = malloc(SIZE*sizeof(char));
	target->country = malloc(SIZE*sizeof(char));

	strncpy(target->key,source.key,SIZE);
	strncpy(target->country,source.country,SIZE);
}

int TSDDA_readValue (FILE *from,  TStoixeiouDDA *Elem){
	char* fd;
	char* string = malloc(SIZE*sizeof(char));	
	char* string2 = malloc(SIZE*sizeof(char));	
	char* tokens;
	char* delimiter = "%";

	// initialization
	Elem->key = NULL;
	Elem->country = NULL;

	fd=fgets(string,SIZE,from);	// read all the line and put it in the string

	if(fd!=NULL){	
		tokens = strtok(string,delimiter);
		if (tokens != NULL){
			Elem->key = tokens;
	//		puts(Elem->key);
		}

		tokens = strtok(NULL,delimiter);
		if (tokens != NULL){
			Elem->country = tokens;
		}
		return 1;
	}
	else{
		return 0;
	}
}

int TSDDA_writeValue(FILE *to, TStoixeiouDDA Elem){
 	int fd;

	fd=fprintf(to, "Key: %s Country: %s -- ", Elem.key,Elem.country);
	return fd;
}


int TSDDA_iso(TStoixeiouDDA s1, TStoixeiouDDA s2){
	if((strcmp(s1.key,s2.key)==0) && (strcmp(s1.country,s2.country)==0))
	  	return 1;
	else
	  	return 0;
}

int TSDDA_mikrotero(TStoixeiouDDA s1, TStoixeiouDDA s2){
	if((strcmp(s1.key,s2.key)<0) || ((strcmp(s1.key,s2.key)==0) && (strcmp(s1.country,s2.country)<0)))
		return 1;
	else
		return 0;       
}

int TSDDA_megalytero(TStoixeiouDDA s1, TStoixeiouDDA s2){
	if((strcmp(s1.key,s2.key)>0) || ((strcmp(s1.key,s2.key)==0) && (strcmp(s1.country,s2.country)>0)))
		return 1;
	else
		return 0;       
}


/* The Following are already Implemented using Above */

int TSDDA_mikrotero_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{ 
    return TSDDA_mikrotero(s1,s2)||TSDDA_iso(s1,s2);
}

int TSDDA_megalytero_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
    return TSDDA_megalytero(s1,s2)||TSDDA_iso(s1,s2);
}

int TSDDA_diaforo(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
    return !TSDDA_iso(s1,s2);
}
