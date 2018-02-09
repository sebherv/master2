% Gradient � pas constant optimal pour f et g
clear; close all;


x0 = 0 : 0.1 : 4;
nit = [];
Jx = [];
X = [];

for curxo = x0
    [ x, curJx, GJx, curnit, RKS] = GCDYOPT(@f, @gradf, @OPTSTEP_f, curxo, 1e-7, 10000);
    nit = [nit curnit];
    Jx = [Jx curJx];
    X = [X x];
end

figure;
subplot(3,1,1);
plot(x0, nit, 'o-');
title("Gradiant Conjugu� Pas Optimal pour f(x) pour n = 1");
xlabel("Valeur de x0");
ylabel("Nombre d'it�rations");


nit = [];
Jx = [];
X = [];
for curxo = x0
    [ x, curJx, GJx, curnit, RKS] = GCDYOPT(@g, @gradg, @OPTSTEP_g, curxo, 1e-7, 10000);
    nit = [nit curnit];
    Jx = [Jx curJx];
    X = [X x];
end

subplot(3,1,2);
plot(x0, nit, 'o-');
title("Gradiant Conjugu� Pas Optimal pour g(x) pour n = 1");
xlabel("Valeur de x0");
ylabel("Nombre d'it�rations");



x0 = 0 : 0.1 : 4;
nit = [];
Jx = [];
X = [];

for curxo = x0
    [ x, curJx, GJx, curnit, RKS] = GCDYOPT(@f, @gradf, @OPTSTEP_f, [curxo;curxo], 1e-7, 10000);
    nit = [nit curnit];
    Jx = [Jx curJx];
    X = [X x];
end

subplot(3,1,3);
plot(x0, nit, 'o-');
title("Gradiant Conjugu� Pas Optimal pour f(x) pour n = 2");
xlabel("Valeur de (x0,x0)");
ylabel("Nombre d'it�rations");




