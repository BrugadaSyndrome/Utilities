/*
Author: Coby Johnson
Version: y15m03d16
Copyright 2015
*/

#ifndef _COLOR_H_
#define _COLOR_H_

#include <iostream>

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

#endif