#include "shapes.h"
#include "context.h"

using namespace std;

using namespace shapes;

int main()
{

    {
        cout << "--- Circle ---" << endl;

        Circle circle(100, 100, 200);

        Shape2D& s = circle;

        cout << s.area() << endl;

        cout << s.perimeter()<< endl;
    }

    {
        cout << "--- Rectangle ---" << endl;
        Rectangle r{200, 300, 15, 10};

        Shape2D& s2 = r;

        cout << s2.area() << endl;

        cout << s2.perimeter()<< endl;

        context::ShapeDrawer& drawer = context::RectangleConsoleShapeDrawer(r, cout);

        drawer.draw();
    }


    return 0;
}
