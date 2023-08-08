//
// Created by Tomáš Petříček on 08.08.2023.
//

#ifndef LEET_CODE_SORT_THE_STUDENTS_BY_THEIR_KTH_SCORE_HPP
#define LEET_CODE_SORT_THE_STUDENTS_BY_THEIR_KTH_SCORE_HPP

#include <vector>
#include <algorithm>

namespace leet_code {
    std::vector<std::vector<int>> sortTheStudents(std::vector<std::vector<int>>& score, int k)
    {
        std::sort(score.begin(), score.end(), [&](const auto& a, const auto& b) {
            return a[k]>b[k];
        });
        return score;
    }

    struct sample {
        std::vector<std::vector<int>> in;
        int k;
        std::vector<std::vector<int>> out;
    };

    void test_sort_the_students()
    {
        std::vector<sample> samples{
                {{{10, 6, 9, 1}, {7, 5, 11, 2}, {4, 8, 3, 15}}, 2, {{7, 5, 11, 2}, {10, 6, 9, 1}, {4, 8, 3, 15}}},
                {{{3,  4},       {5, 6}},                       0, {{5, 6},        {3,  4}}},
        };
        for (auto& s: samples) {
            assert(s.out==sortTheStudents(s.in, s.k));
        }
    }
}

#endif //LEET_CODE_SORT_THE_STUDENTS_BY_THEIR_KTH_SCORE_HPP
