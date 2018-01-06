function [CorrM]=correlationMatrix(Cm)
    vector_sigma_sqrt = sqrt(diag(Cm));
    sigma_sqrt=repmat(vector_sigma_sqrt, 1, size(vector_sigma_sqrt)(1));
    CorrM = Cm ./ sigma_sqrt;
    
    CorrM = CorrM' ./ sigma_sqrt;
    
    CorrM = CorrM';
endfunction
