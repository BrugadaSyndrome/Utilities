#ifndef _COLOR_H_
#define _COLOR_H_

#include <iostream>

namespace Color {

	class Color {

		public:
			Color();
			Color(double r, double g, double b);
			Color(Color &src);
			Color &operator=(Color &src);
			~Color();

			double getR();
			double getG();
			double getB();

			bool setR(double r);
			bool setG(double g);
			bool setB(double b);

			Color operator+(Color &rhs);
			Color operator+(double scalar);
			Color operator-(Color &rhs);
			Color operator-(double scalar);
			Color operator*(Color &rhs);
			Color operator*(double scalar);
			Color operator/(Color &rhs);
			Color operator/(double scalar);
			friend std::ostream &operator<<(std::ostream &os, Color &rhs);
			friend std::istream &operator>>(std::istream &is, Color &rhs);

		private:
			double r, g, b;

	};

	//const Color Black(0, 0, 0);
	//const Color Red(255, 0, 0);
	//const Color Green(0, 255, 0);
	//const Color Blue(0, 0, 255);
	//const Color White(255, 255, 255);
}

#endif