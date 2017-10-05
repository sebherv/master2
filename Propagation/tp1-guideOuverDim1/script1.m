clear; close all;


H = 1;
rhop = 2;
rhom = 1;
w = 10;
n = 256;

e = ones(n-1,1);


% Exo 1: fixer H, faire varier Hmax
Hm=[1.1, 3, 5 ];

for hm = Hm

fprintf("Pour Hm = %f\n", hm);

h=hm*2/n;
h2 = h*h;
x=(-hm+h):h:hm-h;
x=x';
%x=x(2:n)';

middle=2*e/h2-w^2*rho(x,H,rhop,rhom);

A=spdiags([-e/h2, middle, -e/h2],-1:1, n-1, n-1);

opts.disp=0;
[U,D]=eigs(A, 3, -w^2*rhop,opts);

figure

hold on
plot(x, U(:,1));
plot(x,U(:,2));
plot(x,U(:,3));
hold off

disp(diag(D)');

end

% Fixer Hmax = 4, faire varier rhom
hm=4;

rhoMinuses = [1, 1.7, 1.9, 2.5];

for rhom = rhoMinuses

fprintf("Pour rhom = %f\n", rhom);

h=hm*2/n;
h2 = h*h;
x=(-hm+h):h:hm-h;
x=x';
%x=x(2:n)';

middle=2*e/h2-w^2*rho(x,H,rhop,rhom);

A=spdiags([-e/h2, middle, -e/h2],-1:1, n-1, n-1);

opts.disp=0;
[U,D]=eigs(A, 3, -w^2*rhop,opts);

disp(diag(D)');

figure

hold on
plot(x, U(:,1));
plot(x,U(:,2));
plot(x,U(:,3));
hold off;

disp(diag(D)');


end
