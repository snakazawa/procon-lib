#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const double EPS = 1e-12;

double add(double a, double b) {
	if (abs(a + b) < EPS * (abs(a) + abs(b)))
		return 0;
	return a + b;
}

struct P {
	double x, y;
	P() {};
	P(double x, double y) : x(x), y(y) {
	}

	P operator + (P p) {
		return P(add(x, p.x), add(y, p.y));
	}

	P operator - (P p) {
		return P(add(x, -p.x), add(y, -p.y));
	}

	P operator * (double d) {
		return P(x * d, y * d);
	}

	P operator / (double d) {
		return P(x / d, y / d);
	}

	// 内積
	double dot(P p) {
		return add(x * p.x, y * p.y);
	}

	// 外積
	double det(P p) {
		return add(x * p.y, -y * p.x);
	}
};

// 線分上に点があるか
bool on_seg(P p1, P p2, P q) {
	return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

// 直線と直線の交点
P intersection(P p1, P p2, P q1, P q2) {
	return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

// 2直線の直行判定
bool line_orth(P a1, P a2, P b1, P b2) {
	return fabs((a1 - a2).dot(b1 - b2)) < EPS;
}

// 2直線の平行判定
bool line_paral(P a1, P a2, P b1, P b2) {
	return fabs((a1 - a2).det(b1 - b2)) < EPS;
}

// 進行方向
int ccw(P a, P b, P c) {
	a = b - a; b = b - c;
	if (a.det(b) > 0)
		return +1;
	else if (a.det(b) < 0)
		return -1;
	return 0;
}