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
disp("Computing predicted data");
dpred = G*m;

// Compute error vector
err = d-dpred;

// Compute misfit
misfit = (err' * err)/n;

disp(misfit, "Question h: misfit is: ");


// Misfit with sigma = 0.5m
errSigma05 = err ./ 0.5;
mfSigma05 = (errSigma05'*errSigma05)/n;
disp(mfSigma05, "Question j: Misfit avec sigma = 0.5 m: ");


// Misfit with sigma = 800m
errSigma800 = err / 800;
mfSigma800 = (errSigma800'*errSigma800)/n;
disp(mfSigma800, "Question k: Misfit avec sigma = 800m:");




