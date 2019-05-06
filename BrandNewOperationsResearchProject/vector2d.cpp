#include "vector2d.h"
#include <cmath>

vector2d vector2d::operator+(vector2d v2)
{
	return vector2d(this->x + v2.x, this->y + v2.y);
}

vector2d vector2d::operator-(vector2d v2)
{
	return vector2d(this->x - v2.x, this->y - v2.y);
}

vector2d vector2d::operator*(vector2d v2)
{
	return vector2d(this->x * v2.x, this->y * v2.y);
}

vector2d vector2d::operator*(double coef)
{
	return vector2d(this->x * coef, this->y * coef);
}

vector2d vector2d::operator/(vector2d v2)
{
	return vector2d(this->x / v2.x, this->y / v2.y);
}

vector2d vector2d::operator/(double devideBy)
{
	return vector2d(this->x / devideBy, this->y / devideBy);
}


double vector2d::magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

double vector2d::distance(const vector2d & vec2d)
{
	return sqrt(pow(vec2d.x - x, 2) + pow(vec2d.y - y, 2));
}

vector2d vector2d::normalizedVec()
{
	return *this / magnitude();
}

vector2d::vector2d() : x{ 0 }, y{ 0 } {}
vector2d::vector2d(double _x, double _y) : x{ _x }, y{ _y } {}


vector2d operator*(const double coef, vector2d& v)
{
	return vector2d(v.x * coef, v.y * coef);
}
