#pragma once

#include "vector2d.h"
#include <map>
extern unsigned int functionCallCounts;

class Function
{
private:
	static std::map<vector2d, double> functionValues;
	static int coef;
public:
	inline static void setCoef(int _coef) { coef = _coef; };
	static double calcFunction(vector2d _point);
};

