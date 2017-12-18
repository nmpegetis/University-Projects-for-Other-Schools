/**************************************************************************
Arxeio Ylopoihshs	: LISTTA.c -to sigkekrimeno apotelei to arxeio protipo 
Syggrafeas			: Nikolas Begetis
Skopos				: Ylopoihsh me deiktes, ATD Dipla Syndedemenh Lista 
Ana8ewrhsh			: D.Mhlios
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ListTA.h"

typedef struct info_nodeTA
{   int      size;	
	typos_deiktiTA     arxi; 	/*deikths sto proto komvo tis listas*/
} info_nodeTA;     /* o komvos plhroforias ths listas*/        


typedef struct typos_komvouTA
{   TStoixeioyListasTA dedomena;	
	typos_deiktiTA    epomenos; 	
	typos_deiktiTA    proigoumenos; 	
} typos_komvouTA;	   /*o typos toy kombou ths listas*/


void eisagogi_arxiTA(info_deiktiTA * const,TStoixeioyListasTA, int *);
void eisagogi_metaTA(info_deiktiTA *  const,TStoixeioyListasTA, typos_deiktiTA, int *);


info_deiktiTA LIST_dimiourgiaTA( )
{/*	Pro: 		kamia
  *	Meta: 		Dhmioyrgia kenhs syndedemenhs listas meso tis desmeusis kai arxikopoiisis tou  komvou
                linfo pou leitourgei os komvos pliroforias kai tha sindethei me ton proto komvo pou tha 
                eisaxthei */	
    info_deiktiTA linfo;
    linfo = malloc(sizeof(info_nodeTA));
    linfo->size = 0;
	linfo->arxi = NULL;
	return linfo;
}

void LIST_katastrofiTA(info_deiktiTA * linfo)
{/*	Pro: 	  Dhmioyrgia listas
  *	Meta: 	  Katastrofi ths listas kai apodesmeusi sto telos kai tou komvou linfo */   
     
	typos_deiktiTA todel,todel2;

	if(!LIST_keniTA(*linfo)){
		todel= ((*linfo)->arxi)->epomenos;
		while(todel!=(*linfo)->arxi)
		{   todel2=todel;
			todel=(todel)->epomenos;
			free(todel2);
		}
		free((*linfo)->arxi);
		(*linfo)->arxi = NULL;
	}
    free(*linfo);
    (*linfo)=NULL;
}

int LIST_keniTA(const info_deiktiTA  linfo)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		epistrefei 1 an h lista einai kenh, diaforetika 0 */
	return ( linfo->arxi == NULL );
}

void LIST_periexomenoTA(const info_deiktiTA  linfo, typos_deiktiTA p, TStoixeioyListasTA *val,int * error)
{/*	Pro: 		O deikths p deixnei ena kombo sth lista
  *	Meta:		epistrefei ta dedomena ston kombo pou deixnei o p */  
     *error=0;
     if(p!=NULL)
	   TSlist_setValueTA(val, p->dedomena);
	 else
       *error=1;    
}

void LIST_allagiTA(info_deiktiTA * const linfo,typos_deiktiTA * const p, TStoixeioyListasTA stoixeio,int * const error)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		Allazei ta dedomena ston komvo pou deixnei o p */    
	int found,error2;
    *error=0;
	TStoixeioyListasTA st;
	
	printf("allagi_1\n");
	if((*p)!=NULL)
    {  LIST_periexomenoTA(*linfo,*p, &st,&error2);
	printf("allagi_2\n");
	   LIST_anazitisiTA(*linfo, st, p, &found);
       if(found) 
       {  if((*p)!=NULL)
           { LIST_epomenosTA(*linfo, p, &error2);
	printf("allagi_3\n");
             LIST_periexomenoTA(*linfo,*p, &st,&error2);
             }
          else
             LIST_firstTA(*linfo, p, &error2);     
          LIST_diagrafiTA(linfo, p, error);
          if(!(*error))
           { LIST_eisagogiTA(linfo, stoixeio,*p, &error2);
             LIST_anazitisiTA(*linfo, stoixeio, p, &found);
	printf("allagi_4\n");
             if((*p)!=NULL)
             { LIST_epomenosTA(*linfo, p, &error2);
               LIST_periexomenoTA(*linfo,*p, &st,&error2);
	printf("allagi_5\n");
             }
             else
              LIST_firstTA(*linfo, p, &error2);
           }
        }
       else
          *error=1;    
     }  
	else
       *error=1;
}

void LIST_diadromiTA(const info_deiktiTA  linfo, int * const error)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		Grafei stin eksodo ola ta stoixeia tis listas */    
       
    typos_deiktiTA temp;
	temp=(linfo)->arxi;
	*error=0;
	
	if(LIST_keniTA(linfo))
	{   *error=1;
		return;
	}
	
	TSlist_writeValue(stdout,temp->dedomena);
	temp=temp->epomenos;
	while(temp!=linfo->arxi)
	{   
		TSlist_writeValue(stdout,temp->dedomena);
		temp=temp->epomenos;
	}
}

void LIST_eisagogiTA(info_deiktiTA * const linfo, TStoixeioyListasTA stoixeio,
					typos_deiktiTA prodeiktis, int *error)
{/*	Pro: 		Dhmiourgia listas
  * Meta: 		Eisagetai to "stoixeio" meta ton "prodeikti",an einai null autos to stoixeio mpainei
                stin arxi tis listas allios mpainei meta apo ton komvo pou deixnei autos */     
	*error=0;
	if(prodeiktis==NULL)
		eisagogi_arxiTA(linfo, stoixeio, error);
	else
		eisagogi_metaTA(linfo,stoixeio,prodeiktis, error);		 
}

void eisagogi_arxiTA(info_deiktiTA *  const linfo,TStoixeioyListasTA stoixeio, int *error)
{/*	Pro: 		Dhmiourgia listas
  *	Meta: 		O kombos me ta dedomena stoixeio exei eisax8ei sthn arxh ths listas */
  
	typos_deiktiTA prosorinos,temp; /*Deixnei ton neo kombo pou prokeitai na eisax8ei*/

	prosorinos = malloc(sizeof(typos_komvouTA));
	if ( prosorinos == NULL )
	{   *error=1;
		return;
	}
	TSlist_setValueTA(&prosorinos->dedomena, stoixeio);
	if(LIST_keniTA(*linfo)){
	    prosorinos->epomenos = (*linfo)->arxi;
		prosorinos->proigoumenos = (*linfo)->arxi;	
	    (*linfo)->arxi = prosorinos;
		(*linfo)->arxi->epomenos = prosorinos;
		(*linfo)->arxi->proigoumenos = prosorinos;
		printf("eis_arxi1\n");	
	}
	else{
		LIST_lastTA(*linfo, &temp, error);
	    prosorinos->epomenos = (*linfo)->arxi;
		temp->epomenos = prosorinos;
    	prosorinos->proigoumenos=temp;
		printf("eis_arxi2\n");	
    	if ((*linfo)->arxi != NULL){
		printf("eis_arxi3\n");	
       		(*linfo)->arxi->proigoumenos = prosorinos;
       	}
	    (*linfo)->arxi = prosorinos;
    }
    (*linfo)->size ++;
}

void eisagogi_metaTA(info_deiktiTA *  const linfo,TStoixeioyListasTA stoixeio,
					typos_deiktiTA prodeiktis, int *error)
{ /* Pro: 		Dhmioyrgia listas
   * Meta: 		O kombos me ta dedomena stoixeio eisagetai
   *			meta ton kombo pou deixnei o prodeikths*/
   
	typos_deiktiTA prosorinos; /*Deixnei ton neo kombo pou prokeitai na eisax8ei*/

	prosorinos = malloc(sizeof(typos_komvouTA));
	if ( prosorinos == NULL )
	{   *error = 1;
		return;
	}
	else
	{   TSlist_setValueTA(&(prosorinos->dedomena), stoixeio);
		prosorinos->epomenos = prodeiktis->epomenos;
		prosorinos->proigoumenos = prodeiktis;
		if(prosorinos->epomenos!=NULL)
			prosorinos->epomenos->proigoumenos = prosorinos;
		prodeiktis->epomenos = prosorinos;
		(*linfo)->size ++;
	}
}

void LIST_diagrafiTA(info_deiktiTA * const linfo, typos_deiktiTA *deiktis, int * const error)
{/*	Pro: 		Dhmiourgia Listas
  *	Meta: 		Diagrafetai to stoixeio ths listas pou deixnei o "deiktis" */    
     
    typos_deiktiTA prosorinos,previous;
	*error=0;

	if (LIST_keniTA(*linfo)|| (*deiktis==NULL))
	  {	*error=1;
	    return;
     }
	if((*linfo)->arxi==*deiktis)  //an einai o protos kombos tis listas
	{   prosorinos=*deiktis;
	    *deiktis=prosorinos->epomenos;
		(*linfo)->arxi=*deiktis;
        if((*deiktis)!=NULL)	/* no need anymore of this check */
          (*deiktis)->proigoumenos=(*linfo)->arxi->proigoumenos;  		
          // (*deiktis)->proigoumenos=NULL;  		
	}	
	else        //se kathe alli periptosi
	{  prosorinos=*deiktis;  
       previous=prosorinos->proigoumenos; 
       *deiktis=prosorinos->epomenos;  
       previous->epomenos=prosorinos->epomenos;
	   if((*deiktis)!=NULL)
	      (*deiktis)->proigoumenos = previous;
	}
	free(prosorinos);
    prosorinos = NULL;
	(*linfo)->size--;
}

void LIST_epomenosTA( info_deiktiTA  const linfo, typos_deiktiTA * const p, int * const error)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		Epistrefei ton epomeno komvo tou "p" kai sto error 0,an o p einai null tote epistrefei 
                sto error 2 allios an den iparxei epomenos epistrefei sto error 1 */         
	*error = 0;
	printf("epomenos1\n");
	if((*p)!=NULL)
	 { if((*p)->epomenos!=NULL) 
		 *p=(*p)->epomenos;
       else
         *error=1; 
	printf("epomenos2\n");
      }  
	else{

	   *error=2; 
			printf("epomenos3\n");

	}
}

void LIST_proigoymenosTA(const info_deiktiTA linfo, typos_deiktiTA * const p, int * const error)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		Epistrefei ton prohgoumeno komvo tou "p" kai sto error 0,an o p einai null tote epistrefei 
                sto error 2 allios an o p einai o protos komvos tis listas epistrefei sto error 1 */     
	*error = 0;
	if  ((*p)!=NULL)             /* lista oxi adeia */
	{   if ((*p)==(linfo->arxi)->epomenos)			/* p deixnei ston deutero kombo */
   	  		*p=linfo->arxi;
		else if(*p==linfo->arxi){					/* p deixnei ston proto kombo */
			*p=linfo->arxi->proigoumenos;			
		//	*error=1; 				/* not important any more */
		}
		else                       /* se kathe alli periptosi */
			*p=(*p)->proigoumenos;
	 }
	else 
        *error=2;   
}

void LIST_firstTA(info_deiktiTA  const linfo, typos_deiktiTA * const first, int * const error)
{ /*Pro: 		Dhmiourgia Listas
   *Meta:		Epistrefei ton  proto komvo ths listas diaforetika epistrefei 1 sto error */     
    *error=0;
	*first=linfo->arxi;
	if(LIST_keniTA(linfo))          
		*error=1;
}

void LIST_lastTA(info_deiktiTA  const linfo, typos_deiktiTA * const last, int * const error)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		Epistrefei ton  teleutaio komvo ths listas diaforetika 1 sto error an einai kenh auti */     
     
	typos_deiktiTA prosorinos;
	*error = 0;
	*last=NULL;
	if(LIST_keniTA(linfo))           
		*error=1;                 
	else                       
	{   prosorinos=linfo->arxi;
	    while (prosorinos->epomenos != linfo->arxi)
			prosorinos=prosorinos->epomenos;
		*last=prosorinos;
	}
}

void LIST_anazitisiTA(info_deiktiTA  const linfo, TStoixeioyListasTA stoixeio,
					typos_deiktiTA *prodeiktis, int *vrethike)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		Anazhta an yparxei sthn lista to stoixeio,an yparxei to vrethike ginetai 1 */      
	TStoixeioyListasTA temp;
	typos_deiktiTA trexon;
	int error,anazitisi;

	error=0;
	trexon = linfo->arxi;
	LIST_lastTA(linfo, prodeiktis, &error);
	*vrethike = 0;
		error=0;
		anazitisi = 0;
	if(!LIST_keniTA(linfo))
	 {	do
		{   LIST_periexomenoTA(linfo,trexon,&temp,&error);
			if (TSlist_megalyteroTA(temp, stoixeio) || TSlist_isoTA(temp, stoixeio))
			{   anazitisi=1;
				*vrethike=TSlist_isoTA(temp, stoixeio); //gia elegxo an vrethike ontos to stoixeio
			 }
			else
			{   *prodeiktis = trexon;
				LIST_epomenosTA(linfo, &trexon, &error);
			 }
		}
		while ( (!anazitisi) && (trexon!=linfo->arxi));
      }
}
