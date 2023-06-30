//
// Created by Tomáš Petříček on 26.06.2023.
//

#ifndef LEET_CODE_PASCALS_TRIANGLE_HPP
#define LEET_CODE_PASCALS_TRIANGLE_HPP

#include <vector>

std::vector<std::vector<int>> generate_pascals_triangle(int n_rows)
{
    using row_t = std::vector<int>;
    int edge = 1;
    std::vector<row_t> triangle;
    triangle.reserve(n_rows);

    for (std::size_t r{0}; r<n_rows; r++) {
        row_t row(r+1);
        row.front() = row.back() = edge;

        for (std::size_t c{1}; c<(row.size()+1)/2; c++)
            row[c] = row[row.size()-c-1] = triangle.back()[c-1]+triangle.back()[c];

        triangle.emplace_back(std::move(row));
    }
    return triangle;
}

void test_pascals_triangle()
{
    auto triangle = generate_pascals_triangle(10);
}

#endif //LEET_CODE_PASCALS_TRIANGLE_HPP
