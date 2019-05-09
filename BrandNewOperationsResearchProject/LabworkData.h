#pragma once

#include <vector>
#include "vector2d.h"

class LabworkCountings
{
public:
	double epsilone{0.01};

	std::vector<vector2d> direction;
	std::vector<vector2d> pointX;

	std::vector<double> functionVal;
	std::vector<double> lambda;
	std::vector<double> delta;

	LabworkCountings(double coef);
	void calcDelta();
};

