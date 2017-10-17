% Calculates the figures for use in the report

% First generate rounduptime according to size and repeat times
X=load("realRemoteRun.txt");

figure;
hold on;
rowsToKeep = X(:,2)==10;
X10 = X(rowsToKeep, :);
plot(X10(:,1), X10(:,3));

rowsToKeep = X(:,2)==50;
X50 = X(rowsToKeep, :);
plot(X50(:,1), X50(:,3));

rowsToKeep = X(:,2)==100;
X100 = X(rowsToKeep, :);
plot(X100(:,1), X100(:,3));

title({"Temps total d'exécution en mode Distant"; "avec différents nombre d'échanges 1/2"});
xlabel("N");
ylabel("Temps d'éxécution (s)");

legend("M=10", "M=50", "M=100", "Location","northeast");

hold off
saveas(gcf,'ExecTimeRemote1','epsc')

figure

hold on

rowsToKeep = X(:,2)==500;
X500 = X(rowsToKeep, :);
plot(X500(:,1), X500(:,3));

rowsToKeep = X(:,2)==1000;
X1000 = X(rowsToKeep, :);
plot(X1000(:,1), X1000(:,3));

rowsToKeep = X(:,2)==5000;
X5000 = X(rowsToKeep, :);
plot(X5000(:,1), X5000(:,3));

title({"Temps total d'exécution en mode Distant"; "avec différents nombre d'échanges 2/2"});
xlabel("N");
ylabel("Temps d'éxécution (s)");

legend("M=500", "M=1000", "M=5000", "Location","northeast");

hold off;

saveas(gcf,'ExecTimeRemote2','epsc')


% Calculate Bitrates

figure
hold on
B10(:,1) = X10(:,1);
B10(:,2) = X10(:,1) .* X10(:,2) ./ X10(:,3);
plot(B10(:,1),B10(:,2));

B50(:,1) = X50(:,1);
B50(:,2) = X50(:,1) .* X50(:,2) ./ X50(:,3);
plot(B50(:,1),B50(:,2));

B100(:,1) = X100(:,1);
B100(:,2) = X100(:,1) .* X100(:,2) ./ X100(:,3);
plot(B100(:,1),B100(:,2));

B500(:,1) = X500(:,1);
B500(:,2) = X500(:,1) .* X500(:,2) ./ X500(:,3);
plot(B500(:,1),B500(:,2));

B1000(:,1) = X1000(:,1);
B1000(:,2) = X1000(:,1) .* X1000(:,2) ./ X1000(:,3);
plot(B1000(:,1),B1000(:,2));

%B5000(:,1) = X5000(:,1);
%B5000(:,2) = X5000(:,1) .* X5000(:,2) ./ X5000(:,3);
%plot(B5000(:,1),B5000(:,2));

title({"Bitrate en fonction de la taille des messages en mode Distant"});
xlabel("N");
ylabel("Bitrate (floats / s)");

legend("M=10", "M=50", "M=50", "M=500", "M=1000","Location","southeast");

hold off
saveas(gcf,'BitrateRemote','epsc')