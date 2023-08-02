//
// Created by Tomáš Petříček on 02.08.2023.
//

#ifndef LEET_CODE_SPIRAL_MATRIX_HPP
#define LEET_CODE_SPIRAL_MATRIX_HPP

#include <vector>

namespace leet_code {
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        std::vector<int> spiral;
        int i, rows{static_cast<int>(matrix.size())}, cols{static_cast<int>(matrix[0].size())},
                min_row{0}, max_row{rows-1}, min_col{0}, max_col{cols-1};
        while (min_row<=max_row && min_col<=max_col) {
            for (i = min_col; i<=max_col && min_row<=max_row; i++) {
                spiral.push_back(matrix[min_row][i]);
            }
            min_row++;
            for (i = min_row; i<=max_row && min_col<=max_col; i++) {
                spiral.push_back(matrix[i][max_col]);
            }
            max_col--;
            for (i = max_col; i>=min_col && min_row<=max_row; i--) {
                spiral.push_back(matrix[max_row][i]);
            }
            max_row--;
            for (i = max_row; i>=min_row && min_col<=max_col; i--) {
                spiral.push_back(matrix[i][min_col]);
            }
            min_col++;
        }
        return spiral;
    }

    struct sample {
        std::vector<std::vector<int>> matrix;
        std::vector<int> spiral;
    };

    void test_spiral_order()
    {
        std::vector<sample> samples{
                {{{1, 2, 3},    {4, 5, 6},    {7, 8,  9}},      {1, 2, 3, 6, 9, 8,  7,  4,  5}},
                {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}},
        };
        for (auto& s: samples) {
            auto spiral = spiralOrder(s.matrix);
            assert(spiral==s.spiral);
        }
    }
}

#endif //LEET_CODE_SPIRAL_MATRIX_HPP
