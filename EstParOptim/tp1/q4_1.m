% Gradient Ã  pas constant pour h (n=2)
clear; close all;

pas = 0.1:0.1:5;
nit = [];
Jx = [];
X = [];

for curpas = pas
    [ x, curJx, GJx, curnit] = GCST(@h, @gradh, [1.0001;1], curpas, 1e-7, 10000);
    nit = [nit curnit];
    Jx = [Jx curJx];
    X = [X x];
end

plot(pas, nit, 'o-');
title("Gradiant à Pas Constant pour h(x) n = 2");
xlabel("Valeur du pas");
ylabel("Nombres d'itérations");

disp(Jx); 