
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <exception>
#include <functional>
#include <cstdlib>
#include <cmath>

namespace geometry2d {

    template<typename X, typename Y>
    struct Point {
        X x;
        Y y;

        Point(): Point(X(), Y()) {
        }

        template<typename X1, typename Y1>
        Point(X1 x, Y1 y) : x(x), y(y) {
        }

        virtual ~Point() {
        }
    };

    template<typename Y>
    struct Point<int, Y> {
        int x;
        Y y;

        Point(): Point(0, Y()) {
        }

        template<typename X1, typename Y1>
        Point(X1 x, Y1 y) : x(x), y(y) {
        }

        virtual ~Point() {
        }
    };

    template<>
    struct Point<int, int> {
        int x;
        int y;

        Point(): Point(0, 0) {
        }

        template<typename X1, typename Y1>
        Point(X1 x, Y1 y) : x(x), y(y) {
        }

        virtual ~Point() {
        }
    };

    template<typename X, typename Y>
    bool operator==(const Point<X,Y>& p1, const Point<X,Y>& p2)
    {
        return p1.x == p2.x && p1.y == p2.y;
    }

    template<typename X, typename Y>
    std::ostream& operator<<(std::ostream& os, const Point<X, Y>& p)
    {
        os << "(" << p.x << "; " << p.y << ")";

        return os;
    }

    template<typename T, typename K, int size>
    int find_by(T(&a)[size], const K& key)
    {
        for (int i = 0; i < size; ++i)
        {
            if (a[i] == key) {
                return i;
            }
        }
        return -1;
    }

    template<typename X, typename Y, int size>
    int find_by(Point<X,Y>(&a)[size], const Point<X, Y>& key)
    {
        for (int i = 0; i < size; ++i)
        {
            if (a[i] == key) {
                return i;
            }
        }
        return -1;
    }
}