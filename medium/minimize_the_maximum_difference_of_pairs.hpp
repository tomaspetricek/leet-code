//
// Created by Tomáš Petříček on 09.08.2023.
//

#ifndef LEET_CODE_MINIMIZE_THE_MAXIMUM_DIFFERENCE_OF_PAIRS_HPP
#define LEET_CODE_MINIMIZE_THE_MAXIMUM_DIFFERENCE_OF_PAIRS_HPP

#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>

// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
namespace leet_code {
    int minimizeMax(std::vector<int>& nums, int p)
    {
        if (!p) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        std::vector<int> diffs;
        diffs.reserve(nums.size()/2);
        
        for (std::size_t i{0}; i<nums.size()-1; i += 2) {
            diffs.emplace_back(nums[i+1]-nums[i]);
        }
        std::sort(diffs.begin(), diffs.end());
        int max{diffs[p-1]};
        diffs.clear();

        std::sort(diffs.begin(), diffs.end());
        return std::min(max, diffs[p-1]);
    }

    struct sample {
        std::vector<int> nums;
        int p, res;
    };

    void test_minimize_max()
    {
        std::vector<sample> samples{
//                {{10, 1, 2, 7, 1, 3}, 2, 1},
//                {{4,  2, 1, 2},       1, 0},
//                {{0, 5, 3, 4},          0, 0},
//                {{3, 4, 2, 3, 2, 1, 2}, 3, 1},
                {{3, 0, 5, 0, 0, 1, 6}, 3, 1},
        };
        for (auto& s: samples) {
            assert(minimizeMax(s.nums, s.p)==s.res);
        }
    }
}

#endif //LEET_CODE_MINIMIZE_THE_MAXIMUM_DIFFERENCE_OF_PAIRS_HPP
