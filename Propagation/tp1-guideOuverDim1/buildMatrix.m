nfunction [ Aw ] = buildMatrix( n, H, Hm, rhop, rhom, w )
%BUILDMATRIX Build the Aw matrix

h = Hm / n;
h_2 = h*h;

xlim =  % index représentant la frontière entre rhop et rhom.

sides = ones(n-1) / (h*h);
x = linspace(-Hm,Hm,n);

middle;

for xi = x
    if abs(xi) > H
        current = 2/h_2 - w*w*rhom;
    else
        current = 2/h_2 - w*w*rhop;
    end
        
    middle = []
        
end


end

