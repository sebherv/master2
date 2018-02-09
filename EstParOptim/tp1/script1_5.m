% Gradient Ã  pas constant pour g et n=2
clear; close all;

pas = 0.1:0.1:5;
nitConst = [];
nitConj = [];
Jx = [];
X = [];

for curpas = pas
    [ x, curJx, GJx, curnit] = GCST(@g, @gradg, [0;0], curpas, 1e-7, 10000);
    nitConst = [nitConst curnit];
    
    [ x, curJx, GJx, curnit] = GCDYCST(@g, @gradg, [0;0], curpas, 1e-7, 10000);
    nitConj = [nitConj curnit];
end

hold on
plot(pas, nitConst, 'o-');
plot(pas, nitConj, 'x-');
title("Méthode de gradiant pour g(x) n = 2");
xlabel("Valeur du pas");
ylabel("Nombres d'itérations");

legend("GCST", "GCDYCST");
hold off;
