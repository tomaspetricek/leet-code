//
// Created by Tomáš Petříček on 15.08.2023.
//

#ifndef LEET_CODE_MATRIX_DIAGONAL_SUM_HPP
#define LEET_CODE_MATRIX_DIAGONAL_SUM_HPP

#include <vector>
#include <cassert>

namespace leet_code {
    int diagonalSum(std::vector<std::vector<int>>& mat)
    {
        std::size_t size{mat.size()};
        int sum{0};
        for (std::size_t r{0}; r<size; r++) {
            sum += mat[r][r]+mat[r][size-r-1];
        }
        // subtract center if odd
        if (size%2) {
            std::size_t c{size/2};
            sum -= mat[c][c];
        }
        return sum;
    }
}

#endif //LEET_CODE_MATRIX_DIAGONAL_SUM_HPP
