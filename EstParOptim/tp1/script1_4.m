% Gradient Ã  pas constant pour f et n=1
clear; close all;

pas = 0.1:0.1:5;
nit = [];
Jx = [];
X = [];

for curpas = pas
    [ x, curJx, GJx, curnit] = GCDYCST(@f, @gradf, [0;0], curpas, 1e-7, 10000);
    nit = [nit curnit];
    Jx = [Jx curJx];
    X = [X x];
end

plot(pas, nit, 'o-');
title("Gradiant Conjugué Pas Constant pour F(x) n = 2");
xlabel("Valeur du pas");
ylabel("Nombres d'itérations");
