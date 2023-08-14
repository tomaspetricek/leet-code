//
// Created by Tomáš Petříček on 14.08.2023.
//

#ifndef LEET_CODE_DELETE_GREATEST_CALUE_IN_EACH_ROW_HPP
#define LEET_CODE_DELETE_GREATEST_VALUE_IN_EACH_ROW_HPP

#include <vector>
#include <queue>

namespace leet_code {
    int deleteGreatestValue(std::vector<std::vector<int>>& grid)
    {
        std::size_t rows{grid.size()}, cols{grid[0].size()};
        // sort rows
        for (std::size_t r{0}; r<rows; r++) {
            std::sort(grid[r].begin(), grid[r].end());
        }
        int sum{0}, max;
        // compute sum
        for (std::size_t c{0}; c<cols; c++) {
            max = grid[0][c];
            for (std::size_t r{1}; r<rows; r++) {
                max = std::max(grid[r][c], max);
            }
            sum += max;
        }
        return sum;
    }

    struct sample {
        std::vector<std::vector<int>> grid;
        int res;
    };

    void test_delete_greatest_value()
    {
        std::vector<sample> samples{
                {{{1, 2, 4}, {3, 3, 1}}, 8},
                {{{10}},                 10},
        };
        for (auto& s: samples) {
            assert(s.res==deleteGreatestValue(s.grid));
        }
    }
}

#endif //LEET_CODE_DELETE_GREATEST_VALUE_IN_EACH_ROW_HPP
