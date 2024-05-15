#include <ostream>

#include "smart-ptr.h"

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

template<typename T1, typename T2>
struct  Tuple2
{
    T1 t1;
    T2 t2;

    Tuple2(const T1& t1, const T2& t2)
        : t1(t1),
          t2(t2)
    {
        cout << "Create tuple [" << t1 << ";" << t2 << "]" << endl;
    }

    ~Tuple2()
    {
        cout << "Destroy tuple [" << t1 << ";" << t2 << "]" << endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Tuple2& obj)
    {
        return os
            << "t1: " << obj.t1
            << " t2: " << obj.t2;
    }
};

int main()
{
    {
        cout << "===== Example of shared_ptr" << endl;

        shared_ptr<Point> share_point1 = make_shared<Point>(4, 9);

        shared_ptr<Point> share_point2 = make_shared<Point>(5, 7);

        {
            shared_ptr<Point> share_point3 = make_shared<Point>(10, -5);

            share_point1 = share_point3;
        }

        cout << *share_point1 << endl;

        cout << "============================" << endl;
    }

    {
        cout << "===== Example of unique_ptr" << endl;

        unique_ptr<Tuple2<int, string>> u_p1 = make_unique<Tuple2<int, string>>(3, "245234");
        unique_ptr<Tuple2<int, string>> u_p2 = make_unique<Tuple2<int, string>>(4, "6576432");

        u_p1 = move(u_p2);

        cout << *u_p1 << endl;
        cout << "============================" << endl;
    }

    {
        cout << "===== Example of custom smart share ptr" << endl;

        using smart_ptr::SmartPtr;
        using smart_ptr::make_smart;

        SmartPtr s_point = make_smart<Point>(14, 12);
        cout << *s_point << "[" << s_point.usage_count() << "]" << endl;

        s_point = make_smart<Point>(20, 14);
        cout << *s_point << "[" << s_point.usage_count() << "]" << endl;

        SmartPtr<Tuple2<string, double>> s_tuple1 = make_smart<Tuple2<string, double>>("Hello", 12.5);

        cout << *s_tuple1 << "[" << s_tuple1.usage_count() << "]" << endl;

        SmartPtr<Tuple2<string, double>> s_tuple2 = make_smart<Tuple2<string, double>>("Bye", 45.3);

        cout << *s_tuple2 << "[" << s_tuple2.usage_count() << "]" << endl;

        s_tuple2 = s_tuple1;

        cout << *s_tuple2 << "[" << s_tuple2.usage_count() << "]" << endl;

        cout << "============================" << endl;
    }

    return 0;
}
