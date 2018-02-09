clear; close all;

n = [1,2,5,10,100,1000,10000];


for curn = n
    x0 = zeros(curn,1);
    [ x, curJx, GJx, curnit, XKS] = GOPT(@f, @gradf, @OPTSTEP_f, x0, 1e-7, 10000);
    fprintf("f(x) en GOPT, n = %d, Nombre d'itérations est %d min, is = %f\n", curn, curnit, curJx);
end


for curn = n
    x0 = zeros(curn,1);
    [ x, curJx, GJx, curnit, XKS] = GCDYOPT(@f, @gradf, @OPTSTEP_f, x0, 1e-7, 10000);
    fprintf("f(x) en GCDYOPT, n = %d, Nombre d'itérations est %d, min is = %f\n",curn, curnit, curJx);
end



for curn = n
    x0 = zeros(curn,1);
    [ x, curJx, GJx, curnit, XKS] = GOPT(@g, @gradg, @OPTSTEP_g, x0,1e-7, 10000);
    fprintf("g(x) en GOPT, n = %d, Nombre d'itérations est %d min, is = %f\n", curn, curnit, curJx);
end


for curn = n
    x0 = zeros(curn,1);
    [ x, curJx, GJx, curnit, XKS] = GCDYOPT(@g, @gradg, @OPTSTEP_g, x0, 1e-7, 10000);
    fprintf("g(x) GCDYOPT, n = %d, Nombre d'itérations est %d min, is = %f\n",curn, curnit, curJx);
end



[ x, curJx, GJx, curnit, XKS] = GOPT(@g, @gradg, @OPTSTEP_g,[0;0], 1e-7, 10000);

figure;



plot(XKS(1,:), XKS(2,:), 'o-');
hold on;

[ x, curJx, GJx, curnit, XKS] = GCDYOPT(@g, @gradg, @OPTSTEP_g, [0;0], 1e-7, 10000);

plot(XKS(1,:), XKS(2,:), 'x-');

title("Chemins pour minimisation de g(x) avec n = 2");
legend("GOPT", "GCDYOPT");
