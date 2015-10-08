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

// TODO: Test this code.
bool isPrimeMiller(long double n, int num_tests) {
	std::cout << "isPrimeMiller needs to be tested for accuracy!!!" << std::endl;
	for (int i = 0; i<num_tests; i++) {
		// Random number from 2 - n
		long double b = fmod(rand(), n-2) + 2;
		
		// Easy tests
		if (n == 2) {
			return True;
		}
		if (fmod(n, 2) == 0) {
			return False;
		}

		// Factor out
		long double s = 0;
		long double d = n-1;
		while (True) {
			long double quotient = d/2;
			long double remainder = fmod(d, 2);
			if (remainder == 1) {
				break;
			}
			s++;
			d = quotient;
		}

		// Miller-Rambin Tests
		if (pow( fmod(b,n), fmod(d, n) ) == 1) {
			// 3:4 probability this is a prime
			return true;
		}

		for (int j = 0; j<s-1; j++) {
			if (pow( fmod(b, n) , ( fmod( fmod(pow(2, j), n) * fmod(d,n), n) == n-1 ) {
				// 3:4 probability this is a prime
				return true;
			}
		}

		// This is a composite number
		return false;
	}
}

#endif