//
// Created by Tomáš Petříček on 06.08.2023.
//

#ifndef LEET_CODE_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP
#define LEET_CODE_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP

#include <vector>

namespace leet_code {
    // https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=featured-list&envId=top-100-liked-questions
    int search(std::vector<int>& nums, int target)
    {
        int low{0}, high{static_cast<int>(nums.size())-1};
        while (low<=high) {
            int mid = low+(high-low)/2;
            if (nums[mid]==target) {
                return mid;
            }
            if (nums[mid]>=nums[low]) {
                if (target>=nums[low] && target<=nums[mid]) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            else {
                if (target>=nums[mid] && target<=nums[high]) {
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        }
        return -1;
    }

    struct sample {
        std::vector<int> nums;
        int target, index;
    };

    void test_search()
    {
        std::vector<sample> samples{
                {{4, 5, 6, 7, 0, 1, 2}, 0, 4},
                {{4, 5, 6, 7, 0, 1, 2}, 3, -1},
                {{1},                   1, 0},
                {{2, 3, 4, 5, 1},       1, 4},
                {{3, 4, 5, 1, 2},       1, 3},
                {{1, 3},                0, -1},
        };
        for (auto& s: samples) {
            auto index = search(s.nums, s.target);
            assert(index==s.index);
        }
    }
}

#endif //LEET_CODE_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP
