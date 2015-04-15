#ifndef _UTILITES_H_
#define _UTITLIES_H_

#include <iostream>

namespace caj {
	namespace Types {

		class Fraction {
			public:
				Fraction();
				Fraction(long long num, long long den);
				Fraction(Fraction &src);
				Fraction &operator=(Fraction &src);
				~Fraction();

				double getDecimal();
				long long getNumerator();
				long long getDenominator();

				bool setNumerator(long long num);
				bool setDenominator(long long den);

				Fraction operator+(long long scalar);
				Fraction operator+(Fraction &rhs);
				Fraction operator-(long long scalar);
				Fraction operator-(Fraction &rhs);
				Fraction operator*(long long scalar);
				Fraction operator*(Fraction &rhs);
				Fraction operator/(long long scalar);
				Fraction operator/(Fraction &rhs);
				friend std::ostream &operator<<(std::ostream &os, Fraction &rhs);
				friend std::istream &operator>>(std::istream &is, Fraction &rhs);

			private:
				long long numerator, denominator;
				bool fixSign();

		};

	}
}

#endif