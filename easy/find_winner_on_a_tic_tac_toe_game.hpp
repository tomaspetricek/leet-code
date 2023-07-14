//
// Created by Tomáš Petříček on 14.07.2023.
//

#ifndef LEET_CODE_FIND_WINNER_ON_A_TIC_TAC_TOE_GAME_HPP
#define LEET_CODE_FIND_WINNER_ON_A_TIC_TAC_TOE_GAME_HPP

#include <cassert>
#include <string>
#include <vector>

// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
namespace leet_code {
    namespace state {
        std::string a_won = "A", b_won = "B", draw = "Draw", pending = "Pending";
    };

    std::string tictactoe(std::vector<std::vector<int>>& moves)
    {
        static constexpr int size = 3;
        static constexpr int r = 0, c = 1;

        int score[(size*2)+size-1] = {0};
        int i{static_cast<int>(moves.size()-1)};
        while (i>=0) {
            auto row = moves[i][r];
            auto col = moves[i][c];
            // rows and cols
            if (++score[row]==size || ++score[size+col]==size
                    // main diagonal
                    || (row==col) && ++score[2*size]==size
                    // anti-diagonal
                    || row+col==size-1 && ++score[2*size+1]==size) {
                return (moves.size()%2) ? state::a_won : state::b_won;
            }
            i -= 2;
        }
        return (moves.size()==size*3) ? state::draw : state::pending;
    }

    struct data {
        std::vector<std::vector<int>> moves;
        std::string winner;
    };

    void test_tic_tac_toe()
    {
        std::vector<data> samples{
                {{{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 0}},                                 state::a_won},
                {{{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}},                                 state::a_won},
                {{{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}},                         state::b_won},
                {{{0, 0}, {1, 1}, {2, 0}, {1, 0}, {1, 2}, {2, 1}, {0, 1}, {0, 2}, {2, 2}}, state::draw},
        };
        for (auto& s: samples) {
            const auto& res = tictactoe(s.moves);
            if (s.winner!=res) {
                std::cout << s.winner << ' ' << res << std::endl;
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_FIND_WINNER_ON_A_TIC_TAC_TOE_GAME_HPP
