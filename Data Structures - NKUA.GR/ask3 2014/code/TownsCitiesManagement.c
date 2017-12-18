/************************************************************************
Programma pelaths	: TownsCitiesManagement.c
Syggrafeas			: 
Skopos				: skeleton main for askhsh 3
*************************************************************************/
#include <stdio.h>
#include <sys/time.h>                /* for gettimeofday() */
#include <stdlib.h>
#include <string.h>

#include "Evretirio.h"
#include "TSDDA.h"

int ProcessData(EvrPtr X, FILE *Input, FILE *Search, FILE *InOrder, FILE *PreOrder, FILE *PostOrder, FILE *Time);

int main(int argc, char *argv[])
{
 	EvrPtr Ordered, Random;
	FILE *OrderedInput, *Search, *InOrderO, *PreOrderO, *PostOrderO, *TimesO,
		 *RandomInput, *InOrderR, *PreOrderR, *PostOrderR, *TimesR;
  
	int error;	// to dilwnoume ksana kai stin processData sunartisi, tha mporousame na to kanoume kai mia fora san global eksw apo ti main.


	// Ordered=malloc(sizeof(EvrPtr));
	// Random=malloc(sizeof(EvrPtr));

	OrderedInput = fopen (argv[1], "r");
	if (OrderedInput == NULL) {
		perror ("Error opening OrderedInput file");
		return -1;
	}


	RandomInput = fopen (argv[2], "r");
	if (RandomInput == NULL) {
		perror ("Error opening OrderedInput file");
		return -1;
	}

   	Search = fopen (argv[3], "r");
   	if (Search == NULL) {
    		perror ("Error opening Search file");
    		return -1;
   	}

   	InOrderO = fopen (argv[4], "w");
   	if (InOrderO == NULL) {
    		perror ("Error opening InOrderO file");
    		return -1;
   	}

   	PreOrderO = fopen (argv[5], "w");
   	if (PreOrderO == NULL) {
    		perror ("Error opening PreOrderO file");
    		return -1;
   	}

   	PostOrderO = fopen (argv[6], "w");
   	if (PostOrderO == NULL) {
    		perror ("Error opening PostOrderO file");
    		return -1;
   	}


   	TimesO = fopen (argv[7], "w");
   	if (TimesO == NULL) {
    		perror ("Error opening TimesO file");
    		return -1;
   	}

   	InOrderR = fopen (argv[8], "w");
   	if (InOrderR == NULL) {
    		perror ("Error opening InOrderR file");
    		return -1;
   	}

   	PreOrderR = fopen (argv[9], "w");
   	if (PreOrderR == NULL) {
    		perror ("Error opening PreOrderR file");
    		return -1;
   	}

   	PostOrderR = fopen (argv[10], "w");
   	if (PostOrderR == NULL) {
    		perror ("Error opening PostOrderR file");
    		return -1;
   	}


   	TimesR = fopen (argv[11], "w");
   	if (TimesR == NULL) {
    		perror ("Error opening TimesR file");
    		return -1;
   	}


  	Ordered = Evr_dimiourgia();
  	ProcessData(Ordered, OrderedInput, Search, InOrderO, PreOrderO, PostOrderO, TimesO);
  	error = Evr_katastrofi(&Ordered);
	if (error == -1){
		printf("\nDen egine swsta i katastrofi sto dentrou !\n");  
	}

   	Search = fopen (argv[3], "r"); 	// read again the Search file
   	if (Search == NULL) {
    		perror ("Error opening Search file");
    		return -1;
   	}

  	Random = Evr_dimiourgia();
  	ProcessData(Random, RandomInput, Search, InOrderR,  PreOrderR, PostOrderR, TimesR);
  	error = Evr_katastrofi(&Random);
	if (error == -1){
		printf("\nDen egine swsta i katastrofi sto dentrou !\n");  
	}
  
  	// getchar();	
  	return 0;
}
  
int ProcessData(EvrPtr X, 			/* ADT for Evretirio */
			FILE *Input, 		/* Input File for constructing Tree*/
			FILE *Search,		/* Input File for searching Tree */
			FILE *InOrder, 		/* Output File for inorder traversal */
			FILE *PreOrder, 	/* Output File for preorder traversal */
			FILE *PostOrder,	/* Output File for postorder traversal */
			FILE *Times			/* Output File for Times */
){

/*
	 For each line of File Input
	   Read town or city and Insert it into Tree
	   (measure time intervals for insertions)
*/

	TStoixeiouDDA stoixeio;
   	char mystring [100];
   	int error,out_err,counter=1;
    struct timeval t1, t2;
    double elapsedTime,summedTime=0.0,meanTime=0.0;



    /* start timer */
    gettimeofday(&t1, NULL);

	while (!feof(Input)){
		out_err=TSDDA_readValue(Input,&stoixeio);
		if(out_err == 0)
		{  
			printf("\n error stin readValue i teleutaia grammi EOF !\n"); 
		}

		if (out_err != 0){ 	// if it is the last empty line of the file 
			error = Evr_Insert(X, stoixeio);
			if (error == -1){
				printf("\nDen egine swsta i dimiourgia tou dentrou !\n");  
			}
			if (counter==512 || counter==1024 || counter==2048){
			    /* stop timer */
			    gettimeofday(&t2, NULL);

			    /* compute and print the elapsed time in millisec */
			    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
			    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
			    fprintf(Times,"elapsedTime after %d cities in Input=%g msec\n", counter, elapsedTime);			
			}
			counter++;
		}
// uncomment to see printings	of Elements	
/*		out_err=TSDDA_writeValue(stdout,stoixeio); 
		if(out_err <0)
		{
			printf("\n error stin writeValue !\n");
			break;                 
		}
*/
	}
	fclose (Input);

    /* stop timer */
    gettimeofday(&t2, NULL);

    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    fprintf(Times,"total elapsedTime in Input=%g msec\n", elapsedTime);

/*       
	 For each Line of File Search
	   Read town or city and Find it
	   (measure time for all searches and find average)
Resolution in Milli-Seconds. NOT THOUROUGHLY TESTED 
*/

    counter = 0;		// reinitialization of counter to count the cities search
	while (!feof(Search)){
	    /* start timer */
	    gettimeofday(&t1, NULL);	//now each time we count a new time beginning 

		out_err=TSDDA_readValue(Search,&stoixeio);
		if(!out_err)
		{  
			printf("\n error stin readValue i telos arxeio EOF!\n"); 
		}
		else{
			error = Evr_Find(X, stoixeio);
			if (error == -1){
				printf("\nDen egine swsta i anazitisi sto dentrou !\n");  
			}

		    /* stop timer */
		    gettimeofday(&t2, NULL);

		    /* compute and print the elapsed time in millisec */
		    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
		    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms

		    /* sum all times together to find the mean value in the end */
		    summedTime += elapsedTime;
			counter++;
		}
// uncomment to see printings	of Elements	
/*		out_err=TSDDA_writeValue(stdout,stoixeio); 
		if(out_err <0)
		{
			printf("\n error stin writeValue !\n");
			break;                 
		}
*/
	}
	fclose (Search);


	meanTime = summedTime/(float)counter;
    fprintf(Times,"mean elapsedTime in Search=%g msec\n", elapsedTime);

/*   			
-->	Traverse Tree Inorder output in File Inorder, measuring Time
	Traverse Tree Preorder output in File Preorder, measuring Time
	Traverse Tree Postorder output in File Postorder, measuring Time
	
	Print Times in File Times
*/

    /* start timer */
    gettimeofday(&t1, NULL);

	error = Evr_PrintInOrder(X, InOrder);
	if (error == -1){
		printf("\nDen egine swsta i endodiataksi sto dentrou !\n");  
	}


    /* stop timer */
    gettimeofday(&t2, NULL);

    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    fprintf(Times,"elapsedTime in InOrder=%g msec\n", elapsedTime);
	fclose (InOrder);

/*   			
	Traverse Tree Inorder output in File Inorder, measuring Time
-->	Traverse Tree Preorder output in File Preorder, measuring Time
	Traverse Tree Postorder output in File Postorder, measuring Time
	
	Print Times in File Times
*/

    /* start timer */
    gettimeofday(&t1, NULL);

	error = Evr_PrintPreOrder(X, PreOrder);
	if (error == -1){
		printf("\nDen egine swsta i prodiataksi sto dentrou !\n");  
	}


    /* stop timer */
    gettimeofday(&t2, NULL);

    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    fprintf(Times,"elapsedTime in PreOrder=%g msec\n", elapsedTime);
	fclose (PreOrder);

/*   			
	Traverse Tree Inorder output in File Inorder, measuring Time
	Traverse Tree Preorder output in File Preorder, measuring Time
-->	Traverse Tree Postorder output in File Postorder, measuring Time
	
	Print Times in File Times
*/

    /* start timer */
    gettimeofday(&t1, NULL);

	error = Evr_PrintPostOrder(X, PostOrder);
	if (error == -1){
		printf("\nDen egine swsta i metadiataksi sto dentrou !\n");  
	}


    /* stop timer */
    gettimeofday(&t2, NULL);

    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    fprintf(Times,"elapsedTime in PostOrder=%g msec\n", elapsedTime);
	fclose (PostOrder);

	fclose (Times);	//now that we have filled 'Times' file too, we can close it!

  return 0;
}


