#include "LabworkData.h"
#include "Function.h"
#include <iostream>
#include "Methods.h"


int main()
{
	functionCallCounts = 0;
	//DEFAULT EXERCISE CONDITIONS
	double lambda0 = 0;
	int coef = 16;
	vector2d moveY(0, 1);
	vector2d moveX(1, 0);
	
	//PREPARATIONS
	LabworkCountings countings(coef);
	countings.direction.push_back(moveX);
	countings.direction.push_back(moveY);
	countings.direction.push_back(moveX);
	Function::setCoef(coef);

	std::cout << "Start point: " << countings.pointX.at(0) << std::endl;
	std::cout << "Function value in start point: " << Function::calcFunction(countings.pointX.at(0)) << std::endl;
	std::cout << std::endl;

	for (auto i = 0; i < 4; ++i)
	{
		if (i == 3)
		{
			countings.direction.push_back(countings.pointX.at(3) - countings.pointX.at(1));
			countings.direction.at(countings.direction.size() - 1).makeNormalized();
		}

		countings.calcDelta();
		std::cout << "Delta " << i << " is " << countings.delta.at(i) << std::endl;

		std::pair<double,double> interval = Sven::findInterval(countings.pointX.at(i), countings.direction.at(i), countings.delta.at(i));
	
		if (i == 0) 
			countings.lambda.push_back(
				Dichotomy::findStep(interval, countings.pointX.at(i), countings.direction.at(i), countings.epsilone)
			);
		else if (i == 1) 
			countings.lambda.push_back(
				GoldenRatio::findStep(interval, countings.pointX.at(i), countings.direction.at(i), countings.epsilone)
			);
		else 
			countings.lambda.push_back(
				DSK::findStep(interval, countings.pointX.at(i), countings.direction.at(i), countings.epsilone)
			);

		countings.pointX.push_back(countings.pointX.at(i) + countings.direction.at(i) * countings.lambda.at(i));
		
		std::cout << "Lambda" << i << " is " << countings.lambda.at(i) << std::endl;
		std::cout << "X" << i + 1 << " is " << countings.pointX.at(i + 1) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Total function calls is: " << functionCallCounts << std::endl;

//	std::cout << "First Sven "

} 