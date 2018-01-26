function [ m ] = computeModelFromData( d, G )
% Compute model from the data d and resolution matrix G

% Calculer Gg
Gg=pinv(G);


% Calculer le mod�le
m=Gg*d;


end

