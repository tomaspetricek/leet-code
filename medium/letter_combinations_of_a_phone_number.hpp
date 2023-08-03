//
// Created by Tomáš Petříček on 03.08.2023.
//

#ifndef LEET_CODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP
#define LEET_CODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP

#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <array>

namespace leet_code {
    constexpr int first_num = 2, last_num = 9;

    constexpr std::array<std::pair<char, int>, last_num-first_num+1> dial = {
            {
                    {'a', 3}, {'d', 3}, {'g', 3},
                    {'j', 3}, {'m', 3}, {'p', 4},
                    {'t', 3}, {'w', 4}
            }
    };

    void generate(std::vector<std::string>& combs, std::string& digits, std::string& num, std::size_t depth = 0)
    {
        if (depth==digits.size()) {
            combs.emplace_back(num);
        }
        else {
            std::size_t b{static_cast<std::size_t>(digits[depth]-'0')-first_num};
            for (int i{0}; i<dial[b].second; i++) {
                num[depth] = dial[b].first+i;
                generate(combs, digits, num, depth+1);
            }
        }
    }

    std::vector<std::string> letterCombinations(std::string digits)
    {
        std::vector<std::string> combs;
        if (!digits.empty()) {
            std::string num(digits);
            generate(combs, digits, num);
        }
        return combs;
    }

    struct sample {
        std::string digits;
        std::vector<std::string> combs;
    };

    void test_letter_combinations()
    {
        std::vector<sample> samples{
                {{"23"}, {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
                {{""},   {}},
                {{"2"},  {"a",  "b",  "c"}},
                {{"7"},  {"p",  "q",  "r",  "s"}},
        };
        for (auto& s: samples) {
            auto combs = letterCombinations(s.digits);
            assert(std::set(combs.begin(), combs.end())==std::set(s.combs.begin(), s.combs.end()));
        }
    }
}

#endif //LEET_CODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP
