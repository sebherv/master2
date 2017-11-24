
figure;
sigma = 8.0;
e=ones(20,1);
C=ones(1,20);
Ct=diag(C)/sigma;
x=linspace(1,10,20);
plot(X,d2,"ro");

//K=1
G=e;

for K=0:4
    if K > 1
        G=[G X.^(K-1)]
    end
    m=inv(G'*Ct*G)*G'*Ct*d2;
    ymod=m' *X.^K
    
end