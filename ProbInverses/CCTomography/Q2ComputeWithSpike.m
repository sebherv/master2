clear all;

% Computes spike with Nx = Ny = 7
Mtrue = generateSpike(7,7);

% Generate G for Nx = Ny = 7
G = computeG(7,7);

% Generate data from real model and G
d = generateDataFromModel(Mtrue, G);

% Generate data with noise, sigma = 0.1, 0.5, 1.0
sigma = [0 0.1 0.5 1.0]

n = size(d);

for s = sigma
    dnoise = d + randn(n) * s;
    % Derive model from data
    mvect = computeModelFromData(dnoise,G);
    
    % Rebuild model from mvector
    m = rebuildModel(mvect, 7,7);

    fprintf("Computed model woth sigma = %f",s);
    disp(m);
end