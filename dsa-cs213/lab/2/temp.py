# Python3 implementation of the approach  
from random import randint

fh = open('input','w')
n=randint(5, 100000)
k=randint(2, 100)

def randomList(m, n):  
  
    # Create an array of size m where  
    # every element is initialized to 0  
    arr = [0] * m  
      
    # To make the sum of the final list as n  
    for i in range(n) : 
  
        # Increment any random element  
        # from the array by 1  
        arr[randint(0, n) % m] += 1
  
    # Print the generated list  
    return arr

fh.write(str(n)+" "+str(k)+"\n")
arr = randomList(k,n)
for item in arr:
	fh.write(str(item)+" ")
