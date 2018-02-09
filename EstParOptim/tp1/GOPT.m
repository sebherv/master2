function [ x, Jx, GJx, nit, XKS ] = GOPT( J, GJ, OPTSTEP, x0, epsil, nitmax )
%GOPT Summary of this function goes here
%   Méthode du gradient à pas optimal UNIQUEMENT POUR f ET g
% J  - fonction dont on doit trouver le minimum
% GJ - fonction gradient de la fonction J
% x0 - valeur initiale
% epsil - valeur vers pour convergence
% nitmax - nombre max d'iteration
%
% Retourne:
% x - le x pour lequel J est minimal
% Jx - la valeur de J pour x
% GJx - le gradient de J en x
% nit - le nombre d'iteration

% iterer
n = 1;
nit = 1;
xk = x0;

gk = GJ(xk);
dk = -gk;
dk1 = 0;

XKS = [];
XKS = x0;

while n < nitmax & norm(dk) > epsil
    
    % Calculer gradient
    pas = OPTSTEP(gk, xk, dk);
    xk1 = xk + pas * dk;
    nit = n;
    
    % Mettre Ã  jour les valeurs
    n = n+1;
    xk = xk1;
    
    % Préparer la boucle suivante
    dk1 = dk;
    gk = GJ(xk);
    dk = -gk;
    
    XKS = [XKS xk];
   
end
x = xk;
Jx = J(x);
GJx = GJ(x);

end

