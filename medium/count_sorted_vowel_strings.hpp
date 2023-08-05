//
// Created by Tomáš Petříček on 05.08.2023.
//

#ifndef LEET_CODE_COUNT_SORTED_VOWEL_STRINGS_HPP
#define LEET_CODE_COUNT_SORTED_VOWEL_STRINGS_HPP

#include <vector>
#include <cassert>

namespace leet_code {
    int countVowelStrings(int n)
    {

    }

    struct sample {
        int n, count;
    };

    void test_count_vowel_strings()
    {
        std::vector<sample> samples{
                {1,  5},
                {2,  15},
                {33, 66045},
        };
        for (auto s: samples) {
            auto count = countVowelStrings(s.n);
            assert(count==s.count);
        }
    }
}

#endif //LEET_CODE_COUNT_SORTED_VOWEL_STRINGS_HPP
