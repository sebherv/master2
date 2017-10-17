clear all; close all;

X=load("localRun.txt");

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

rowsToKeep = X(:,2)==500;
X500 = X(rowsToKeep, :);
plot(X500(:,1), X500(:,3));

title({"Temps total d'exécution en mode Local"; "avec différents nombre d'échanges"});
xlabel("N");
ylabel("Temps d'éxécution (s)");

legend("M=10", "M=50", "M=100", "M=500","Location","northeast");

hold off

saveas(gcf,'ExecTimeLocal1','epsc')

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


title({"Bitrate en fonction de la taille des messages en mode Local"});
xlabel("N");
ylabel("Bitrate (floats / s)");

legend("M=10", "M=50", "M=100", "M=500","Location","northwest");

hold off
saveas(gcf,'BitrateLocal','epsc')
