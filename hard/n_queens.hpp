//
// Created by Tomáš Petříček on 18.08.2023.
//

#ifndef LEET_CODE_N_QUEENS_HPP
#define LEET_CODE_N_QUEENS_HPP

#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <cassert>
#include <iostream>

// link: https://leetcode.com/problems/n-queens/
namespace leet_code {
    constexpr char empty = '.', queen = 'Q';

    void solve(int r, std::vector<std::vector<std::string>>& res, std::vector<std::string>& board,
            std::vector<bool>& horizontal, std::vector<bool>& right_diagonal, std::vector<bool>& left_diagonal)
    {
        std::size_t n{horizontal.size()};
        if (r==n) {
            res.emplace_back(board);
        }
        else {
            for (std::size_t c{0}; c<n; c++) {
                if (!horizontal[c] && !left_diagonal[r+c] && !right_diagonal[(n-1-r)+c]) {
                    horizontal[c] = left_diagonal[r+c] = right_diagonal[(n-1-r)+c] = true;
                    board[r][c] = queen;
                    solve(r+1, res, board, horizontal, right_diagonal, left_diagonal);
                    horizontal[c] = left_diagonal[r+c] = right_diagonal[(n-1-r)+c] = false;
                    board[r][c] = empty;
                }
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<bool> horizontal(n, false), right_diagonal((2*n)-1, false), left_diagonal((2*n)-1, false);
        std::vector<std::string> board(n, std::string(n, empty));
        std::vector<std::vector<std::string>> res;
        solve(0, res, board, horizontal, right_diagonal, left_diagonal);
        return res;
    }

    struct sample {
        int n;
        std::vector<std::vector<std::string>> res;
    };

    void test_solve_n_queens()
    {
        solveNQueens(4);
        std::vector<sample> samples{
                {4, {{{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}}}},
                {1, {{{"Q"}}}},
        };
        for (auto& s: samples) {
            auto res = solveNQueens(s.n);
            assert(std::set(res.begin(), res.end())==std::set(s.res.begin(), s.res.end()));
        }
    }
}

#endif //LEET_CODE_N_QUEENS_HPP
