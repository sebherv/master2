function [ x, Jx, GJx, nit, XKS ] = GCDYOPT( J, GJ,OPTSTEP, x0, epsil, nitmax )
%GCDYOPT Méthode de gradient conjugué de Dai-Yuan
% J  - fonction dont on doit trouver le minimum
% GJ - fonction gradient de la fonction J
% x0 - valeur initiale
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
nit = 1;
xk = x0;
dk = 1;  % d_k
dk1 = 0; % d_{k-1}
gk = 0;  % g_k
gk1 = 0; % g_{k-1}

gk = GJ(xk);

XKS = [];
XKS = x0;

while n < nitmax & norm(gk) > epsil
    
    if n > 1
        dk1 = dk;
        betak1 = gk'*gk / (dk1'*(gk - gk1));
        dk = -gk+ betak1 * dk1;
    else 
        dk = -gk;
    end
    
    pas = OPTSTEP(gk, xk, dk);
    xkp1 = xk + pas * dk;
    nit = n;
    
    % Mettre à jour les valeurs
    n = n+1;
    xk = xkp1;
    
    XKS = [XKS, xk];
    
    % Préparer la boucle suivante
    gk1 = gk;
    gk = GJ(xk);
   
end
x = xk;
Jx = J(x);
GJx = GJ(x);
end

