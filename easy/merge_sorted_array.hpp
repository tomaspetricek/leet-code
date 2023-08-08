//
// Created by Tomáš Petříček on 06.08.2023.
//

#ifndef LEET_CODE_MERGE_SORTED_ARRAY_HPP
#define LEET_CODE_MERGE_SORTED_ARRAY_HPP

#include <vector>

namespace leet_code {
    // https://leetcode.com/problems/merge-sorted-array/
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        int f{m-1}, s{n-1}, b{m+n-1};
        // if you run out of the second array, all elements in the first one are already sorted
        while (s>=0) {
            if (f>=0 && nums1[f]>nums2[s]) {
                nums1[b--] = nums1[f--];
            }
            else {
                nums1[b--] = nums2[s--];
            }
        }
    }

    struct sample {
        std::vector<int> nums1;
        int m;
        std::vector<int> nums2;
        int n;
        std::vector<int> res;
    };

    void test_merge()
    {
        std::vector<sample> samples{
                {{1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6}},
                {{2, 3, 5, 0, 0, 0}, 3, {2, 5, 6}, 3, {2, 2, 3, 5, 5, 6}},
                {{4, 5, 6, 0, 0, 0, 0}, 3, {0, 1, 2, 3}, 4, {0, 1, 2, 3, 4, 5, 6}},
                {{1}, 1, {}, 0, {1}},
        };
        for (auto& s: samples) {
            merge(s.nums1, s.m, s.nums2, s.n);
            assert(s.res==s.nums1);
        }
    }
}

#endif //LEET_CODE_MERGE_SORTED_ARRAY_HPP
