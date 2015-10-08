# Version: y2015m03d21
from math import sqrt

def isPrime(n):
    if (n < 2):
        return False
    if n in (2,3):
        return True
    if (n % 2 == 0) or (n % 3 == 0):
        return False

    max_divisor = int(sqrt(n))
    divisor = 5

    while (divisor <= max_divisor):
        if (n % divisor == 0) or (n % (divisor + 2) == 0):
            return False
        divisor += 6
    return True
