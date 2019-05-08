#include "Function.h"
#include <cmath>

unsigned int functionCallCounts;

int Function::coef;

double Function::calcFunction(vector2d _point)
{
	++functionCallCounts;
	return 2 * pow((_point.x - coef), 2) - _point.x * _point.y + 5 * pow(_point.y,2);
}