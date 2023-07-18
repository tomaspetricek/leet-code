//
// Created by Tomáš Petříček on 18.07.2023.
//

#ifndef LEET_CODE_LRU_CACHE_HPP
#define LEET_CODE_LRU_CACHE_HPP

#include <vector>
#include <variant>
#include <limits>
#include <ranges>
#include <functional>

int null = 0;

// https://leetcode.com/problems/lru-cache/
namespace leet_code {
    class LRUCache {
    public:
        LRUCache(int capacity)
        {

        }

        int get(int key)
        {
            return -1;
        }

        void put(int key, int value)
        {

        }
    };

    namespace task {
        struct init {
            int capacity;

            explicit init(int capacity)
                    :capacity(capacity) { }

            int operator()(LRUCache& cache) const
            {
                cache = LRUCache(capacity);
                return null;
            }
        };

        struct put {
            int key, value;

            explicit put(int key, int value)
                    :key(key), value(value) { }

            int operator()(LRUCache& cache) const
            {
                cache.put(key, value);
                return null;
            }
        };

        struct get {
            int key;

            explicit get(int key)
                    :key(key) { }

            int operator()(LRUCache& cache) const
            {
                return cache.get(key);
            }
        };
    }

    using task_t = std::function<int(LRUCache&)>;

    struct data {
        std::vector<std::pair<task_t, int>> tasks;
    };

    void test_lru_cache()
    {
        std::vector<data> samples{
                {{{task::init{2}, null}, {task::put{1, 1}, null}, {task::put{2, 2}, null}, {task::get{1}, 1},
                  {task::put{3, 3}, null}, {task::get{2}, -1}, {task::put{4, 4}, null}, {task::get{1}, -1},
                  {task::get{3}, 3}, {task::get{4}, 4}}},
        };
        LRUCache cache{0};
        for (const auto& s: samples) {
            for (auto& t: s.tasks) {
                if (t.second==t.first(cache)) {
                    assert(false);
                }
            }
        }
    }
}

#endif //LEET_CODE_LRU_CACHE_HPP
