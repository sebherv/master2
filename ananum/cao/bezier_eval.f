************************************************************************
*    Version double precision pour Matlab
************************************************************************
* COUBEZ : Generation d'une courbe de Bezier
* DECAST : Calcul de la position d'un point sur une courbe de Bezier
*          par l'algorithme de de Casteljau.
************************************************************************
      subroutine COUBEZ(nbp,ta,tb,ndim,n,P,Ptamp,B)
      integer nbp, ndim, n
      double precision ta,tb, P(ndim,0:n), Ptamp(n+1), B(ndim,nbp)
*  Variables locales :
      integer i
      double precision pas, t
*       ---------------------------------------------------------------
*       Generation de la courbe de Bezier Bn(t) de Rd, ou d=ndim,
*       construite a partir des n+1 points de controle P(.,0),...P(.,n)
*       pour t variant entre ta et tb.
*       Ptamp est un tableau de travail de dimension n+1.
*       nbp est le nombre de points de la courbe a calculer.
*       Arguments d'entree  : nbp,ta,tb,ndim,n,P
*       Arguments de sortie : B
*       Tableaux de travail : Ptamp
*       ---------------------------------------------------------------
*
      pas = (tb-ta)/dble(nbp-1)
*
      do 10 i=0,nbp-1
        t = ta + i*pas
   10   call DECAST(ndim,n,P,Ptamp,t,B(1,i+1))
*
      end
************************************************************************
      subroutine DECAST(ndim,n,P,Ptamp,t,B)
      integer ndim, n
      double precision P(ndim,0:n), Ptamp(0:n), t, B(ndim)
*  Variables locales
      integer i, k, m
      double precision unmt
*      ------------------------------------------------------------------
*      Calcul de la valeur des ndim coordonnees du point B situe sur la
*      courbe de Bezier definie par le polygone P(.,0), P(.,2),...P(.,n)
*      pour la valeur du parametre t.
*      Ptamp est un vecteur tampon de taille n+1 destinee aux calculs
*      intermediaires.
*       Arguments d'entree  : ndim,n,P,t
*       Arguments de sortie : B
*       Tableaux de travail : Ptamp
*      ------------------------------------------------------------------
      unmt = 1. - t
*        Calcul coordonnee par coordonnee
      do 30 m=1,ndim
*        Initialisation (correspond a k = 0)
        do 10 i=0,n
   10     Ptamp(i) = P(m,i)
*        Calcul de la m-ieme coordonnee pour la valeur du parametre t
        do 20 k=1,n
          do 20 i=0,n-k
   20       Ptamp(i) = unmt*Ptamp(i) + t*Ptamp(i+1)
   30   B(m) = Ptamp(0)
*
      end
