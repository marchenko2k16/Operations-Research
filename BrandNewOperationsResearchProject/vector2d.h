#pragma once
#include <cmath>

class vector2d
{
public:

	double x;
	double y;

	friend vector2d operator*(const double coef, vector2d& v);

	vector2d operator* (double coef);
	vector2d operator+ (vector2d v2);
	vector2d operator- (vector2d v2);
	vector2d operator* (vector2d v2);
	vector2d operator/ (vector2d v2);
	vector2d operator/ (double devideBy);
	double magnitude() const;


	double distance(const vector2d& vec2d);
	vector2d normalizedVec();

	vector2d();
	vector2d(double _x, double _y);

};