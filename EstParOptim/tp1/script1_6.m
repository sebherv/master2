% Gradient à  pas constant pour s
clear; close all;

pas = 0.01;
x0 = 0 : 0.01 : 4;
nit = [];
Jx = [];
X = [];

for curxo = x0
    [ x, curJx, GJx, curnit] = GCST(@s, @grads, curxo, pas, 1e-7, 10000);
    nit = [nit curnit];
    Jx = [Jx curJx];
    X = [X x];
end

plot(x0, X, '-');
title("Gradiant  Pas Constant pour s(x)");
xlabel("Valeur de x0");
ylabel("Valeur de x minimisé trouvée");
