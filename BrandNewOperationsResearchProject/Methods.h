#pragma once
#include <utility>
#include "vector2d.h"

namespace Sven
{
	std::pair<double, double> findInterval(vector2d _point, vector2d direction);
}

namespace Dychotomy
{
	double findStep(std::pair<double, double>);
}

namespace GoldenRatio
{
	double findStep(std::pair<double, double>);
}

namespace DSK
{
	double findStep(std::pair<double,double>);
}
