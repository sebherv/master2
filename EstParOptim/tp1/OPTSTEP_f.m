function [ rhok ] = OPTSTEP_f(  gk, xk, dk )
%OPTSTEP_f Calcule le pas optimal pour f()
% GJ - fonction gradient de la fonction J
% xk - la valeur courante
% dk - la direction de gradient

B = dk' * gk;
C = dk'* dk;

rhok = - B / (2*C);
end

