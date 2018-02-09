
clear; close all;

x0 = 0.99 : 0.001 :1.01;
nit = [];
Jx = [];
GJx = [];
X = [];

for curxo = x0
    [ x, curJx, curGJx, curnit, RKS] = GCDYOPT(@h, @gradh, @OPTSTEP_h, [curxo;curxo], 1e-7, 10000);
    nit = [nit curnit];
    GJx = [GJx curGJx];
    Jx = [Jx curJx];
    X = [X x];
end


plot(x0, nit, 'o-');
title("Gradiant Conjugué à pas Optimal pour h(x) (n = 2)");
xlabel("Valeur de (x0,x0)");
ylabel("Nombre d'itérations");