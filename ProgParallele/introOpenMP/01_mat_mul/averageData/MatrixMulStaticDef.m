
ONE_THREAD = [100,0.01636481;
    200	0.102037;
    400	0.8610715];

TWO_THREADS = [100,	0.00660463;
    200	0.05158513;
    400	0.4306114];

THREE_THREADS = [100,	0.004466411;
    200	0.03503941;
    400	0.2950875];

FOUR_THREADS = [    100,	0.003368504;
    200,	0.02745959;
    400,	0.2315282];

hold on

plot(ONE_THREAD(:,1), ONE_THREAD(:,2), '-o')
plot(TWO_THREADS(:,1), TWO_THREADS(:,2), '-.o')
plot(THREE_THREADS(:,1), THREE_THREADS(:,2), '-o')
plot(FOUR_THREADS(:,1), FOUR_THREADS(:, 2), '-o')

title("Temps d'exécution en mode schedule(static)");

xlabel("Taille des cotés (matrices carrées)");
ylabel("Temps d'éxécution (s)");

legend("1 thread", "2 threads", "3 threads", "4 threads", "Location","northwest");

hold off