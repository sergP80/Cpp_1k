#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <exception>

struct Student
{
    std::string name;
    int age;
    double scoring;
};

std::ostream& operator<<(std::ostream& os, const Student& s)
{
    os << "{";

    os << "name: " << s.name;
    os << ", age: " << s.age;
    os << ", scoring: " << std::setprecision(3) << s.scoring;
    os << "}";

    return os;
}