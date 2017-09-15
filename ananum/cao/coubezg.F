************************************************************************
*
* Interface avec MATLAB pour une fonction dont le modele est :
*
*   B = COUBEZ(NBP, TA, TB, P)
*
* Calcul d'une courbe de Bezier par l'algorithme d'evaluation de
* de Casteljau.
*
* ENTREES
*  NBP : nombre de points de la courbe
*  TA  : valeur min du parametre
*  TB  : valeur max du parametre
*  P   : polygone de controle dans Rd tel que size(P) = [d, n].
*
* SORTIES
*  B   : points de la courbe. On a size(B) = [d, NBP].
*
************************************************************************
* fintrf.h     - MATLAB/FORTRAN interface header file.
#include "fintrf.h"
      subroutine mexFunction(nlhs, plhs, nrhs, prhs)
      mwPointer plhs(*), prhs(*)
      integer nlhs, nrhs
*  Variables locales
      mwSize NBP_m, d_m, n_m, Un_m, DblePrec
      integer*4 NBP, d, n
      integer*4 j, nrhsex, nlhsex, ComplexFlag
      mwPointer B, TA, TB, P, pPtamp,Ptamp
      integer*4 naB, naNBP, naTA, naTB, naP
*  Points d'entree MATLAB
      mwSize mxGetM, mxGetN
      mwPointer mxCreateDoubleMatrix, mxGetPr, mxCalloc
      integer*4 mxIsNumeric, mxIsComplex
      double precision mxGetScalar
*  Initialisations
      parameter (ComplexFlag = 0, Un_m = 1, DblePrec_m = 8)
*      Nombre exact d'arguments
      parameter (nrhsex = 4, nlhsex = 1)
*      Numero des arguments de sortie
      parameter (naB = 1)
*      Numero des arguments d'entree
      parameter (naNBP=1, naTA=2, naTB=3, naP=4)
*
*       Controle du nombre d'arguments
*
      if (nrhs .ne. nrhsex) then
        call mexErrMsgTxt('Nombre d''arguments d''entree incorrect.')
      elseif (nlhs .gt. nlhsex) then
        call mexErrMsgTxt('Nombre d''arguments de sortie incorrect.')
      endif
*
*       Controle des types
*
      do 20 j=1,nrhs
       if (mxIsNumeric(prhs(j)).eq.0 .or. mxIsComplex(prhs(j)).ne.0)then
         call mexErrMsgTxt('Argument de type incorrect.')
       endif
   20 continue
*
*       Recuperation de la dimension de P
*
      d_m = mxGetM(prhs(naP))
      d = d_m
      n_m = mxGetN(prhs(naP))
      n = n_m
*
*       Creation de l'argument de sortie
*
      NBP = int(mxGetScalar(prhs(naNBP)))
      NBP_m = NBP
      plhs(naB) = mxCreateDoubleMatrix(d_m,NBP_m,ComplexFlag)
*
*       Extraction des adresses des arguments
*
      B = mxGetPr(plhs(naB))
*
      TA = mxGetPr(prhs(naTA))
      TB = mxGetPr(prhs(naTB))
      P  = mxGetPr(prhs(naP))
*
*        Creation du tableau de travail temporaire
*
*      1. soit dans l'espace d'adressage de Matlab
      pPtamp = mxCreateDoubleMatrix(Un_m,n_m,ComplexFlag)
      Ptamp = mxGetPr(pPtamp)
*      2. soit dans l'espace d'adressage du systeme en utilisant
*        les fonctions Matlab
*      Ptamp = mxCalloc(n_m,DblePrec_m)
*
*        Appel de la subroutine de calcul
*
      n = n-1
      call COUBEZ(NBP,%val(TA),%val(TB),d,n,%val(P),%val(Ptamp),%val(B))
*
*        Liberation du tableau temporaire
*
*      1. cree dans l'espace d'adressage de Matlab
      call mxDestroyArray(pPtamp)
*      2. cree dans l'espace d'adressage du systeme
*      call mxFree(Ptamp)
*
      return
      end
