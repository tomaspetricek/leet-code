//
// Created by Tomáš Petříček on 11.08.2023.
//

#ifndef LEET_CODE_MOVE_ZEROES_HPP
#define LEET_CODE_MOVE_ZEROES_HPP

#include <vector>
#include <cassert>

namespace leet_code {
    void moveZeroes(std::vector<int>& nums)
    {
        std::size_t j{0};
        for (std::size_t i{0}; i<nums.size(); i++) {
            if (nums[i]) {
                nums[j++] = nums[i];
            }
        }
        for (std::size_t i{j}; i<nums.size(); i++) {
            nums[i] = 0;
        }
    }

    struct sample {
        std::vector<int> nums, res;
    };

    void test_move_zeroes()
    {
        std::vector<sample> samples{
                {{0, 1, 0, 3, 12}, {1, 3, 12, 0, 0}},
                {{0},              {0}},
        };
        for (auto& s: samples) {
            moveZeroes(s.nums);
            assert(s.nums==s.res);
        }
    }
}

#endif //LEET_CODE_MOVE_ZEROES_HPP
