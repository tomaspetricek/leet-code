//
// Created by Tomáš Petříček on 31.07.2023.
//

#ifndef LEET_CODE_LONGEST_PALINDROMIC_SUBSTRING_HPP
#define LEET_CODE_LONGEST_PALINDROMIC_SUBSTRING_HPP

#include <string>
#include <string_view>
#include <iostream>
#include <tuple>

namespace leet_code {
    struct slice {
        std::size_t first, len;
    };

    slice find_longest_palindrome(std::size_t first, std::size_t last, const std::string& s)
    {
        slice curr{first, 1};
        first++;
        while (first-- && last<s.size() && s[first]==s[last]) {
            curr = {first, last-first+1};
            last++;
        }
        return curr;
    }

    slice longer(const slice& a, const slice& b)
    {
        if (a.len>b.len) {
            return a;
        }
        else {
            return b;
        }
    }

    std::string longestPalindrome(std::string s)
    {
        slice max{0, 1};
        for (std::size_t i{0}; i<s.size(); i++) {
            // check odd
            max = longer(find_longest_palindrome(i, i, s), max);
            // check even
            if (i) {
                max = longer(find_longest_palindrome(i-1, i, s), max);
            }
        }
        return s.substr(max.first, max.len);
    }

    struct sample {
        std::string s, res;
    };

    void test_longest_palindrome()
    {
        std::vector<sample> samples{
                {{"babad"}, {"bab"}},
                {{"b"},     {"b"}},
                {{"cbbd"},  {"bb"}},
        };
        for (const auto& s: samples) {
            auto res = longestPalindrome(s.s);
            std::cout << res << std::endl;
            assert(res==s.res);
        }
    }
}

#endif //LEET_CODE_LONGEST_PALINDROMIC_SUBSTRING_HPP
