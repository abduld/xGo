/*
 *	Author:	hyf042
 *	Date:	12-02-2013
 *
 *  Copyright 2013 hyf042. All rights reserved.
 */
#ifndef _BASIC_H_
#define _BASIC_H_

#include <unordered_set>

namespace Go
{
	class Point
	{
	public:
		int r;
		int c;
		Point(int r = -1, int c = -1) :r(r), c(c) {}
		friend Point operator+(const Point &a, const Point &b) {
			return Point(a.r + b.r, a.c + b.c);
		}
		friend Point operator-(const Point &a, const Point &b) {
			return Point(a.r - b.r, a.c - b.c);
		}
		friend bool operator==(const Point &a, const Point &b) {
			return a.r == b.r&&a.c == b.c;
		}
		friend bool operator!=(const Point &a, const Point &b) {
			return !(a == b);
		}
	};

	class PointHasher
	{
	public:
		size_t operator()(const Point &p) const {
			return p.r * 1000 + p.c;
		}
	};

	typedef std::unordered_set<Point, PointHasher> point_set;

	enum Color { EMPTY = 0, WHITE = 1, BLACK = 2 };
	enum FinalStatus { DEAD, ALIVE, SEKI, WHITE_TERRITORY, BLACK_TERRITORY, UNKNOWN };
	const int MIN_BOARD = 2;
	const int MAX_BOARD = 23;
#define override
}

#endif