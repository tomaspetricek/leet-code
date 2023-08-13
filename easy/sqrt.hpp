//
// Created by Tomáš Petříček on 13.08.2023.
//

#ifndef LEET_CODE_SQRT_HPP
#define LEET_CODE_SQRT_HPP

#include <cassert>
#include <vector>

namespace leet_code {
    int mySqrt(int x)
    {
        // perform binary search
        long low{1}, high{x}, mid, res; // must be long, otherwise an overflow may occur
        while (low<=high) {
            mid = low+(high-low)/2;
            res = mid*mid;
            if (res==x) {
                return static_cast<int>(mid);
            }
            if (res<x) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return static_cast<int>(low-1);
    }

    struct sample {
        int x, res;
    };

    void test_my_sqrt()
    {
        std::vector<sample> samples{
                {4,  2},
                {8,  2},
                {9,  3},
                {10, 3},
                {11, 3},
                {1,  1},
                {0,  0},
                {3,  1},
        };
        for (auto& s: samples) {
            assert(s.res==mySqrt(s.x));
        }
    }
}

#endif //LEET_CODE_SQRT_HPP
