//
// Created by Tomáš Petříček on 02.08.2023.
//

#ifndef LEET_CODE_BASEBALL_GAME_HPP
#define LEET_CODE_BASEBALL_GAME_HPP

#include <vector>
#include <cassert>
#include <string>
#include <stack>

namespace leet_code {
    bool is_number(const std::string& s)
    {
        return (atoi(s.c_str()));
    }

    int calPoints(std::vector<std::string>& operations)
    {
        std::stack<int> record;
        int prev, curr;
        for (const auto& op: operations) {
            if (is_number(op)) {
                record.push(std::stoi(op));
            }
            else {
                switch (op[0]) {
                case '+': {
                    prev = record.top();
                    record.pop();
                    curr = record.top()+prev;
                    record.push(prev);
                    record.push(curr);
                    break;
                }
                case 'D':
                    record.push(record.top()*2);
                    break;
                default:
                    record.pop();
                }
            }
        }
        int score{0};
        while (!record.empty()) {
            score += record.top();
            record.pop();
        }
        return score;
    }

    struct sample {
        std::vector<std::string> operations;
        int score;
    };

    void test_cal_points()
    {
        std::vector<sample> samples{
                {{"5", "2",  "C", "D", "+"},                30},
                {{"5", "-2", "4", "C", "D", "9", "+", "+"}, 27},
                {{"1", "C"},                                0},
        };
        for (auto& s: samples) {
            auto score = calPoints(s.operations);
            assert(score==s.score);
        }
    }
}

#endif //LEET_CODE_BASEBALL_GAME_HPP
