XYZ = dlmread('XYZ.txt',",");
x = XYZ(:,1);
y = XYZ(:,2);
z = XYZ(:,3);
n = length(x);
M = [sum(x.^2) sum(x.*y) sum(x);sum(x.*y) sum(y.^2) sum(y);sum(x) sum(y) n];
rhs = [sum(x.*z);sum(y.*z);sum(z)];
sol = pinv(M)*rhs;
sol
noisemat = [sol(1).*x + sol(2).*y + sol(3) - z];
noisevar = var(noisemat);
noisevar
