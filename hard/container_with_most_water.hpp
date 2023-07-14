//
// Created by Tomáš Petříček on 11.07.2023.
//

#ifndef LEET_CODE_CONTAINER_WITH_MOST_WATER_HPP
#define LEET_CODE_CONTAINER_WITH_MOST_WATER_HPP

#include <vector>
#include <cassert>
#include <algorithm>

// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/830/
namespace leet_code {
    namespace combinatorial {
        int maxArea(std::vector<int>& height)
        {
            int max{0};
            int area;
            for (std::size_t f{0}; f<height.size()-1; f++) {
                for (std::size_t l{f+1}; l<height.size(); l++) {
                    area = std::min(height[f], height[l])*static_cast<int>(l-f);
                    max = std::max(max, area);
                }
            }
            return max;
        }
    }

    // passed --> too great runtime
    namespace heuristic {
        int maxArea(std::vector<int>& height)
        {
            int max{0};
            int area;
            for (std::size_t f{0}; f<height.size()-1; f++) {
                for (std::size_t l{height.size()-1}; l>f; l--) {
                    int len = static_cast<int>(l-f);
                    // check upper bound
                    if (height[f]*len<=max) break;
                    area = std::min(height[f], height[l])*len;
                    max = std::max(max, area);
                }
            }
            return max;
        }
    }

    // fastest
    int maxArea(std::vector<int>& height)
    {
        int max{0};
        std::size_t l{0}, u{height.size()-1};
        while (l<u) {
            max = std::max(max, std::min(height[l], height[u])*static_cast<int>(u-l));
            if (height[l]<height[u]) l++; else u--;
        }
        return max;
    }

    struct data {
        std::vector<int> height;
        int area;
    };

    // solved
    void test_max_area()
    {
        std::vector<data> samples{
                {{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
                {{1, 1},                      1},
                {{3, 5, 4, 3},                9}
        };
        for (auto& s: samples) {
            assert(s.area==maxArea(s.height));
        }
    }
}

#endif //LEET_CODE_CONTAINER_WITH_MOST_WATER_HPP
