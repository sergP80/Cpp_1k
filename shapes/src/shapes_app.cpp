#include "shapes.h"
#include "context.h"

using namespace std;

using namespace shapes;



void point_demo(Point2D p)
{
    p.setX(2*p.getX());
    p.setY(2*p.getY());
}

//void point_demo(Point2D &p)
//{
//    p.setX(2*p.getX());
//    p.setY(2*p.getY());
//}

void point_demo(Point2D* p)
{
    p->setX(2*p->getX());
    p->setY(2*p->getY());
}

int main()
{

//    {
//        cout << "--- Circle ---" << endl;
//
//        Circle circle(100, 100, 200);
//
//        Shape2D& s = circle;
//
//        cout << s.area() << endl;
//
//        cout << s.perimeter()<< endl;
//    }
//
//    {
//        cout << "--- Rectangle ---" << endl;
//        Rectangle r{200, 300, 15, 10};
//
//        Shape2D& s2 = r;
//
//        cout << s2.area() << endl;
//
//        cout << s2.perimeter()<< endl;
//
//        const context::ShapeDrawer& drawer = context::RectangleConsoleShapeDrawer(r, cout);
//
//        drawer.draw();
//    }
//
//    {
//        cout << "--- Rectangle Triangle ---" << endl;
//        RectangleTriangle r{200, 300, 7, 5};
//
//        Shape2D& s2 = r;
//
//        cout << s2.area() << endl;
//
//        cout << s2.perimeter()<< endl;
//
//        const context::ShapeDrawer& drawer = context::RectangleTringleConsoleShapeDrawer(r, cout);
//
//        drawer.draw();
//    }

//    {
//        CircleRectangle cr1(-20, -50, 100, 200, 145);
//
//        cout << cr1.perimeter() << endl;
//        cout << cr1.area() << endl;
//
//        cr1.foo();
//
//        Circle* pc1 = &cr1;
//
//        pc1->foo();
//
//        cout <<  pc1->perimeter() << endl;
//
//        Rectangle* pr1 = &cr1;
//
//        cout <<  pr1->perimeter() << endl;
//
//        pr1->foo();
//
//    }

//    {
//        Point2D p0 = Point2D{10, 20};
//
//        cout << p0 << endl;
//
//        Point2D* pp0 = &p0;
//
//        point_demo(p0);
//
//        point_demo(pp0);
//
//        cout << p0 << endl;
//    }

    {
        Point2D p1{ -10, 15};

        cout << p1 << endl;

        cout << Point2D::global_count() << endl;

        {
            Point2D p2;

            p2 = p1;

            p1 += 2;
            cout << p2 << endl;

            cout << Point2D::global_count() << endl;
        }

        cout << Point2D::global_count() << endl;

    }

    return 0;
}
