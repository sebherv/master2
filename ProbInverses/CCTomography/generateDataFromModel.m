function [ d ] = generateDataFromModel( Mtrue, G )
% Generates data vector d from model Mtrue and G

% first put all lines into a single
Mrowed = [];
[w h] = size(Mtrue);
for i = 1 : h
    Mrowed = [Mrowed Mtrue(i,:)];
end

d = G * Mrowed';

end

