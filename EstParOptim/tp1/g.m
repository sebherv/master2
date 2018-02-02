function [ gx ] = g( x )
%G 

n = length(x);
i = (1:n)';

gx = x - i;
gx = gx .* gx;
gx = gx ./ i;
gx = sum(gx);



end

