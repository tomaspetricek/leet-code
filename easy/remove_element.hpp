//
// Created by Tomáš Petříček on 01.08.2023.
//

#ifndef LEET_CODE_REMOVE_ELEMENT_HPP
#define LEET_CODE_REMOVE_ELEMENT_HPP

#include <vector>

namespace leet_code {
    int removeElement(std::vector<int>& nums, int val)
    {
        std::size_t s{0};
        for (std::size_t i{0}; i<nums.size(); i++) {
            if (nums[i]!=val) {
                nums[s++] = nums[i];
            }
        }
        return s;
    }
}

#endif //LEET_CODE_REMOVE_ELEMENT_HPP
