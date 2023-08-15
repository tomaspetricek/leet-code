//
// Created by Tomáš Petříček on 14.08.2023.
//

#ifndef LEET_CODE_PUT_MARBLES_IN_BAGS_HPP
#define LEET_CODE_PUT_MARBLES_IN_BAGS_HPP

#include <vector>
#include <cassert>
#include <queue>

namespace leet_code {
    long long putMarbles(std::vector<int>& weights, int k)
    {
        
        return 0;
    }

    struct sample {
        std::vector<int> weights;
        int k;
        long long res;
    };

    void test_put_marbles()
    {
        std::vector<sample> samples{
                {{1, 3, 5, 1}, 2, 4},
                {{1, 3},       2, 0},
        };
        for (auto& s: samples) {
            assert(s.res==putMarbles(s.weights, s.k));
        }
    }
}

#endif //LEET_CODE_PUT_MARBLES_IN_BAGS_HPP
