function [ r ] = rho( x, H, rhop, rhom )
%RHO 
r=rhom*ones(size(x));
r(abs(x)<H) = rhop;

