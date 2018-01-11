function [ triple ] = tripleBitmap( im )
%TRIPLEBITMAP Returns an image with 3x3 pixels blocks
[w h] = size(im);
triple = zeros(0,w*3);
for i = 1 : h
    row = [];
    for j = 1 : w
        % build pixel
        pixel = [im(i,j) im(i,j) im(i,j)];
        pixel = [pixel;pixel;pixel];
        row = [row pixel];
    end
    triple = [triple;row]
end
end

