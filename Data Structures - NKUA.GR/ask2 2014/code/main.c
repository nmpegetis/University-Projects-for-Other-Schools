/*************************************************
Arxeio ylopoihshs	: main.c
Syggrafeas			: Nikolas Begetis
Skopos				: Paradeigma gia Dokimh ATD List
**************************************************/

#include <stdio.h>
#include "ListE.h"
#include "TStoixeioyListasE.h"
#include "ListTA.h"
#include "TStoixeioyListasTA.h" /*edo analoga tin efarmogi i to test 
 tou tipou stoixeiou mpainei to antoistixo .h tou tipou stoixeiou */


void print_options(void);
void mainTA(TStoixeioyListasE*);
void print_optionsTA(void);

int main(void)
{   int option, error, found,out_err;
	info_deikti list;
	typos_deikti  cur;
  typos_deikti  cur1,cur2;
	TStoixeioyListasE x;
	error=found=0;
	list=NULL;
	cur=NULL;

	printf("Arxikh timh dromea: NULL!\n");
	do{ print_options();
		scanf("%d", &option);
		switch(option)
	   {case 1:
		    list=LIST_dimiourgia();
	        printf("\nH lista dimiourgithike!\n");
			break;
		case 2:
            if(list==NULL)
            {  printf("\nDen uparxei lista  gia na elexthei an einai kenh !\n");  
               break;          
             }
            if(LIST_keni(list))
	           printf("\nH lista einai kenh!\n");
		    else
	           printf("\nH lista DEN einai kenh!\n");
            break;
		case 3:
            if(list==NULL)
             { printf("\nDen uparxei lista  gia na eisaxthei stoixeio!\n");   
               break;          
              }
            printf("\nDwse ena stoixeio gia eisagwgh meta th 8esh dromea: ");
            out_err=TSlist_readValue(stdin,&x);
            if(!out_err)
            {  printf("\n error stin readValue !\n"); 
               break;                
             }
            LIST_eisagogi(&list, x, cur, &error);
            if(error)
               printf("\nError! Adynamia desmeyshs mnhmhs(malloc)!\n");
            else
	           printf("\nTo stoixeio eishx8h!\n");
          
            LIST_first(list, &cur1, &error);
            LIST_last(list, &cur2, &error);
            if(cur1 == cur2){
              printf("main3\n");
              LIST_first(list, &cur, &error);
            }
            break;
		case 4:
            if(list==NULL)
             { printf("\nDen uparxei lista  gia na paei o kersoras stin proti thesi tis !\n");   
               break;          
              }               
	        LIST_first(list, &cur, &error);
            if(error)
               printf("\nError! O deikths einai NULL 'h h lista einai kenh!\n");
            else
               printf("\nO dromeas deixnei ston prwto kombo ths listas!\n");
            break;
		case 5:
            if(list==NULL)
             { printf("\nDen uparxei lista  gia na paei o kersoras stin teleutaia thesi tis !\n");   
               break;          
             }
            LIST_last(list, &cur, &error);
            if(error)
	           printf("\nError! O deikths einai NULL 'h h lista einai kenh!\n");
            else
	           printf("\nO dromeas deixnei ston teleytaio kombo ths listas!\n");
            break;
		case 6:
            if(list==NULL)
             { printf("\nDen uparxei lista  gia na paei o kersoras stin epomeni thesi tis !\n");     
               break;          
             }
             if(cur==NULL){
                printf("main6\n");
             }
            if(cur!=NULL){
                printf("main6_2\n");
             }
            LIST_epomenos(list, &cur, &error);
            if(error==1)
	           printf("\n O deikths  paramenei ston trexonta/den iparxei epomenos !\n");
            else if (error==2)
	           printf("\nError o deikths einai null!\n");
            else
         	   printf("\nO dromeas metakinh8hke ston epomeno kombo!\n"); 	
            break;
		case 7:
            if(list==NULL)
             { printf("\nDen uparxei lista  gia na paei o kersoras stin proigoumeni thesi tis !\n");     
               break;          
             }
            LIST_proigoymenos(list, &cur, &error);
            if(error==1)
	           printf("\n O  deikths deixnei stin arxi tis listas/den iparxei proigoumenos!\n");
            else if (error==2)
	           printf("\nError o deikths einai null!\n");	
            else
	           printf("\nO dromeas metakinh8hke ston prohgoumeno kombo!\n");
            break;
		case 8:
            if(list==NULL)
             { printf("\nDen uparxei lista  gia na ektipothei to periexomeno tis thesi pou deixnei o kersoras !\n");     
               break;          
              }
            LIST_periexomeno(list,cur, &x,&error);
            if(error)
	           printf("\nError! O deikths einai NULL 'h h lista einai kenh!\n");
            else
	          { printf("\nH thesi periexei thn timh ");
				  out_err=TSlist_writeValue(stdout,x); 
                 if(out_err <0)
                 {  printf("\n error stin writeValue !\n");
                    break;                 
                  }
                }
            break;
		case 9:
            if(list==NULL)
             { printf("\nDen uparxei lista  gia na ektypothoun ta periexomena ths listas !\n");    
               break;          
             }
            printf("\nEktypwsh twn periexomenwn ths listas!\n");
            LIST_diadromi(list, &error);
            if(error)
	           printf("\nH lista einai kenh!\n");
            break;
		case 10:
            if(list==NULL)
            {  printf("\nDen uparxei lista  gia na allaxthei to periexomeno ths thesi pou deixnei o kersoras  !\n");     
               break;          
             }
            printf("\nDwse ena stoixeio gia allagh toy dedomenou ston komvo pou deixnei o dromeas: ");
            out_err=TSlist_readValue(stdin,&x);
            if(!out_err)
            {  printf("\n error stin readValue !\n"); 
               break;                
             }
            LIST_allagi(&list,&cur, x,&error);
            if(error)
	          printf("\nError! O deikths einai NULL 'h h lista einai kenh!\n");
            else
              printf("\nH allagh egine!\n");
            break;
		case 11:
            if(list==NULL)
             { printf("\nDen uparxei lista  gia na anazithithei stoixeio ths  !\n");     
               break;          
              }
            printf("\nDwse ena stoixeio gia anazhthsh sth lista: ");
            out_err=TSlist_readValue(stdin,&x);
            if(!out_err)
            {  printf("\n error stin readValue !\n"); 
               break;                
             }
            LIST_anazitisi(list, x, &cur, &found);
            if(found)
	           printf("\nTo stoixeio bre8hke!\n");
            else
	           printf("\nTo stoixeio DEN bre8hke!\n");
            break;
		case 12:
            if(list==NULL)
             { printf("\nDen uparxei lista  gia na diagrafei stoixeio ths  !\n");       
               break;          
             }
            LIST_diagrafi(&list, &cur, &error);
            if(error)
	           printf("\nError! O deikths einai NULL 'h h lista einai kenh!\n");
            else
               printf("\nDiagrafhke o kombos pou edeixne o dromeas!\n");
            break;
		case 13:
            if(list==NULL)
             { printf("\nDen uparxei lista  gia na katastrafei  !\n");     
               break;          
             }
            LIST_katastrofi(&list);
            list=NULL;
            printf("\nH lista katastrafike!\n");
            break;
    case 14:
      LIST_periexomeno(list,cur, &x,&error);
      mainTA(&x);
      LIST_allagi(&list, &cur, x,&error);
break;
	   }
	 }
	while(option);
	return 0;
}


void mainTA(  TStoixeioyListasE *x)
{   
  // Dilwseis ap eksw gia na ginoun mono mia fora stin klisis tou arxeiou
int optionTA, errorTA, foundTA,out_errTA;
  typos_deiktiTA  curTA, tempfirstTA,templastTA;
  info_deiktiTA listTA;
  TStoixeioyListasTA xTA;

  errorTA=foundTA=0;

  listTA=x->integer;
  curTA=NULL;

  do{ print_optionsTA();
    scanf("%d", &optionTA);
    switch(optionTA)
     {case 1:
            listTA=LIST_dimiourgiaTA();   
            printf("\n********\tH eswteriki lista dimiourgithike!\n"); 
      break;
    case 2:
            if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na elexthei an einai kenh !\n");  
               break;          
              }
            if(LIST_keniTA(listTA))
               printf("\n********\tH eswteriki lista einai kenh!\n");
        else
               printf("\n********\tH eswteriki lista DEN einai kenh!\n");
            break;
    case 3:
            if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na eisaxthei stoixeio!\n");   
               break;          
             }
            printf("\n********\tDwse ena stoixeio gia eisagwgh meta th 8esh dromea: ");
            out_errTA=TSlist_readValueTA(stdin,&xTA);
            if(!out_errTA)
             { printf("\n********\t errorTA stin readValue !\n"); 
               break;                
              }
            LIST_eisagogiTA(&listTA, xTA, curTA, &errorTA);
            if(errorTA)
             printf("\n********\tError! Adynamia desmeyshs mnhmhs(malloc)!\n");
            else{
              LIST_firstTA(listTA, &tempfirstTA, &errorTA);
              LIST_lastTA(listTA, &templastTA, &errorTA);
              if(tempfirstTA == templastTA){
                LIST_firstTA(listTA, &curTA, &errorTA);
              }
             printf("\n********\tTo stoixeio eishx8h!\n");
            }
            break;
    case 4:
            if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na paei o kersoras stin proti thesi tis !\n");   
               break;          
             }
            LIST_firstTA(listTA, &curTA, &errorTA);
            if(errorTA)
             printf("\n********\tError! O deikths einai NULL 'h h eswteriki lista einai kenh!\n");
            else
             printf("\n********\tO dromeas deixnei ston prwto kombo ths eswterikis listas!\n");
            break;
    case 5:
            if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na paei o kersoras stin teleutaia thesi tis !\n");   
               break;          
             }
            LIST_lastTA(listTA, &curTA, &errorTA);
            if(errorTA)
               printf("\n********\tError! O deikths einai NULL 'h h eswteriki lista einai kenh!\n");
            else
             printf("\n********\tO dromeas deixnei ston teleytaio kombo ths eswterikis listas!\n");
            break;
    case 6:
            if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na paei o kersoras stin epomeni thesi tis !\n");     
               break;          
              }
            LIST_epomenosTA(listTA, &curTA, &errorTA);
            if(errorTA==1)
             printf("\n O deikths  paramenei ston trexonta/den iparxei epomenos !\n");
            else if (errorTA==2)
             printf("\nError o deikths einai null!\n");
            else
               printf("\nO dromeas metakinh8hke ston epomeno kombo!\n");  
            break;
    case 7:
            if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na paei o kersoras stin proigoumeni thesi tis !\n");     
               break;          
             }
            LIST_proigoymenosTA(listTA, &curTA, &errorTA);
            if(errorTA==1)
             printf("\n********\t O  deikths deixnei stin arxi tis eswterikis listas/den iparxei proigoumenos!\n");
            else if (errorTA==2)
             printf("\n********\tError o deikths einai null!\n"); 
            else
               printf("\n********\tO dromeas metakinh8hke ston prohgoumeno kombo!\n");
            break;  
    case 8:
            if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na ektipothei to periexomeno tis thesi pou deixnei o kersoras !\n");     
               break;          
              }
              if(curTA==NULL){
                LIST_firstTA(listTA, &curTA, &errorTA);
              }
            LIST_periexomenoTA(listTA,curTA, &xTA,&errorTA);
            if(errorTA)
               printf("\n********\tError! O deikths einai NULL 'h h eswteriki lista einai kenh!\n");
            else
               { printf("\n********\tH thesi periexei thn timh ");
          out_errTA=TSlist_writeValueTA(stdout,xTA); 
                 if(out_errTA <0)
                 {  printf("\n********\t errorTA stin writeValue !\n");
                    break;                 
                  }
                 }
            break;
    case 9:
            if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na ektypothoun ta periexomena ths eswterikis listas !\n");    
               break;          
             }
            printf("\n********\tEktypwsh twn periexomenwn ths eswterikis listas!\n");
            LIST_diadromiTA(listTA, &errorTA);
            if(errorTA)
             printf("\n********\tH eswteriki lista einai kenh!\n");
            break;
    case 10:
            if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na allaxthei to periexomeno ths thesi pou deixnei o kersoras !\n");     
               break;          
             }
            printf("\n********\tDwse ena stoixeio gia allagh toy dedomenou ston komvo pou deixnei o dromeas: ");
            out_errTA=TSlist_readValueTA(stdin,&xTA);
            if(!out_errTA)
             { printf("\n********\t errorTA stin readValue !\n"); 
               break;                
              }
            LIST_allagiTA(&listTA, &curTA, xTA,&errorTA);
            if(errorTA)
              printf("\n********\tError! O deikths einai NULL 'h h eswteriki lista einai kenh!\n");
            else
            printf("\n********\tH allagh egine!\n");
            break;
    case 11:
             if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na anazithithei stoixeio ths  !\n");     
               break;          
             }
             printf("\n********\tDwse ena stoixeio gia anazhthsh sth eswteriki lista: ");
             out_errTA=TSlist_readValueTA(stdin,&xTA);
             if(!out_errTA)
             { printf("\n********\t errorTA stin readValue !\n"); 
               break;                
              }
             LIST_anazitisiTA(listTA, xTA, &curTA, &foundTA);
             if(foundTA)
            printf("\n********\tTo stoixeio bre8hke!\n");
             else
             printf("\n********\tTo stoixeio DEN bre8hke!\n");
             break;
    case 12:
             if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na diagrafei stoixeio ths  !\n");       
               break;          
              }
             LIST_diagrafiTA(&listTA, &curTA, &errorTA);
             if(errorTA)
             printf("\n********\tError! O deikths einai NULL 'h h eswteriki lista einai kenh!\n");
             else
             printf("\n********\tDiagrafhke o kombos pou edeixne o dromeas!\n");
             break;
    case 13:
             if(listTA==NULL)
             { printf("\n********\tDen uparxei eswteriki lista  gia na katastrafei  !\n");     
               break;          
             } 
             LIST_katastrofiTA(&listTA);
             listTA=NULL;
             printf("\n********\tH eswteriki lista katastrafike!\n");
             break;
    case 14:
       curTA=NULL;
       break; 
     }
   }
  while(optionTA);
    x->integer=listTA;
}

void print_options(void)
{  printf("\n\n1. Dhmioyrgia listas\n\
2. Elegxos gia kenh lista\n\
3. Eisagwgh stoixeioy sth lista\n\
4. Metakinhsh toy dromea ston prwto kombo ths listas\n\
5. Metakinhsh toy dromea ston teleytaio kombo ths listas\n\
6. Metakinhsh toy dromea ston epomeno kombo sth lista\n\
7. Metakinhsh toy dromea ston prohgoymeno kombo sth lista\n\
8. Epistrofh toy periexomenou toy komboy toy dromea\n\
9. Diadromh oloklhrhs ths listas kai ektypwsh twn dedomenwn twn kombwn\n\
10.Allagh toy periexomenoy toy komboy poy deixnei o dromeas\n\
11.Anazhthsh stoixeioy sth lista\n\
12.Diagrafh stoixeioy apo th lista\n\
13.Katastrofh ths listas\n\
14.Epeksergasia tis lista alirtmwn tou kombou tou dromea\n\
Dwste thn epilogh sas(1-14, 0 gia eksodo):");
}


void print_optionsTA(void)
{  printf("\n\n********\t1. Dhmioyrgia eswterikis listas\n\
********\t2. Elegxos gia kenh eswteriki lista\n\
********\t3. Eisagwgh stoixeioy sth eswteriki lista\n\
********\t4. Metakinhsh toy dromea ston prwto kombo ths eswterikis listas\n********\t\
5. Metakinhsh toy dromea ston teleytaio kombo ths eswterikis listas\n********\t\
6. Metakinhsh toy dromea ston epomeno kombo sth eswteriki lista\n********\t\
7. Metakinhsh toy dromea ston prohgoymeno kombo sth eswteriki lista\n********\t\
8. Epistrofh toy periexomenou toy komboy toy dromea\n********\t\
9. Diadromh oloklhrhs ths eswterikis listas kai ektypwsh twn dedomenwn twn kombwn\n********\t\
10.Allagh toy periexomenoy toy komboy poy deixnei o dromeas\n********\t\
11.Anazhthsh stoixeioy sth eswteriki lista\n********\t\
12.Diagrafh stoixeioy apo th eswteriki lista\n********\t\
13.Katastrofh ths eswterikis listas\n********\t\
14.Allagh dromea se NULL\n********\t\
Dwste thn epilogh sas(1-14, 0 gia eksodo):");
}
