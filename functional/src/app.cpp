#include "app.hpp"

#include <iostream>
#include <ostream>

using namespace std;

class Summator
{
  int origin;
  public:

  Summator(): Summator(0) {}

  Summator(int origin_): origin(origin_) {}

  int operator()(int i, int j) const
  {
    return origin + i + j;
  }

};

class Mutlipliyer
{
public:

  Mutlipliyer() = default;

  int operator()(int i, int j) const
  {
    return i * j;
  }

};

int main() {

  Mutlipliyer m1;

  auto r = m1(3, 4);

  cout << r << endl;

  Summator s1{-5};

  // r = s1(3, 4);
  // cout << r << endl;

  {
    auto origin = -5;

    auto summator = [origin](int i, int j)
    {
      return origin + i + j;
    };

    auto r = summator(3, 4);

    cout << r << endl;
  }
  return 0;
}
