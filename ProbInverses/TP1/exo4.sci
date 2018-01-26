// Exo 4: plotting and projecting confidence regions

// Gen data et gen modèle
// Our model is m2 (with 3 parameters), our Cm is inv(G2'*G2)
exec('/Users/sebh/Desktop/MasterII/repos_master2/ProbInverses/TP1/01genTestDistribs.sce',-1);
exec('/Users/sebh/Desktop/MasterII/repos_master2/ProbInverses/TP1/02leastsquares.sce',-1);


Cm = inv(G2'*Ct*G2);

covmls=correlationMatrix(Cm)

ins1D=sqrt(4)*sqrt(diag(Cm))

// Calcul des ellipses à 95% pour 3 paramètres
