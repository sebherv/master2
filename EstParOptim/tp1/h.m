function [ hx ] = h( x )

x1 = x(1);
x2 = x(2);
hx = (1-x1)^2 + 100 * (x2 - x1^2)^2;

end