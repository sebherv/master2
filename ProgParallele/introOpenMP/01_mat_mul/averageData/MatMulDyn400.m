
DYN_DEF = [
    1,	0.8555228;
2,	0.4323407;
3,	0.2984442;
4,	0.2330862];

DYN_5 = [
1,	0.8587452;
2,	0.4375623;
3,	0.3020772;
4,	0.2331177];

DYN_10 = [
1,	0.8711925;
2,	0.4424008;
3,	0.3147905;
4,	0.2397];

DYN_50 = [
1,	0.8554045;
2,	0.435508;
3,	0.3328175;
4,	0.2343009];



hold on

plot(DYN_DEF(:,1), DYN_DEF(:,2), '-o')
plot(DYN_5(:,1), DYN_5(:,2), '-.o')
plot(DYN_10(:,1), DYN_10(:,2), '-o')
plot(DYN_50(:,1), DYN_50(:, 2), '-o')

title({"Temps d'exécution en schedule(dynamic) avec"; "différentes chunksizes sur des matrices 400 x 400"});

xlabel("Nombre de threads");
ylabel("Temps d'éxécution (s)");

legend("Chunksize Default", "Chunksize = 5", "Chunksize = 10", "Chunksize = 50", "Location","northeast");

hold off
