function [ rhok ] = OPTSTEP_h( gk, xk, dk )
%OPTSTEP_H Calcul de pas optimal pour Rosenbrock
% gk unused,

xk1 = xk(1);
xk2 = xk(2);
dk1 = dk(1);
dk2 = dk(2);

B = 100 * dk2 - 200 * dk1 * xk1;
C = -(100 * xk1^2 - dk1^2);

rhok = - B / (2 * C);

end

