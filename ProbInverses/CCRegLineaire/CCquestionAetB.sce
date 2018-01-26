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

disp(m, "Question b: Computed model m = ");

// Compute predicted data
dpred = G*m;

// Compute error vector
err = d-dpred;

// Compute misfit
misfit = err' * err;

// Compute Model covariance matrix
disp("Computing Model covariance matrix Cm = ");
Cm = inv(G'*G);

disp(Cm, "Question b: Model covariance matrix Cm =");

// Compute Model correlation matrix
disp("Computing Model correlation matrix...");

CorrM = correlationMatrix(Cm);
disp(CorrM, "Question b: Model correlation matrix CorrM =");

