import re
import argparse
from ring import *

parser = argparse.ArgumentParser()

parser.add_argument("-m", "--message", help="Message file")
args = parser.parse_args()

def check(s, n):
    seqs = re.findall("\([-?\d\,]+\)",s)
    a = []
    b = []
    
    a = re.findall("\d+", seqs[0])
    b = re.findall("\d+", seqs[1])
    
    sum_a = 0
    for i in range(len(a)):
        if int(a[i]) < 0 or int(a[i]) > n:
            return False
        sum_a += (i+1)*int(a[i])
    
    sum_b = 0
    for i in range(len(b)):
        if int(b[i]) < 0 or int(b[i]) > n:
            return False
        sum_b += (i+1)*int(b[i])
        
    return sum_a%n == sum_b%n
    


file = open(args.message, "r")
n = file.readline()

message = file.readline()

codes = re.findall("\$\([-?\d\,]+\)\#\([-?\d\,]+\)\$", message)

corrup = False
for code in codes:
    if not check(code, int(n)):
        corrup = True
        
if corrup:
    print("CORRUPTED")
else:
    print("OK")
        