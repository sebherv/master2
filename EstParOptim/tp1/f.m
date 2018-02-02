function [ fx ] = f( x )
%F retourne la valeur de la fonction f(x) = \sum_{i=1}^{n} (x_i - i)^2
n = length(x);
i = (1:n)';

fx = x - i;
fx = fx'*fx;

end

