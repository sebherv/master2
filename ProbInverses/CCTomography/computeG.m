% Compute matrix G based on a 2D model with height Nx and width Ny
% Rays go through first through
%   - each horizontal lines
%   - then through each vertical lines
%   - diagonaly up, starting from the left, then starting from the bottom
%   - diagonaly down, starting from the top, then from the left
%   - We assume unit size for each model element
function [G] = computeG(Nx, Ny )
    % Allocate the matrix, size will Nx * My columns (number of slowness values)
    % with Nx + Ny + Nx + 2*Ny rows.
    gWidth = Nx * Ny;
    gHeight = 2*Nx + 3*Ny - 1;
    
    G = zeros(0);
    
    % First compute rays going through the rows
    for i = 1:Nx
        row = [zeros(1,(i-1)*Ny) ones(1,Ny) zeros(1, (Nx-i)*Ny)];
        G = [G;row];
    end
    
    % then compute rays going throw colums
    for i = 1:Ny
        elem = [zeros(1,i-1) 1 zeros(1, Ny-i)];
        row = zeros(0);
        for j = 1:Nx
            row = [row elem];
        end
        G = [G;row];
    end
    
    % then compute rays going diagonaly up (lenght is sqrt(2) from
    % left side
    sq2 = sqrt(2);
    
    elem = [sq2 zeros(1,Ny-1)];
    memElem = [elem;zeros(Nx-1,Ny)];
    
    for i = 1:Nx
        if i ~= 1
            if i <= Ny
                elem = memElem(1,:);
                elem = [0 elem];
                elem(:,end) = [];
            else
                elem = zeros(1,Ny);
            end
            memElem = [elem; memElem];
            memElem(end,:) = [];
        end
        
        row = [];
        for j = 1:Nx
            row = [row memElem(j,:)];
        end
        G = [G;row];
    end
    
    % compute rays going diagonaly up right from the bottom
    % reuse memElem as these rays are nearly symetric to the
    % previous ones
    dimDiff = Ny - Nx + 1;
    for i = 2:Ny % Start from 2 because the first one is the
        if i <= dimDiff
            % add a zeros colum to the left
            % and remove right colum to the right
            memElem = [zeros(Nx,1) memElem];
            memElem(:,end) = [];
        else
            elem = zeros(1,Ny);
             %Remove last line from memElem
             memElem = [elem; memElem];
             memElem(end,:) = [];
        end
        
        row = [];
        for j = 1:Nx
            row = [row memElem(j,:)];
        end
       
        G = [G;row];
    end
    
    % compute rays going diagonaly down right from the top
    elem = [zeros(1,Ny-1) sq2];
    memElem = [elem;zeros(Nx - 1, Ny)];
    
    for i = 1:Ny
        if i ~= 1
            elem = memElem(1,:);
            elem = [elem 0];
            elem(:,1) = [];
            memElem(end,:) = [];
            memElem = [elem;memElem];
        end
        
        row = [];
        for j = 1:Nx
            row = [row memElem(j,:)];
        end
        G = [G;row];
    end
    
    %% compute rays going diagonaly down right from the left
    for i = 2 : Nx
        elem = zeros(1,Ny);
        memElem(end,:) = [];
        memElem = [elem;memElem];
        
        row = [];
        for j = 1:Nx
            row = [row memElem(j,:)];
        end
        G = [G;row];
    end
    
    
    
    
    
    
    
end