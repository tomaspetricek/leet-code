//
// Created by Tomáš Petříček on 27.07.2023.
//

#ifndef LEET_CODE_THREE_SUM_HPP
#define LEET_CODE_THREE_SUM_HPP

#include <cassert>
#include <vector>
#include <unordered_map>

namespace leet_code {
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        int low, high, sum, temp;
        for (int first{0}; first<nums.size(); first++) {
            low = first+1;
            high = static_cast<int>(nums.size())-1;
            while (low<high) {
                sum = nums[first]+nums[low]+nums[high];
                if (sum<0) {
                    low++;
                }
                else if (sum>0) {
                    high--;
                }
                else {
                    res.emplace_back(std::vector<int>{nums[first], nums[low], nums[high]});
                    // skip duplicates
                    temp = low;
                    while (low<high && nums[temp]==nums[low]) {
                        low++;
                    }
                    // skip duplicates
                    temp = high;
                    while (low<high && nums[temp]==nums[high]) {
                        high--;
                    }
                }
            }
            // skip duplicates
            while (first+1<nums.size() && nums[first]==nums[first+1]) {
                first++;
            }
        }
        return res;
    }

    struct data {
        std::vector<int> nums;
        std::vector<std::vector<int>> res;
    };

    void test_three_sum()
    {
        std::vector<data> samples{
                {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}},
                {{0, 1, 1}, {}},
                {{0, 0, 0}, {{0, 0, 0}}},
                {{0, 2, 2, 3, 0, 1, 2, 3, -1, -4, 2}, {{-4, 1, 3}, {-4, 2, 2}, {-1, 0, 1}}},
        };
        for (auto& s: samples) {
            auto res = threeSum(s.nums);
            assert(res==s.res);
        }
    }
}

#endif //LEET_CODE_THREE_SUM_HPP
