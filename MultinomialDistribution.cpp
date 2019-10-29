#include <iostream>
#include <cmath>
#include <algorithm>
#include "MultinomialDistribution.h"

using namespace std;

MultinomialDistribution::MultinomialDistribution(vector<double> _probs)
{
   /* double sum = 0;
    for(unsigned i=0; i<_probs.size(); ++i)
    {
        sum = sum + _probs.at(i);
    }

    for(unsigned i=0; i<_probs.size(); ++i)
    {
        probs.push_back(_probs.at(i)/sum);
    }*/
    probs = _probs;
    for(unsigned i=1; i<probs.size(); ++i)
    {
        probs.at(i) = probs.at(i) + probs.at(i-1);
    }
    for(unsigned i=0; i<probs.size(); ++i)
    {
        probMap[i] = probs.at(i);
        //cout << probMap[i] << endl;
    }
}

MultinomialDistribution::~MultinomialDistribution() {};


int MultinomialDistribution::drawNumber(double _rn)
{
    for(unsigned i=0; i<probs.size(); ++i)
    {
        if(_rn < probs.at(i))
        {
            return i;
        }

    }
}

double MultinomialDistribution::getProb(int _n)
{
    return probMap[_n];
}


int MultinomialDistribution::bisection(int _a, int _b, double _u)
{
    //cout << _u << " " << getProb(0) << endl;
    if(_u <= getProb(0))
        return 0;

    /*if(_u >= getProb(probs.size()-1))
    {
        //cout << "hello " << getProb(probs.size()-1) << endl;
        return (probs.size());
    }*/

    if((getProb(_a) - _u) * (getProb(_b) - _u) >= 0)
    {
        _a = 0;
        _b = probs.size();
    }

    double c = _a;
    while(abs(_a - _b) > 1)
    {
        c = round((_a + _b) / 2);
        //cout << "Root finding: " << c << " " << getProb(c) << endl;
        double d;

        if(_u > getProb(c) && _u <= getProb(c+1))
            return c+1;

        if((getProb(c)-_u) * (getProb(_a)-_u) < 0)
        {
            _b = c;
            //cout << "b " << b << endl;
        }
        else
        {
            _a = c;
            //cout << "a " << a << endl;
        }
    }

    //return c;
}


int MultinomialDistribution::bisection(mt19937_64 _gen, int _a, int _b)
{
    uniform_real_distribution<double> unifDist(0.0, *max_element(begin(probs), end(probs)));
    double _u = unifDist(_gen);
    cout << _u << " " << getProb(0) << endl;
    if(_u <= getProb(0))
        return 0;

    /*if(_u >= getProb(probs.size()-1))
    {
        //cout << "hello " << getProb(probs.size()-1) << endl;
        return (probs.size());
    }*/

    if((getProb(_a) - _u) * (getProb(_b) - _u) >= 0)
    {
        _a = 0;
        _b = probs.size();
    }

    double c = _a;
    while(abs(_a - _b) > 1)
    {
        c = round((_a + _b) / 2);
        //cout << "Root finding: " << c << " " << getProb(c) << endl;
        double d;

        if(_u > getProb(c) && _u <= getProb(c+1))
            return c+1;

        if((getProb(c)-_u) * (getProb(_a)-_u) < 0)
        {
            _b = c;
            //cout << "b " << b << endl;
        }
        else
        {
            _a = c;
            //cout << "a " << a << endl;
        }
    }

    //return c;
}


