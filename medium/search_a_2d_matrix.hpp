//
// Created by Tomáš Petříček on 15.07.2023.
//

#ifndef LEET_CODE_SEARCH_A_2D_MATRIX_HPP
#define LEET_CODE_SEARCH_A_2D_MATRIX_HPP

#include <cassert>
#include <vector>
#include <algorithm>

namespace leet_code {
    using matrix_t = std::vector<std::vector<int>>;

    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        for (std::size_t r{0}; r<matrix.size(); r++) {
            if (target<=matrix[r].back()) {
                return std::binary_search(matrix[r].begin(), matrix[r].end(), target);
            }
        }
        return false;
    }

    struct data {
        matrix_t matrix;
        int target;
        bool found;
    };

    void test_search_matrix()
    {
        std::vector<data> samples{
                {{{1}}, 1, true},
                {{{ 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 }}, 3, true },
                {{{ 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 }}, 13, false },
        };
        for (auto& s: samples) {
            if (searchMatrix(s.matrix, s.target)!=s.found) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_SEARCH_A_2D_MATRIX_HPP
