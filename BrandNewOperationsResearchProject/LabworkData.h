#pragma once

#include <vector>
#include "vector2d.h"

class LabworkCountings
{
public:
	std::vector<vector2d> direction;
	std::vector<vector2d> pointX;
	std::vector<double> functionVal;
	std::vector<double> lambda;
	std::vector<double> delta;

	LabworkCountings(double coef, double lambda0);
	void calcDelta();
};

