import random

n = 100000
m = 100000
op = 0

print(n, m, op)
for i in range(m):
    a = random.randrange(0,n-1);
    b = random.randrange(0,n-1);
    if a == b:
        if a == 0:
            b += 1
        else:
            b -= 1;
            
    print(a, b)