//
// Created by Tomáš Petříček on 08.08.2023.
//

#ifndef LEET_CODE_HOW_MANY_NUMBERS_ARE_SMALLER_THAN_THE_CURRENT_NUMBER_HPP
#define LEET_CODE_HOW_MANY_NUMBERS_ARE_SMALLER_THAN_THE_CURRENT_NUMBER_HPP

#include <map>
#include <vector>
#include <cassert>

namespace leet_code {
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums)
    {
        std::vector<int> sorted{nums};
        std::sort(sorted.begin(), sorted.end());
        std::unordered_map<int, int> sums;
        int j{static_cast<int>(nums.size())};
        while(j--)
        {
            sums[sorted[j]] = j;
        }
        for (std::size_t i{0}; i<nums.size(); i++) {
            nums[i] = sums[nums[i]];
        }
        return nums;
    }

    void test_smaller_numbers_than_current()
    {
        std::vector<int> nums{8, 1, 2, 2, 3};
        smallerNumbersThanCurrent(nums);
    }
}

#endif //LEET_CODE_HOW_MANY_NUMBERS_ARE_SMALLER_THAN_THE_CURRENT_NUMBER_HPP
