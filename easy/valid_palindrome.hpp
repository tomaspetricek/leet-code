//
// Created by Tomáš Petříček on 27.07.2023.
//

#ifndef LEET_CODE_VALID_PALINDROME_HPP
#define LEET_CODE_VALID_PALINDROME_HPP

#include <string>
#include <cassert>
#include <vector>
#include <cctype>

namespace leet_code {
    bool isPalindrome(std::string s)
    {
        std::size_t f{0}, b{s.size()-1};
        while (f<b) {
            // move to alphanumeric characters
            while (!std::isalnum(s[f]) && ++f<b);
            while (!std::isalnum(s[b]) && --b>f);
            if (f>=b) {
                break;
            }
            if (std::tolower(s[f++])!=std::tolower(s[b--])) {
                return false;
            }
        }
        return true;
    }

    struct data {
        std::string s;
        bool res;
    };

    void test_is_palindrome()
    {
        std::vector<data> samples{
                {{"A man, a plan, a canal: Panama"}, true},
                {{"race a car"},                     false},
                {{" "},                              true},
                {{"::"},                             true},
                {{"0P"},                             false},
        };
        for (auto& s: samples) {
            auto res = isPalindrome(s.s);
            if (res!=s.res) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_VALID_PALINDROME_HPP
