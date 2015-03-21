class RGB:
    def __init__(self, r=0, g=0, b=0):
        self.r = r
        self.g = g
        self.b = b

    #COMPARATORS
    def __eq__(self, other):
        if (self.r == other.r and self.g == other.g and self.b == other.b):
                return True
        return False
        
    def __ne__(self, other):
        if (self == other):
                return False
        return True
    
    def __lt__(self, other):
        raise NotImplementedError("RGB: __lt__ Operator")
    
    def __le__(self, other):
        raise NotImplementedError("RGB: __le__ Operator")
    
    def __gt__(self, other):
        raise NotImplementedError("RGB: __gt__ Operator")

    def __ge__(self, other):
        raise NotImplementedError("RGB: __ge__ Operator")

    #OPERATORS
    def __add__(self, other):
        if (str(type(other)) == "<type 'instance'>"):
            self.r += other.r
            self.g += other.g
            self.b += other.b
        else:
            self.r += other
            self.g += other
            self.b += other
        return self

    def __sub__(self, other):
        if (str(type(other)) == "<type 'instance'>"):
            self.r -= other.r
            self.g -= other.g
            self.b -= other.b  
        else:
            self.r -= other
            self.g -= other
            self.b -= other
        return self
    
    def __div__(self, other):
        if (str(type(other)) == "<type 'instance'>"):
            self.r /= other.r
            self.g /= other.g
            self.b /= other.b
        else:
            self.r /= other
            self.g /= other
            self.b /= other
        return self
    
    def __mul__(self, other):
        if (str(type(other)) == "<type 'instance'>"):
            self.r *= other.r
            self.g *= other.g
            self.b *= other.b
        else:
            self.r *= other
            self.g *= other
            self.b *= other
        return self

    def __str__(self):
        return '({0}, {1}, {2})'.format(self.r, self.g, self.b)
