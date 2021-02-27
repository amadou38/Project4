#include<stdio.h>
#include<stdlib.h>
	
	void triangulaireinf(int choix1, int *trouve1, double **M[], int nl[], int nc[])
	{
		int i, j, maxc=0;
		if(nl[choix1]!=nc[choix1])	printf("Impossible car cette matrice n'est pas carrée\n");
		else
		{
			maxc=nc[choix1];
			for(j=2; j<=maxc; j++)
				for(i=1; i<j; i++)						
				{
					if(M[choix1][i][j]!=0)	*trouve1=1; break;
				}
			if(*trouve1==1)	printf("Cette Matrice n'est pas triangulaire inferieure\n");
			else	printf("Cette Matrice est triangulaire inferieure\n");
		}
	}
