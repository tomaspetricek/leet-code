//
// Created by Tomáš Petříček on 14.07.2023.
//

#ifndef LEET_CODE_PLUS_ONE_HPP
#define LEET_CODE_PLUS_ONE_HPP

#include <cassert>
#include <vector>

namespace leet_code {
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        std::size_t i{digits.size()};
        while (i--!=0) {
            if (digits[i]<9) {
                digits[i] += 1;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }
        digits[0] = 1;
        digits.emplace_back(0);
        return digits;
    }

    struct data {
        std::vector<int> digits, res;
    };

    void test_plus_one()
    {
        std::vector<data> samples{
                {{1, 2, 3},    {1, 2, 4}},
                {{4, 3, 2, 1}, {4, 3, 2, 2}},
                {{9},          {1, 0}},
                {{9, 9, 9, 9}, {1, 0, 0, 0, 0}},
        };
        for (auto& s: samples) {
            const auto& res = plusOne(s.digits);
            if (s.res!=res) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_PLUS_ONE_HPP
