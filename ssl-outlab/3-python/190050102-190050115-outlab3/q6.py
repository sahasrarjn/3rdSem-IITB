# Enter your code here
import functools

def collapse(L):
    	if type(L) is list:
		s1 = list(map(collapse,L))
		k = functools.reduce(lambda a,b :a+' '+b,s1)
		return k
	elif type(L) is str:
		return L
