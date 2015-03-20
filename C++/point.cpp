#include "point.h"

namespace R2 {
	Point::Point()
		: x(0.0), y(0.0) {
	}

	Point::Point(double x, double y)
		: x(0.0), y(0.0) {
		setX(x);
		setY(y);
	}

	Point::Point(Point &src)
		: x(0.0), y(0.0) {
		setX(0.0);
		setY(0.0);
		*this = src;
	}

	Point &Point::operator=(Point &src) {
		setX(src.getX());
		setY(src.getY());
		return *this;
	}

	Point::~Point() {
	}

	double Point::getX() {
		return x;
	}

	double Point::getY() {
		return y;
	}

	bool Point::setX(double x) {
		this->x = x;
		return true;
	}

	bool Point::setY(double y) {
		this->y = y;
		return true;
	}

	Point Point::operator+(Point &rhs) {
		Point p = Point();
		p.setX(getX() + rhs.getX());
		p.setY(getY() + rhs.getY());
		return p;
	}

	Point Point::operator+(double scalar) {
		Point p = Point();
		p.setX(getX() + scalar);
		p.setY(getY() + scalar);
		return p;
	}

	Point Point::operator-(Point &rhs) {
		Point p = Point();
		p.setX(getX() - rhs.getX());
		p.setY(getY() - rhs.getY());
		return p;
	}

	Point Point::operator-(double scalar) {
		Point p = Point();
		p.setX(getX() - scalar);
		p.setY(getY() - scalar);
		return p;
	}

	Point Point::operator*(Point &rhs) {
		Point p = Point();
		p.setX(getX() * rhs.getX());
		p.setY(getY() * rhs.getY());
		return p;
	}

	Point Point::operator*(double scalar) {
		Point p = Point();
		p.setX(getX() * scalar);
		p.setY(getY() * scalar);
		return p;
	}

	Point Point::operator/(Point &rhs) {
		Point p = Point();
		p.setX(getX() / rhs.getX());
		p.setY(getY() / rhs.getY());
		return p;
	}

	Point Point::operator/(double scalar) {
		Point p = Point();
		p.setX(getX() / scalar);
		p.setY(getY() / scalar);
		return p;
	}

	std::ostream &operator<<(std::ostream &os, Point &rhs){
		os << "(" << rhs.getX() << "," << rhs.getY() << ")";
		return os;
	}

	std::istream &operator>>(std::istream &is, R2::Point &rhs){
		double x1, y1;
		is >> x1 >> y1;
		if (is){
			rhs.setX(x1);
			rhs.setY(y1);
		}
		return is;
	}
}

namespace R3 {
	Point::Point()
		: R2::Point(), z(0.0) {
	}

	Point::Point(double x, double y, double z)
		: R2::Point(x, y), z(z) {
		setX(x);
		setY(y);
		setZ(z);
	}

	Point::Point(Point &src)
		: R2::Point(), z(0.0) {
			setZ(0.0);
			*this = src;
	}

	Point &Point::operator=(Point &src) {
		setX(src.getX());
		setY(src.getY());
		setZ(src.getZ());
		return *this;
	}

	Point::~Point() {
	}

	double Point::getZ() {
		return z;
	}

	bool Point::setZ(double z) {
		this->z = z;
		return true;
	}

	Point Point::operator+(Point &rhs) {
		Point p = Point();
		p.setX(getX() + rhs.getX());
		p.setY(getY() + rhs.getY());
		p.setZ(getZ() + rhs.getZ());
		return p;
	}

	Point Point::operator+(double scalar) {
		Point p = Point();
		p.setX(getX() + scalar);
		p.setY(getY() + scalar);
		p.setZ(getZ() + scalar);
		return p;
	}

	Point Point::operator-(Point &rhs) {
		Point p = Point();
		p.setX(getX() - rhs.getX());
		p.setY(getY() - rhs.getY());
		p.setZ(getZ() - rhs.getZ());
		return p;
	}

	Point Point::operator-(double scalar) {
		Point p = Point();
		p.setX(getX() - scalar);
		p.setY(getY() - scalar);
		p.setZ(getZ() - scalar);
		return p;
	}

	Point Point::operator*(Point &rhs) {
		Point p = Point();
		p.setX(getX() * rhs.getX());
		p.setY(getY() * rhs.getY());
		p.setZ(getZ() * rhs.getZ());
		return p;
	}

	Point Point::operator*(double scalar) {
		Point p = Point();
		p.setX(getX() * scalar);
		p.setY(getY() * scalar);
		p.setZ(getZ() * scalar);
		return p;
	}

	Point Point::operator/(Point &rhs) {
		Point p = Point();
		p.setX(getX() / rhs.getX());
		p.setY(getY() / rhs.getY());
		p.setZ(getZ() / rhs.getZ());
		return p;
	}

	Point Point::operator/(double scalar) {
		Point p = Point();
		p.setX(getX() / scalar);
		p.setY(getY() / scalar);
		p.setZ(getZ() / scalar);
		return p;
	}

	std::ostream &operator<<(std::ostream &os, Point &rhs) {
		os << "(" << rhs.getX() << "," << rhs.getY() << "," << rhs.getZ() << ")";
		return os;
	}

	std::istream &operator>>(std::istream &is, R3::Point &rhs) {
		double x1, y1, z1;
		is >> x1 >> y1 >> z1;
		if (is){
			rhs.setX(x1);
			rhs.setY(y1);
			rhs.setZ(z1);
		}
		return is;
	}
}