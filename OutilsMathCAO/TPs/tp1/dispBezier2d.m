system('./a.out');

BOX=load("contpoints.dat");
RES=load("bezier_result.dat");

%Transpose
BOX=BOX.';

figure
hold on
plot(BOX(:,1), BOX(:,2))
plot(RES(:,1), RES(:,2))
hold off