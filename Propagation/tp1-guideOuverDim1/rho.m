function [ result ] = rho( x, H, rhop, rhom )
%RHO 

if abs(x) > H
    result = rhom;
else
    result = rhop;
end
