#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

namespace R2 {
	class Point {
	public:
		Point();
		Point(double x, double y);
		Point(Point &src);
		Point &operator=(Point &src);
		~Point();

		double getX();
		double getY();

		bool setX(double x);
		bool setY(double y);

		Point operator+(Point &rhs);
		Point operator+(double scalar);
		Point operator-(Point &rhs);
		Point operator-(double scalar);
		Point operator*(Point &rhs);
		Point operator*(double scalar);
		Point operator/(Point &rhs);
		Point operator/(double scalar);
		friend std::ostream &operator<<(std::ostream &os, R2::Point &rhs);
		friend std::istream &operator>>(std::istream &is, R2::Point &rhs);

	private:
		double x, y;

	};
}

namespace R3 {
	class Point : R2::Point {
	public:
		Point();
		Point(double x, double y, double z);
		Point(Point &src);
		Point &operator=(Point &src);
		~Point();

		double getZ();

		bool setZ(double z);

		Point operator+(Point &rhs);
		Point operator+(double scalar);
		Point operator-(Point &rhs);
		Point operator-(double scalar);
		Point operator*(Point &rhs);
		Point operator*(double scalar);
		Point operator/(Point &rhs);
		Point operator/(double scalar);
		friend std::ostream &operator<<(std::ostream &os, R3::Point &rhs);
		friend std::istream &operator>>(std::istream &is, R3::Point &rhs);

	private:
		double z;
	};
}

#endif