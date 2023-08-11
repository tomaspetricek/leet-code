//
// Created by Tomáš Petříček on 11.08.2023.
//

#ifndef LEET_CODE_CLIMBING_STAIRS_HPP
#define LEET_CODE_CLIMBING_STAIRS_HPP

#include <vector>
#include <cassert>
#include <cmath>

namespace leet_code {
    int climbStairs(int n)
    {
        int bef_prev{0}, prev{1}, curr;
        while (n--) {
            curr = bef_prev+prev;
            bef_prev = prev;
            prev = curr;
        }
        return curr;
    }

    struct sample {
        int n, res;
    };

    void test_climb_stairs()
    {
        std::vector<sample> samples{
                {2, 2},
                {3, 3},
                {4, 5},
                {5, 8},
                {6, 13},
        };
        for (auto& s: samples) {
            assert(climbStairs(s.n)==s.res);
        }
    }
}

#endif //LEET_CODE_CLIMBING_STAIRS_HPP
