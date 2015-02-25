/*
 * FX.hpp
 *
 *  Created on: Feb 25, 2015
 *      Author: haotian
 */

#ifndef FX_HPP_
#define FX_HPP_

#include <iostream>
#include <string>
#include "Uniform_Generator.hpp"
#include "Normal_Generator.hpp"
using namespace std;

class FX
{
public:
	double Notional;
	bool EURtoUSD;
	bool LongorShort;
public:
	FX(double Notional_, bool EURtoUSD_,	bool LongorShort_): Notional(Notional_) , EURtoUSD(EURtoUSD_) , LongorShort(	LongorShort_){};
	static vector<double> FX_curve(double t, double T)
	{

	};
	static double PV()
	{

	};

};



#endif /* FX_HPP_ */
