# Enter your code here
import argparse
import os

parser = argparse.ArgumentParser()

parser.add_argument('-inp','--infile',help="input")
parser.add_argument('-out','--outfile',help="output")
args = parser.parse_args()

f = open(args.infile,"r")
lines = f.read().splitlines()
path = lines[0]

f.close()

canonpath = os.path.realpath(path)

f1 = open(args.outfile,'w')
f1.write(canonpath)
f1.close()


