#pragma once

#include "vector2d.h"

class Function
{
private:
	static int coef;
public:
	inline static void setCoef(int _coef) { coef = _coef; };
	static double calcFunction(vector2d _point);
};

