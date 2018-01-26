function [ gf ] = gradf( x )
%GRADF 

[n m] = size(x);
i = 1:n;

gf = x - i';
gf = 2*gf;

end

