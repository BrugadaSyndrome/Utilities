#include "types.h"

namespace caj{
	namespace Types {

		Fraction::Fraction() 
			: numerator(0), denominator(0) {
			setNumerator(0);
			setDenominator(0);
		}

		Fraction::Fraction(long long num, long long den)
			: numerator(0), denominator(0){
			setNumerator(num);
			setDenominator(den);
		}

		Fraction::Fraction(Fraction &src)
			: numerator(0), denominator(0) {
			setNumerator(src.getNumerator());
			setDenominator(src.getDenominator());
			*this = src;
		}

		Fraction &Fraction::operator=(Fraction &src) {
			setNumerator(src.getNumerator());
			setDenominator(src.getDenominator());
			return *this;
		}

		Fraction::~Fraction() {
		}

		double Fraction::getDecimal() {
			if (this->denominator == 0) {
				std::cout << "Divide by zero!" << std::endl;
				return 0;
			}
			return (static_cast<double>(this->numerator) / this->denominator);
		}

		long long Fraction::getNumerator() {
			return this->numerator;
		}

		long long Fraction::getDenominator() {
			return this->denominator;
		}

		bool Fraction::setNumerator(long long num) {
			this->numerator = num;
			fixSign();
			return true;
		}

		bool Fraction::setDenominator(long long den) {
			this->denominator = den;
			fixSign();
			return false;
		}

		// (a/b) + c = ((a+(b*c))/b)
		Fraction Fraction::operator+(long long scalar) {
			Fraction f = Fraction();
			f.setNumerator(this->getNumerator() + (scalar * this->getDenominator()));
			f.setDenominator(this->getDenominator());
			return f;
		}

		// (a/b) + (c/d) = ((a*d)+(b*c))/(b*d)
		Fraction Fraction::operator+(Fraction &rhs) {
			Fraction f = Fraction();
			f.setNumerator((this->getNumerator() * rhs.getDenominator()) + (rhs.getNumerator() * this->getDenominator()));
			f.setDenominator(this->getDenominator() * rhs.getDenominator());
			return f;
		}

		// (a/b) - c = ((a-(b*c))/b)
		Fraction Fraction::operator-(long long scalar) {
			Fraction f = Fraction();
			f.setNumerator(this->getNumerator() - (scalar * this->getDenominator()));
			f.setDenominator(this->getDenominator());
			return f;
		}

		// (a/b) + (c/d) = ((a*d)-(b*c))/(b*d)
		Fraction Fraction::operator-(Fraction &rhs) {
			Fraction f = Fraction();
			f.setNumerator((this->getNumerator() * rhs.getDenominator()) - (rhs.getNumerator() * this->getDenominator()));
			f.setDenominator(this->getDenominator() * rhs.getDenominator());
			return f;
		}

		// (a/b) * c = (a*c)/b
		Fraction Fraction::operator*(long long scalar) {
			Fraction f = Fraction();
			f.setNumerator(this->getNumerator() * scalar);
			f.setDenominator(this->getDenominator());
			return f;
		}
		
		// (a/b) * (c/d) = (a*c)/(b*d)
		Fraction Fraction::operator*(Fraction &rhs) {
			Fraction f = Fraction();
			f.setNumerator(this->getNumerator() * rhs.getNumerator());
			f.setDenominator(this->getDenominator() * rhs.getDenominator());
			return f;
		}

		// (a/b) / c = (a/(b*c))
		Fraction Fraction::operator/(long long scalar) {
			Fraction f = Fraction();
			f.setNumerator(this->getNumerator());
			f.setDenominator(this->getDenominator() * scalar);
			return f;
		}

		// (a/b) / (c/d) = (a*d)/(b*c)
		Fraction Fraction::operator/(Fraction &rhs) {
			Fraction f = Fraction();
			f.setNumerator(this->getNumerator() * rhs.getDenominator());
			f.setDenominator(this->getDenominator() * rhs.getNumerator());
			return f;
		}

		// make it so the numerator has the negative sign
		// not the denominator. Also fix for both having
		// the negative sign
		bool Fraction::fixSign() {
			// -x/-x || x/-x
			if (getDenominator() < 0) {
				this->numerator = getNumerator() * -1;
				this->denominator = getDenominator() * -1;
				return true;
			}
			// x/x || -x/x
			return false;
		}

		std::ostream &operator<<(std::ostream &os, Fraction &rhs) {
			os << rhs.getNumerator() << "/" << rhs.getDenominator();
			return os;
		}

		std::istream &operator>>(std::istream &is, Fraction &rhs) {
			long long num, den;
			is >> num >> den;
			if (is){
				rhs.setNumerator(num);
				rhs.setDenominator(den);
			}
			return is;
		}

	}
}
