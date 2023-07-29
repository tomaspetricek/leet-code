//
// Created by Tomáš Petříček on 27.07.2023.
//

#ifndef LEET_CODE_THREE_SUM_HPP
#define LEET_CODE_THREE_SUM_HPP

#include <cassert>
#include <vector>

namespace leet_code {
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> res;
        return res;
    }

    struct data {
        std::vector<int> nums;
        std::vector<std::vector<int>> res;
    };

    void test_three_sum()
    {
        std::vector<data> samples{
                {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}},
                {{0,  1, 1},            {}},
                {{0,  0, 0},            {{0,  0,  0}}},
        };
        for (auto& s: samples) {
            auto res = threeSum(s.nums);
            assert(res==s.res);
        }
    }
}

#endif //LEET_CODE_THREE_SUM_HPP
