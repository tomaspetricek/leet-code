//
// Created by Tomáš Petříček on 29.07.2023.
//

#ifndef LEET_CODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_HPP
#define LEET_CODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_HPP

#include <cassert>
#include <vector>
#include <algorithm>

namespace leet_code {
    int maxProfit(std::vector<int>& prices)
    {
        int profit{0}, buy{prices.front()};
        for (auto curr: prices) {
            buy = std::min(buy, curr);
            profit = std::max(profit, curr-buy);
        }
        return profit;
    }

    struct sample {
        std::vector<int> prices;
        int profit;
    };

    void test_max_profit()
    {
        std::vector<sample> samples{
                {{7, 1, 5, 3, 6, 4}, 5},
                {{7, 6, 4, 3, 1},    0},
                {{2, 4, 1},          2},
                {{7, 1, 5, 3, 6, 4}, 5},
        };
        for (auto& s: samples) {
            int profit = maxProfit(s.prices);
            assert(profit==s.profit);
        }
    }
}

#endif //LEET_CODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_HPP
