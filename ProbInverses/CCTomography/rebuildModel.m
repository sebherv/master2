function [ m ] = rebuildModel( mvect, Nx, Ny )
m=reshape(mvect', Nx, Ny);
end