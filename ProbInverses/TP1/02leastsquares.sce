//clear all;

//load('d2.dat');

figure;
sigma = 8.0;
e=ones(20,1);
C=ones(1,20);
Ct=diag(C)/sigma;
x=linspace(1,10,20);
plot(X,d2,"ro");

// Problème inverse
MODELES=zeros(5,5);
y=zeros(20,5);


// Cas K = 0
//G=e
//m0 = inv(G'*Ct*G)*G'*Ct*d2;
//y0 = x*0+m0;

//(x, y0, "b")

// Cas K =1 , on cherche yi=a*xi/b (inconnues a et b)
G=[X e];
m1 = inv(G'*Ct*G)*G'*Ct*d2;
y1=m1(1)*x + m1(2);
Y1=m1(1)*X + m1(2);

plot(x,y1,"g");

// Cas K = 2
X2 = X.*X;
G=[X2 G];
m2 = inv(G'*Ct*G)*G'*Ct*d2;
y2=m2(1)*x^2 + m2(2)*x + m2(3);
Y2=m2(1)*X^2 + m2(2)*X+ m2(3);

plot(x,y2,"c");


// Cas K = 3
X3 = X2 .* X;
G=[X3 G];
m3 = inv(G'*Ct*G)*G'*Ct*d2;
y3=m3(1)*x^3 + m3(2)*x^2 + m3(3)*x + m3(4);
Y3=m3(1)*X^3 + m3(2)*X^2 + m3(3)*X + m3(4);

plot(x,y3, "m") 

// Cas K = 4
X4 = X3 .* X;
G=[X4 G];
m4 = inv(G'*Ct*G)*G'*Ct*d2;
y4 = m4(1)*x^4 + m4(2)*x^3 + m4(3)*x^2 + m4(4)*x + m4(5);
Y4 = m4(1)*X^4 + m4(2)*X^3 + m4(3)*X^2 + m4(4)*X + m4(5);

plot(x,y4, "b")


// Plot chi-squared
chi=zeros(4,1);

ytrue = 10+100*X-4.0*X^2

y1err = ((Y1 - ytrue)/sigma)^2;
y2err = ((Y2 - ytrue)/sigma)^2;
y3err = ((Y3 - ytrue)/sigma)^2;
y4err = ((Y4 - ytrue)/sigma)^2;

chi(1) = sum(y1err)/20;
chi(2) = sum(y2err)/20;
chi(3) = sum(y3err)/20;
chi(4) = sum(y4err)/20;

chi = chi/20

figure
plot([1;2;3;4],chi);



 

