//
// Created by Tomáš Petříček on 10.08.2023.
//

#ifndef LEET_CODE_MINESWEEPER_HPP
#define LEET_CODE_MINESWEEPER_HPP

#include <vector>
#include <algorithm>

namespace leet_code {
    namespace mine {
        constexpr char revealed = 'X', unrevealed = 'M';
    }

    namespace empty {
        constexpr char revealed = 'B', unrevealed = 'E';
    }

    void reveal(int x, int y, std::vector<std::vector<char>>& board)
    {
        int count{0}, rows{static_cast<int>(board.size())}, cols{static_cast<int>(board[0].size())},
                min_row{std::max(x-1, 0)}, max_row{std::min(x+1, rows-1)},
                min_col{std::max(y-1, 0)}, max_col{std::min(y+1, cols-1)};
        board[x][y] = empty::revealed;
        // count mines
        for (int r{min_row}; r<=max_row; r++) {
            for (int c{min_col}; c<=max_col; c++) {
                if (board[r][c]==mine::unrevealed) {
                    count++;
                }
            }
        }
        if (count) {
            board[x][y] = '0'+count;
        }
        // reveal adjacent
        else {
            for (int r{min_row}; r<=max_row; r++) {
                for (int c{min_col}; c<=max_col; c++) {
                    if (board[r][c]==empty::unrevealed) {
                        reveal(r, c, board);
                    }
                }
            }
        }
    }

    std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>>& board, std::vector<int>& click)
    {
        int x{click[0]}, y{click[1]};
        if (board[x][y]==mine::unrevealed) {
            board[x][y] = mine::revealed;
        }
        else {
            reveal(x, y, board);
        }
        return board;
    }

    struct sample {
        std::vector<std::vector<char>> before;
        std::vector<int> click;
        std::vector<std::vector<char>> after;
    };

    void test_update_board()
    {
        std::vector<sample> samples{
                {
                        {
                                {empty::unrevealed, empty::unrevealed, empty::unrevealed, empty::unrevealed,
                                                                                               empty::unrevealed},
                                {empty::unrevealed, empty::unrevealed, mine::unrevealed, empty::unrevealed,
                                                                                              empty::unrevealed},
                                {empty::unrevealed, empty::unrevealed, empty::unrevealed, empty::unrevealed,
                                                                                               empty::unrevealed},
                                {empty::unrevealed, empty::unrevealed, empty::unrevealed, empty::unrevealed,
                                                                                                           empty::unrevealed}
                        },
                        {3, 0},
                        {
                                {empty::revealed, '1', empty::unrevealed, '1', empty::revealed},
                                {empty::revealed, '1', mine::unrevealed, '1', empty::revealed},
                                {empty::revealed, '1', '1', '1', empty::revealed},
                                {empty::revealed, empty::revealed, empty::revealed, empty::revealed, empty::revealed}
                        },
                },
                {
                        {
                                {empty::revealed,   '1',               empty::unrevealed, '1', empty::revealed},
                                {empty::revealed,   '1',               mine::unrevealed, '1', empty::revealed},
                                {empty::revealed,   '1',               '1',               '1', empty::revealed},
                                {empty::revealed,   empty::revealed,   empty::revealed,   empty::revealed, empty::revealed},
                        },
                        {1, 2},
                        {
                                {empty::revealed, '1', empty::unrevealed, '1', empty::revealed},
                                {empty::revealed, '1', mine::revealed,   '1', empty::revealed},
                                {empty::revealed, '1', '1', '1', empty::revealed},
                                {empty::revealed, empty::revealed, empty::revealed, empty::revealed, empty::revealed}
                        }
                },
        };
        for (auto& s: samples) {
            assert(updateBoard(s.before, s.click)==s.after);
        }
    }
}
#endif //LEET_CODE_MINESWEEPER_HPP
