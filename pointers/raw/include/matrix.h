
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <exception>
#include <functional>
#include <cstdlib>

namespace matrix {

    struct xOutOfBoundException: public std::runtime_error {
        explicit xOutOfBoundException(int index, int limit): std::runtime_error(to_string(index, limit))
        {}

        static std::string to_string(int index, int limit)
        {
            std::stringstream sin;
            sin << "Invalid index [" << index << "] with limit [" << limit << "]";

            return sin.str();
        }
    };

    class RealMatrix final {
        int rows_;
        int cols_;

        double **data_;
    protected:
        void init();

        void clear();

        void check_range(int i, int limit) const;

    public:
        RealMatrix(int rows, int cols);

        RealMatrix(const RealMatrix& rhs) = delete;
        RealMatrix& operator=(const RealMatrix& rhs) = delete;

        virtual ~RealMatrix();

        int getRows() const {
            return rows_;
        }

        int getCols() const {
            return cols_;
        }

        void fill_by(std::function<double(int, int)> filler);

        void fill_random(double from, double to);

        const double& operator()(int i, int j) const {
            check_range(i, rows_);
            check_range(j, cols_);

            return data_[i][j];
        }

        double& operator()(int i, int j) {
            check_range(i, rows_);
            check_range(j, cols_);

            return data_[i][j];
        }

    };

    std::ostream& operator<<(std::ostream&, const RealMatrix&);
}