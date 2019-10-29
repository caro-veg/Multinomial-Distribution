#ifndef MULTINOMIALDISTRIBUTION_H_INCLUDED
#define MULTINOMIALDISTRIBUTION_H_INCLUDED

#include <vector>
#include <map>
#include <random>

using std::vector;
using std::map;
using std::mt19937_64;

class MultinomialDistribution
{
public:
     MultinomialDistribution(vector<double> _probs);
    ~MultinomialDistribution();

    int drawNumber(double _rn);
    double getProb(int _n);
    int bisection(int _n1, int _n2, double _u);
    int bisection(mt19937_64 _gen, int _n1, int _n2);

    vector<double> probs;
    map<int, double> probMap;
};

#endif // MULTINOMIALDISTRIBUTION_H_INCLUDED
