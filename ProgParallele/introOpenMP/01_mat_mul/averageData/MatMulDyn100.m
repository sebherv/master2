
DYN_DEF = [
    1,	0.01242667;
2,	0.006299585;
3,	0.00437245;
4,	0.003381816];

DYN_5 = [
    1,	0.01246027;
2,	0.006413052;
3,	0.004621977;
4,	0.003381705];

DYN_10 = [
 1,	0.01289672;
2,	0.006389474;
3,	0.005294774;
4,	0.004060464   ];

DYN_50 = [
1,	0.01358559;
2,	0.006399691;
3,	0.006450659;
4,	0.006510568];



hold on

plot(DYN_DEF(:,1), DYN_DEF(:,2), '-o')
plot(DYN_5(:,1), DYN_5(:,2), '-.o')
plot(DYN_10(:,1), DYN_10(:,2), '-o')
plot(DYN_50(:,1), DYN_50(:, 2), '-o')

title({"Temps d'exécution en schedule(static) avec"; "différentes chunksizes sur des matrices 100 x 100"});

xlabel("Nombre de threads");
ylabel("Temps d'éxécution (s)");

legend("Chunksize Default", "Chunksize = 5", "Chunksize = 10", "Chunksize = 50", "Location","northeast");

hold off
