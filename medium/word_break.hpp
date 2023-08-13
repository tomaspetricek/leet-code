//
// Created by Tomáš Petříček on 13.08.2023.
//

#ifndef LEET_CODE_WORD_BREAK_HPP
#define LEET_CODE_WORD_BREAK_HPP

#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string_view>
#include <string>
#include <cassert>
#include <iostream>

// topic: hash map
// link: https://leetcode.com/problems/word-break/
namespace leet_code {
    constexpr int empty = -1;

    // uses memoization to track explored possibilities
    bool search(std::size_t f, std::string_view s, std::unordered_set<std::string_view>& words, std::vector<int>& mem)
    {
        // reached the end, therefore it can be broken
        if (f==s.size()) {
            return true;
        }
        // check if not visited
        if (mem[f]==empty) {
            for (std::size_t l{f}; l<s.size(); l++) {
                if (words.contains(std::string_view{s.data()+f, l-f+1})) {
                    if (search(l+1, s, words, mem)) {
                        mem[f] = true;
                        return mem[f];
                    }
                }
            }
            mem[f] = false;
        }
        return mem[f];
    }

    bool wordBreak(std::string s, std::vector<std::string>& dict)
    {
        std::unordered_set<std::string_view> words{dict.begin(), dict.end()};
        std::vector<int> mem(s.size(), empty);
        return search(0, s, words, mem);
    }

    struct sample {
        std::string s;
        std::vector<std::string> words;
        bool res;
    };

    void test_word_break()
    {
        std::vector<sample> samples{
                {{"leetcode"},      {"leet",    "code"},                      true},
                {{"applepenapple"}, {{"apple"}, {"pen"}},                     true},
                {{"catsandog"},     {"cats",    "dog", "sand", "and", "cat"}, false},
        };
        for (auto& s: samples) {
            assert(s.res==wordBreak(s.s, s.words));
        }
    }
}

#endif //LEET_CODE_WORD_BREAK_HPP
