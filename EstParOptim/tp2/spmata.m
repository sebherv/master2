function [ A ] = spmata( n )
%SPMATA 

e = -ones(n,1);

B = [ e -2*e e];
d = [-1 0 1];

A = spdiags(B,d, n,n);

end

