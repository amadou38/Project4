#include<stdio.h>
#include<stdlib.h>
	
	void triangulairesup(int choix1, int *trouve2, double **M[], int nl[], int nc[])
	{
		int i, j, maxc=0;

		if(nl[choix1]!=nc[choix1])	printf("Impossible car cette matrice n'est pas carrée\n");
		else
		{
			maxc=nc[choix1];
			for(i=2; i<=maxc; i++)
				for(j=1; j<i; j++)						
				{
					if(M[choix1][i][j]!=0)	*trouve2=1; break;
				}
			if(*trouve2==1)	printf("Cette Matrice n'est pas triangulaire superieure\n");
			else	printf("Cette Matrice est triangulaire superieure\n");
		}
	}
