//
// Created by Tomáš Petříček on 11.07.2023.
//

#ifndef LEET_CODE_FIRST_MISSING_POSITIVE_HPP
#define LEET_CODE_FIRST_MISSING_POSITIVE_HPP

#include <vector>
#include <cassert>
#include <list>

namespace leet_code {
    namespace combinatorial {
        int firstMissingPositive(std::vector<int>& nums)
        {
            int missing{1};
            std::size_t it{0};
            while (true) {
                for (std::size_t i{0}; i<nums.size(); i++) {
                    if (nums[i]==missing) {
                        missing++;
                        break;
                    }
                }
                if (++it==missing) return missing;
            }
        }
    }

    struct data {
        std::vector<int> nums;
        int missing;
    };

    void test_first_missing_positive()
    {
        std::vector<data> samples{
                {{1, 2, 0},                        3},
                {{3, 4, -1, 1},                    2},
                {{1, 2, 3},                        4},
                {{3, 2, 3},                        1},
                {{7, 8, 9,  11, 12},               1},
                {{1, 2, 7,  0,  8, 1, 2, 9, 7, 3}, 4},
                {{1, 2, 6,  3,  5, 4},             7},
                {{0, 2, 2,  1,  1},                3},
                {{2, 1},                           3},
                {{0, 2, 2,  4,  0, 1, 0, 1, 3},    5},
        };
        for (auto& s: samples)
            assert(s.missing==combinatorial::firstMissingPositive(s.nums));
    }
}

#endif //LEET_CODE_FIRST_MISSING_POSITIVE_HPP
