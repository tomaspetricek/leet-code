//
// Created by Tomáš Petříček on 14.08.2023.
//

#ifndef LEET_CODE_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_HPP
#define LEET_CODE_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_HPP

#include <vector>
#include <cassert>
#include <queue>

namespace leet_code {
    namespace sorting {
        int findKthLargest(std::vector<int>& nums, int k)
        {
            std::sort(nums.begin(), nums.end(), std::greater<>());
            return nums[k-1];
        }
    }

    namespace min_heap {
        int findKthLargest(std::vector<int>& nums, int k)
        {
            // keeps track of k largest elements in a descending order
            std::priority_queue<int, std::vector<int>, std::greater<>> heap{nums.begin(), nums.begin()+k};
            for (std::size_t i{static_cast<std::size_t>(k)}; i<nums.size(); i++) {
                heap.push(nums[i]);
                heap.pop();
            }
            return heap.top();
        }
    }

    struct sample {
        std::vector<int> nums;
        int k, res;
    };

    void test_find_kth_largest()
    {
        std::vector<sample> samples{
                {{3, 2, 1, 5, 6, 4}, 2, 5},
                {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4},
        };
        for (auto& s: samples) {
            assert(s.res==min_heap::findKthLargest(s.nums, s.k));
        }
    }
}

#endif //LEET_CODE_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_HPP
