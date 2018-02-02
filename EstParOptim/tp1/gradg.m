function [ gg ] = gradg( x )
%GRADG 

n = length(x);
i = (1:n)';

gg = x - i;
gg = 2*gg ./ i;

end

