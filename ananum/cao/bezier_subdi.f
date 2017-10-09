************************************************************************
*    Version double precision pour Matlab
************************************************************************
* SBELEM : Subdivision elementaire d'un polygone de controle
* SBGEN  : Algorithme general de subdivision
************************************************************************
      subroutine SBELEM(ndim,n,P,t,GD)
      integer ndim, n
      double precision P(ndim,0:n), GD(ndim,0:2*n)
*  Variables locales
      integer deuxn, i, j, k
      double precision t, unmt
*      ------------------------------------------------------------------
*      Subdivision elementaire du polygone de controle P(0), P(1),...P(n)
*      Cette procedure renvoie les nouveaux points de controle G(0)=P(0),
*      G(1),...G(n)=D(0), D(1),...D(n)=P(n) dans GD(i), i=0,...2n.
*      t est la valeur du parametre d'evaluation de l'algorithme
*      de De Casteljau.
*       Arguments d'entree  : ndim,n,P,t
*       Arguments de sortie : GD
*      ------------------------------------------------------------------
      unmt = 1. - t
      deuxn = n + n
*        Initialisation (correspond a k = 0)
      do 10 i=n,0,-1
       do 10 j=1,ndim
   10  GD(j,n+i) = P(j,i)
      do 20 j=1,ndim
   20  GD(j,0) = P(j,0)
*        Algorithme de DE Casteljau au point t
      do 50 k=1,n
       do 30 i=n,deuxn-k
        do 30 j=1,ndim
   30    GD(j,i) = unmt*GD(j,i) + t*GD(j,i+1)
*        Sauvegarde de la diagonale descendante
       do 40 j=1,ndim
   40  GD(j,k) = GD(j,n)
   50 continue
*
      return
      end
************************************************************************
      subroutine SBGEN(nptmax,ndim,n,P,nbiter,m,PS)
      integer nptmax, ndim, n, nbiter, m
      double precision P(ndim,0:n), PS(ndim,0:nptmax)
*  Variables locales :
      integer deuxn, j, l, dpj, dpjm1, adrdep, adrarr, adep, adar
      double precision t
      data t /0.5/
      external SBELEM
*      ------------------------------------------------------------------
*      Approximation de la courbe de Bezier definie par les n+1 points de
*      controle P(0), P(1),...P(n) par subdivision, nbiter etant le
*      nombre d'iterations demandees.
*      Le tableau PS doit etre de taille ndim*(nptmax+1) au moins,
*      nptmax+1 etant le nombre maximum de points a etre generes.
*      En sortie, la procedure renvoie dans m la nouvelle valeur du nombre
*      de points et dans PS leurs coordonnees PS(.,0),PS(.,1),...PS(.,m).
*      Si la place necessaire aux nbiter iterations est insuffisante, la
*      procedure renvoie dans nbiter le numero de la derniere iteration
*      realisee.
*      Le fonctionnement de cette routine est lie a celui de SBELEM, ou
*      on a pris soin d'eviter le chevauchement lors des transferts en
*      memoire, du fait qu'on travaille sur le meme tableau PS.
*       Arguments d'entree  : nptmax,ndim,n,P,nbiter
*       Arguments de sortie : nbiter,m,PS
*      ------------------------------------------------------------------
      if (n.gt.nptmax+1) then
       m = -1
       return
      else
*         Recopie du polygone initial dans le tableau resultat
       do 10 l=0,n
        do 10 j=1,ndim
   10    PS(j,l) = P(j,l)
      endif
*
      deuxn = n + n
*       dpj = 2^j,  dpjm1 = 2^(j-1)
      dpj = 1
*       Controle de la place memoire
      do 20 j=1,nbiter
       dpj = dpj * 2
   20  if (dpj*n .gt. nptmax) goto 30
      goto 40
*       Pas assez de place
   30 nbiter = j-1
*
   40 adrarr = -n
      dpj = 1
      dpjm1 = dpj
      do 60 j=1,nbiter
       dpj = dpj * 2
*       adrdep : adresse de depart (du polygone a subdiviser)
*       adrarr : adresse d'arrivee (de stockage des nouveaux points)
       adrdep = adrarr + n
       adrarr = adrarr + dpjm1*n
       adep = adrdep
       adar = adrarr
       do 50 l=1,dpjm1
        call SBELEM(ndim,n,PS(1,adep),t,PS(1,adar))
        adep = adep - n
   50   adar = adar - deuxn
   60  dpjm1 = dpj
*
      m = dpj*n
*
      return
      end
