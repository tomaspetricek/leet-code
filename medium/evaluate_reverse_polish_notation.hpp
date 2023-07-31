//
// Created by Tomáš Petříček on 30.07.2023.
//

#ifndef LEET_CODE_EVALUATE_REVERSE_POLISH_NOTATION_HPP
#define LEET_CODE_EVALUATE_REVERSE_POLISH_NOTATION_HPP

#include <cassert>
#include <vector>
#include <string>
#include <stack>
#include <cctype>

namespace leet_code {
    int evalRPN(std::vector<std::string>& tokens)
    {
        int res, fst, snd;
        std::stack<int> nums;
        for (const auto& token: tokens) {
            // TODO fix inner brackets
            if (!std::isdigit(token[0])) {
                switch (token[0]) {
                case '+': {
                    res = fst+snd;
                    break;
                }
                case '-': {
                    res = fst-snd;
                    break;
                }
                case '*' : {
                    res = fst*snd;
                    break;
                }
                default:
                    res = fst/snd;
                }
            }
            else {
                nums.push(std::stoi(token));
            }
        }
        if (!nums.empty()) {
            res = nums.top();
        }
        return res;
    }

    struct sample {
        std::vector<std::string> tokens;
        int res;
    };

    void test_eval_rpn()
    {
        std::vector<sample> samples{
//                {{"2", "1", "+", "3", "*"}, 9},
//                {{"4", "13", "5", "/", "+"}, 6},
//                {{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, 22},
//                {{"1"}, 1},
//                {{"1", "2", "+"}, 3},
//                {{"3", "11", "+", "5", "-"}, 9},
                {{"3", "11", "5", "+", "-"}, -13}
        };
        for (auto& s: samples) {
            auto res = evalRPN(s.tokens);
            assert(res==s.res);
        }
    }
}

#endif //LEET_CODE_EVALUATE_REVERSE_POLISH_NOTATION_HPP
