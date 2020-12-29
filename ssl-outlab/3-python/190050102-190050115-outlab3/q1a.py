import argparse
from ring import *

def sum1(k, x):
    sm = RingInt(0, k.characteristic)
    x_pow = RingInt(1, k.characteristic)
    fact = RingInt(1, k.characteristic)
    i = RingInt(1, k.characteristic)
    one = RingInt(1, k.characteristic)
    # zero = RingInt(0, k.characteristic)
    
    for j in range(k.value):
        temp = x_pow/fact
        sm = sm + temp
        x_pow = x_pow * x
        fact = fact * i
        i = i + one
    return sm


def sum2(k, x):
    fact = []
    i = RingInt(1, k.characteristic)
    fact_0 = RingInt(1, k.characteristic)
    fact.append(fact_0)
    one = RingInt(1, k.characteristic)
    
    for j in range(1, x.value+k.value+1):
        fact.append( fact[j-1] * i )
        i = i + one
    
    prod = RingInt(1, x.characteristic)
    for a in range(k.value):
        sm = RingInt(0, x.characteristic)
        for b in range(a+1):
            try :
                if x.value + a == 0:
                    raise ValueError
                sm = sm + fact[x.value + a]/(fact[b]*fact[x.value + a - b])
            except: 
                return "UNDEFINED"
        prod = prod * sm
        
    return prod
    

def sum3(k, x):
    sm = RingInt(0, k.characteristic)
    i = RingInt(1, k.characteristic)
    one = RingInt(1, k.characteristic)
    
    for j in range(k.value):
        sm += i ** x
        
        i = i + one
    
    return sm


parser = argparse.ArgumentParser()
parser.add_argument("-inp", "--input", help="Input File")
parser.add_argument("-out", "--output", help="Output File")
args = parser.parse_args()

in_file = open(args.input, "r")
out_file = open(args.output, "w")

for line in in_file.read().splitlines():
    a, b, m, sm = [int(i) for i in line.split()]
    k = RingInt(a, m)
    if sm != 3:
        x = RingInt(b, m)
    else:
        x = b
    
    if sm==1:
        try:
            res = sum1(k, x)
            res =  str(res)
            out_file.write(res + "\n")
        except ValueError:
            out_file.write("UNDEFINED" + "\n")
    elif sm==2:
        try:
            res = sum2(k, x)
            res =  str(res)
            out_file.write(res + "\n")
        except ValueError:
            out_file.write("UNDEFINED"+"\n")
    elif sm==3:
        try:
            res = sum3(k, x)
            res =  str(res)
            out_file.write(res + "\n")
        except ValueError:
            out_file.write("UNDEFINED"+"\n")
        
