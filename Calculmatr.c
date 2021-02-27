#include<stdio.h>
#include<stdlib.h>

	double **Calculmatr(int choixvm, double **M[], int nl[], int nc[], double *V[], int NV[])
{
	int choix1, choix2, i, j, k, maxl=0, maxc=0, maxv=0, trouve1=0, trouve2=0;
	double **MatriceReelle( int lg, int ld, int cg, int cd);
	double *TableauReel(int ig,int id);	
	double **Mat, *T, trace, alpha;
	void AfficherMatriceReelle(double **M[], int nl[], int nc[]);
	AfficherMatriceReelle(M, nl, nc);
	void AfficherTableauReel(double *V[], int NV[]);
	void triangulaireinf(int choix1, int *trouve1, double **M[], int nl[], int nc[]);
	void triangulairesup(int choix1, int *trouve2, double **M[], int nl[], int nc[]);
	switch(choixvm)
		{
			case 1:
				printf("Choisissez la matrice: ");
				
				scanf("%d", &choix1);
				printf("Entrez le scalaire: ");
				scanf("%lf", &alpha);
				maxl=nl[choix1];
				maxc=nc[choix1];
				Mat=MatriceReelle(1,maxl, 1, maxc);
				for(i=1; i<=nl[choix1]; i++)
				for(j=1; j<=nc[choix1]; j++)
				Mat[i][j]= alpha*M[choix1][i][j];
				break;
			case 2:
				printf("Choisissez la premiere matrice: ");
				scanf("%d", &choix1);
				printf("Choisissez la deuxième matrice: ");
				scanf("%d", &choix2);
				if(nl[choix1]!=nl[choix2] || nl[choix1]!=nl[choix2])	printf("Addition matricielle impossible car les nombres de colonne sont differentes et egalement les nombres de ligne!!!\n");
				else
				maxl=nl[choix1];
				maxc=nc[choix2];
				Mat=MatriceReelle(1,maxl, 1, maxc);//Cij
				for(i=1; i<=maxl; i++)
					for(j=1; j<=maxc; j++)
				Mat[i][j]= M[choix1][i][j]+M[choix2][i][j];
				break;
			case 3:
				AfficherTableauReel(V, NV);
				printf("Choisissez la matrice: ");
				scanf("%d", &choix1);
				printf("Choisissez le vecteur: ");
				scanf("%d", &choix2);
				if(nc[choix1]!=NV[choix2])	printf("Produit matrice vecteur impossible car le nombre de colonne: %d de la matrice est differente de la taille du vecteur: %d !!!\n", nc[choix1], NV[choix2]);
				else
				{
					maxv=nl[choix1];
					T=TableauReel(1,maxv);
					for(i=1; i<=nl[choix1]; i++)
						for(j=1; j<=nc[choix2]; j++)
							T[i]+= M[choix1][i][j]*V[choix2][j];
				}
				break;
			case 4:
				printf("Choisissez la premiere matrice: ");
				scanf("%d", &choix1);
				printf("Choisissez la deuxième matrice: ");
				scanf("%d", &choix2);
				if(nc[choix1]!=nl[choix2])	printf("Produit matricielle impossible car le nombre de colonne: %d de la premiere matrice est differente du nombre de ligne: %d de la deuxieme matrice!!!\n", nc[choix1], nl[choix2]);
				else
				maxl=nl[choix1];
				maxc=nc[choix2];
				Mat=MatriceReelle(1,maxl, 1, maxc);//Cij
				for(i=1; i<=maxl; i++)
					for(j=1; j<=maxc; j++)
						for(k=1; k<=nc[choix1]; k++)
							Mat[i][j]+= M[choix1][i][k]*M[choix2][k][j];
				break;
			case 5:
				printf("Choisissez la matrice: ");
				scanf("%d", &choix1);
				maxl=nl[choix1];
				maxc=nc[choix1];
				Mat=MatriceReelle(1,maxl, 1, maxc);
				for(i=1; i<=maxc; i++)
					for(j=1; j<=maxl; j++)
						Mat[i][j]= M[choix1][j][i];
				break;
			case 6:
				printf("Choisissez la matrice: ");
				scanf("%d", &choix1);
				if(nl[choix1]!=nc[choix1])
					printf("Impossible de caluler la trace de cette matrice car elle n'est pas carrée: Mat %d  %d\n", nl[choix1], nc[choix1]);
				else
				{
					maxl=nl[choix1];
					maxc=nc[choix1];
					Mat=MatriceReelle(1,maxl, 1, maxc);
					for(i=1; i<=maxc; i++)
						trace+= M[choix1][i][i];
				printf("La trace est : %2.0f \n", trace);
				}
				break;
			/*case 7:
				printf("Choisissez la matrice: ");
				scanf("%d", &choix1);
				
				break;*/
			case 8:
				printf("Choisissez la matrice: ");
				scanf("%d", &choix1);
				triangulaireinf(choix1, &trouve1, M, nl, nc);
				break;
			case 9:
				printf("Choisissez la matrice: ");
				scanf("%d", &choix1);
				triangulairesup(choix1, &trouve2, M, nl, nc);
				break;
			case 10:
				printf("Choisissez la matrice: ");
				scanf("%d", &choix1);
				triangulaireinf(choix1, &trouve1, M, nl, nc); printf("\n");
				triangulairesup(choix1, &trouve2, M, nl, nc); printf("\n");
				if(trouve1==trouve2==1)	printf("Donc elle est Diagonale\n");
				else	printf("Donc elle n'est pas Diagonale\n");
				break;
	/*	}	

	/*if(choixvm==1)
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
			printf("Impossible car les tailles ne sont pas les memes\n");*/

	}
	if(choixvm!=3)
	{	
		printf("La solution est: \nMatrice globale:\n");
			for(i=1; i<=maxl; i++)
			{
				for(j=1; j<=maxc; j++)
				printf(" %2.0f\t", Mat[i][j]);
				printf("\n");
			}
	return Mat;
	}
	else
	{
		printf("La solution est un vecteur: \nVecteur global:\n");
			for(i=1; i<=maxv; i++)
				printf(" %2.0f\t", T[i]);
			printf("\n");
	return T;
	}
}
