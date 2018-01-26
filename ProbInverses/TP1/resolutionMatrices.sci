function [Rm,Rd]=resolutionMatrices(G)
    // Compute Singular Value Decomposition
    [U,S,V]=svd(G);
    p=rank(G);
    
    // Truncate U,S and V to their non 0 vector
    Up=U(:, 1:p);
    Vp=V(:, 1:p);
    Sp=S(:, 1:p);
    
    // Calculate Rm
    Rm = Vp*Vp';
    
    // Calculate Rd
    Rd = Up*Up';
endfunction
