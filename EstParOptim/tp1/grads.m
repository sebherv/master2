function [ gs ] = grads( x )
%GRADS Summary of this function goes here
%   Detailed explanation goes here

gs = 2*(x-1) + 4*pi*cos(4*pi*(x-(9/8)));

end

