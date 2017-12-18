#include "Evretirio.h"


/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres - mporeite na xrhsimopoihsete 
   thn parapanv domh #if ... #else ...#endif gia na diaforopihsete tis dyo ylopoihseis  */

struct EvrNode{
	  typos_deikti TreeRoot;     /* Root of Tree */
	  int NTownsCities; /* the number of nodes in the tree */
} EvrNode;

int option, error, found,ypsilotero,out_err,created=0;
typos_deikti TreeRoot, cur=NULL;
TStoixeiouDDA x, x1;

EvrPtr evrNode;

EvrPtr Evr_dimiourgia(void){
	  /* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres - mporeite na xrhsimopoihsete 
   thn  domh #if ... #else ...#endif 
   
   See following example 
*/
//   	typos_deikti TreeRoot;
	#if (Simple)
   		printf("Call Dimiourgia simple\n");
   		Tree_dimiourgia(&TreeRoot);
	#else   
		printf("Call Dimiourgia AVL\n");
		AVLTree_dimiourgia(&TreeRoot);
	#endif

	evrNode=malloc(sizeof(EvrNode));
	evrNode->TreeRoot = TreeRoot;

	created=1;
	printf("\nTo dentro dimiourgithike!\n");

	return evrNode;
}



///mallon to treeroot prepei na to parw apo to evrptr


int Evr_Insert(EvrPtr E, TStoixeiouDDA stoixeio) {
	if(!created)
	{ 
		printf("\nDen uparxei dentro gia na eisaxthei stoixeio !\n");
		return -1;         
	}


	#if (Simple)
		printf("Call Insert simple\n");
		Tree_eisagogi(&(E->TreeRoot), stoixeio, &error);
	#else
		printf("Call Insert AVL\n");
		AVLTree_eisagogi(&(E->TreeRoot), stoixeio, &ypsilotero, &error);
	#endif
	if(error)
	 	printf("\nError! Adynamia malloc 'h to stoixeio yparxei hdh!\n");
	else
	 	printf("\nTo stoixeio eishx8h!\n");

	 return 0;
}

int Evr_Find(EvrPtr E, TStoixeiouDDA stoixeio){
	if(!created)
	{  
		printf("\nDen uparxei  dentro  gia na anazithithei stoixeio tou !\n");  
		return -1;
	}  

	#if (Simple)
		printf("Call Find simple\n");
		Tree_anazitisi(E->TreeRoot, stoixeio, &cur, &found);
	#else
		printf("Call Insert AVL\n");
		AVLTree_anazitisi(E->TreeRoot, stoixeio, &cur, &found);
	#endif		


	if(found)
		printf("\nTo stoixeio %s bre8hke!\n",stoixeio.key);
	else
//		printf("\nTo stoixeio %s DEN bre8hke!\n", stoixeio.key);

	return 0;
}

int Evr_PrintInOrder(EvrPtr E, FILE *out){
	if(!created)
	{   
		printf("\nDen uparxei  dentro gia na ginei endodiataksi !\n");  
		return -1;
	} 

	#if (Simple)
		printf("\nCall Endodiataksi simple\n");
		endodiataksi(E->TreeRoot,out,&error);
	#else   
		printf("\nCall Endodiataksi AVL\n");
		AVLendodiataksi(E->TreeRoot,out,&error);
	#endif

	return error;
}

int Evr_PrintPreOrder(EvrPtr E, FILE *out){
	if(!created)
	{   
		printf("\nDen uparxei  dentro gia na ginei endodiataksi !\n");  
		return -1;
	} 

	#if (Simple)
		printf("\nCall Prodiataksi simple\n");
		prodiataksi(E->TreeRoot,out,&error);
	#else   
		printf("\nCall Prodiataksi AVL\n");
		AVLprodiataksi(E->TreeRoot,out,&error);
	#endif

	return error;
}

int Evr_PrintPostOrder(EvrPtr E, FILE *out){
	if(!created)
	{   
		printf("\nDen uparxei  dentro gia na ginei endodiataksi !\n");  
		return -1;
	} 

	#if (Simple)
		printf("\nCall Metadiataksi simple\n");
		metadiataksi(E->TreeRoot,out,&error);
	#else   
		printf("\nCall Metadiataksi AVL\n");
		AVLmetadiataksi(E->TreeRoot,out,&error);
	#endif


	return error;
}


int Evr_katastrofi(EvrPtr *E){
	if(!created)
	{ 
		printf("\nDen uparxei AVL dentro gia na katastrafei !\n");  
		return -1;
	}

	#if (Simple)
		printf("Call Katastrofi simple\n");
		Tree_katastrofi(&((*E)->TreeRoot));
	#else   
		printf("Call Katastrofi AVL\n");
		AVLTree_katastrofi(&((*E)->TreeRoot));
	#endif  

	created=0;		// epanafora tou created wste na min thewreite dimiourgimeno
	printf("\nTo dentro katastrafike!\n");

	return 0;
}


void episkepsi(typos_deikti tree,FILE* out){
	#if (Simple) 
		TStoixeiouDDA x;
		Tree_periexomeno(tree, &x);
		
		out_err=TSDDA_writeValue(out,x);
		
		if(out_err <0)
		{
			printf("\n error stin writeValue !\n");
		}
	#endif
}

void endodiataksi(typos_deikti tree,FILE* out, int *error){ 
	#if (Simple)
		typos_deikti paidi;
		error=0;
		if(!Tree_keno(tree)){   
			paidi =Tree_apaidi(tree);
			endodiataksi(paidi,out,error);
			episkepsi(tree,out);
			paidi = Tree_dpaidi(tree);
			endodiataksi(paidi,out,error);
		}
	#endif
}

void prodiataksi(typos_deikti tree,FILE* out, int *error){
	#if (Simple)
		typos_deikti paidi;
		error=0;
		if(!Tree_keno(tree)){
		   	episkepsi(tree,out);
			paidi = Tree_apaidi(tree);
	        prodiataksi(paidi,out,error);
			paidi = Tree_dpaidi(tree);
			prodiataksi(paidi,out,error);
		}
	#endif
}

void metadiataksi(typos_deikti tree,FILE* out, int *error){
	#if (Simple)
		typos_deikti paidi;
		error=0;
		if(!Tree_keno(tree)){
		    paidi = Tree_apaidi(tree);
	        metadiataksi(paidi,out,error);
			paidi = Tree_dpaidi(tree);
			metadiataksi(paidi,out,error);
			episkepsi(tree,out);
		}
	#endif
}


void AVLepiskepsi(typos_deikti tree,FILE* out){ 
	#if (!Simple)
		TStoixeiouDDA x;
		AVLTree_periexomeno(tree, &x);

		out_err=TSDDA_writeValue(out,x);

		if(out_err <0)
		{
			printf("\n error stin writeValue !\n");
		}
	#endif
}

void AVLendodiataksi(typos_deikti tree,FILE* out, int *error){ 
	#if (!Simple)
		typos_deikti paidi;
		error=0;
		if(!AVLTree_keno(tree)){   
			paidi = AVLTree_apaidi(tree);
			AVLendodiataksi(paidi,out,error);
			AVLepiskepsi(tree,out);
			paidi = AVLTree_dpaidi(tree);
			AVLendodiataksi(paidi,out,error);
		}

	#endif
}

void AVLprodiataksi(typos_deikti tree,FILE* out, int *error){
	#if (!Simple)
		typos_deikti paidi;
		error=0;
		if(!AVLTree_keno(tree)){
		   	AVLepiskepsi(tree,out);
			paidi = AVLTree_apaidi(tree);
	        AVLprodiataksi(paidi,out,error);
			paidi = AVLTree_dpaidi(tree);
			AVLprodiataksi(paidi,out,error);
		}
	#endif
}

void AVLmetadiataksi(typos_deikti tree,FILE* out, int *error){
	#if (!Simple)
		typos_deikti paidi;
		error=0;
		if(!AVLTree_keno(tree)){
		    paidi = AVLTree_apaidi(tree);
	        AVLmetadiataksi(paidi,out,error);
			paidi = AVLTree_dpaidi(tree);
			AVLmetadiataksi(paidi,out,error);
			AVLepiskepsi(tree,out);
		}
	#endif
}
