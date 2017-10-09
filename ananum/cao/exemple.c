#include <stdlib.h>
#include <stdio.h>
/*
   Lecture d'un fichier de donnees de la forme
    dim np 0 ... 0  (dim-2 zeros pour compatibilite avec Matlab)
    P1,1 ... P1,dim
    P2,1 ... P2,dim
    .
    .
    .
    Pnp,1 ... Pnp,dim

    
     et ecriture de la meme information
   dans un autre fichier.
*/
int main()
{
	int i, j, dim, np;
	FILE* fdon, *fres;
	char ficdon[20], ficres[20];
	double **P;
	
/* Ouverture des fichiers : */
	printf("Nom du fichier de donnees : ");
	scanf("%s",ficdon);
	printf("Nom du fichier resultat : ");
	scanf("%s",ficres);
	fdon = fopen(ficdon,"r");
	if (fdon == NULL){
		printf("*** Erreur a l'ouverture du fichier %s ***\n",ficdon);
		exit(1);
	}
	fres = fopen(ficres,"w");
	if (fres == NULL){
		printf("*** Erreur a l'ouverture du fichier %s ***\n",ficres);
		exit(1);
	}

/* Lecture de la dimension et du nombre de points : */
	fscanf(fdon,"%d %d",&dim,&np);
	printf("Lecture d'une liste de %d points de R%d.\n",np,dim);
	for (i=0; i<dim-2; i++)
		fscanf(fdon,"%d",&j); /* "Consommation" des zeros */

/* Allocation du tableau de pointeurs : */
	P = (double **)calloc(dim,sizeof(double *));
	if (P == NULL){
		printf("*** Probleme d'allocation ***\n");
		exit(1);
	}
/* Allocation des elements de la matrice : */
	for (i=0; i<dim; i++){
		P[i] = (double *)calloc(np,sizeof(double));
		if (P[i] == NULL){
			printf("*** Probleme d'allocation ***\n");
			exit(1);
		}
	}

/* Lecture des points : */
	for (j=0; j<np; j++)
		for (i=0; i<dim; i++)
	/* Attention au format : on passe un pointeur de double */
		     fscanf(fdon,"%lf",&P[i][j]); 

/* Ecriture des points : */
	for (j=0; j<np; j++) {
		for (i=0; i<dim; i++)
		     fprintf(fres," %g",P[i][j]);
		fprintf(fres,"\n");
	}
	
	fclose(fdon);
	fclose(fres);
}
