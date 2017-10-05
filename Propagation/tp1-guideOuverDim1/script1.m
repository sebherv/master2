H = 1;
rhop = 2;
rhom = 1;
w = 10;
n = 16;

e = ones(n-1,1);

%Hm=[1.1, 3, 5 ];

Hm=[1.1];

for hm = Hm

fprintf("Pour Hm = %f\n", hm);

h=hm/n;
h2 = h*h;
x=-hm:h:hm;x=x(2:n)';

middle=2*e/h2-w^2*rho(x,H,rhop,rhom);

A=spdiags([-e/h2, middle, -e/h2],-1:1, n-1, n-1);

opts.disp=0;
[U,D]=eigs(A, 3, -w^2*rhop,opts);


disp(diag(D)');

end