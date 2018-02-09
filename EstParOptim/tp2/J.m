function [ Y ] = J( F )
% 

global Uobs;

h = 1 / (length(F)+1);
U = direct(F);

u = U -Uobs;
Y = h*u'*u;


end

