// Définition de G
G=[1,0,0;0,.5,.5];
d=[3;4.5]

// SVD
[U,S,V]=svd(G);

// Calculer Up, Vp, Sp
p=rank(G);
Vp=V(:,1:p);
Up=U(:,1:p);
Sp=S(:,1:p);

// Calculer Rm;
Rm=Vp*Vp';

// Calculer Rd;
Rd=Up*Up';

// Calculer Gg
Ggpen=pinv(G);
Ggcalc=Vp*inv(Sp)*Up';

// Calculer le modèle
M=Gg*d;

// Prédire les données


