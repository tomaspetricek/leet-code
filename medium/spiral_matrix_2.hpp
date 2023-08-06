//
// Created by Tomáš Petříček on 06.08.2023.
//

#ifndef LEET_CODE_SPIRAL_MATRIX_2_HPP
#define LEET_CODE_SPIRAL_MATRIX_2_HPP

#include <vector>

namespace leet_code {
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        std::vector<std::vector<int>> mat(n, std::vector<int>(n, 0));
        int i, top, down, right, left, val{1};
        top = right = 0, down = left = n-1;
        while (top<=down && right<=left) {
            // right
            for (i = right; i<=left; i++) {
                mat[top][i] = val++;
            }
            top++;
            // down
            for (i = top; i<=down; i++) {
                mat[i][left] = val++;
            }
            left--;
            // left
            for (i = left; i>=right; i--) {
                mat[down][i] = val++;
            }
            down--;
            // up
            for (i = down; i>=top; i--) {
                mat[i][right] = val++;
            }
            right++;
        }
        return mat;
    }

    void test_generate_matrix()
    {
        generateMatrix(5);
    }
}

#endif //LEET_CODE_SPIRAL_MATRIX_2_HPP
