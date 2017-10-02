
STATIC_1000 = [
   1,	0.002686895;
2,	0.001754106;
3,	0.001542067;
4,	0.0014929000 ];

STATIC_10000 = [
 1,	0.2542269;
2,	0.1259528;
3,	0.09324132;
4,	0.07382134   ];

STATIC_20000 = [
 1,	1.082684;
2,	0.5137698;
3,	0.3685886;
4,	0.286582   ];

STATIC_40000 = [
 1,	4.530167;
2,	2.186642;
3,	1.580458;
4,	1.1928450000   ];


hold on

plot(STATIC_1000(:,1), STATIC_1000(:,2), '-o')
plot(STATIC_10000(:,1), STATIC_10000(:,2), '-o')
plot(STATIC_20000(:,1), STATIC_20000(:,2), '-o')
plot(STATIC_40000(:,1), STATIC_40000(:, 2), '-o')


title({"Temps d'exécution en schedule(static) avec"; "avec différentes tailles de liste"});

xlabel("Nombre de threads");
ylabel("Temps d'éxécution (s)");

legend("Taille Liste = 1000", "Taille Liste = 10000", "Taille Liste = 20000", "Taille Liste = 40000", "Location","northeast");

hold off