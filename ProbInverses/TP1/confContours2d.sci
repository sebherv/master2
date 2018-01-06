// Code to plot confidence ellipse in 2D for 95% confidence interval
// mls = least square model esitmates
// covmls = least square covariance matrix (project for 2 dimensions)

// Diagonalize the covariance matrix
[u,lam]=spec()inv(covmls); // eig for matlab instead of spec

// generate a vector of angles for 0 to 2*pi
theta=(0:0.01:2*pi);

delta = sqrt(6.17);

// calculate the x component of the ellipsoid for all angles
r(:,1)=(delta/sqrt(lam(1,1)))*u(1,1)*cos(theta)+(delta/sqrt(lam(2,2)))*u(1,2)*sin(theta);
// calculate the y component of the ellipsoid for all angles
r(:,2)=(delta/sqrt(lam(1,1)))*u(2,1)*cos(theta)+delta/sqrt(lam(2,2)))*u(2,2)*sin(theta);

// plot(x,y) adding in the model parameters
plot(mls(1)+r(:,1),mls(2)+r(:,2))
