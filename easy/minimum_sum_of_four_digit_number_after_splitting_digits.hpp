//
// Created by Tomáš Petříček on 08.08.2023.
//

#ifndef LEET_CODE_MINIMUM_SUM_OF_FOUR_DIGIT_NUMBER_AFTER_SPLITTING_DIGITS_HPP
#define LEET_CODE_MINIMUM_SUM_OF_FOUR_DIGIT_NUMBER_AFTER_SPLITTING_DIGITS_HPP

#include <array>
#include <vector>
#include <iostream>

namespace leet_code {
    static constexpr int digit_count = 4;
    static int digits[digit_count];

    int minimumSum(int num)
    {
        std::size_t i{digit_count};
        while (i--) {
            digits[i] = num%10;
            num /= 10;
        }
        std::sort(digits, digits+digit_count);
        return (digits[0]+digits[1])*10+digits[2]+digits[3];
    }

    struct sample {
        int num, sum;
    };

    void test_minimum_sum()
    {
        std::vector<sample> samples{
                {2932, 52},
                {4009, 13},
                {1000, 1},
                {2211, 24},
        };
        for (auto& s: samples) {
            auto sum = minimumSum(s.num);
            assert(s.sum==sum);
        }
    }
}

#endif //LEET_CODE_MINIMUM_SUM_OF_FOUR_DIGIT_NUMBER_AFTER_SPLITTING_DIGITS_HPP
