//
// Created by Tomáš Petříček on 10.08.2023.
//

#ifndef LEET_CODE_NUMBER_OF_ISLANDS_HPP
#define LEET_CODE_NUMBER_OF_ISLANDS_HPP

#include <cassert>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// https://leetcode.com/problems/number-of-islands/
namespace leet_code {
    constexpr char island = '1', water = '0';

    void search(std::size_t r, std::size_t c, std::vector<std::vector<char>>& grid)
    {
        if (grid[r][c]==island) {
            grid[r][c] = water;
            if (c) {
                search(r, c-1, grid);
            }
            if (c!=grid[0].size()-1) {
                search(r, c+1, grid);
            }
            if (r) {
                search(r-1, c, grid);
            }
            if (r!=grid.size()-1) {
                search(r+1, c, grid);
            }
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid)
    {
        int count{0};
        for (std::size_t r{0}; r<grid.size(); r++) {
            for (std::size_t c{0}; c<grid[0].size(); c++) {
                if (grid[r][c]==island) {
                    count++;
                    search(r, c, grid);
                }
            }
        }
        return count;
    }

    struct sample {
        std::vector<std::vector<char>> grid;
        int res;
    };

    void test_num_islands()
    {
        std::vector<sample> samples{
                {{
                         {'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                         {'1', '1', '0', '0', '0'},
                         {'0', '0', '0', '0', '0'},
                 },                     1},
                {{
                         {'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                         {'0', '0', '1', '0', '0'},
                         {'0', '0', '0', '1', '1'}
                 },                     3},
                {{       {'0'}},        0},
                {{       {'1'}, {'1'}}, 1},
        };
        for (auto& s: samples) {
            assert(numIslands(s.grid)==s.res);
        }
    }
}

#endif //LEET_CODE_NUMBER_OF_ISLANDS_HPP
