function [ U ] = direct( F )
%DIRECT Summary of this function goes here
%   Detailed explanation goes here

n = length(F) + 1;
h = 1/n;
A = spmata(n-1)/ (h*h);

U = A\F;

end

