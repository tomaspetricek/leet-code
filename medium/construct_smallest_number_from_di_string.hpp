//
// Created by Tomáš Petříček on 15.07.2023.
//

#ifndef LEET_CODE_CONSTRUCT_SMALLEST_NUMBER_FROM_DI_STRING_HPP
#define LEET_CODE_CONSTRUCT_SMALLEST_NUMBER_FROM_DI_STRING_HPP

#include <cassert>
#include <vector>

#include <string>

// https://leetcode.com/problems/construct-smallest-number-from-di-string/
namespace leet_code {
    std::string smallestNumber(std::string pattern)
    {
        std::string num;
        num.reserve(pattern.size()+1);
    }

    struct data {
        std::string pattern, num;
    };

    void test_smallest_number()
    {
        std::vector<data> samples{
                {"IIIDIDDD", "123549876"},
                {"DDD",      "4321"},
        };
        for (const auto& s: samples) {
            if (s.num!=smallestNumber(s.pattern)) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_CONSTRUCT_SMALLEST_NUMBER_FROM_DI_STRING_HPP
