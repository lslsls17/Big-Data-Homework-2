/*
 * Counter_Party.hpp
 *
 *  Created on: Feb 25, 2015
 *      Author: haotian
 */

#ifndef COUNTER_PARTY_HPP_
#define COUNTER_PARTY_HPP_


#include <iostream>
#include <string>
#include <vector>
#include "Swap.hpp"
#include "FX.hpp"
using namespace std;

class Counter_Party
{
public:
	double Hazard_Rate;
	string Level;
	vector<Swap> myswap;
	vector<FX> myFX;


public:
	Counter_Party(string Level_ ,vector<Swap> & myswap_,vector<FX> & myFX_) : Level(Level_) , myswap(myswap_) , myFX(myFX_)
	{
			if (Level=="A") Hazard_Rate=0.02;
			else if (Level=="B") Hazard_Rate=0.04;
			else if (Level=="C") Hazard_Rate=0.06;
			else if (Level=="D") Hazard_Rate=0.08;
			else Hazard_Rate=0.1;
	}
};


#endif /* COUNTER_PARTY_HPP_ */
