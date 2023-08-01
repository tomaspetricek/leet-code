//
// Created by Tomáš Petříček on 01.08.2023.
//

#ifndef LEET_CODE_DAILY_TEMPERATURES_HPP
#define LEET_CODE_DAILY_TEMPERATURES_HPP

#include <vector>
#include <stack>
#include <map>

namespace leet_code {
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        std::vector<int> wait(temperatures.size(), 0);
        std::stack<std::pair<int, int>> mem;
        for (int i{0}; i<temperatures.size(); i++) {
            // assign distance to all lower
            while (!mem.empty() && temperatures[i]>mem.top().first) {
                wait[mem.top().second] = i-mem.top().second;
                mem.pop();
            }
            mem.push({temperatures[i], i});
        }
        return wait;
    }

    struct sample {
        std::vector<int> temperatures, res;
    };

    void test_daily_temperatures()
    {
        std::vector<sample> samples{
                {{73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0}},
                {{30, 40, 50, 60},                 {1, 1, 1, 0}},
                {{30, 60, 90},                     {1, 1, 0}},
        };
        for (auto& s: samples) {
            auto res = dailyTemperatures(s.temperatures);
            assert(res==s.res);
        }
    }
}

#endif //LEET_CODE_DAILY_TEMPERATURES_HPP
