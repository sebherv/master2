% Gradient à pas constant pour f

pas = 0.1:0.1:5;
nit = [];
Jx = [];
for curpas = pas
    [ x, curJx, GJx, curnit] = GCST(@f, @gradf, 0, curpas, 1e-7, 10000);
    nit = [nit curnit];
    Jx = [Jx curJx];
end

plot(pas, nit, 'o-');