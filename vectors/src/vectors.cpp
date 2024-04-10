#include "vectors.h"

using namespace std;

//function<bool(int)>
bool is_odd (int a)
{
    return a% 2 == 0;
}

//function<int(int, int)>
//int(int, int)
int max (int a, int b)
{
    return a < b ? b : a;
}

//function<double(double, double)>
double max (double a, double b)
{
    return a < b ? b : a;
}

//function<vector<int>(const vector<int>&)>
//vector<int> sub_vector(const vector<int>& v);

vector<int> sub_vector(const vector<int>& v, function<bool(const int)> predicate)
{
    vector<int> result;

    auto it = v.cbegin();

    do {
        it = find_if(it, v.end(), predicate);

        if (it != v.end())
        {
            result.push_back(*it);
            ++it;
        }
    } while (it != v.cend());

    return result;
}

template<typename T>
ostream & operator<<(ostream& os, const vector<T> v)
{
    os << "[";

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
        {
            os << ", ";
        }

        os << *it;
    }

    os << "]";

    return os;
}

int main()
{

    vector<int> v1 {-1, 3, 4, 8, 10, 11, 18, 20};

    auto even_predicate = [](const auto i) {
        return i % 2 == 0;
    };

    auto odd_predicate = [](const auto i) {
        return i % 2 != 0;
    };

    {
        auto result = sub_vector(v1, even_predicate);

        cout << result << endl;

    }

    {
        auto result = sub_vector(v1, odd_predicate);

        cout << result << endl;

    }

    return 0;
}
