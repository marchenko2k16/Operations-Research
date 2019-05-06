#include "LabworkData.h"
#include "Function.h"
#include <iostream>
#include "Methods.h"

int main()
{
	//DEFAULT EXERCISE CONDITIONS
	double lambda0 = 0;
	int coef = 9;
	vector2d moveY(0, 1);
	vector2d moveX(1, 0);
	//PREPARATIONS
	LabworkCountings countings(coef, lambda0);
	countings.direction.push_back(moveX);
	countings.direction.push_back(moveY);
	countings.direction.push_back(moveX);
	Function::setCoef(coef);
	countings.calcDelta();

	std::cout << "Start point: " << countings.pointX.at(0).x << " " << countings.pointX.at(0).y << std::endl;
	std::cout << "Function value in start point: " << Function::calcFunction(countings.pointX.at(0)) << std::endl;

	for (auto i = 0; i < 4; ++i)
	{

		std::pair<double,double> interval = Sven::findInterval(countings.pointX.at(i), countings.direction.at(i));
	
		if (i == 0) countings.lambda.at(i + 1) = Dychotomy::findStep(interval);
		if (i == 1) countings.lambda.at(i + 1) = GoldenRatio::findStep(interval);
		if (i == 3) countings.direction.at(i + 1) = (countings.pointX.at(3) - countings.pointX.at(1));
		countings.lambda.at(i + 1) = DSK::findStep(interval);

		countings.pointX.at(i + 1) = countings.pointX.at(i) + countings.direction.at(i) * countings.lambda.at(i + 1);
	}

} 