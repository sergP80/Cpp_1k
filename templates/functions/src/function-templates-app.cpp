#include "search.h"

using namespace std;

int main()
{

    {
        int a_i[] = {-1, 4, 5, 8};

        double a_d[] = {-1.2, 3.41, 5.8, 4};

        string a_s[] = {"JJJJ", "34232", "KKKKL"};

        cout << "Found int " << find_by(a_i,  5) << endl;
        cout << "Found double " << find_by(a_d,  4) << endl;
        cout << "Found string " << find_by(a_s,  "KKKKL") << endl;
    }

    return 0;
}
