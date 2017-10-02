
STATIC_1000 = [
1,	0.009426836;
2,	0.01708146;
3,	0.02006975;
4,	0.0226979];

STATIC_10000 = [
1,	0.9391807;
2,	0.01708146;
3,	1.85773;
4,	2.130047];

STATIC_20000 = [
1,	3.770712;
2,	6.298532;
3,	7.424093;
4,	8.484127];

STATIC_40000 = [
1,	15.14889;
2,	25.14313;
3,	29.78717;
4,	33.94898];


hold on

plot(STATIC_1000(:,1), STATIC_1000(:,2), '-o')
plot(STATIC_10000(:,1), STATIC_10000(:,2), '-o')
plot(STATIC_20000(:,1), STATIC_20000(:,2), '-o')
plot(STATIC_40000(:,1), STATIC_40000(:, 2), '-o')


title({"Temps d'exécution en schedule(dynamic) avec"; "avec différentes tailles de liste"});

xlabel("Nombre de threads");
ylabel("Temps d'éxécution (s)");

legend("Taille Liste = 1000", "Taille Liste = 10000", "Taille Liste = 20000", "Taille Liste = 40000", "Location","northeast");

hold off