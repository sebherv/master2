clear; close all;

% Configurer
% Gradient Ã  pas constant pour f et n=1
clear; close all;

pas = 1:5:100;
pas = [pas 64];
nit = [];
Jx = [];
X = [];

global Uobs;

nList = [5 10 50 100 500 1000 2000 5000 10000];
n = 50;
X = linspace(0,1,n+1)';
X = X(2:n); % remove first and last as 0 and 1 are to be excluded.
Uobs = uex(X);

F = 0 * X;

for curpas = pas
    [ x, curJx, GJx, curnit] = GCST(@J, @GJ, F, curpas, 1e-7, 10000);
    nit = [nit curnit];
    Jx = [Jx curJx];
    X = [X x];
end

plot(pas, nit, 'o-');
title("Gradiant à Pas Constant pour F(x) n = 1");
xlabel("Valeur du pas");
ylabel("Nombres d'itérations");

disp(Jx);