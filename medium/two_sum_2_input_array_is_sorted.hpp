//
// Created by Tomáš Petříček on 27.07.2023.
//

#ifndef LEET_CODE_TWO_SUM_2_INPUT_ARRAY_IS_SORTED_HPP
#define LEET_CODE_TWO_SUM_2_INPUT_ARRAY_IS_SORTED_HPP

#include <cassert>
#include <vector>

namespace leet_code {
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        int f{0}, s{static_cast<int>(numbers.size())-1}, sum;
        while (f<s) {
            sum = numbers[f]+numbers[s];
            if (sum==target) {
                return {f+1, s+1};
            }
            if (sum>target) {
                s--;
            }
            else {
                f++;
            }
        }
        return {};
    }

    struct data {
        std::vector<int> nums;
        int target;
        std::vector<int> res;
    };

    void test_two_sum()
    {
        std::vector<data> samples{
                {{2,  7, 11, 15}, 9,  {1, 2}},
                {{2,  3, 4},      6,  {1, 3}},
                {{-1, 0},         -1, {1, 2}},
        };
        for (auto& s: samples) {
            auto res = twoSum(s.nums, s.target);
            if (res!=s.res) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_TWO_SUM_2_INPUT_ARRAY_IS_SORTED_HPP
