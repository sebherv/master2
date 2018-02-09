
clear; close all;

x0 = 0 : 0.1 : 5;
nit = [];
Jx = [];
X = [];

for curxo = x0
    [ x, curJx, GJx, curnit, RKS] = GOPT(@h, @gradh, @OPTSTEP_h, [curxo;curxo], 1e-7, 10000);
    nit = [nit curnit];
    Jx = [Jx curJx];
    X = [X x];
end


plot(x0, nit, 'o-');
title("Gradiant Pas Optimal pour h(x) (n = 2)");
xlabel("Valeur de (x0,x0)");
ylabel("Nombre d'itérations");