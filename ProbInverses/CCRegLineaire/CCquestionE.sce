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

// Diagonalize the covariance matrix
[u,lam]=spec(inv(Cm));

disp(u, "u =", "Eigen vectors for inv(Cm):");
disp(lam, "lam = ", "Eigen values for inv(Cm)");

theta = (0:0.01:2*%pi);
delta = sqrt(ChiSqNu2);

// M1 et M2
// calculate the x component of the ellipsoid for all angles
r(:,1)=(delta/sqrt(lam(1,1)))*u(1,1)*cos(theta)+(delta/sqrt(lam(2,2)))*u(1,2)*sin(theta);
// calculate the y component of the ellipsoid for all angles
r(:,2)=(delta/sqrt(lam(1,1)))*u(2,1)*cos(theta)+(delta/sqrt(lam(2,2)))*u(2,2)*sin(theta);

// plot(x,y) adding in the model parameters
scf(1)
xtitle("Ellipse de confiance à 95% entre m1 et m2", "m1 (m)", "m2 (m/s)");
plot(m(1)+r(:,1),m(2)+r(:,2));


// M1 et M3
// calculate the x component of the ellipsoid for all angles
r(:,1)=(delta/sqrt(lam(1,1)))*u(1,1)*cos(theta)+(delta/sqrt(lam(3,3)))*u(1,3)*sin(theta);
// calculate the y component of the ellipsoid for all angles
r(:,2)=(delta/sqrt(lam(1,1)))*u(3,1)*cos(theta)+(delta/sqrt(lam(3,3)))*u(3,3)*sin(theta);

scf(2)
xtitle("Ellipse de confiance à 95% entre m1 et m3", "m1 (m)", "m3 (m/s2)");
plot(m(1)+r(:,1),m(3)+r(:,2));

// M2 et M3
// calculate the x component of the ellipsoid for all angles
r(:,1)=(delta/sqrt(lam(2,2)))*u(2,2)*cos(theta)+(delta/sqrt(lam(3,3)))*u(2,3)*sin(theta);
// calculate the y component of the ellipsoid for all angles
r(:,2)=(delta/sqrt(lam(2,2)))*u(3,2)*cos(theta)+(delta/sqrt(lam(3,3)))*u(3,3)*sin(theta);

scf(3)
xtitle("Ellipse de confiance à 95% entre m2 et m3", "m2 (m/s)", "m3 (m/s2)");
plot(m(2)+r(:,1),m(3)+r(:,2));

// Save files
xs2pdf(1,"m1m2");
xs2pdf(2,"m1m3");
xs2pdf(3,"m2m3");
