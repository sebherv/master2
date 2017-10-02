
STATIC_DEF = [
1,	0.01797755;
2,	0.009073753;
3,	0.006196186;
4,	0.005039349];

STATIC_5 = [
1,	0.01790111;
2,	0.009046192;
3,	0.006174491;
4,	0.004888017];

STATIC_100 = [
1,	0.01788626;
2,	0.00904607;
3,	0.006240392;
4,	0.005164962   ];

STATIC_1000 = [
1,	0.01851505;
2,	0.009741657;
3,	0.007437513;
4,	0.006431802];

hold on

plot(STATIC_DEF(:,1), STATIC_DEF(:,2), '-o')
plot(STATIC_5(:,1), STATIC_5(:,2), '-.o')
plot(STATIC_100(:,1), STATIC_100(:,2), '-o')
plot(STATIC_1000(:,1), STATIC_1000(:,2), '-o')

title({"Temps d'exécution en schedule(dynamic) avec"; "des chunksizes différents pour input = 10000"});

xlabel("Nombre de threads");
ylabel("Temps d'éxécution (s)");

legend("Chunksize = Def", "Chunksize = 5", "Chunksize = 100", "Chunksize = 1000", "Location","northeast");

hold off
