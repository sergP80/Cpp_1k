#include "matrix.h"

using namespace std;

struct Point {
    int x;
    int y;

    Point(): Point(0, 0) {
        cout << "Create point" << endl;
    }

    Point(int x, int y) : x(x), y(y) {

        cout << "Created point: " << x << ";" << y << endl;
    }

    virtual ~Point() {
        cout << "Destroyed point: " << x << ";" << y << endl;
    }
};

ostream& operator<<(ostream& os, const Point& p)
{
    os << "(" << p.x << "; " << p.y << ")";

    return os;
}

//void*

//new/delete

/**
 new
 * Allocate memory
 * Place and init object
 * Call constructor
 */

/**
 delete
 * Call destructor
 * Deinit and remove object
 * Deallocate memory
 */
//new[]/delete[]
int main()
{

//    Point p{4, 5};
    //malloc/free
    //calloc/free

//    {
//        cout << "Example 1 ====================" << endl;
//        auto pp1 = new Point;
//        auto pp2 = new Point(4, 5);
//
//        try
//        {
//            throw "Error";
//        }
//        catch (const char* e)
//        {
//            cout << "Caught error: " << e << endl;
//            delete pp1;
//            delete pp2;
//
//            pp1 = nullptr;
//            pp2 = nullptr;
//        }
//
//        if (pp1) {
//            delete pp1;
//        }
//        if (pp2) {
//            delete pp2;
//        }
//
//    }
//
//    {
//        cout << "Example 2 ====================" << endl;
//        auto size = 10;
//
//        Point *points = new Point[size];
//
////        for (int i = 0; i < size; ++i)
////        {
////            cout << points[i] << endl;
////        }
//
//        delete[] points;
//    }

    {
        using matrix::RealMatrix;
        using matrix::operator<<;

        int sz = 3;

        RealMatrix rm{sz,sz};

        cout << rm << endl;

        rm.fill_by([&](int i, int j) {
           if (i == j) {
               return i + j + 1.0;
           } else if (i < j) {
               return i - j - 1.0;
           } else {
               return j - i + 1.0;
           }
        });

        cout << rm << endl;

    }


    return 0;
}
