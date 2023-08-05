//
// Created by Tomáš Petříček on 05.08.2023.
//

#ifndef LEET_CODE_ROTATE_IMAGE_HPP
#define LEET_CODE_ROTATE_IMAGE_HPP

#include <vector>
#include <algorithm>
#include <cassert>

namespace leet_code {
    void rotate(std::vector<std::vector<int>>& matrix)
    {
        std::size_t n{matrix.size()}, l;
        for (std::size_t c{0}; c<n/2; c++) {
            l = n-c-1;
            for (std::size_t i{0}; i<l-c; i++) {
                std::swap(matrix[c][c+i], matrix[c+i][l]);
                std::swap(matrix[l-i][c], matrix[l][l-i]);
                std::swap(matrix[c][c+i], matrix[l][l-i]);
            }
        }
    }

    struct sample {
        std::vector<std::vector<int>> in, out;
    };

    void test_rotate()
    {
        std::vector<sample> samples{
                {{{1, 2},          {3, 4}},                                                                             {{3,  1},            {4,  2}}},
                {{{1, 2, 3},       {4, 5, 6},        {7,  8,  9}},                                                      {{7,  4,  1},        {8,  5,  2},        {9,  6,  3}}},
                {{{5, 1, 9, 11},   {2, 4, 8, 10},    {13, 3,  6,  7},      {15, 14, 12, 16}},                           {{15, 13, 2,  5},    {14, 3,  4,  1},    {12, 6,  8,  9},    {16, 7,  10, 11}}},
                {{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}}, {{21, 16, 11, 6, 1}, {22, 17, 12, 7, 2}, {23, 18, 13, 8, 3}, {24, 19, 14, 9, 4}, {25, 20, 15, 10, 5}}},
        };
        for (auto& s: samples) {
            rotate(s.in);
            assert(s.in==s.out);
        }
    }
}

#endif //LEET_CODE_ROTATE_IMAGE_HPP
