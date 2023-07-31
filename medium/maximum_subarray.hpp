//
// Created by Tomáš Petříček on 31.07.2023.
//

#ifndef LEET_CODE_MAXIMUM_SUBARRAY_HPP
#define LEET_CODE_MAXIMUM_SUBARRAY_HPP

#include <cassert>
#include <vector>
#include <algorithm>

namespace leet_code {
    int maxSubArray(std::vector<int>& nums)
    {
        int curr, max;
        curr = max = nums[0];
        for (std::size_t i{1}; i<nums.size(); i++) {
            curr = std::max(nums[i], curr+nums[i]);
            max = std::max(max, curr);
        }
        return max;
    }

    struct sample {
        std::vector<int> nums;
        int res;
    };

    void test_max_subarray()
    {
        std::vector<sample> samples{
                {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
                {{1},                             1},
                {{5,  4, -1, 7, 8},               23},
                {{-2, 1},                         1},
                {{-1},                            -1},
        };
        for (auto& s: samples) {
            auto res = maxSubArray(s.nums);
            assert(res==s.res);
        }
    }
}

#endif //LEET_CODE_MAXIMUM_SUBARRAY_HPP
