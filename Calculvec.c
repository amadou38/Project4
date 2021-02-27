#include<stdio.h>
#include<stdlib.h>

	double *Calculvec(int choixvm, double *V[], int NV[])
{
	int choix1, choix2, i, j, maxv=0;
	double *TableauReel(int ig,int id);	
	double *T, alpha;
	void AfficherTableauReel(double *V[], int NV[]);
	AfficherTableauReel(V, NV);
	if(choixvm==1)
	{
			printf("Choisissez le premier vecteur ");
			scanf("%d", &choix1);
			printf("Choisissez le deuxieme vecteur ");
			scanf("%d", &choix2);
			if(NV[choix1]<NV[choix2]) maxv=NV[choix2];
			else maxv=NV[choix1];
			T=TableauReel(1,maxv);
			//printf("%d\n",NV[choix1]);
			for(j=1; j<=maxv; j++)
				T[j]= V[choix1][j]+V[choix2][j];
	}
	if(choixvm==2)
	{
		printf("Choisissez le vecteur ");
		scanf("%d", &choix1);
		printf("Entrez la valeur du scalaire: ");
		scanf("%lf", &alpha);
		maxv=NV[choix1];
		T=TableauReel(1,maxv);
		for(i=1; i<=NV[choix1]; i++)
			T[i]= alpha*V[choix1][i];
	}
	if(choixvm==3)
	{
		printf("Choisissez le premier vecteur ");
			scanf("%d", &choix1);
			printf("Choisissez le deuxieme vecteur ");
			scanf("%d", &choix2);
			if(NV[choix1]==NV[choix2])
			{
				maxv=NV[choix1];
				T=TableauReel(1,maxv);
			for(j=1; j<=maxv; j++)
				T[j]= V[choix1][j]*(V[choix2][j]);
			}
			else
			printf("Impossible car les tailles ne sont pas les memes\n");

	}
		printf("La solution est: \nVecteur global:\n");
			for(j=1; j<=maxv; j++)
				printf(" %2.0f\t", T[j]);
			printf("\n");
return T-0;
}
