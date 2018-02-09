function [ x, Jx, GJx, nit ] = GCST( J, GJ, x0, pas, epsil, nitmax )
%GCST MÈthode du gradient ‡ pas constant
% J  - fonction dont on doit trouver le minimum
% GJ - fonction gradient de la fonction J
% x0 - valeur initiale
% pas - valeur du pas
% epsil - valeur vers pour convergence
% nitmax - nombre max d'it√©ration
%
% Retourne:
% x - le x pour lequel J est minimal
% Jx - la valeur de J pour x
% GJx - le gradient de J en x
% nit - le nombre d'iteration

% iterer
nit = 1;
xk = x0;
dk = 0;

dk = -GJ(xk);
dk1 = dk + 1;  % make sure the grad diff is not 0

while nit < nitmax & norm(dk1 -dk) > epsil & norm(dk) > epsil
    
    % Calculer gradient
    xk1 = xk + pas * dk;
    
    % Mettre √† jour les valeurs
    nit = nit+1;
    xk = xk1;
    
    dk1 = dk;
    dk = -GJ(xk);
   
end
x = xk;
Jx = J(x);
GJx = GJ(x);
end

