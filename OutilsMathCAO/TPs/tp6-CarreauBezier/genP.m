
clear;

p = 2;
q = 1;

[pX,pY] = meshgrid(0:p, 0:q);
pZ = 1-(1-pX).^2;
pX=pX'; pY=pY'; pZ=pZ';

header = [p q 0];
val=[pX(:) pY(:) pZ(:)];
save P.dat header val -ascii;