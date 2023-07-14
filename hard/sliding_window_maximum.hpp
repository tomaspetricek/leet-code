//
// Created by Tomáš Petříček on 09.07.2023.
//

#ifndef LEET_CODE_SLIDING_WINDOW_MAXIMUM_HPP
#define LEET_CODE_SLIDING_WINDOW_MAXIMUM_HPP

#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <deque>

namespace leet_code {
    // https://leetcode.com/problems/sliding-window-maximum/
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        std::vector<int> max;
        max.reserve(nums.size()-k+1);
        // stores relevant indices
        std::deque<int> deque;

        for (int i = 0; i<nums.size(); i++) {
            if (deque.empty()) {
                deque.emplace_back(i);
            }
            else {
                // removes index out of valid range -> only one can be invalid,
                // pop_front therefore is better deque then vector
                if (deque.front()<=i-k) deque.pop_front();
                // removes lower from back -> therefore the first is always lower
                while (!deque.empty() && nums[i]>nums[deque.back()]) deque.pop_back();
                deque.emplace_back(i);
            }
            if (i>=k-1) {
                max.push_back(nums[deque.front()]);
            }
        }
        return max;
    }

    struct data {
        std::vector<int> nums;
        int k;
        std::vector<int> max;
    };

    void test_max_sliding_window()
    {
        std::vector<data> samples{
                {{1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7}},
        };
        for (auto& sample: samples) {
            assert(maxSlidingWindow(sample.nums, sample.k)==sample.max);
        }
    }
}

#endif //LEET_CODE_SLIDING_WINDOW_MAXIMUM_HPP
