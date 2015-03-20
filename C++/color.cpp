/*
Author: Coby Johnson
Version: y15m03d16
Copyright 2015
*/

#include "color.h"

Color::Color()
	: r(0.0), g(0.0), b(0.0) {
}

Color::Color(double r, double g, double b)
	:r(0.0), g(0.0), b(0.0) {
	setR(r);
	setG(g);
	setB(b);
}

Color::Color(Color &src) 
	:r(0.0), g(0.0), b(0.0) {
	setR(0.0);
	setG(0.0);
	setB(0.0);
	*this = src;
}

Color &Color::operator=(Color &src) {
	setR(src.getR());
	setG(src.getG());
	setB(src.getB());
	return *this;
}

Color::~Color() {
}

double Color::getR() {
	return r;
}

double Color::getG() {
	return g;
}

double Color::getB() {
	return b;
}

bool Color::setR(double r) {
	this->r = r;
	return true;
}

bool Color::setG(double g) {
	this->g = g;
	return true;
}

bool Color::setB(double b) {
	this->b = b;
	return true;
}

Color Color::operator+(Color &rhs) {
	Color c = Color();
	c.setR(getR() + rhs.getR());
	c.setG(getG() + rhs.getG());
	c.setB(getB() + rhs.getB());
	return c;
}

Color Color::operator+(double scalar) {
	Color c = Color();
	c.setR(getR() + scalar);
	c.setG(getG() + scalar);
	c.setB(getB() + scalar);
	return c;
}

Color Color::operator-(Color &rhs) {
	Color c = Color();
	c.setR(getR() - rhs.getR());
	c.setG(getG() - rhs.getG());
	c.setB(getB() - rhs.getB());
	return c;
}

Color Color::operator-(double scalar) {
	Color c = Color();
	c.setR(getR() - scalar);
	c.setG(getG() - scalar);
	c.setB(getB() - scalar);
	return c;
}

Color Color::operator*(Color &rhs) {
	Color c = Color();
	c.setR(getR() * rhs.getR());
	c.setG(getG() * rhs.getG());
	c.setB(getB() * rhs.getB());
	return c;
}

Color Color::operator*(double scalar) {
	Color c = Color();
	c.setR(getR() * scalar);
	c.setG(getG() * scalar);
	c.setB(getB() * scalar);
	return c;
}

Color Color::operator/(Color &rhs) {
	Color c = Color();
	c.setR(getR() / rhs.getR());
	c.setG(getG() / rhs.getG());
	c.setB(getB() / rhs.getB());
	return c;
}

Color Color::operator/(double scalar) {
	Color c = Color();
	c.setR(getR() / scalar);
	c.setG(getG() / scalar);
	c.setB(getB() / scalar);
	return c;
}

std::ostream &operator<<(std::ostream &os, Color &rhs) {
	os << "(" << rhs.getR() << "," << rhs.getG() << "," << rhs.getB() << ")";
	return os;
}

std::istream &operator>>(std::istream &is, Color &rhs) {
	double r1, g1, b1;
	is >> r1 >> g1 >> b1;
	if (is){
		rhs.setR(r1);
		rhs.setG(g1);
		rhs.setB(b1);
	}
	return is;
}