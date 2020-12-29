y = [];
sum = 0;

for i=1:10000
    sum = sum+ 1/i;
    y =[y sum*i];
end
x = 1:10000;
plot(x,y);
title('E(X^{(n)}) vs n');
xlabel('n');
ylabel('E(X^{(n)})');

grid on
