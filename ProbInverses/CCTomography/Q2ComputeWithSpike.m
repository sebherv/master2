clear all;

% Computes spike with Nx = Ny = 7
Mtrue = generateSpike(7,7);

% Generate G for Nx = Ny = 7
G = computeG(7,7);

% Generate data from real model and G
d = generateDataFromModel(Mtrue, G);