/***********************************************************************
 S'utilise grace aux commandes UNIX :

 cc -c invmat.c
 f77 invmat.o gauss.f -o invmat

ou bien

 f77 -c gauss.f
 cc invmat.c gauss.o -o invmat

Nota : - la premiere facon de proceder est necessaire s'il est fait appel
       a une fonction intrinseque du Fortran telle que SIN, COS...
       ou a une instruction d'entree/sortie.
       - adapter les commandes en fonction des compilateurs disponibles,
       par exemple, sous Linux remplacer (cc, f77) par (gcc, gfortran).
 ***********************************************************************/

#include <stdio.h>
#define NLX 10
#define NCX 2*NLX
#define N 3

main()
{
  const int nlx=NLX, ncx=NCX, n=N;
  int i, j, codret;
  float Adon[N][N]={{11, 21, 31}, {-12, 22, 32}, {13, 23, -33}};
  float A[NCX][NLX], det;
  float eps = 1.e-5;

/*
      Initialisation
*/
  printf(" Matrice donnee :\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      A[j][i] = Adon[j][i];
      printf("%g ",A[j][i]);
      }
    printf("\n");
    }
/*
   Inversion de la matrice : initialisation des seconds membres
   puis appel au sous-programme GAUSS ecrit en FORTRAN
*/
  for (i=0; i<n; i++) {
    for (j=n; j<2*n; j++)
      A[j][i] = 0.;
    A[i+n][i] = 1.;
    }

	/* Appel de la routine FORTRAN : son nom doit etre suivi d'un _
	   par defaut avec la plupart des compilateurs. */
  gauss_(A,&n,&nlx,&n,&eps,&det,&codret);

/*
   Resultats
*/
  printf(" Determinant de la matrice : %g\n", det);
  printf(" Inverse de la matrice :\n");
  for (i=0; i<n; i++) {
    for (j=n; j<2*n; j++) {
      printf("%13.5e ",A[j][i]);
      }
    printf("\n");
    }
}
