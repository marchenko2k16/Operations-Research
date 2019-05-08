#pragma once

#include "vector2d.h"

extern unsigned int functionCallCounts;

class Function
{
private:
	static int coef;
public:
	inline static void setCoef(int _coef) { coef = _coef; };
	static double calcFunction(vector2d _point);
};

