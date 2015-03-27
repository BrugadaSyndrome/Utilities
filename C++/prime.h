#ifndef _PRIME_H_
#define _PRIME_H_

#include <cmath>

bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	if (n == 2 || n == 3) {
		return true;
	}
	if (n % 2 == 0 || n % 3 == 0) {
		return false;
	}
	
	int max_divisor = sqrt(n);
	int divisor = 5;
	
	while (divisor <= max_divisor) {
		if ((n % divisor == 0) || (n % (divisor + 2) == 0)) {
			return false;
		}
		divisor += 6;
	}
	return true;
}

#endif