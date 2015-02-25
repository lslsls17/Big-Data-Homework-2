/*
 * Uniform_Generator.hpp
 *
 *  Created on: Feb 25, 2015
 *      Author: haotian
 */

#ifndef UNIFORM_GENERATOR_HPP_
#define UNIFORM_GENERATOR_HPP_

#include <iostream>
#include <math.h>
using namespace std;

class mRND //random number generator
{
public:
    void seed( unsigned long int s ) { _seed = s; }

//protected:
public:
    long int  _a;
    long int _c;
    unsigned long _m, _seed;
    long int count_num;
    mRND() {
    	_seed=1;
    	_a=39373;
    	_c=0;
    	_m=pow(2.0,31.0)-1;
    	count_num=0;
    }
    double rnd() {
    	_seed = ( _a * _seed + _c ) % _m ;
    	count_num++;
    return double(_seed) /double(_m);
    }
public:
    long int count(){
    	return count_num;
    };
};
//--------------------------------------------------------------------------------------------------

class MY_RND : public mRND
{
public:
    MY_RND() { _a = 39373; _c = 0; _seed=1;}
    double rnd() { return mRND::rnd(); }
};

#endif /* UNIFORM_GENERATOR_HPP_ */
