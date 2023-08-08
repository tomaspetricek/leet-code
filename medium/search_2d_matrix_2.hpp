//
// Created by Tomáš Petříček on 06.08.2023.
//

#ifndef LEET_CODE_SEARCH_2D_MATRIX_2_HPP
#define LEET_CODE_SEARCH_2D_MATRIX_2_HPP

#include <vector>
#include <algorithm>

namespace leet_code {
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {

    }

    struct sample {
        std::vector<std::vector<int>> matrix;
        int target;
        bool present;
    };

    void test_search_matrix()
    {
        std::vector<sample> samples{
                {{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}, 5,  true},
                {{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}, 20, false},
        };
        for (auto& s: samples) {
            assert(searchMatrix(s.matrix, s.target)==s.present);
        }
    }
}

#endif //LEET_CODE_SEARCH_2D_MATRIX_2_HPP
