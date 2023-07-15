//
// Created by Tomáš Petříček on 15.07.2023.
//

#ifndef LEET_CODE_REMOVING_STARS_FROM_A_STRING_HPP
#define LEET_CODE_REMOVING_STARS_FROM_A_STRING_HPP

#include <cassert>
#include <vector>

#include <string>

// https://leetcode.com/problems/removing-stars-from-a-string/
namespace leet_code {
    std::string removeStars(std::string s)
    {
        std::string out;
        out.reserve(s.size());
        for (std::size_t i{0}; i<s.size(); i++) {
            if (s[i]=='*' && !out.empty()) {
                out.pop_back();
            }
            else {
                out.push_back(s[i]);
            }
        }
        return out;
    }

    struct data {
        std::string s, out;
    };

    void test_remove_stars()
    {
        std::vector<data> samples{
                {"leet**cod*e",     "lecoe"},
                {"erase*****",      ""},
                {"abb*cdfg*****x*", "a"},
        };
        for (const auto& s: samples) {
            if (s.out!=removeStars(s.s)) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_REMOVING_STARS_FROM_A_STRING_HPP
