#include "calculator.hpp"
#include  <cmath>

namespace calculator
{

    using std::pow;
    using std::sin;

    double Calculator::compute(const double& x) const
    {
        return pow(2, a - x) * sin(6*x - b);
    }

}