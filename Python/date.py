# Version: y2015m03d21
class Date:

    def __init__(self, month=None, day=None, year=None):
        self.month = month
        self.day = day
        self.year = year

    def __eq__(self, other):
        if int(self.year) == int(other.year):
            if int(self.month) == int(other.month):
                if int(self.day) == int(other.day):
                    return True
        return False

    def __ne__(self, other):
        if int(self.year) != int(other.year):
            if int(self.month) != int(other.month):
                if int(self.day) != int(other.day):
                    return True
        return False

    def __lt__(self, other):
        if int(self.year) < int(other.year):
            if int(self.month) < int(other.month):
                if int(self.day) < int(other.day):
                    return True
        return False

    def __gt__(self, other):
        if int(self.year) > int(other.year):
            if int(self.month) > int(other.month):
                if int(self.day) > int(other.day):
                    return True
        return False

    def __le__(self, other):
        if int(self.year) <= int(other.year):
            if int(self.month) <= int(other.month):
                if int(self.day) <= int(other.day):
                    return True
        return False

    def __ge__(self, other):
        if int(self.year) >= int(other.year):
            if int(self.month) >= int(other.month):
                if int(self.day) >= int(other.day):
                    return True
        return False

    def __str__(self):
        return "{0}/{1}/{2}".format(self.month, self.day, self.year)
