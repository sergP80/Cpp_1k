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

    class ShapeComputable {
        //VMT
        virtual double area() const = 0;

        virtual double perimeter() const = 0;
    };

    class Shape2D {
    protected:
        int x;
        int y;
    public:
        Shape2D() = default;

        Shape2D(int x_, int y_) : x(x_), y(y_) {
        }

        virtual ~Shape2D() {
        }

        int getX() const {
            return x;
        }

        void setX(int x) {
            this->x = x;
        }

        int getY() const {
            return y;
        }

        void setY(int y) {
            Shape2D::y = y;
        }
    };

    class Circle: public Shape2D, public ShapeComputable
    {
    private:
        int radius;
    public:

        Circle() = default;

        Circle(int x, int y, int radius) : Shape2D(x, y), radius(radius) {}

        ~Circle() override {
        }

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

        void foo() {
            std::cout << "Foo from Circle" << std::endl;
        }

    };

    class Rectangle: public Shape2D, public ShapeComputable
    {
    private:
        int w;
        int h;
    public:
        Rectangle() = default;

        Rectangle(int x, int y, int w, int h) : Shape2D(x, y), w(w), h(h) {}

        ~Rectangle() override {

        }

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

        void foo() {
            std::cout << "Foo from Rectangle" << std::endl;
        }
    };

    class RectangleTriangle : public Shape2D, public ShapeComputable
    {
    private:
        int w;
        int h;
    public:
        RectangleTriangle() {}

        RectangleTriangle(int x, int y, int w, int h) : Shape2D(x, y), w(w), h(h) {}

        int getW() const {
            return w;
        }

        void setW(int w) {
            this->w = w;
        }

        int getH() const {
            return h;
        }

        void setH(int h) {
            this->h = h;
        }

        int getC() const {
            return std::sqrt(w*w + h*h);
        }

        double area() const override {
            return 1.0*w * 1.0*h/2.0;
        }

        double perimeter() const override {
            return 1.0 * w + 1.0 * h + getC();
        }
    };

    class CircleRectangle: public virtual Circle, public virtual Rectangle {
    public:
        CircleRectangle() = default;

        CircleRectangle(int x_, int y_, int w_, int h_, int r)
            : Circle(x_, y_, r)
            , Rectangle(x_, y_, w_, h_)
        {}

        ~CircleRectangle() override {

        }

        double area() const override {
            return 100;
        }

        double perimeter() const override {
            return 200;
        }

        void foo()
        {
            std::cout << "Foo from CircleRectangle" << std::endl;
        }
    };

    class Point2D
    {
        int x;
        int y;

        static int global_count_;

    public:
        Point2D(): Point2D(0, 0)
        {}

        Point2D(int x_, int y_): x(x_), y(y_) {
            ++global_count_;
        }

        Point2D(const Point2D& rhs) : Point2D(rhs.x, rhs.y)
        {
            std::cout << "Copy point" << std::endl;
        }

        ~Point2D()
        {
            global_count_--;
        }

        Point2D & operator=(const Point2D& rhs)
        {
            std::cout << "Assigment point" << std::endl;

            if (&rhs != this)
            {
                this->x = rhs.x;
                this->y = rhs.y;
            }

            return *this;
        }

        Point2D& operator+=(const int& dec)
        {
            this->x += dec;

            this->y += dec;

            return *this;
        }

        int getX() const {
            return x;
        }

        void setX(int x) {
            Point2D::x = x;
        }

        int getY() const {
            return y;
        }

        void setY(int y) {
            Point2D::y = y;
        }

        static int global_count() {
            return global_count_;
        }

        friend std::ostream& operator<<(std::ostream& os, const Point2D& p);
    };

    int Point2D::global_count_ = 0;

    std::ostream& operator<<(std::ostream& os, const Point2D& p)
    {
        os << "Point(";
        os << p.x;
        os << ", " << p.y;
        os << ")";
        return os;
    }
}