//
// Created by Tomáš Petříček on 16.08.2023.
//

#ifndef LEET_CODE_IMPLEMENT_TRIE_HPP
#define LEET_CODE_IMPLEMENT_TRIE_HPP

#include <utility>
#include <vector>
#include <cassert>
#include <string>
#include <limits>
#include <iostream>
#include <unordered_map>

int null{std::numeric_limits<int>::quiet_NaN()};

// topic: blind 75
// link: https://leetcode.com/problems/implement-trie-prefix-tree/
namespace leet_code {
    namespace alphabet {
        static constexpr std::size_t size = 26;
        static constexpr char first = 'a';
    }

    class Trie {
        struct node {
            std::vector<node*> children;
            bool terminal{false};

            explicit node()
                    :children(alphabet::size, nullptr) { }
        };
        node root_;

    public:
        Trie() = default;

        // time complexity: O(n)
        void insert(const std::string& word)
        {
            node* curr{&root_};
            std::size_t i;
            for (auto c: word) {
                i = c-alphabet::first;
                if (!curr->children[i]) {
                    curr->children[i] = new node{};
                }
                curr = curr->children[i];
            }
            curr->terminal = true;
        }

        // time complexity: O(n)
        bool search(const std::string& word)
        {
            node* curr{&root_};
            std::size_t i;
            for (auto c: word) {
                i = c-alphabet::first;
                if (!curr->children[i]) {
                    return false;
                }
                curr = curr->children[i];
            }
            return curr->terminal;
        }

        // time complexity: O(n)
        bool startsWith(const std::string& prefix)
        {
            node* curr{&root_};
            std::size_t i;
            for (auto c: prefix) {
                i = c-alphabet::first;
                if (!curr->children[i]) {
                    return false;
                }
                curr = curr->children[i];
            }
            return true;
        }
    };

    namespace task {
        struct init {
            int operator()(Trie& trie) const
            {
                trie = Trie{};
                return null;
            }
        };

        struct insert {
            std::string word;

            explicit insert(std::string word)
                    :word{std::move(word)} { }

            int operator()(Trie& trie) const
            {
                trie.insert(word);
                return null;
            }
        };

        struct search {
            std::string word;

            explicit search(std::string word)
                    :word{std::move(word)} { }

            int operator()(Trie& trie) const
            {
                return trie.search(word);
            }
        };

        struct starts_with {
            std::string prefix;

            explicit starts_with(std::string prefix)
                    :prefix{std::move(prefix)} { }

            int operator()(Trie& trie) const
            {
                return trie.startsWith(prefix);
            }
        };
    }

    using task_t = std::function<int(Trie&)>;

    struct sample {
        std::vector<std::pair<task_t, int>> tasks;
    };

    void test_trie()
    {
        std::vector<sample> samples{
                {
                        {
                                {task::init{}, null},
                                {task::insert{"apple"}, null},
                                {task::search{"apple"}, true},
                                {task::search{"app"}, false},
                                {task::starts_with{"app"}, true},
                                {task::insert{"app"}, null},
                                {task::search{"app"}, true},
                        }
                }
        };
        Trie trie;
        for (const auto& s: samples) {
            for (std::size_t i{0}; i<s.tasks.size(); i++) {
                auto& t = s.tasks[i];
                if (t.second!=t.first(trie)) {
                    std::cout << "i: " << i << std::endl;
                    assert(false);
                }
            }
        }
    }
}

#endif //LEET_CODE_IMPLEMENT_TRIE_HPP
