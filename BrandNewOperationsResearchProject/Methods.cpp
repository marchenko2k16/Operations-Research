#include "Methods.h"
#include "Function.h"

#include <vector>
#include <string>

#include <cmath>

std::pair<double, double> Sven::findInterval(vector2d _point, vector2d direction, double delta)
{
	std::vector<double> svenLambdas;
	std::vector<double> functionValues;
	
	double lambdaMinus	= 0 - delta;
	double lambdaPlus	= 0 + delta;

	double plusDeltaFunc(Function::calcFunction(_point + direction * lambdaPlus));
	double minusDeltaFunc(Function::calcFunction(_point + direction * lambdaMinus));
 	char sign;
	
	if (minusDeltaFunc > plusDeltaFunc)
	{
		sign = 1;
		svenLambdas.push_back(lambdaPlus);
		functionValues.push_back(plusDeltaFunc);
	}
	else if(plusDeltaFunc > minusDeltaFunc)
	{
		sign = -1;
		svenLambdas.push_back(lambdaMinus);
		functionValues.push_back(minusDeltaFunc);
	}

	for (int i = 1; ;++i)
	{
		svenLambdas.push_back(svenLambdas.at(i - 1) + sign * pow(2,i)*delta);
		functionValues.push_back(Function::calcFunction(_point + direction*svenLambdas.at(i)));
		if (functionValues.at(i) > functionValues.at(i - 1))
		{
			break;
		}
	}
	double middleLambdaValue = (svenLambdas.at(svenLambdas.size() - 1) + svenLambdas.at(svenLambdas.size() - 2) ) / 2;
	svenLambdas.insert(svenLambdas.begin() + svenLambdas.size() - 1, middleLambdaValue);

	double functionValueStepBack(Function::calcFunction(_point + direction * svenLambdas.at(svenLambdas.size() - 2)));
	functionValues.insert(functionValues.begin() + functionValues.size() - 1, functionValueStepBack);
	
	if (functionValues.at(functionValues.size() - 3) > functionValues.at(functionValues.size() - 2))
	{
		return std::pair<double, double>
			(svenLambdas.at(svenLambdas.size() - 3),
				svenLambdas.at(svenLambdas.size() - 1));
	}
	else
	{
		return std::pair<double, double>
			(svenLambdas.at(svenLambdas.size() - 4),
				svenLambdas.at(svenLambdas.size() - 2));
	}
}

double GoldenRatio::findStep(std::pair<double, double>)
{



	return 0.0;
}

double Dichotomy::findStep(std::pair<double, double>)
{



	return 0.0;
}

double DSK::findStep(std::pair<double, double>)
{




	return 0.0;
}