#ifndef _LINE_H_
#define _LINE_H_

#include <iostream>

#include "point.h"

namespace R2 {
	class Line {
	public:
		Line();
		Line(Point p1, Point p2);
		Line(Line &src);
		Line &operator=(Line &src);
		~Line();

		Point getP1();
		Point getP2();
		double getSlope();

		bool setP1(Point p1);
		bool setP2(Point p2);

		friend std::ostream &operator<<(std::ostream &os, R2::Line &rhs);
		friend std::istream &operator>>(std::istream &is, R2::Line &rhs);

	private:
		Point p1, p2;
		double slope;

	};
}

namespace R3 {
	class Line : R2::Line {
	public:
		Line();
		Line(Point p1, Point p2, Point p3);
		Line(Line &src);
		Line &operator=(Line &src);
		~Line();

		Point getP3();

		bool setP3(Point p3);

		friend std::ostream &operator<<(std::ostream &os, R3::Line &rhs);
		friend std::istream &operator>>(std::ostream &is, R3::Line &rhs);

	private:
		Point p3;

	};
}
#endif