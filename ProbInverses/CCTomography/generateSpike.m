function [S] = generateSpike( Nx, Ny )
% Generates a spike model with size Nx and Ny
S = zeros(Nx, Ny);
S(floor(Nx/2+1), floor(Ny/2+1)) = 1;
end

