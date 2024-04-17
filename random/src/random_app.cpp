#include "random_app.h"

using namespace std;


int main()
{

//    mt19937 mt32 {
//        static_cast<mt19937::result_type>(chrono::steady_clock::now().time_since_epoch().count())
//    };

    random_device rnd {};
    mt19937 mt32 {rnd()};
//    mt19937 mt32;

    {
        int from = -100, to = 100;
        cout << "Int distribution from " << from << " to "<< to <<endl;
        uniform_int_distribution uid {from, to};
        for (auto i{0}; i < 10; ++i)
        {
            cout << uid(mt32) << endl;
//            cout << mt32() << endl;
        }

    }

    {
        auto from = -10.55, to = 10.95;
        cout << "Real distribution from " << from << " to "<< to <<endl;
        uniform_real_distribution urd {from, to};

        for (auto i{0}; i < 10; ++i)
        {
            cout << urd(mt32) << endl;
        }

    }


    return 0;
}
