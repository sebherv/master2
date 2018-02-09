function [ V ] = adjoint( U )
%ADJOINT 
global Uobs;

rhs = U - Uobs;
V = direct(rhs);

end

