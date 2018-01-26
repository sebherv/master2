function [ x, Jx, GJx, nit ] = GCST( J, GJ, x0, pas, epsil, nitmax )
%GCST Méthode du gradient à pas constant
% J  - fonction dont on doit trouver le minimum
% GJ - fonction gradient de la fonction J
% x0 - valeur initiale
% pas - valeur du pas
% epsil - valeur vers pour convergence
% nitmax - nombre max d'itération
%
% Retourne:
% x - le x pour lequel J est minimal
% Jx - la valeur de J pour x
% GJx - le gradient de J en x
% nit - le nombre d'iteration

% iterer
n = 0;
xk = x0;
dk 

while n < nitmax & abs(dk) < epsil
    
    % Calculer gradient
    dk = -GJ(xk);
    xk1 = xk + pas * dk;
    nit = n;
    if abs(dk) < epsil
        n = nitmax;
    end
    
    % Mettre à jour les valeurs
    n = n+1;
    xk = xk1;
   
end
x = xk1;
Jx = J(x);
GJx = GJ(x);
end

