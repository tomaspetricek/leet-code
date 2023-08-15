//
// Created by Tomáš Petříček on 15.08.2023.
//

#ifndef LEET_CODE_STONE_GAME_HPP
#define LEET_CODE_STONE_GAME_HPP

#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <numeric>

// topic: dynamic programming
// link: https://leetcode.com/problems/stone-game/
namespace leet_code {
    constexpr int empty = -1;

    int alice_max_total(int f, int l, std::vector<int>& piles,
            std::vector<std::vector<int>>& cache)
    {
        if (f>l) {
            return 0;
        }
        if (cache[f][l]==empty) {
            int left{0}, right{0};
            // check alice turn
            if ((l-f)%2) {
                left = piles[f];
                right = piles[l];
            }
            cache[f][l] = std::max(alice_max_total(f+1, l, piles, cache)+left,
                    alice_max_total(f, l-1, piles, cache)+right);
        }
        return cache[f][l];
    }

    bool stoneGame(std::vector<int>& piles)
    {
        std::vector<std::vector<int>> cache(piles.size(), std::vector<int>(piles.size(), empty));
        int bob_max = std::accumulate(piles.begin(), piles.end(), 0)/2;
        return alice_max_total(0, static_cast<int>(piles.size()-1), piles, cache)>bob_max;
    }

    struct sample {
        std::vector<int> piles;
        bool res;
    };

    void test_stone_game()
    {
        std::vector<sample> samples{
                {{5, 3, 4, 5},  true},
                {{3, 7, 2, 3},  true},
                {{7, 8, 8, 10}, true},
        };
        for (auto& s: samples) {
            assert(s.res==stoneGame(s.piles));
        }
    }
}

#endif //LEET_CODE_STONE_GAME_HPP
