/*
 * Normal_Generator.hpp
 *
 *  Created on: Feb 25, 2015
 *      Author: haotian
 */

#ifndef NORMAL_GENERATOR_HPP_
#define NORMAL_GENERATOR_HPP_

#include "Uniform_Generator.hpp"
#include "math.h"

#include <iostream>
class STD_NOR
{
protected:
	STD_NOR() {count_num=0;};
	virtual ~STD_NOR(){};
	int count_num;

public:
	MY_RND uniform_rnd;
    virtual double rnd( ) =0;
	int count()
	{
		return count_num;
	}

};
class Inverse_Transform_std_nor : public STD_NOR
{
private:
	double _u;
public:

	Inverse_Transform_std_nor():STD_NOR(){_u=0;};
	 virtual double rnd(){
		_u=uniform_rnd.rnd();
		double y=_u-0.5;
		double r=0;
				double x =0;
				double a0=2.50662823884;
				double a1=-18.61500062529;
				double a2=41.39119773534;
				double a3=-25.44106049637;

				double b0=-8.47351093090;
				double b1=23.08336743743;
				double b2=-21.06224101826;
				double b3=3.13082909833;

				double c0=0.3374754822726147;
				double c1=0.9761690190917186;
				double c2=0.1607979714918209;
				double c3=0.0276438810333863;
				double c4=0.0038405729373609;
				double c5=0.0003951896511919;
				double c6=0.0000321767881768;
				double c7=0.0000002888167364;
				double c8=0.0000003960315187;
		if (fabs(y)<0.42)
		{
			r=y*y;
			x=y*(((a3*r+a2)*r+a1)*r+a0)/((((b3*r+b2)*r+b1)*r+b0)*r+1);
		}
		else
		{
			r=_u;
			if (y>0) r=1-_u;
			r=log(-log(r));
			x=c0+r*(c1+r*(c2+r*(c3+r*(c4+r*(c5+r*(c6+r*(c7+r*c8)))))));
			if (y<0) x=-x;

		}
		count_num++;
		return x;
	};
};
class Acceptance_Rejection_std_nor : public STD_NOR
{

private:
	double _u1;
	double _u2;
	double _u3;

public:

	Acceptance_Rejection_std_nor():STD_NOR(){
		_u1=0;_u2=0;_u3=0;

	};

	 virtual double rnd(){
		double X=0;
		do{
		_u1=uniform_rnd.rnd();
		_u2=uniform_rnd.rnd();

		X=-log(_u1);
		}
		while (_u2 > exp(-0.5*(fabs(X)-1)*(fabs(X)-1)));
		_u3=uniform_rnd.rnd();
		if (_u3<=0.5) X=-X;
		count_num++;
		return X;
	};

};
class Box_Muller_Marsaglia_Bray_std_nor : public STD_NOR
{

private:
	double _u1;
	double _u2;
	double z1;
	double z2;

public:

	Box_Muller_Marsaglia_Bray_std_nor():STD_NOR(){
		_u1=0;_u2=0;z1=0;z2=0;
	};

	 virtual double rnd(){

		if  (z2 !=0)
			{
			double temp=z2;
			z2=0;
			count_num++;
			return temp;
			}
		double X=0;

		do
		{
		_u1=uniform_rnd.rnd();
		_u2=uniform_rnd.rnd();
		_u1=2*_u1-1;
		_u2=2*_u2-1;
		X=_u1*_u1+_u2*_u2;
		//cout<<"X="<<X<<endl;
		}while(X>1);
		double Y=sqrt(-2*log(X)/X);
		//cout<<"Y="<<Y<<endl;
		z1=_u1*Y;
		z2=_u2*Y;
		count_num++;
		return z1;
	};

};

#endif /* NORMAL_GENERATOR_HPP_ */
