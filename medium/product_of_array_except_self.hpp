//
// Created by Tomáš Petříček on 26.07.2023.
//

#ifndef LEET_CODE_PRODUCT_OF_ARRAY_EXCEPT_SELF_HPP
#define LEET_CODE_PRODUCT_OF_ARRAY_EXCEPT_SELF_HPP

#include <cassert>
#include <vector>

namespace leet_code {
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        std::vector<int> res(nums.size());
        res[0] = 1;
        for (std::size_t i{1}; i<nums.size(); i++) {
            res[i] = res[i-1]*nums[i-1];
        }
        int right{1};
        std::size_t i{nums.size()};
        while (i--) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }

    struct data {
        std::vector<int> nums, res;
    };

    void test_product_except_self()
    {
        std::vector<data> samples{
                {{1,  2, 3, 4},     {24, 12, 8, 6}},
                {{-1, 1, 0, -3, 3}, {0,  0,  9, 0, 0}},
        };
        for (auto& s: samples) {
            auto res = productExceptSelf(s.nums);
            if (res!=s.res) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_PRODUCT_OF_ARRAY_EXCEPT_SELF_HPP
