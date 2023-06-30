//
// Created by Tomáš Petříček on 10.06.2022.
//

#ifndef LEETCODE_TRAPPING_RAIN_WATER_H
#define LEETCODE_TRAPPING_RAIN_WATER_H

#include <vector>
#include <cassert>
#include <stack>

int trap(std::vector<int>& heights)
{
    int drops{0};

    std::stack<int> max_heights;
    std::stack<int> dist_prev;
    std::stack<int> sum_heights_between;

    max_heights.push(heights[0]);
    sum_heights_between.push(0);
    dist_prev.push(0);

    bool going_up{false};

    for (int i{1}; i < heights.size(); i++) {
        if (heights[i] > max_heights.top()) {
            max_heights.top() = heights[i];
            going_up = true;
            dist_prev.top() += 1;
            sum_heights_between.top() += heights[i-1];
        }else if (heights[i] < max_heights.top()) {
            if (going_up) {
                max_heights.push(heights[i]);
                sum_heights_between.push(0);
                dist_prev.push(0);
                going_up = false;
            }else {
                dist_prev.top() += 1;
                sum_heights_between.top() += heights[i-1];
            }
        }
    }

    assert(drops > -1);
    return drops;
}

void test_water_trapping()
{
    std::vector<int> heights{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(trap(heights)==6);
}

#endif //LEETCODE_TRAPPING_RAIN_WATER_H
