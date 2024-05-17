
#pragma once

#include <iostream>
#include <cmath>

namespace geometry
{
    template<typename T>
    struct Point final
    {
        T x;
        T y;

        Point(): Point(T(), T()) {
        }

        Point(const T& x, const T& y) : x(x), y(y) {

        }

        ~Point() = default;

        template<typename V>
        double distance(const Point<V> other) const
        {
            auto dx = x - other.x;
            auto dy = y - other.y;

            return std::sqrt(dx * dx + dy * dy);
        }
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Point<T>& p)
    {
        os << "(" << p.x << "; " << p.y << ")";

        return os;
    }
}