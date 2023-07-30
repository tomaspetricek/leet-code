//
// Created by Tomáš Petříček on 29.07.2023.
//

#ifndef LEET_CODE_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_HPP
#define LEET_CODE_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_HPP

#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <string_view>

namespace leet_code {
    std::size_t next_occurrence(char c, std::string_view s)
    {
        for (std::size_t i{0}; i<s.size(); i++) {
            if (c==s[i]) {
                return i;
            }
        }
        return s.size();
    }

    int lengthOfLongestSubstring(std::string s)
    {
        int max{0};
        std::size_t f, c, l;
        f = c = 0;
        l = c+1+next_occurrence(s[c], {s.data()+c+1, s.size()-c});
        while (++c<s.size()) {
            if (c+1==l) {
                max = std::max(max, static_cast<int>(l-f)-1);
                f = c;
                l = c+1+next_occurrence(s[c], {s.data()+c+1, s.size()-c});
            }
            else {
                for (std::size_t i{c+1}; i<l; i++) {
                    if (s[c]==s[i]) {
                        l = c+1+next_occurrence(s[c], {s.data()+c+1, s.size()-c});
                    }
                }
            }
        }
        if (c+1==l) {
            max = std::max(max, static_cast<int>(l-f)-1);
        }
        return max;
    }

    struct sample {
        std::string s;
        int len;
    };

    void test_length_of_longest_substring()
    {
        std::vector<sample> samples{
                {{"abcabcbb"},    3},
//                {{"bbbbb"},       1},
//                {{"pwwkew"},      3},
//                {{"la"},          2},
//                {{"abc"},         3},
//                {{"ab"},          2},
//                {{"abcaabcabcd"}, 4},
//                {{"aa"},          1},
//                {{"aaabbcdaaa"}, 4},
//                {{""}, 0},
                {{"dvdf"}, 3},
        };
        for (const auto& s: samples) {
            auto len = lengthOfLongestSubstring(s.s);
            assert(len==s.len);
        }
    }

}

#endif //LEET_CODE_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_HPP
