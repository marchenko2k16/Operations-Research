#include "LabworkData.h"

LabworkCountings::LabworkCountings(double coef, double lambda0)
{
	pointX.push_back(vector2d(-1.3 * coef - 4, -1.3 * coef - 4));
	lambda.push_back(lambda0);
}

void LabworkCountings::calcDelta()
{
	delta.push_back(0.1 * pointX.at(delta.size()).magnitude() /
	direction.at(delta.size()).magnitude());
}
