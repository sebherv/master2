clear; close all;

sigmas = [0 0.1 0.5];
% Open file
I = imread('mario16x16.png');

Mtrue = double(I);
Mtrue = tripleBitmap(Mtrue);
[Ny, Nx] = size(Mtrue);

% Generate G for Nx = Ny = 7
G = computeG(Nx,Ny);

% Generate data from real model and G
d = generateDataFromModel(Mtrue, G);

n = size(d);
sigmasSize = size(sigmas);
maxSigmas = sigmasSize(2);

subplotHeight = (floor(maxSigmas/2+0.5));

randnoise = randn(n);

figure
curtitle = sprintf("Model Invader", Nx, Ny);
title(curtitle);


for i = 1: maxSigmas
    s= sigmas(i);
    dnoise = d + randnoise * s;
    % Derive model from data
    mvect = computeModelFromData(dnoise,G);
    
    % Rebuild model from mvector
    m = rebuildModel(mvect, Nx,Ny);

    curtitle = sprintf('Mest sigma = %.2f ', s);
    
    subplot(subplotHeight,2,i)
    
    image(m, 'CDataMapping', 'scaled');
    colorbar;
    title(curtitle)
    
end