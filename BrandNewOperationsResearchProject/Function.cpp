#include "Function.h"
#include <cmath>

std::map<vector2d, double> Function::functionValues;
int Function::coef;

unsigned int functionCallCounts;

double Function::calcFunction(vector2d _point)
{
	for (auto e : functionValues)
	{
		if (_point == e.first)
		{
			return e.second;
		}
	}
	double functionValue = 2 * pow((_point.x - coef), 2) - _point.x * _point.y + 5 * pow(_point.y, 2);
	++functionCallCounts;
	functionValues.insert(std::make_pair(_point, functionValue));
	return functionValue;
}