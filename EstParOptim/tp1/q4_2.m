% Gradient conjugué pour h (n=2)
clear; close all;

pas = 0.001:0.001:0.01 ;
nit = [];
GJx = [];
Jx = [];
X = [];

for curpas = pas
    [ x, curJx, curGJx, curnit] = GCDYCST(@h, @gradh, [1.0001;1], curpas, 1e-7, 10000);
    nit = [nit curnit];
    Jx = [Jx curJx];
    X = [X x];
    GJx = [GJx curGJx];
end

plot(pas, nit, 'o-');
title("Gradiant Conjugué pour h(x) n = 2");
xlabel("Valeur du pas");
ylabel("Nombres d'itérations");

disp(Jx); 