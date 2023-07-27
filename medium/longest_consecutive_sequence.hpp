//
// Created by Tomáš Petříček on 27.07.2023.
//

#ifndef LEET_CODE_LONGEST_CONSECUTIVE_SEQUENCE_HPP
#define LEET_CODE_LONGEST_CONSECUTIVE_SEQUENCE_HPP

#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

namespace leet_code {
    int longestConsecutive(std::vector<int>& nums)
    {
        if (!nums.size()) {
            return 0;
        }
        // sort
        std::sort(nums.begin(), nums.end());
        // count longest
        int max, curr, diff;
        max = curr = 1;
        for (std::size_t i{1}; i<nums.size(); i++) {
            diff = nums[i]-nums[i-1];
            if (!diff) {
                continue;
            }
            if (diff==1) {
                curr++;
            }
            else {
                max = std::max(max, curr);
                curr = 1;
            }
        }
        max = std::max(max, curr);
        return max;
    }

    struct data {
        std::vector<int> nums;
        int len;
    };

    void test_longest_consecutive()
    {
        std::vector<data> samples{
                {{100, 4, 200, 1, 3, 2},             4},
                {{0,   3, 7,   2, 5, 8, 4, 6, 0, 1}, 9},
                {{},                                 0},
        };
        for (auto& s: samples) {
            auto len = longestConsecutive(s.nums);
            if (len!=s.len) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_LONGEST_CONSECUTIVE_SEQUENCE_HPP
