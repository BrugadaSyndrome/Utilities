class 2D:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    #COMPARATORS
    def __eq__(self, other):
        if (self.x == other.x and self.y == other.y):
                return True
        return False
    
    def __ne__(self, other):
        if (self == other):
            return False
        return True

    #OPERATORS
    def __add__(self, other):
        if (str(type(other)) == "<type 'instance'>"):
            self.x += other.x
            self.y += other.y
        else:
            self.x += other
            self.y += other
        return self
    
    def __sub__(self, other):
        if (str(type(other)) == "<type 'instance'>"):
            self.x -= other.x
            self.y -= other.y
        else:
            self.x -= other
            self.y -= other
        return self
    
    def __div__(self, other):
        if (str(type(other)) == "<type 'instance'>"):
            self.x /= other.x
            self.y /= other.y
        else:
            self.x /= other
            self.y /= other
        return self
    
    def __mul__(self, other):
        if (str(type(other)) == "<type 'instance'>"):
            self.x *= other.x
            self.y *= other.y
        else:
            self.x *= other
            self.y *= other
        return self

    def __str__(self):
        return "({0},{1})".format(self.x,self.y)
