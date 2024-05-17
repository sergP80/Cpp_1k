
#pragma once

#include <iostream>

namespace tuples
{

    template<typename T1, typename T2>
    struct  Tuple2
    {
        T1 t1;
        T2 t2;

        Tuple2(const T1& t1, const T2& t2)
            : t1(t1),
              t2(t2)
        {
        }

        ~Tuple2()
        {
        }

        friend std::ostream& operator<<(std::ostream& os, const Tuple2& obj)
        {
            return os
                << "t1: " << obj.t1
                << " t2: " << obj.t2;
        }
    };
}