//
// Created by Tomáš Petříček on 25.07.2023.
//

#ifndef LEET_CODE_VALID_ANAGRAM_HPP
#define LEET_CODE_VALID_ANAGRAM_HPP

#include <vector>
#include <string>
#include <unordered_map>

namespace leet_code {
    bool isAnagram(std::string s, std::string t)
    {
        constexpr char first{'a'}, last{'z'};
        if (s.size()!=t.size()) {
            return false;
        }
        std::vector<int> counts(last-first+1, 0);
        for (auto& c: s) {
            counts[c-first]++;
        }
        for (auto& c: t) {
            if (!counts[c-first]--) {
                return false;
            }
        }
        return true;
    }

    struct data {
        std::string s, t;
        bool res;
    };

    void test_is_anagram()
    {
        std::vector<data> samples{
                {{"anagram"}, {"nagaram"}, true},
                {{"rat"},     {"car"},     false},
                {{"ab"},      {"a"},       false},
        };
        for (const auto& s: samples) {
            auto res = isAnagram(s.s, s.t);
            if (res!=s.res) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_VALID_ANAGRAM_HPP
