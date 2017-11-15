clear all;

rand("seed",123456);
rand("uniform");

X=rand(20,1);
X=1 + X*(10-1);

rand("654321");
rand("normal");

// Générer le bruit
epsilon=rand(20,1);
epsilon=epsilon*8.0;

d1true=10 + 100*X;
d1 = d1true + epsilon;

d2true = 10+100*X - 4.9*X^2;
d2= d2true + epsilon;


// Save d1
save("d1.dat", "X", "d1");

// Save d2
save("d2.dat", "X", "d2");

plot(X,d1, 'ro')
plot(X,d1true, 'r-')


plot(X,d2, 'go')
plot(X,d2true, 'g-')

// Least square misfit
d1err = d1true - d1;
d2err = d2true - d2;
d1mf = d1err'*d1err;
d2mf = d2err'*d2err;

printf("Misfit for d1 is %f\n", d1mf);
printf("Misfit for d2 is %f\n", d2mf);
