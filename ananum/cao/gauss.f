************************************************************************
      subroutine GAUSS(A,n,nmax,m,eps,det,codret)
      integer n, nmax, m, codret
      real A(nmax,*), eps, det
*  Variables locales :
      integer ncol, i, i1, j, ind, k
      real pivot, v, b
*    ----------------------------------------------------------------
*    Resolution des systemes lineaires Axj = bj, j=1,m avec
*    A matrice (n,n), bj vecteur colonne suppose memorise dans la
*    (n+j)eme colonne de A : bj(i)=A(i,n+j), i=1,n.
*    La methode utilisee est la methode de Gauss avec recherche
*    du pivot maximal dans la i-eme colonne a la i-eme etape.
*    En sortie, les vecteurs solutions sont a la place des
*    seconds membres.
*
*    Arguments d'entree :
*     A    : matrice du systeme et seconds membres
*     n    : ordre de la matrice
*     nmax : premiere dimension de la matrice (correspond en general
*            a la declaration faite dans le module appelant)
*     m    : nombre de seconds membres a traiter
*     eps  : sert a detecter si la matrice est singuliere (pivot<eps)
*    Arguments de sortie :
*     A    : solutions dans les colonnes n+1 a n+m (matrice modifiee)
*     det  : determinant de la matrice du systeme.
*     codret : code de retour qui vaut 0 si R.A.S., 1 si pivot nul,
*              2 si |pivot| < eps.
*    ----------------------------------------------------------------
      codret=0
      ncol=n+m
      det=1.
*
      do 80 i=1,n
      i1=i+1
*       --------------------------
*       recherche du pivot maximal
*       --------------------------
      pivot=0.
      do 10 j=i,n
      v=abs(A(j,i))
      if (v.le.pivot) goto 10
      pivot=v
      ind=j
   10 continue
      if (pivot.gt.eps) goto 20
      if (pivot.eq.0.) goto 90
      codret=2
   20 if (ind.eq.i) goto 40
      det=-det
*       ----------------------
*       permutation des lignes
*       ----------------------
      do 30 k=i,ncol
      b=A(i,k)
      A(i,k)=A(ind,k)
   30 A(ind,k)=b
   40 det=det*A(i,i)
*
      do 60 k=1,n
      if (k.eq.i) goto 60
      do 50 j=i1,ncol
   50 A(k,j)=A(k,j)-(A(k,i)*A(i,j))/A(i,i)
   60 continue
      do 70 j=i1,ncol
   70 A(i,j)=A(i,j)/A(i,i)
   80 continue
*
      return
   90 codret=1
      return
      end
