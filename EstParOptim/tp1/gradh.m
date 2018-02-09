function [ gh ] = gradh( x )

x1 = x(1);
x2 = x(2);

gh1 = 2*(x1 - 1) + 400 * x1 *(x1^2 - x2);
gh2 = 200 * (x2 - x1^2);

gh = [gh1;gh2];

end

