//
// Created by Tomáš Petříček on 14.08.2023.
//

#ifndef LEET_CODE_COUNT_SQUARE_SUBMATRICES_WITH_ALL_ONES_HPP
#define LEET_CODE_COUNT_SQUARE_SUBMATRICES_WITH_ALL_ONES_HPP

#include <vector>
#include <cassert>

namespace leet_code {
    int countSquares(std::vector<std::vector<int>>& matrix)
    {
        return 0;
    }

    struct sample {
        std::vector<std::vector<int>> matrix;
        int res;
    };

    void test_count_squares()
    {
        std::vector<sample> samples{
                {{
                         {0, 1, 1, 1},
                         {1, 1, 1, 1},
                         {0, 1, 1, 1},
                 }, 15},
                {{
                         {1, 0, 1},
                         {1, 1, 0},
                         {1, 1, 0},
                 }, 7},
        };
        for (auto& s: samples) {
            assert(s.res==countSquares(s.matrix));
        }
    }
}

#endif //LEET_CODE_COUNT_SQUARE_SUBMATRICES_WITH_ALL_ONES_HPP
