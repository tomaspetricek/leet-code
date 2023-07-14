//
// Created by Tomáš Petříček on 14.07.2023.
//

#ifndef LEET_CODE_VALID_TIC_TAC_TOE_STATE_HPP
#define LEET_CODE_VALID_TIC_TAC_TOE_STATE_HPP

#include <cassert>
#include <string>
#include <vector>

namespace leet_code {
    using board_t = std::vector<std::string>;

    constexpr int size = 3;
    constexpr char empty = ' ';
    constexpr int fst = 0, snd = 1;
    constexpr int marks[2] = {'X', '0'};
    constexpr int multipliers[2] = {-1, 1};

    bool validTicTacToe(board_t& board)
    {
        int r{0}, c{0}, i;
        int score[(3*size)-1] = {0};
        int move_counts[2] = {0};
        for (const auto& row: board) {
            c = 0;
            for (const auto& field: row) {
                if (field!=empty) {
                    i = (field==marks[fst]) ? 0 : 1;
                    move_counts[i]++;
                    int add = -1*multipliers[i];
                    score[r] += add;
                    score[size+c] += add;
                    if (r==c) {
                        score[2*size] += add;
                    }
                    if (r+c==size-1) {
                        score[2*size+1] += add;
                    }
                }
                c++;
            }
            r++;
        }
        if (!(move_counts[fst]-1==move_counts[snd]
                || move_counts[fst]==move_counts[snd])) {
            return false;
        }
        bool won[2] = {false};
        for (const auto& s: score) {
            if (s==size) {
                won[fst] = true;
            }
            if (s==-size) {
                won[snd] = true;
            }
        }
        if (won[fst] && won[snd]) {
            return false;
        }
        if (won[fst] && move_counts[fst]-1!=move_counts[snd]
                || won[snd] && move_counts[fst]!=move_counts[snd]) {
            return false;
        }
        return true;
    }

    struct data {
        board_t board;
        bool valid;
    };

    void test_valid_tic_tac_toe()
    {
        std::vector<data> samples{
                {{"O  ", "   ", "   "}, false},
                {{"XOX", " X ", "   "}, false},
                {{"XOX", "O O", "XOX"}, true},
                {{"XXX", "   ", "OOO"}, false},
                {{"XXX", "OOX", "OOX"}, true},
        };
        for (auto& s: samples) {
            const auto& res = validTicTacToe(s.board);
            if (res!=s.valid) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_VALID_TIC_TAC_TOE_STATE_HPP
