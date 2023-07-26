//
// Created by Tomáš Petříček on 26.07.2023.
//

#ifndef LEET_CODE_TOP_K_FREQUENT_ELEMENTS_HPP
#define LEET_CODE_TOP_K_FREQUENT_ELEMENTS_HPP

#include <cassert>
#include <vector>
#include <map>
#include <queue>

namespace leet_code {
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        // count occurrences
        std::unordered_map<int, int> freqs;
        for (auto num: nums) {
            freqs[num] += 1;
        }
        // sort based on the frequency
        std::priority_queue<std::pair<int, int>> queue;
        for (const auto&[val, count] : freqs) {
            queue.push(std::pair<int, int>{count, val});
        }
        // retrieve the most frequent
        std::vector<int> res;
        res.reserve(k);
        for (std::size_t i{0}; i<k; i++) {
            res.emplace_back(queue.top().second);
            queue.pop();
        }
        return res;
    }

    struct data {
        std::vector<int> nums;
        int k;
        std::vector<int> res;
    };

    void test_top_k_frequent()
    {
        std::vector<data> samples{
                {{1, 1, 1, 2, 2, 3},    2, {1, 2}},
                {{1, 1, 2, 2, 2, 2, 3}, 2, {2, 1}},
                {{1},                   1, {1}},
        };
        for (auto& s: samples) {
            auto res = topKFrequent(s.nums, s.k);
            if (res!=s.res) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_TOP_K_FREQUENT_ELEMENTS_HPP
