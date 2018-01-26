function [ Rd, Rm ] = computeResolutionMatrices( G )

% Perform SVD
[U,S,V] = svd(G);

% Calculer Up, Vp , Sp
p=rank(G);
Vp=V(:,1:p);
Up=U(:,1:p);
Sp=S(:,1:p);

% Calculer Rm;
Rm=Vp*Vp';

% Calculer Rd;
Rd=Up*Up';

end

