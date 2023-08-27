//
// Created by Tomáš Petříček on 27.08.2023.
//

#ifndef LEET_CODE_SUDOKU_SOLVER_HPP
#define LEET_CODE_SUDOKU_SOLVER_HPP

#include <vector>
#include <cassert>

namespace leet_code {
    constexpr unsigned int rows = 9, cols = rows;
    constexpr char blank = '.';

    bool can_fill(std::vector<std::vector<char>>& sudoku, int row, int col, char num)
    {
        // check row
        for (int c{0}; c<cols; c++) {
            if (sudoku[row][c]==num) {
                return false;
            }
        }
        // check col
        for (int r{0}; r<rows; r++) {
            if (sudoku[r][col]==num) {
                return false;
            }
        }
        int start_row{row-row%3};
        int start_col{col-col%3};
        for (int i{0}; i<3; i++) {
            for (int j{0}; j<3; j++) {
                if (sudoku[start_row+i][start_col+j]==num) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(std::vector<std::vector<char>>& sudoku, int row = 0, int col = 0)
    {
        if (row==rows-1 && col==cols) {
            return true;
        }
        // move to next row
        if (col==cols) {
            row++;
            col = 0;
        }
        // move to other cell
        if (sudoku[row][col]!=blank) {
            return solve(sudoku, row, col+1);
        }
        for (char num{'1'}; num<='9'; num++) {
            if (can_fill(sudoku, row, col, num)) {
                sudoku[row][col] = num;
                if (solve(sudoku, row, col+1)) {
                    return true;
                }
                sudoku[row][col] = blank;
            }
        }
        return false;
    }

    void solveSudoku(std::vector<std::vector<char>>& board)
    {
        solve(board);
    }
}

#endif //LEET_CODE_SUDOKU_SOLVER_HPP
