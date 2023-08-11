//
// Created by Tomáš Petříček on 11.08.2023.
//

#ifndef LEET_CODE_COIN_CHANGE_2_HPP
#define LEET_CODE_COIN_CHANGE_2_HPP

#include <vector>
#include <cassert>
#include <iostream>

namespace leet_code {
    int change(int amount, std::vector<int>& coins)
    {
        std::vector<int> mem(amount+1, 0);
        mem[0] = 1; // one way to get amount 0
        for (auto coin : coins) {
            for (int i{coin}; i<=amount; i++) {
                mem[i] += mem[i-coin];
            }
        }
        return mem[amount];
    }

    struct sample {
        int amount;
        std::vector<int> coins;
        int res;
    };

    void test_change()
    {
        std::vector<sample> samples{
                {5, {1, 2, 5}, 4},
                {3, {2}, 0},
                {10, {10}, 1},
                {500, {1, 2, 5}, 12701},
                {500, {3, 5, 7, 8, 9, 10, 11}, 35502874},
        };
        for (auto& s: samples) {
            assert(change(s.amount, s.coins)==s.res);
        }
    }
}

#endif //LEET_CODE_COIN_CHANGE_2_HPP
