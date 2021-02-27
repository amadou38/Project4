#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int NV6;
int main(int argc, char *argv[]) {
	int i, choix, choixvm=7, choix1, choix2, dim=0, NV1, NV2, NV3, NV4, NV5;
	int nl1, nl2, nl3, nl4, nl5, nl6, nl7, nc1, nc2, nc3, nc4, nc5, nc6, nc7;
	double *T, **Mat, *V1, *V2, *V3, *V4, *V5, *V6, **M1, **M2, **M3, **M4, **M5, **M6, **M7, alpha;
	double* RemplirVect(FILE *pfichier, int *NV);
	double **RemplirMatr(FILE *pfichier, int *l, int *c);
	double *Calculvec(int choixvm, double *V[], int NV[]);
  	double **Calculmatr(int choixvm, double **M[], int nl[], int nc[], double *V[], int NV[]);	system("clear");
	printf("Ce programme manipule les vecteurs et les matrices\n");
	printf("<1>\t Operations sur les vecteurs\n");
	printf("<2>\t Operations sur les matrices\n");
	printf("votre choix? ");
	scanf("%d", &choix);	system("clear");
	FILE *pfichier;
		pfichier=fopen("Donnees.dat","r");
		V1=RemplirVect(pfichier, &NV1);
		V2=RemplirVect(pfichier, &NV2);
		M1=RemplirMatr(pfichier, &nl1, &nc1);
		M2=RemplirMatr(pfichier, &nl2, &nc2);
		V3=RemplirVect(pfichier, &NV3);
		V4=RemplirVect(pfichier, &NV4);
		V5=RemplirVect(pfichier, &NV5);
		M3=RemplirMatr(pfichier, &nl3, &nc3);
		M4=RemplirMatr(pfichier, &nl4, &nc4);
		V6=RemplirVect(pfichier, &NV6);
		M5=RemplirMatr(pfichier, &nl5, &nc5);
		M6=RemplirMatr(pfichier, &nl6, &nc6);
		M7=RemplirMatr(pfichier, &nl7, &nc7);
		fclose(pfichier);
		 double *V[]={V1,V1,V2,V3,V4,V5,V6};
		double **M[]={M1,M1,M2,M3,M4,M5,M6,M7};
	int NV[]={NV1,NV1,NV2,NV3,NV4,NV5,NV6};
	int nl[]={nl1,nl1,nl2,nl3,nl4,nl5,nl6,nl7};
	int nc[]={nc1,nc1,nc2,nc3,nc4,nc5,nc6,nc7};
	if(choix==1)
	{
		printf("Vous avez choisi d'éffectuer les operations sur les vecteurs.\n Les opérations proposées sont: \n");
		printf("<1>\t Addition de deux vecteurs\n");
		printf("<2>\t Multiplication de deux vecteurs\n");
		printf("<3>\t Produits scalaire de deux vecteurs\n");
		printf("votre choix? ");
		scanf("%d", &choixvm);	system("clear");
		printf("Pour les vecteurs, nous en avons 6: \n");	
		T=Calculvec(choixvm, V,NV);	
	}
	if(choix==2)
	{
		printf("Vous avez choisi d'éffectuer les operations sur les matrices.\n Les opérations proposées sont: \n");
		printf("<1>\t Multiplication d'une matrice par un scalaire\n");
		printf("<2>\t Addition de deux matrices\n");
		printf("<3>\t Produits matrice vecteur\n");
		printf("<4>\t Produits de deux matrices\n");
		printf("<5>\t Calcul de la transposée d'une matrice\n");
		printf("<6>\t Calcul de la trace d'une matrice\n");
		printf("<7>\t Transformer une matrice en sa transposée\n");
		printf("<8>\t Tester si une matrice est triangulaire inférieure\n");
		printf("<9>\t Tester si une matrice est triangulaire supérieure\n");
		printf("<10>\t Tester si une matrice est diagonale\n");
		printf("votre choix? ");
		scanf("%d", &choixvm);	system("clear");
		printf("Pour les matrices nous en avons 7: \n");	
		Mat=Calculmatr(choixvm,M, nl, nc,V, NV);
	}
	return 0;
}
