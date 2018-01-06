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
    gHeight = 2*Nx + 3*Ny;
    
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
    
    % then compute rays going diagonaly up (lenght is sqrt(2) frpm
    % left side
    sq2 = sqrt(2);
    
    memElem = zeros(0, Ny);
    for i = 1:Nx
        if i <= Ny
            elem = [zeros(1, i-1) sq2 zeros(1, Ny-i)];
        else 
            elem = zeros(1,Ny);
        end
        memElem = [elem; memElem];
        
        curMemElemSize = size(memElem);
        curMemElemSize = curMemElemSize(1);
        
        row = [];
        for j = 1:curMemElemSize
            row = [row memElem(j,:)]
        end
       
        curRowSize = size(row);
        row = [row zeros(1,gWidth-curRowSize(2))];
        G = [G;row];
    end
    
    % compute rays going diagonaly up from the bottom
    dimDiff = Ny - Nx;
    for i = 1:Ny
        if i <= dimDiff
            elem = [zeros(1, Nx + i) sq2 zeros(1, Ny-Nx-i)];
        else
            elem = zeros(1,Ny);
        end
        %Remove last line from memElem
        memElem(end,:) = [];
        memElem = [elem; memElem];
        
        curMemElemSize = size(memElem);
        curMemElemSize = curMemElemSize(1);
        
        row = [];
        for j = 1:curMemElemSize
            row = [row memElem(j,:)]
        end
       
        curRowSize = size(row);
        row = [row zeros(1,gWidth-curRowSize(2))];
        G = [G;row];
    end
    
end