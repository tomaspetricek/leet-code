//
// Created by Tomáš Petříček on 11.08.2023.
//

#ifndef LEET_CODE_PACIFIC_ATLANTIC_WATER_FLOW_HPP
#define LEET_CODE_PACIFIC_ATLANTIC_WATER_FLOW_HPP

#include <cassert>
#include <vector>
#include <iostream>

// https://leetcode.com/problems/pacific-atlantic-water-flow/
namespace leet_code {
    // dfs
    void search(int r, int c, std::vector<std::vector<bool>>& visited, std::vector<std::vector<int>>& heights)
    {
        visited[r][c] = true;
        std::size_t rows{heights.size()}, cols{heights[0].size()};
        // north
        if (r && !visited[r-1][c] && heights[r-1][c]>=heights[r][c]) {
            search(r-1, c, visited, heights);
        }
        // south
        if (r!=rows-1 && !visited[r+1][c] && heights[r+1][c]>=heights[r][c]) {
            search(r+1, c, visited, heights);
        }
        // west
        if (c && !visited[r][c-1] && heights[r][c-1]>=heights[r][c]) {
            search(r, c-1, visited, heights);
        }
        // east
        if (c!=cols-1 && !visited[r][c+1] && heights[r][c+1]>=heights[r][c]) {
            search(r, c+1, visited, heights);
        }
    }

    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights)
    {
        int rows{static_cast<int>(heights.size())}, cols{static_cast<int>(heights[0].size())};
        std::vector<std::vector<bool>> atlantic(rows, std::vector<bool>(cols, false));
        auto pacific = atlantic;
        // from borders search inland while keeping track of visited points
        for (int i{0}; i<rows; i++) {
            search(i, 0, pacific, heights);
            search(i, cols-1, atlantic, heights);
        }
        for (int i{0}; i<cols; i++) {
            search(0, i, pacific, heights);
            search(rows-1, i, atlantic, heights);
        }
        // collect intersection
        std::vector<std::vector<int>> res;
        for (int r{0}; r<rows; r++) {
            for (int c{0}; c<cols; c++) {
                if (atlantic[r][c] && pacific[r][c]) {
                    res.emplace_back(std::vector<int>{{r, c}});
                }
            }
        }
        return res;
    }

    struct sample {
        std::vector<std::vector<int>> heights, res;
    };

    void test_pacific_atlantic()
    {
        std::vector<sample> samples{
                {
                        {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}},
                        {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}}
                },
        };
        for (auto& s: samples) {
            auto res = pacificAtlantic(s.heights);
        }
    }
}

#endif //LEET_CODE_PACIFIC_ATLANTIC_WATER_FLOW_HPP
