clear;

% TO DO load ('T.dat')

p = 3;
q = 2;

P = load('P.dat');
pX = reshape(P(:,1),p,q)';
pY = reshape(P(:,2),p,q)';
pZ = reshape(P(:,3),p,q)';

hP = mesh(pX, pY, pZ); 

set(hP, 'FaceColor', 'none');
