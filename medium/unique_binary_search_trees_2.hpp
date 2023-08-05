//
// Created by Tomáš Petříček on 05.08.2023.
//

#ifndef LEET_CODE_UNIQUE_BINARY_SEARCH_TREES_2_HPP
#define LEET_CODE_UNIQUE_BINARY_SEARCH_TREES_2_HPP

#include "../tree.hpp"
#include <vector>
#include <set>
#include <cassert>
#include <ranges>

namespace leet_code {
    std::vector<tree::node*> generate(int start, int end)
    {
        if (start>end) {
            return {nullptr};
        }
        if (start==end) {
            return {new tree::node{start}};
        }
        std::vector<tree::node*> trees;
        tree::node* root{nullptr};
        for (int i{start}; i<=end; i++) {
            // generate all possible left and right children
            std::vector<tree::node*> left = generate(start, i-1);
            std::vector<tree::node*> right = generate(i+1, end);
            for (tree::node* l: left) {
                for (tree::node* r: right) {
                    root = new tree::node{i};
                    root->left = l;
                    root->right = r;
                    trees.emplace_back(root);
                }
            }
        }
        return trees;
    }

    // left is lower than the right
    std::vector<tree::node*> generateTrees(int n)
    {
        return generate(1, n);
    }

    struct sample {
        int n;
        std::vector<tree::node*> trees;
    };

    void test_generate_trees()
    {
        std::vector<sample> samples{
                {3, {tree::build({1, tree::empty, 2, tree::empty, 3}), tree::build({1, tree::empty, 3, 2}),
                            tree::build({2, 1, 3}), tree::build({3, 1, tree::empty, tree::empty, 2}),
                            tree::build({3, 2, tree::empty, 1})}
                },
                {1, {tree::build({1})}},
        };
        for (const auto& s: samples) {
            auto trees = generateTrees(s.n);
            auto actual_trees = std::set(trees.begin(), trees.end());
            auto expect_trees = std::set(s.trees.begin(), s.trees.end());
            for (const auto& [actual, expect]: std::views::zip(actual_trees, expect_trees)) {
                assert(true);
            }
        }
    }
}
#endif //LEET_CODE_UNIQUE_BINARY_SEARCH_TREES_2_HPP
