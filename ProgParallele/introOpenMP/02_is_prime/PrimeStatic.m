
STATIC_1000 = [
1,	0.00028652;
2,	0.000510691;
3,	0.000381365;
4,	0.000293136    ];

STATIC_10000 = [
 1,	0.01852265;
2,	0.01310282;
3,	0.009708774;
4,	0.007807532   ];

STATIC_100000 = [
 1,	1.409538;
2,	0.7166681;
3,	0.4924106;
4,	0.387403   ];

hold on

plot(STATIC_1000(:,1), STATIC_1000(:,2), '-o')
plot(STATIC_10000(:,1), STATIC_10000(:,2), '-.o')
%plot(STATIC_100000(:,1), STATIC_100000(:,2), '-o')

title({"Temps d'exécution en schedule(static) avec"; "chunksize par défaut."});

xlabel("Nombre de threads");
ylabel("Temps d'éxécution (s)");

legend("Input = 1000", "Input = 10000", "Location","northeast");

hold off
