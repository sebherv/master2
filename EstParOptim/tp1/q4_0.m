% Plot 2d rosenkrank

clear; %close all;

x = linspace(0.99, 1.01);
y = linspace(0.99, 1.01);
[X,Y] = meshgrid(x,y);

Z = (1-X).^2 + 100 .* (Y - X.^2).^2;

figure
surf(X,Y,Z);