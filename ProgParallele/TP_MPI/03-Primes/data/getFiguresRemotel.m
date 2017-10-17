clear; close all;

X=load("remoteRun.txt");


figure
hold on
rowsToKeep = X(:,3)==100;
XBlock = X(rowsToKeep, :);
plot(XBlock(:,1), XBlock(:,4), 'o-');

rowsToKeep = X(:,3)==101;
XCyclic = X(rowsToKeep, :);
plot(XCyclic(:,1), XCyclic(:,4), 'o-');

hold off

title("Temps total d'ex�cution en mode Distant");
xlabel("N");
ylabel("Temps d'�x�cution (s)");

legend("Mode Block", "Mode Cyclic","Location","northwest");

saveas(gcf,'ExecTimeRemote','epsc')