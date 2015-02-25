/*
 * Swap.hpp
 *
 *  Created on: Feb 25, 2015
 *      Author: haotian
 */

#ifndef SWAP_HPP_
#define SWAP_HPP_
#include <iostream>
#include <string>
#include "Uniform_Generator.hpp"
#include "Normal_Generator.hpp"
using namespace std;

class Swap
{
public:
	double Notional;
	double t;
	double T;
	string Currency;
	bool LongorShort;

public:
	Swap(double Notional_,double T_, string Currency_,bool LongorShort_) : Notional(Notional_) , t(0), T(T_), Currency (Currency_) , LongorShort(LongorShort_) {};
	void Time_t(double t_)
	{
		t=t_;
	};
	static vector<double> Yield_Curve()
	{

	};
	static double PV()
	{

	};
};

Swap Swap_Generator()
{

}



#endif /* SWAP_HPP_ */
