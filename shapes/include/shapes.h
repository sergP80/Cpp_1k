#pragma once

#include <iostream>
#include <cmath>
#include <exception>

#ifdef _WIN32

#ifdef _MSC_VER

#define PI M_PI
#endif // _MSVC_VER

#else

#define PI M_1_PI

#endif // _WIN32

//SOLID
/*

S - Single Responsibility
O - Open-Closed
L - Liskov Substituion
I - Interface Segration
D - Dependency Injection
*/

namespace shapes
{

    class Shape2D {
    protected:
        int x;
        int y;
    public:
        Shape2D() = default;

        Shape2D(int x_, int y_) : x(x_), y(y_) {}

        int getX() const {
            return x;
        }

        void setX(int x) {
            Shape2D::x = x;
        }

        int getY() const {
            return y;
        }

        void setY(int y) {
            Shape2D::y = y;
        }
        //VMT
        virtual double area() const = 0;

        virtual double perimeter() const = 0;
    };

    class Circle: public Shape2D
    {
    private:
        int radius;
    public:

        Circle() {}

        Circle(int x, int y, int radius) : Shape2D(x, y), radius(radius) {}

        int getRadius() const {
            return radius;
        }

        void setRadius(int radius) {
            Circle::radius = radius;
        }

        double area() const override {
            return PI * radius * radius;
        }

        double perimeter() const override {
            return 2* PI * radius;
        }

    };

    class Rectangle: public Shape2D
    {
    private:
        int w;
        int h;
    public:
        Rectangle() {}

        Rectangle(int x, int y, int w, int h) : Shape2D(x, y), w(w), h(h) {}

        int getW() const {
            return w;
        }

        void setW(int w) {
            Rectangle::w = w;
        }

        int getH() const {
            return h;
        }

        void setH(int h) {
            Rectangle::h = h;
        }

        double area() const override {
            return w*h;
        }

        double perimeter() const override {
            return 2 *(w + h);
        }
    };
}