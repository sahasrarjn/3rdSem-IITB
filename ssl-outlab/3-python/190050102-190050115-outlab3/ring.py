class RingInt:
    def __init__(self, value, characteristic):
        self.characteristic = characteristic
        self.value = value%characteristic
        
    def __str__(self):
        return "{}[{}]".format(self.value, self.characteristic)
    
    def __add__(self, other):
        return RingInt((self.value + other.value)%self.characteristic, self.characteristic)
    
    def __sub__(self, other):
        return RingInt((self.value - other.value)%self.characteristic, self.characteristic)
    
    def __mul__(self, other):
        return RingInt((self.value * other.value)%self.characteristic, self.characteristic)
        
    def __truediv__(self, other):
        inv = self.__mod_inv(other.value, self.characteristic)
        if inv == -1:
            raise ValueError("UNDEFINED")
        r = RingInt( (inv * self.value) % self.characteristic , self.characteristic )
        return r

    def __pow__(self, other):
        if other >= 0:
            return RingInt((self.value ** other )%self.characteristic, self.characteristic)
        else:
            return RingInt(1, self.characteristic) / RingInt((self.value ** abs(other) )%self.characteristic, self.characteristic)
    
    def __eq__(self, other):
        if self.value == other.value and self.characteristic == other.characteristic:
            return True
        return False
 
    def __mod_inv(self, b, m):
        for i in range(m):
            if( (b*i)%m == 1):
                return i  
        return -1
