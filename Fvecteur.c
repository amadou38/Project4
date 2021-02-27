#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double *RemplirVect(FILE *pfichier, int *NV)
{
	 double *V;
double *TableauReel(int ig,int id);

int i;
char car='1';
	if(pfichier==NULL) 
	{
  		printf("\nOuverture du fichier impossible");
  		exit(-1);
	}
	
	
	fscanf(pfichier,"%d",NV);
  	while(car!='\n')
	{
		fscanf(pfichier,"%c",&car);
//	printf("%c",car);
	}
//	printf(":%d\n",*NV);
	V=TableauReel(1,*NV);
	fscanf(pfichier,"%lf",&V[1]);
	car='1';
	while(car!='\n')
	{
		car=fgetc(pfichier);
//	printf("%c",car);
	}
//	printf("%2.0f\t",V[1]);
	for(i=2;i<=*NV;i++)
	{
 		fscanf(pfichier,"%lf",&V[i]);
//		printf("%2.0f\t",V[i]);
	}
//printf("\n\n");
	
	return V-0;
}
