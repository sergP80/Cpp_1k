#pragma once

namespace calculator
{
    class Calculator
    {
        double a;
        double b;

    public:
        Calculator(const double& a_, const double& b_): a(a_), b(b_) {}

        [[nodiscard]] double compute(const double& x) const;
    };
}