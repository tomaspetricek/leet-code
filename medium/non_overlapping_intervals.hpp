//
// Created by Tomáš Petříček on 19.07.2023.
//

#ifndef LEET_CODE_NON_OVERLAPPING_INTERVALS_HPP
#define LEET_CODE_NON_OVERLAPPING_INTERVALS_HPP

#include <cassert>
#include <vector>

namespace leet_code {
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
    {
        int count{0};

        return count;
    }

    struct data {
        std::vector<std::vector<int>> intervals;
        int count;
    };

    void test_erase_overlap_intervals()
    {
        std::vector<data> samples{
                {{{1, 2}, {2, 3}, {3, 4}, {1, 3}}, 1},
                {{{1, 2}, {1, 2}, {1, 2}},         2},
                {{{1, 2}, {2, 3}},                 0},
        };
        for (auto& s: samples) {
            auto count = eraseOverlapIntervals(s.intervals);
            if (count!=s.count) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_NON_OVERLAPPING_INTERVALS_HPP
