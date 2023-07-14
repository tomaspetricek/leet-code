//
// Created by Tomáš Petříček on 14.07.2023.
//

#ifndef LEET_CODE_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP
#define LEET_CODE_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP

#include <vector>

namespace leet_code {
    int removeDuplicates(std::vector<int>& nums)
    {
        int k{0};
        for (std::size_t i{1}; i<nums.size(); i++) {
            if (nums[k]!=nums[i]) {
                nums[++k] = nums[i];
            }
        }
        return k+1;
    }

    struct data {
        std::vector<int> nums;
        std::vector<int> res;
    };

    void test_remove_duplicates()
    {
        std::vector<data> samples{
                {{1, 1, 2},                      {1, 2}},
                {{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {0, 1, 2, 3, 4}},
        };
        for (auto& s: samples) {
            int k = removeDuplicates(s.nums);
            s.nums.resize(k);
            if (k!=s.res.size() || s.res!=s.nums) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP
