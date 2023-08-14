//
// Created by Tomáš Petříček on 14.08.2023.
//

#ifndef LEET_CODE_MAXIMUM_PRODUCT_OF_TWO_ELEMENTS_IN_AN_ARRAY_HPP
#define LEET_CODE_MAXIMUM_PRODUCT_OF_TWO_ELEMENTS_IN_AN_ARRAY_HPP

#include <vector>
#include <cassert>
#include <algorithm>

namespace leet_code {
    int maxProduct(std::vector<int>& nums)
    {
        std::partial_sort(nums.begin(), nums.begin()+2, nums.end(), std::greater<>());
        return (nums[0]-1)*(nums[1]-1);
    }
}

#endif //LEET_CODE_MAXIMUM_PRODUCT_OF_TWO_ELEMENTS_IN_AN_ARRAY_HPP
