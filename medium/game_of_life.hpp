//
// Created by Tomáš Petříček on 06.08.2023.
//

#ifndef LEET_CODE_GAME_OF_LIFE_HPP
#define LEET_CODE_GAME_OF_LIFE_HPP

#include <vector>
#include <vector>
#include <algorithm>
#include <iostream>

namespace leet_code {
    void gameOfLife(std::vector<std::vector<int>>& board)
    {
        int rows{static_cast<int>(board.size())}, cols{static_cast<int>(board[0].size())};
        std::vector<std::vector<int>> counts(rows, std::vector<int>(cols, 0));
        for (int r{0}; r<board.size(); r++) {
            for (int c{0}; c<board[0].size(); c++) {
                for (int i{std::max(0, r-1)}; i<=std::min(r+1, rows-1); i++) {
                    for (int j{std::max(0, c-1)}; j<=std::min(c+1, cols-1); j++) {
                        if (i!=r || j!=c) {
                            counts[r][c] += board[i][j];
                        }
                    }
                }
            }
        }
        for (int r{0}; r<board.size(); r++) {
            for (int c{0}; c<board[0].size(); c++) {
                if (board[r][c]) {
                    if (counts[r][c]<2 || counts[r][c]>3) {
                        board[r][c] = 0;
                    }
                }
                else {
                    if (counts[r][c]==3) {
                        board[r][c] = 1;
                    }
                }
            }
        }
    }

    struct sample {
        std::vector<std::vector<int>> before, after;
    };

    void test_game_of_life()
    {
        std::vector<sample> samples{
                {{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}}, {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}}},
                {{{1, 1},    {1, 0}},                          {{1, 1},    {1, 1}}},
        };
        for (auto& s: samples) {
            gameOfLife(s.before);
            assert(s.before==s.after);
        }
    }
}

#endif //LEET_CODE_GAME_OF_LIFE_HPP
