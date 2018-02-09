% Gradient à  pas constant optimal pour f et g
clear; close all;



[ x, curJx, GJx, curnit] = GCST(@g, @gradg,[0;0], 0.5, 1e-7, 10000);
fprintf("Pour GCST, Nombre d'itérations est %d, min is = %f\n", curnit, curJx);

[ x, curJx, GJx, curnit, XKS] = GOPT(@g, @gradg, [0;0], 1e-7, 10000);
fprintf("Pour GOPT, Nombre d'itérations est %d min is = %f\n", curnit, curJx);

%plot(XKS(1,:), XKS(2,:), 'o-');
%hold on;

[ x, curJx, GJx, curnit, XKS] = GCDYOPT(@g, @gradg, [0;0], 1e-7, 10000);
fprintf("Pour GCDYOPT, Nombre d'itérations est %d min is = %f\n", curnit, curJx);


%plot(XKS(1,:), XKS(2,:), 'x-');

