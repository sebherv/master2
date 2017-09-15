#include "mex.h"
#include "matrix.h"
/************************************************************************

 Interface avec MATLAB pour une fonction dont le modele est :

   B = COUBEZ_C(NBP, TA, TB, P)

 Calcul d'une courbe de Bezier par l'algorithme d'evaluation de
 de Casteljau.

 ENTREES
  NBP : nombre de points de la courbe
  TA  : valeur min du parametre
  TB  : valeur max du parametre
  P   : polygone de controle dans Rd tel que size(P) = [n, d].

 SORTIES
  B   : points de la courbe. On a size(B) = [d, NBP].

************************************************************************/
void mexFunction(int nlhs, mxArray *plhs[],
		 int nrhs, const mxArray *prhs[])
{
      int d, n, j;
      int NBP;
      double  TA, TB;
      double *B, *P, *Ptamp;
      mxArray *pPtamp;
/*  Initialisations */
/*       Nombre exact d'arguments */
      const int nrhsex = 4, nlhsex = 1;
/*       Numero des arguments de sortie */
      const int naB = 0;
/*       Numero des arguments d'entree */
      const int naNBP=0, naTA=1, naTB=2, naP=3;
/*       Prototype de la fonction de calcul */
      void COUBEZ(int nbp, double ta, double tb, int ndim, int n,
                  double *P, double *Ptamp, double *B);

/*      Controle du nombre d'arguments */

      if (nrhs != nrhsex)
        mexErrMsgTxt("Nombre d'arguments d'entree incorrect.");
      else if (nlhs > nlhsex)
        mexErrMsgTxt("Nombre d'arguments de sortie incorrect.");

/*      Controle des types */

      for (j=0; j<nrhs; j++)
       if (!mxIsNumeric(prhs[j]) || mxIsComplex(prhs[j]))
         mexErrMsgTxt("Argument de type incorrect.");

/*      Recuperation de la dimension de P */

      d = mxGetN(prhs[naP]);
      n = mxGetM(prhs[naP]);

/*      Creation de l'argument de sortie */

      NBP = (int)mxGetScalar(prhs[naNBP]);
      plhs[naB] = mxCreateDoubleMatrix(d,NBP,mxREAL);

/*      Extraction des adresses ou des valeurs des arguments */

      B = mxGetPr(plhs[naB]);

      TA = mxGetScalar(prhs[naTA]);
      TB = mxGetScalar(prhs[naTB]);
      P  = mxGetPr(prhs[naP]);

/*       Creation du tableau de travail temporaire */

/*     1. soit dans l'espace d'adressage de Matlab */
      pPtamp = mxCreateDoubleMatrix(1,n,mxREAL);
      Ptamp = mxGetPr(pPtamp);
/*     2. soit dans l'espace d'adressage du systeme en utilisant
          les fonctions Matlab */
/*      Ptamp = mxCalloc(n,sizeof(double)); */

/*       Appel de la subroutine de calcul */
      n = n-1;
      COUBEZ(NBP,TA,TB,d,n,P,Ptamp,B);

/*       Liberation du tableau temporaire */
/*     1. cree dans l'espace d'adressage de Matlab */
      mxDestroyArray(pPtamp);
/*     2. cree dans l'espace d'adressage du systeme */
/*      mxFree(Ptamp); */

}
