/*
 COUBEZ : Generation d'une courbe de Bezier
 DECAST : Calcul de la position d'un point sur une courbe de Bezier
           par l'algorithme de de Casteljau.
*/
/************************************************************************/
void COUBEZ(int nbp, double ta, double tb, int ndim, int n,
            double *P, double *Ptamp, double *B)
{
      int i;
      double pas, t;
      void DECAST(int ndim, int n,
	    double *P, double *Ptamp, double t, double B[]);
/*      ---------------------------------------------------------------
        Generation de la courbe de Bezier Bn(t) de Rd, ou d=ndim,
        construite a partir des n+1 points de controle P(.,0),...P(.,n)
        pour t variant entre ta et tb.
        nbp   : nombre de points de la courbe a calculer.
        P     : adresse des coordonnees des points de controle dans
		l'ordre suivant : 1ere coord. des n+1 points, puis
		2eme coord. des n+1 points, ...
        Ptamp : tableau de travail de dimension n+1.
        B     : adresse ou sont stockees les coordonnees des points
		de la courbe (les ndim coordonnees du ieme point
		suivent celle du (i-1)eme point).
        Arguments d'entree  : nbp,ta,tb,ndim,n,P
        Arguments de sortie : B
        Tableaux de travail : Ptamp
        ---------------------------------------------------------------*/
      pas = (tb-ta)/(nbp-1);

      for (i=0; i<nbp; i++, B+=ndim) {
        t = ta + i*pas;
        DECAST(ndim,n,P,Ptamp,t,B);
      }
}
/************************************************************************/
void DECAST(int ndim, int n,
	    double *P, double *Ptamp, double t, double B[])
{
      int i, k, m;
      double unmt = 1. - t;
/*    ------------------------------------------------------------------
      Calcul de la valeur des ndim coordonnees du point B situe sur la
      courbe de Bezier definie par le polygone P(.,0), P(.,2),...P(.,n)
      pour la valeur du parametre t.
        P     : adresse des coordonnees des points de controle dans
		l'ordre suivant : 1ere coord. des n+1 points, puis
		2eme coord. des n+1 points, ...
        Ptamp : vecteur tampon de taille n+1 destinee aux calculs
                intermediaires.
       Arguments d'entree  : ndim,n,P,t
       Arguments de sortie : B
       Tableaux de travail : Ptamp
      ------------------------------------------------------------------*/
/*       Calcul coordonnee par coordonnee */
      for (m=0; m<ndim; m++, P+=(n+1)) {
/*       Initialisation (correspond a k = 0) */
        for (i=0; i<=n; i++)
          Ptamp[i] = P[i];
/*       Calcul de la m-ieme coordonnee pour la valeur du parametre t */
        for (k=1; k<=n; k++)
          for (i=0; i<=n-k; i++)
            Ptamp[i] = unmt*Ptamp[i] + t*Ptamp[i+1];
        B[m] = Ptamp[0];
      }
}
