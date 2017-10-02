
STATIC_DEF = [
1,	0.01852265;
2,	0.01310282;
3,	0.009708774;
4,	0.007807532   ];

STATIC_5 = [
1,	0.01789165;
2,	0.01346121;
3,	0.006921665;
4,	0.007354239   ];

STATIC_100 = [
1,	0.02020824;
2,	0.009362527;
3,	0.006248254;
4,	0.005493367   ];

STATIC_1000 = [
1,	0.02302132;
2,	0.009753738;
3,	0.007436638;
4,	0.006160412];

hold on

plot(STATIC_DEF(:,1), STATIC_DEF(:,2), '-o')
plot(STATIC_5(:,1), STATIC_5(:,2), '-.o')
plot(STATIC_100(:,1), STATIC_100(:,2), '-o')
plot(STATIC_1000(:,1), STATIC_1000(:,2), '-o')

title({"Temps d'exécution en schedule(static) avec"; "des chunksizes différents pour input = 10000"});

xlabel("Nombre de threads");
ylabel("Temps d'éxécution (s)");

legend("Chunksize = Def", "Chunksize = 5", "Chunksize = 100", "Chunksize = 1000", "Location","northeast");

hold off
