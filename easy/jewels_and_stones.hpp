//
// Created by Tomáš Petříček on 03.08.2023.
//

#ifndef LEET_CODE_JEWELS_AND_STONES_HPP
#define LEET_CODE_JEWELS_AND_STONES_HPP

#include <vector>
#include <string>
#include <unordered_set>
#include <cassert>

namespace leet_code {
    int numJewelsInStones(std::string jewels, std::string stones)
    {
        int count{0};
        for (auto j: jewels) {
            for (auto s: stones) {
                if (j==s) {
                    count++;
                }
            }
        }
        return count;
    }

    struct sample {
        std::string jewels, stones;
        int count;
    };

    void test_num_jewels_in_stones()
    {
        std::vector<sample> samples{
                {{"aA"}, {"aAAbbbb"}, 3},
                {{"z"},  {"ZZ"},      0},
        };
        for (const auto& s: samples) {
            assert(s.count==numJewelsInStones(s.jewels, s.stones));
        }
    }
}

#endif //LEET_CODE_JEWELS_AND_STONES_HPP
