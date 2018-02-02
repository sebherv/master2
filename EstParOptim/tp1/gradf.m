function [ gf ] = gradf( x )
%GRADF 

n = length(x);
i = (1:n)';

gf = x - i;
gf = 2*gf;

end

