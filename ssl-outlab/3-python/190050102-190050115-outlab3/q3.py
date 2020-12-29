import argparse
from collections import Counter

parser = argparse.ArgumentParser()

parser.add_argument("-ca", "--candies", help="Candies file")
parser.add_argument("-ch", "--children",  help="Chinldren file")
args = parser.parse_args()

f =  open(args.candies, "r")

m = f.readline()

candies=[]
for line in f.readlines():
    for word in line.split():
        candies.append(int(word))
        
candies = Counter(candies)

f = open(args.children, "r")
n = f.readline()

children = []
for line in f.readlines():
    children.append( [int(line.split()[0]), int(line.split()[1])] )

children.sort(reverse=True)

ans=0
for child in children:
    if(candies[ child[0] ] != 0):
        candies[ child[0] ] -= 1
        ans += child[1]
        
print(ans)