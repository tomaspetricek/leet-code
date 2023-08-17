//
// Created by Tomáš Petříček on 16.08.2023.
//

#ifndef LEET_CODE_BALANCE_A_BINARY_SEARCH_TREE_HPP
#define LEET_CODE_BALANCE_A_BINARY_SEARCH_TREE_HPP

#include "../tree.hpp"
#include <vector>
#include <cassert>

// topic: binary search tree
// link: https://leetcode.com/problems/balance-a-binary-search-tree/
namespace leet_code {
    tree::node* balanceBST(tree::node* root)
    {
        return nullptr;
    }

    struct sample {
        tree::node* root, * res;
    };

    void test_balance_bst()
    {
        std::vector<sample> samples{
                {
                        tree::build({1, tree::empty, 2, tree::empty, 3, tree::empty, 4, tree::empty, tree::empty}),
                        tree::build({2, 1, 3, tree::empty, tree::empty, tree::empty, 4}),
                },
                {tree::build({2, 1, 3}), tree::build({2, 1, 3})},
        };
        for (auto& s: samples) {
            assert(tree::same(s.res, balanceBST(s.root)));
        }
    }
}

#endif //LEET_CODE_BALANCE_A_BINARY_SEARCH_TREE_HPP
