#include "vectors.h"

using namespace std;

//bool(int)
//function<bool(int)>
bool is_even(int a)
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

//    vector<int> v1 {-1, 3, 4, 8, 10, 11, 18, 20, -3, -10, 12};
//
//    auto even_predicate = [](const auto i) {
//        return i % 2 == 0;
//    };
//
//    auto odd_predicate = [](const auto i) {
//        return i % 2 != 0;
//    };
//
//    auto negative_predicate = [](const auto i) {
//        return i < 0;
//    };
//
//    {
//        auto result = sub_vector(v1, even_predicate);
//
//        cout << result << endl;
//
//    }
//
//    {
//        auto result = sub_vector(v1, odd_predicate);
//
//        cout << result << endl;
//
//    }
//
//    {
//        auto result = sub_vector(v1, negative_predicate);
//
//        cout << result << endl;
//
//    }

    {
        vector<Student> students{
                {"Bob", 18, 4.64},
                {"Alice", 22, 4.8},
                {"Dillon", 19, 4.75},
                {"Jess", 23, 4.55}
        };

        auto sort_by_name = [](const Student& s1, const Student& s2)
        {
            return s1.name < s2.name;
        };

        auto sort_by_age = [](auto& s1, auto& s2)
        {
            return s1.age < s2.age;
        };

        auto sort_by_score = [](auto& s1, auto& s2)
        {
            return s1.scoring < s2.scoring;
        };

        cout << "Before..." << endl;
        cout << students << endl;

        cout << "After by name" << endl;
        sort(students.begin(), students.end(), sort_by_name);

        cout << students << endl;

        cout << "After by age" << endl;
        sort(students.begin(), students.end(), sort_by_age);

        cout << students << endl;

        cout << "After by score" << endl;
        sort(students.begin(), students.end(), sort_by_score);

        cout << students << endl;

    }



    return 0;
}
