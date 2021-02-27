#include <stdio.h>
#include <stdlib.h>

double *TableauReel(int ig,int id)
{
	double *T;
	T=(double*)malloc((id-ig+1)*sizeof(double));
	if(T==NULL){
		printf(" Tableau reel : pas assez de memoire \n");
		exit(-1);
	}
	return T-ig;
}

