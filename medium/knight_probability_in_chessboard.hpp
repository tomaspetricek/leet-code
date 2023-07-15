//
// Created by Tomáš Petříček on 15.07.2023.
//

#ifndef LEET_CODE_KNIGHT_PROBABILITY_IN_CHESSBOARD_HPP
#define LEET_CODE_KNIGHT_PROBABILITY_IN_CHESSBOARD_HPP

#include <cassert>
#include <vector>
#include <queue>
#include <cmath>

// https://leetcode.com/problems/knight-probability-in-chessboard/
namespace leet_code {
    struct pos {
        int r, c;
    };

    bool valid_move(const pos& p, int n)
    {
        return p.r>=0 && p.r<n && p.c>=0 && p.c<n;
    }

    namespace too_slow {
        double knightProbability(int n, int k, int row, int column)
        {
            // no moves to make
            if (!k) return 1.0;
            std::queue<pos> curr, next;
            curr.push({row, column});
            for (int i{0}; i<k; i++) {
                while (!curr.empty()) {
                    const auto& origin = curr.front();
                    for (int f: {1, -1}) {
                        for (int s: {2, -2}) {
                            for (const auto& p: {pos{f+origin.r, s+origin.c}, pos{s+origin.r, f+origin.c}}) {
                                if (valid_move(p, n)) {
                                    next.push(p);
                                }
                            }
                        }
                    }
                    curr.pop();
                }
                curr.swap(next);
            }
            std::cout << curr.size() << std::endl;
            return static_cast<double>(curr.size())/std::pow(8, k);
        }
    }

    double knightProbability(int n, int k, int row, int column)
    {
        if (!k) return 1.0;
    }

    struct data {
        int n, k, row, column;
        double prob;
    };

    void test_knight_probability()
    {
        std::vector<data> samples{
//                {3, 2, 0, 0, 0.06250},
//                {1, 0, 0, 0, 1.},
//                {3, 3, 0, 0, 8./std::pow(8, 3)},
                {8, 30, 6, 4, /std::pow(8, 30)},
        };
        for (auto& s: samples) {
            auto prob = knightProbability(s.n, s.k, s.row, s.column);
            if (prob!=s.prob) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_KNIGHT_PROBABILITY_IN_CHESSBOARD_HPP
