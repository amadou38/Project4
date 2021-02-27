#include<stdio.h>
#include<stdlib.h>
 
 void AfficherTableauReel(double *V[], int NV[])
{
 int i, j;
	printf("Nous avons:\n");
 for(i=1; i<=6; i++)
 {	printf("La taille du vecteur V%d: %d\n",i, NV[i]);
	printf("Les éléments du vecteur V%d sont:",i); 
	for(j=1; j<=NV[i]; j++)
		printf("\t%2.0f  ", V[i][j]);
		getchar();
	printf("\n"); 
  }
 }
