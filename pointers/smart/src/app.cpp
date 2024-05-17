
#include "app.h"

using namespace std;

using geometry::Point;

using tuples::Tuple2;

int main()
{
    {
        cout << "===== Example of shared_ptr" << endl;

        shared_ptr<Point<int>> share_point1 = make_shared<Point<int>>(4, 9);

        shared_ptr<Point<int>> share_point2 = make_shared<Point<int>>(5, 7);

        {
            shared_ptr<Point<int>> share_point3 = make_shared<Point<int>>(10, -5);

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

        SmartPtr s_point = make_smart<Point<int>>(14, 12);
        cout << *s_point << "[" << s_point.usage_count() << "]" << endl;

        s_point = make_smart<Point<int>>(20, 14);
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
