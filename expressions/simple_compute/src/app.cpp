#include "app.hpp"

using std::cin;
using std::cout;
using std::endl;

using std::pow;
using std::sin;

namespace simple_compute
{
  double compute(const double& x, const double& a, const double& b)
  {
    return pow(2, a - x) * sin(6*x - b);
  }
}

int main() {

  //using simple_compute::compute;

  {
    cout << "Task #1" << endl;
    //C++ 11 and later
    auto a = -5.36, b = 2.38, x = 14.09;

    const auto result = simple_compute::compute(x, a, b);

    cout << result << endl;
  }

  {
    cout << "Task #2" << endl;
    auto a {0.0}, b {0.0}, x {0.0};

    cout << "Type a, b, x:";

    cin >> a >> b >> x;

    const auto result = simple_compute::compute(x, a, b);

    cout << result << endl;
  }

  {
    using calculator::Calculator;

    cout << "Task #3. Using Calculator" << endl;

    auto a {0.0}, b {0.0}, x {0.0};

    cout << "Type a, b, x:";

    cin >> a >> b >> x;

    Calculator calculator(a, b);

    const auto result = calculator.compute(x);

    cout << result << endl;
  }

  return 0;
}
