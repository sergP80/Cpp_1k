
#pragma once

#include "matrix.h"

namespace matrix {
    void RealMatrix::init() {
        data_ = new double* [rows_];

        for (int i = 0; i < rows_; ++i) {
            data_[i] = new double[cols_];
        }
    }

    void RealMatrix::clear() {

        if (data_ == nullptr) {
            return;
        }

        for (int i = 0; i < rows_; ++i) {
            if (data_[i]) {
                delete[] data_[i];
                data_[i] = nullptr;
            }
        }

        delete[] data_;

        data_ = nullptr;
    }

    void RealMatrix::check_range(int i, int limit) const {
        if (i < 0 || i >= limit) {
            throw xOutOfBoundException(i, limit);
        }
    }

    RealMatrix::RealMatrix(int rows, int cols)
            : rows_(rows)
            , cols_(cols)
            , data_(nullptr)
    {
        init();
    }

    RealMatrix::~RealMatrix() {
        clear();

        std::cout << "Destroy matrix";
    }

    void RealMatrix::fill_by(std::function<double(int, int)> filler) {
        if (data_ == nullptr)
        {
            return;
        }

        for (int i = 0; i < rows_; ++i)
        {
            for (int j = 0; j < cols_; ++j)
            {
                data_[i][j] = filler(i, j);
            }
        }
    }

    void RealMatrix::fill_random(double from, double to) {

    }

    std::ostream& operator<<(std::ostream &os, const RealMatrix &rm) {
        for (int i = 0; i < rm.getRows(); ++i)
        {
            os << "|";
            for (int j = 0; j < rm.getCols(); ++j)
            {
                auto item = rm(i, j);

                if (j > 0)
                {
                    os << ", ";
                }

                os << item;
            }

            os << "|" << std::endl;
        }
        return os;
    }
}
