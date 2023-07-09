//
// Created by Tomáš Petříček on 08.07.2023.
//

#ifndef LEET_CODE_BASIC_CALCULATOR_2_HPP
#define LEET_CODE_BASIC_CALCULATOR_2_HPP

#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>

// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/836/
namespace leet_code {
    int apply_operation(int fst, char op, int snd)
    {
        switch (op) {
        case '+':
            return fst+snd;
        case '-':
            return fst-snd;
        case '*':
            return fst*snd;
        case '/':
            return fst/snd;
        }
        return -1;
    }

    int calculate(std::string s)
    {
        constexpr int neutral_res = 0;
        constexpr char neutral_op = '+';
        std::istringstream seq(s);
        int num, res, interm_res;
        res = interm_res = neutral_res;
        char op, res_op, interm_op;
        res_op = interm_op = neutral_op;

        while (true) {
            seq >> num;
            if (!(seq >> op)) break;

            if (op=='/' || op=='*') {
                interm_res = apply_operation(interm_res, interm_op, num);
                interm_op = op;
            }
            else {
                res = apply_operation(res, res_op, apply_operation(interm_res, interm_op, num));
                res_op = op;
                interm_res = neutral_res;
                interm_op = neutral_op;
            }
        }
        return apply_operation(res, res_op, apply_operation(interm_res, interm_op, num));
    }

    void test_calculate()
    {
        std::vector<std::pair<std::string, int>> test_data{
                {"1+1+1",       3},
                {"3+2*2",       7},
                {"3+2*1",       5},
                {" 3/2 ",       1},
                {" 3+5 / 2 ",   5},
                {"42",          42},
                {"1-1+1",       1},
                {"1+2-3/2",     2},
                {"1-5/2",       -1},
                {"5+10-1*10/2", 10},
                {"5+10-1/10*2", 15},
                {"2*3+4",       10},
                {"8*10/2*10",   400},
                {"8*10/2/10",   4},
        };

        for (const auto& [s, r]: test_data)
            assert(calculate(s)==r);
    }
}

#endif //LEET_CODE_BASIC_CALCULATOR_2_HPP
