//
// Created by Tomáš Petříček on 25.07.2023.
//

#ifndef LEET_CODE_TWO_SUM_HPP
#define LEET_CODE_TWO_SUM_HPP

#include <cassert>
#include <vector>
#include <unordered_map>

namespace leet_code {
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> complements;
        int complement;
        for (int i{0}; i<nums.size(); i++) {
            complement = target-nums[i];
            auto it = complements.find(complement);
            if (it!=complements.end()) {
                return {it->second, i};
            }
            complements.insert({nums[i], i});
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
                {{2, 7, 11, 15}, 9, {0, 1}},
                {{3, 2, 4},      6, {1, 2}},
                {{3, 3},         6, {0, 1}},
        };
        for (auto s: samples) {
            const auto& res = twoSum(s.nums, s.target);
            if (res!=s.res) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_TWO_SUM_HPP
