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
misfit = err' * err;

a=[2,4,10,20,50,100,200,400,800];
for v=a, errSig = err/v;,disp([v, (errSig'*errSig)/n]),  end

