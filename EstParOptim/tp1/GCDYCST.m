function [ x, Jx, GJx, nit ] = GCDYCST( J, GJ, x0, pas, epsil, nitmax )
%GCDYCST Méthode de gradient conjugué de Dai-Yuan
% J  - fonction dont on doit trouver le minimum
% GJ - fonction gradient de la fonction J
% x0 - valeur initiale
% pas - valeur du pas
% epsil - valeur vers pour convergence
% nitmax - nombre max d'itÃ©ration
%
% Retourne:
% x - le x pour lequel J est minimal
% Jx - la valeur de J pour x
% GJx - le gradient de J en x
% nit - le nombre d'iteration

% iterer
n = 1;
xk = x0;
dk = 1;  % d_k
dk1 = 0; % d_{k-1}
gk = 0;  % g_k
gk1 = 0; % g_{k-1}

gk = GJ(xk);

while n < nitmax & norm(gk) > epsil
    
    if n > 1
        dk1 = dk;
        betak1 = gk'*gk / (dk1'*(gk - gk1));
        dk = -gk+ betak1 * dk1;
    else 
        dk = -gk;
    end
        
    xkp1 = xk + pas * dk;
    nit = n;
    
    % Mettre Ã  jour les valeurs
    n = n+1;
    xk = xkp1;
    
    % Préparer la boucle suivante
    gk1 = gk;
    gk = GJ(xk);
   
end
x = xkp1;
Jx = J(x);
GJx = GJ(x);
end

