//
// Created by Tomáš Petříček on 01.08.2023.
//

#ifndef LEET_CODE_COMBINATIONS_HPP
#define LEET_CODE_COMBINATIONS_HPP

#include <vector>
#include <unordered_map>
#include <cassert>

namespace leet_code {
    void generate(std::vector<std::vector<int>>& res, std::vector<int>& seq, int last, int first = 1,
            std::size_t depth = 0)
    {
        if (depth==seq.size()) {
            res.emplace_back(seq);
        }
        else {
            for (int i{first}; i<=last; i++) {
                seq[depth] = i;
                generate(res, seq, last, i+1, depth+1);
            }
        }
    }

    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> seq(k, 0);
        generate(res, seq, n);
        return res;
    }

    struct sample {
        int n, k;
        std::vector<std::vector<int>> res;
    };

    void test_combine()
    {
        std::vector<sample> samples{
                {4, 2, {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}}},
                {1, 1, {{1}}},
        };
        for (auto& s: samples) {
            auto res = combine(s.n, s.k);
        }
    }
}

#endif //LEET_CODE_COMBINATIONS_HPP
