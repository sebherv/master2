function [ G ] = GJ( F )
% Gradient de J en F

U = direct(F);
G = adjoint(U);

end

