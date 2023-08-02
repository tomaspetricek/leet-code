//
// Created by Tomáš Petříček on 02.08.2023.
//

#ifndef LEET_CODE_REMOVE_OUTERMOST_PARENTHESES_HPP
#define LEET_CODE_REMOVE_OUTERMOST_PARENTHESES_HPP

#include <cassert>
#include <vector>
#include <string>
#include <stack>
#include <iostream>

namespace leet_code {
    std::string removeOuterParentheses(std::string s)
    {
        std::string res;
        res.reserve(s.size());
        std::size_t count{0};
        for (auto c: s) {
            if ((c=='(' && count++>0) || (c==')' && count-->1)) {
                res.push_back(c);
            }
        }
        return res;
    }

    struct sample {
        std::string s, res;
    };

    void test_remove_outer_parentheses()
    {
        std::vector<sample> samples{
                {{"(()())(())"},         {"()()()"}},
                {{"(()())(())(()(()))"}, {"()()()()(())"}},
                {{"()()"},               {""}},
                {{"()"},                 {""}},
        };
        for (const auto& s: samples) {
            auto res = removeOuterParentheses(s.s);
            assert(res==s.res);
        }
    }
}

#endif //LEET_CODE_REMOVE_OUTERMOST_PARENTHESES_HPP
