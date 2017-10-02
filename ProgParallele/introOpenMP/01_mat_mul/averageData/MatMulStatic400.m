
STATIC_DEF = [1,	0.8610715;
2,	0.4306114;
3,	0.2950875;
4,	0.2315282];

STATIC_5 = [
1,	0.858811778;
2,	0.428772667;
3,	0.297134667;
4,	0.229946778];

STATIC_10 = [
1,	0.8625685;
2,	0.4331885;
3,	0.3096847;
4,	0.2338287];

STATIC_50 = [
   1,	0.8714649;
2,	0.4371083;
3,	0.333092;
4,	0.2317762 ];

hold on

plot(STATIC_DEF(:,1), STATIC_DEF(:,2), '-o')
plot(STATIC_5(:,1), STATIC_5(:,2), '-.o')
plot(STATIC_10(:,1), STATIC_10(:,2), '-o')
plot(STATIC_50(:,1), STATIC_50(:, 2), '-o')

title({"Temps d'exécution en schedule(static) avec"; "différentes chunksizes sur des matrices 400 x 400"});

xlabel("Nombre de threads");
ylabel("Temps d'éxécution (s)");

legend("Chunksize Default", "Chunksize = 5", "Chunksize = 10", "Chunksize = 50", "Location","northeast");

hold off