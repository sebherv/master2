function [ m ] = rebuildModel( mvect, Nx, Ny )
%m=reshape(mvect, Nx, Ny);
m=zeros(0,Ny);
for i = 1 : Nx
    m = [m;mvect(1+(i-1)*Ny: i*Ny)'];
end
end