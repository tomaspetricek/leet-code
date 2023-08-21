//
// Created by Tomáš Petříček on 21.08.2023.
//

#ifndef LEET_CODE_REPEATED_SUBSTRING_PATTERN_HPP
#define LEET_CODE_REPEATED_SUBSTRING_PATTERN_HPP

#include <string>
#include <vector>
#include <cassert>

namespace leet_code {
    bool repeatedSubstringPattern(std::string s)
    {
        if (s.size()>1) {
            std::string test;
            test.reserve(s.size()-2);
            test.append(s.begin()+1, s.end());
            test.append(s.begin(), s.end()-1);
            return test.find(s)!=std::string::npos;
        }
        return false;
    }

    struct sample {
        std::string s;
        bool res;
    };

    void test_repeated_substring_pattern()
    {
        std::vector<sample> samples{
                {{"abab"},         true},
                {{"aba"},          false},
                {{"abcabcabcabc"}, true},
        };
        for (auto& s: samples) {
            assert(s.res==repeatedSubstringPattern(s.s));
        }
    }
}

#endif //LEET_CODE_REPEATED_SUBSTRING_PATTERN_HPP
