#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "MultinomialDistribution.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    unsigned seed = 1244;
    mt19937_64 gen(seed);

    //vector<double> probs {1.0, 0.002, 1.0, 1.0, 0.0004, 0.05, 0.005, 0.1};
    //vector<double> probs{0.0142578, 0.012184, 0.0142578, 0.0109479, 0.00811079, 0.00612931, 0.0339339, 0.0271615, 0.0339339, 0.018237, 0.0109479, 0.00739799, 1, 1, 1, 0.0339339, 0.0142578, 0.00853397, 1, 1, 1, 0.0271615, 0.012184, 0.00756678, 1, 1, 1, 0.0339339, 0.0142578, 0.00853397};
    //vector<double> probs{0.020513, 0.0213483, 0.0186088, 0.0228913, 0.0175824, 0.0174699, 0.0179134, 0.0221558, 0.0257468, 0.0332394, 0.032678, 0.0344565, 0.0315489, 0.0327203, 0.043948, 0.0517692, 0.0323035, 0.026291, 0.0509678, 0.0630634, 0.0245783, 0.0258429, 0.0287628, 0.0268431, 0.0828288, 0.0770797, 0.0739539};
    vector<double> probs{0.00612931, 0.00811079, 0.0109479, 0.0142578, 0.012184, 0.0142578, 0.00739799, 0.0109479, 0.018237, 0.0339339, 0.0271615, 0.0339339, 0.00853397, 0.0142578, 0.0339339, 1, 1, 1, 0.00756678, 0.012184, 0.0271615, 1, 1, 1, 0.00853397, 0.0142578, 0.0339339, 1, 1, 1};
    MultinomialDistribution mn(probs);

    for(unsigned i=0; i<mn.probs.size(); ++i)
    {
        cout << mn.probMap[i] << " ";
    }
    cout << endl;

    cout << endl << mn.probs.size() << " " << mn.getProb(mn.probs.size()-1) << endl;

    uniform_real_distribution<double> unifDist(0.0, *max_element(begin(mn.probs), end(mn.probs)));
    vector<int> out(probs.size(), 0);
    for(int i=0; i<100; ++i)
    {
        double u = unifDist(gen);
        //cout << u << " " << mn.bisection(0, probs.size()-1, u) << endl;
        //out.at(mn.bisection(0, probs.size()-1, u))++;
        out.at(mn.bisection(gen, 0, probs.size()-1))++;
    }
    cout << endl;

    for(unsigned i=0; i<out.size(); ++i)
    {
        cout << probs.at(i) << "\t" << out.at(i) << endl;
    }
    cout << endl;

    return 0;
}
