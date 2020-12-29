from ring import *

class Series:
    def __init__(self, k, x, n):
        self.k = RingInt(int(k), int(n))
        self.x = RingInt(int(x), int(n))
        self.n = int(n)
        
        self.x_pow = RingInt(1, self.n)
        self.fact = RingInt(1, self.n)
        self.i = RingInt(1, self.n)
        self.one = RingInt(1, self.n)
        self.zero = RingInt(0, self.n)
        self.term = self.x_pow/self.fact
        
    def __str__(self):
        return "{}".format(self.term)
        
    def __iter__(self):
        return self
    
    def __next__(self):
        if(self.i == ( self.k + self.one )):
            raise StopIteration
        else:
            self.term = self.x_pow/self.fact
            self.x_pow = self.x_pow * self.x
            self.fact = self.fact * self.i
            self.i = self.i + self.one
            
            return self



def main():

	in_str = str(input())
	in_list = in_str.split(' ')
	k, x, n = in_list[0], in_list[1], in_list[2]
	
	for ele in Series(k, x, n):
		print(ele)


if __name__=="__main__":
	main()

