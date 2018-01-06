clear;
getd();

// Get data from file
disp("Loading ballistic data file...");
DATA=fscanfMat('BallisticsDataFile.txt');

d=DATA(:,2);
t=DATA(:,1);

// Create G from the time data
disp("Creating matrix G...");
n=size(t)(1);
G=ones(n,1);
G=[G t -0.5*t^2];

// Compute model
disp("Computing model...");
m=inv(G'*G)*G'*d;

// Compute Model covariance matrix
disp("Computing Model covariance matrix...");
Cm = inv(G'*G);

// Chi Squared for different nu's at p = 95%
ChiSqNu1 = 3.96;
ChiSqNu2 = 5.99;
ChiSqNu3 = 7.81;

disp("Computing Confidence Interval for Chi Squared for 1 degre of liberty, at p=95%")
deltaM_Nu1 = sqrt(ChiSqNu1 * diag(Cm));
disp(deltaM_Nu1, "deltaM_Nu1 =","Question c: delta M for nu = 1;");


disp("Computing Confidence Interval for Chi Squared for 2 degre of liberty, at p=95%")
deltaM_Nu2 = sqrt(ChiSqNu2 * diag(Cm));
disp(deltaM_Nu2, "deltaM_Nu2 =","Question c: delta M for nu = 2;");
