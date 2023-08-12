//
// Created by Tomáš Petříček on 12.08.2023.
//

#ifndef LEET_CODE_SURROUNDED_REGIONS_HPP
#define LEET_CODE_SURROUNDED_REGIONS_HPP

#include <vector>
#include <cassert>
#include <iostream>

namespace leet_code {
    constexpr char x = 'X', o = 'O', k = 'K'; // K stands for keep

    void mark(std::size_t r, std::size_t c, std::vector<std::vector<char>>& board)
    {
        if (board[r][c]==o) {
            std::size_t rows{board.size()}, cols{board[0].size()};
            board[r][c] = k;
            // up
            if (r) {
                mark(r-1, c, board);
            }
            // down
            if (r!=rows-1) {
                mark(r+1, c, board);
            }
            // left
            if (c) {
                mark(r, c-1, board);
            }
            // right
            if (c!=cols-1) {
                mark(r, c+1, board);
            }
        }
    }

    void solve(std::vector<std::vector<char>>& board)
    {
        std::size_t rows{board.size()}, cols{board[0].size()};
        // mark cols
        for (std::size_t r{0}; r<rows; r++) {
            // left most column
            mark(r, 0, board);
            // right most column
            mark(r, cols-1, board);
        }
        // mark rows
        for (std::size_t c{0}; c<cols; c++) {
            // up most row
            mark(0, c, board);
            // down most row
            mark(rows-1, c, board);
        }
        for (std::size_t r{0}; r<rows; r++) {
            for (std::size_t c{0}; c<cols; c++) {
                board[r][c] = (board[r][c]==k) ? o : x;
            }
        }
    }

    struct sample {
        std::vector<std::vector<char>> before, after;
    };

    void test_solve()
    {
        std::vector<sample> samples{
                {
                        {{x, x, x, x}, {x, o, o, x}, {x, x, o, x}, {x, o, x, x}},
                        {{x, x, x, x}, {x, x, x, x}, {x, x, x, x}, {x, o, x, x}}
                },
                {
                        {{x}},
                        {{x}}
                },
                {
                        {{o}},
                        {{o}}
                },
                {
                        {{o, o},       {o, o}},
                        {{o, o},       {o, o}},
                },
                {
                        {
                         {o, o, o, o, x, x},
                                       {o, o, o, o, o, o},
                                                     {o, x, o, x, o, o},
                                                                   {o, x, o, o, x, o},
                                {o, x, o, x, o, o},
                                {o, x, o, o, o, o}
                        },
                        {
                         {o, o, o, o, x, x},
                                       {o, o, o, o, o, o},
                                                     {o, x, o, x, o, o},
                                                                   {o, x, o, o, x, o}, // {o,x,o,!x!,!o!,o}
                                {o, x, o, x, o, o},
                                {o, x, o, o, o, o}
                        },
                },
                {
                        {
                         {x, o, x, o, x, o, o, o, x, o},
                                       {x, o, o, x, x, x, o, o, o, x},
                                                     {o, o, o, o, o, o, o, o, x, x},
                                                                   {o, o, o, o, o, o, x, o, o, x},
                                {o, o, x, x, o, x, x, o, o, o},
                                {x, o, o, x, x, x, o, x, x, o},
                                {x, o, x, o, o, x, x, o, x, o},
                                {x, x, o, x, x, o, x, o, o, x},
                                {o, o, o, o, x, o, x, o, x, o},
                                {x, x, o, x, x, x, x, o, o, o}
                        },
                        {
                         {x, o, x, o, x, o, o, o, x, o},
                                       {x, o, o, x, x, x, o, o, o, x},
                                                     {o, o, o, o, o, o, o, o, x, x},
                                                                   {o, o, o, o, o, o, x, o, o, x},
                                {o, o, x, x, o, x, x, o, o, o},
                                {x, o, o, x, x, x, x, x, x, o},
                                {x, o, x, x, x, x, x, o, x, o},
                                {x, x, o, x, x, x, x, o, o, x},
                                {o, o, o, o, x, x, x, o, x, o},
                                {x, x, o, x, x, x, x, o, o, o}
                        }
                }
        };
        for (auto& s: samples) {
            solve(s.before);
            assert(s.before==s.after);
        }
    }
}

#endif //LEET_CODE_SURROUNDED_REGIONS_HPP
