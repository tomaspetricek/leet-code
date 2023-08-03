//
// Created by Tomáš Petříček on 03.08.2023.
//

#ifndef LEET_CODE_SEARCH_INSERT_POSITION_HPP
#define LEET_CODE_SEARCH_INSERT_POSITION_HPP

#include <vector>

namespace leet_code {
    int searchInsert(std::vector<int>& nums, int target)
    {
        // binary search
        int low{0}, high{static_cast<int>(nums.size())-1}, mid;
        while (low<=high) {
            mid = low+(high-low)/2;
            if (nums[mid]<target) {
                low = mid+1;
            }
            else if (nums[mid]>target) {
                high = mid-1;
            }
            else {
                return mid;
            }
        }
        return low;
    }

    struct sample {
        std::vector<int> nums;
        int target, res;
    };

    void test_search_insert()
    {
        std::vector<sample> samples{
                {{1, 3, 5, 6}, 5, 2},
                {{1, 3, 5, 6}, 2, 1},
                {{1, 3, 5, 6}, 7, 4},
                {{2, 3, 4, 5}, 1, 0},
                {{2, 3, 4, 5}, 2, 0},
        };
        for (auto& s: samples) {
            assert(s.res==searchInsert(s.nums, s.target));
        }
    }
}

#endif //LEET_CODE_SEARCH_INSERT_POSITION_HPP
