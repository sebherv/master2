
STATIC_DEF  = load("testrun-static.txt");
STATIC_5    = load("testrun-static-5.txt");
STATIC_10   = load("testrun-static-10.txt");
STATIC_50   = load("testrun-static-50.txt");

DYN_DEF     = load("testrun-dyn.txt");
DYN_5       = load("testrun-dyn-5.txt");
DYN_10      = load("testrun-dyn-10.txt");
DYN_50      = load("testrun-dyn-50.txt");

DISTINCT_SIZES = unique(STATIC_DEF(2,:));
DISTINCT_THREADS = unique(STATIC_DEF(1,:));

%Build matrices with average values
AV_STATIC_DEF = [];
for i = DISTINCT_SIZES
   for j = DISTINCT_THREADS
       rowsToKeep = STATIC_DEF(:,2)==i;
       tmp = STATIC_DEF(rowsToKeep, :);
       rowsToKeep = STATIC_DEF(:,1)==j;
       tmp = tmp(rowsToKeep, :);
       AV_STATIC_DEF = [AV_STATIC_DEF; mean(tmp(1,:)), j, i ]
   end
end

AV_STATIC_DEF 

