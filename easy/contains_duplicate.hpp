//
// Created by Tomáš Petříček on 25.07.2023.
//

#ifndef LEET_CODE_CONTAINS_DUPLICATE_HPP
#define LEET_CODE_CONTAINS_DUPLICATE_HPP

#include <cassert>
#include <vector>
#include <set>
#include <algorithm>

namespace leet_code {
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::unordered_map<int, int> map;
        for (auto num: nums) {
            map[num]++;
        }
        for (const auto& [num, count]: map) {
            if (count>1) {
                return true;
            }
        }
        return false;
    }

    struct data {
        std::vector<int> nums;
        bool contains;
    };

    void test_contains_duplicate()
    {
        std::vector<data> samples{
                {{1, 2, 3, 1},                   true},
                {{1, 2, 3, 4},                   false},
                {{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true},
        };
        for (auto& s: samples) {
            auto contains = containsDuplicate(s.nums);
            if (contains!=s.contains) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_CONTAINS_DUPLICATE_HPP
