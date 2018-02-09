function [ rhok ] = OPTSTEP_g( gk, xk, dk )
%OPTSTEP_g Calcule le pas optimal pour g()
% GJ - fonction gradient de la fonction J
% xk - la valeur courante
% dk - la direction de gradient

n = length(xk);
i = (1:n)';

B = dk' * gk;
C = dk ./ i;

C = dk'* C;

rhok = - B / (2*C);

end

