//
// Created by Tomáš Petříček on 26.06.2023.
//

#ifndef LEET_CODE_MAXIMUM_SUBSEQUENCE_HPP
#define LEET_CODE_MAXIMUM_SUBSEQUENCE_HPP

#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <queue>

long long max_score(std::vector<int>& nums1, std::vector<int>& nums2, int k)
{
    std::vector<std::pair<int, int>> vals;
    for (int i{0}; i<nums1.size(); i++)
        vals.emplace_back(std::pair{nums2[i], nums1[i]});
    std::sort(vals.rbegin(), vals.rend());

    long long score{0}, sum{0};
    std::priority_queue<int, std::vector<int>, std::greater<>> queue;
    for (int i{0}; i<nums1.size(); i++) {
        sum += vals[i].second;
        queue.push(vals[i].second);

        if (i>=k-1) {
            score = std::max(score, sum*vals[i].first);
            sum -= queue.top();
            queue.pop();
        }
    }
    return score;
}

void test_max_score()
{
    std::vector<int> nums1{1, 3, 3, 2};
    std::vector<int> nums2{2, 1, 3, 4};
    int k{1};
    int expect{30};
    assert(expect==max_score(nums1, nums2, k));
}

#endif //LEET_CODE_MAXIMUM_SUBSEQUENCE_HPP
