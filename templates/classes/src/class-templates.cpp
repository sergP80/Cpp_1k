#include "point.h"

using namespace std;
using geometry2d::Point;
using geometry2d::find_by;


int main()
{
    {
        Point<int, int> a_p[] = {
                {-1, 2},
                {3, 4},
                {5, 7}
        };

        Point<double, int> a_p2[] = {
                {-1.3, 2},
                {3.4, 4},
                {5.1, 7},
                {-1.8, 14}
        };

        cout << "Found point " << find_by(a_p,  Point<int, int>(5, 7)) << endl;
        cout << "Found point " << find_by(a_p2,  Point<double, int>(-1.3, 2)) << endl;
    }

    return 0;
}
