//
// Created by Tomáš Petříček on 30.07.2023.
//

#ifndef LEET_CODE_VALID_PARENTHESES_HPP
#define LEET_CODE_VALID_PARENTHESES_HPP

#include <string>
#include <vector>
#include <cassert>
#include <stack>
#include <unordered_map>
#include <iostream>

namespace leet_code {
    bool is_open(char bracket)
    {
        return bracket=='(' || bracket=='{' || bracket=='[';
    }
    bool matches(char open, char close)
    {
        return (open=='(' && close==')') || (open=='{' && close=='}') || (open=='[' && close==']');
    }

    bool isValid(std::string s)
    {
        std::stack<char> opened;
        for (const auto& bracket: s) {
            if (is_open(bracket)) {
                opened.push(bracket);
            }
            else {
                if (opened.empty() || !matches(opened.top(), bracket)) {
                    return false;
                }
                opened.pop();
            }
        }
        return opened.empty();
    }

    struct sample {
        std::string s;
        bool res;
    };

    void test_is_valid()
    {
        std::vector<sample> samples{
                {{"()"},       true},
                {{"()[]{}"},   true},
                {{"(]"},       false},
                {{"{()}{]"},   false},
                {{"{()}{}()"}, true},
                {{")"}, false},
                {{"("},        false},
        };
        for (std::size_t i{0}; i<samples.size(); i++) {
            auto res = isValid(samples[i].s);
            assert(res==samples[i].res);
        }
    }
}

#endif //LEET_CODE_VALID_PARENTHESES_HPP
