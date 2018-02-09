clear; close all;
nList = [5 10 50 100 500 1000 2000 5000 10000];

global Uex;
hList = 1./nList;
errList = [];
figure;
hold on;
for n = nList
    X = linspace(0,1,n+1)';
    X = X(2:n); % remove first and last as 0 and 1 are to be excluded.

    F = f2(X);
    U = direct(F);
    
    Uex = uex(X);
    V = adjoint(U);
    
    Vex = uex(X);
    
    err = norm(V-Vex)/norm(Vex);
    errList = [errList err];
    
    plot(X, V);
    
end

figure;

loglog(hList, errList, 'o-');
grid on;
title("Erreur en fonction de h");
xlabel("h");
ylabel("err");


ordre = polyfit(log10(hList), log10(errList), 1);

disp("Ordre de convergence:");
disp(ordre(1));