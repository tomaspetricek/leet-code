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
#include <unordered_map>

int null{0};

// https://leetcode.com/problems/lru-cache/
// Least Recently Used (LRU) cache
// inspired by: https://www.romaglushko.com/blog/design-lru-cache/
namespace leet_code {
    template<class T>
    class list {
        struct node {
            T item{0};
            node* prev{nullptr}, * next{nullptr};

            explicit node(const T& x)
                    :item(x) { }
            node(const T& val, node* prev, node* next)
                    :item{val}, prev{prev}, next{next} { }
        };

        node* head_{nullptr}, * tail_{nullptr};

    public:
        using node_ptr = node*;

        ~list()
        {
            while (head_) {
                auto curr = head_;
                head_ = head_->next;
                delete curr;
            }
        }

        void push_front(const T& val)
        {
            node* ahead = new node{val, nullptr, head_};
            if (!head_) {
                head_ = tail_ = ahead;
            }
            else {
                head_->prev = ahead;
                head_ = ahead;
            }
        }

        void move_front(node* ahead)
        {
            if (ahead->prev) {
                ahead->prev->next = ahead->next;
                if (ahead->next) {
                    ahead->next->prev = ahead->prev;
                }
                else {
                    tail_ = ahead->prev;
                }
                ahead->prev = nullptr;
                ahead->next = head_;
                head_->prev = ahead;
                head_ = ahead;
            }
        }

        void pop_back()
        {
            if (tail_) {
                node* remove = tail_;
                tail_ = tail_->prev;
                if (tail_) {
                    tail_->next = nullptr;
                }
                else {
                    head_ = nullptr;
                }
                delete remove;
            }
        }

        node* head() const
        {
            return head_;
        }

        node* tail() const
        {
            return tail_;
        }
    };

    class LRUCache {
        static constexpr int not_exists = -1;
        std::size_t size_{0}, capacity_{0};
        struct pair {
            int key, value;
        };
        list<pair> history_;
        std::unordered_map<int, list<pair>::node_ptr> vals_;

    public:
        explicit LRUCache(int capacity)
                :capacity_{static_cast<std::size_t>(capacity)} { }

        int get(int key)
        {
            int val = -1;
            const auto& it = vals_.find(key);
            if (it!=vals_.end()) {
                history_.move_front(it->second);
                val = it->second->item.value;
            }
            return val;
        }

        void put(int key, int value)
        {
            const auto& it = vals_.find(key);
            if (it!=vals_.end()) {
                if (it->second->item.value!=value) {
                    it->second->item.value = value;
                }
                history_.move_front(it->second);
            }
            else {
                if (size_==capacity_) {
                    vals_.erase(vals_.find(history_.tail()->item.key));
                    history_.pop_back();
                }
                else {
                    size_++;
                }
                history_.push_front(pair{key, value});
                vals_.insert({key, history_.head()});
            }
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
                {
                        {{task::init{2}, null}, {task::put{1, 1}, null}, {task::put{2, 2}, null}, {task::get{1}, 1},
                         {task::put{3, 3}, null}, {task::get{2}, -1}, {task::put{4, 4}, null}, {task::get{1}, -1},
                         {task::get{3}, 3}, {task::get{4}, 4}}
                },
        };
        LRUCache cache{0};
        for (const auto& s: samples) {
            for (std::size_t i{0}; i<s.tasks.size(); i++) {
                auto& t = s.tasks[i];
                if (t.second!=t.first(cache)) {
                    std::cout << i << std::endl;
                    assert(false);
                }
            }
        }
    }
}

#endif //LEET_CODE_LRU_CACHE_HPP
