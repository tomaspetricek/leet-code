//
// Created by Tomáš Petříček on 27.08.2023.
//

#ifndef LEET_CODE_SET_MATRIX_ZEROES_HPP
#define LEET_CODE_SET_MATRIX_ZEROES_HPP

#include <vector>
#include <cassert>

// topic: set matrix zeroes
// link: https://leetcode.com/problems/set-matrix-zeroes/
namespace leet_code {
    void set_zeros(std::vector<std::vector<int>>& matrix, std::size_t row, std::size_t col)
    {
        // zero column upwards
        std::size_t r{row};
        while (r--) {
            matrix[r][col] = 0;
        }
        // zero column downwards
        r = row+1;
        for (; r<matrix.size(); r++) {
            matrix[r][col] = 0;
        }
        // zero row left
        std::size_t c{col};
        while (c--) {
            matrix[row][c] = 0;
        }
        // zero row right
        c = col+1;
        for (; c<matrix[0].size(); c++) {
            matrix[row][c] = 0;
        }
    }

    void setZeroes(std::vector<std::vector<int>>& matrix)
    {
        std::vector<std::vector<int>> copy{matrix};
        for (std::size_t r{0}; r<matrix.size(); r++) {
            for (std::size_t c{0}; c<matrix[0].size(); c++) {
                if (!copy[r][c]) {
                    set_zeros(matrix, r, c);
                }
            }
        }
    }

    struct sample {
        std::vector<std::vector<int>> matrix, out;
    };

    void test_set_zeroes()
    {
        std::vector<sample> samples{
                {{{1, 1, 1},    {1, 0, 1},    {1, 1, 1}},    {{1, 0, 1},    {0, 0, 0},    {1, 0, 1}}},
                {{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}, {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}}},
        };
        for (auto& s: samples) {
            setZeroes(s.matrix);
            assert(s.matrix==s.out);
        }
    }
}

#endif //LEET_CODE_SET_MATRIX_ZEROES_HPP
