//
// Created by Tomáš Petříček on 01.08.2023.
//

#ifndef LEET_CODE_FIND_THE_INDEX_OF_THE_FIRST_OCCURRENCE_IN_A_STRING_HPP
#define LEET_CODE_FIND_THE_INDEX_OF_THE_FIRST_OCCURRENCE_IN_A_STRING_HPP

#include <string>
#include <vector>
#include <cassert>

namespace leet_code {
    int strStr(std::string haystack, std::string needle)
    {
        constexpr int not_found = -1;
        std::size_t j;
        for (std::size_t i{0}; i<haystack.size(); i++) {
            if (haystack.size()-i<needle.size()) {
                return not_found;
            }
            j = 0;
            while (haystack[i+j]==needle[j] && j<needle.size()) {
                j++;
            }
            if (j==needle.size()) {
                return i;
            }
        }
        return not_found;
    }

    struct sample {
        std::string haystack, needle;
        int res;
    };

    void test_str_str()
    {
        std::vector<sample> samples{
                {{"sadbutsad"},   {"sad"},   0},
                {{"leetcode"},    {"leeto"}, -1},
                {{"sasassad"},    {"sad"},   5},
                {{"sasas"},       {"sad"},   -1},
                {{"mississippi"}, {"issip"}, 4},
                {{"hello"},       {"ll"},    2},
        };
        for (auto& s: samples) {
            auto res = strStr(s.haystack, s.needle);
            assert(res==s.res);
        }
    }
}

#endif //LEET_CODE_FIND_THE_INDEX_OF_THE_FIRST_OCCURRENCE_IN_A_STRING_HPP
