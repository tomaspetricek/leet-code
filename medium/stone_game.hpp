//
// Created by Tomáš Petříček on 15.08.2023.
//

#ifndef LEET_CODE_STONE_GAME_HPP
#define LEET_CODE_STONE_GAME_HPP

#include <vector>
#include <cassert>
#include <iostream>

// topic: dynamic programming
// link: https://leetcode.com/problems/stone-game/
namespace leet_code {
    bool stoneGame(std::vector<int>& piles)
    {
        return true;
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
