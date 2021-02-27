#include<stdio.h>
#include<stdlib.h>
 
 double **MatriceReelle( int lg, int ld, int cg, int cd)
{    
	double *TableauReel( int ig, int id);
		int i;
  	double **A;
  	A=(double **)malloc((ld-lg+1)*sizeof(double*));
	if(A==NULL)
{ 
		printf("Matrice reelle: pas assez de memoire!!!\n");
 		exit(-1);
 }
		A-=lg;
	for(i=lg; i<=ld; i++)
		A[i]=TableauReel(cg, cd);
 	return A;
}
