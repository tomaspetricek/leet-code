//
// Created by Tomáš Petříček on 15.08.2023.
//

#ifndef LEET_CODE_VALIDATE_BINARY_SEARCH_TREE_HPP
#define LEET_CODE_VALIDATE_BINARY_SEARCH_TREE_HPP

#include "../tree.hpp"
#include <vector>
#include <cassert>

// topic: binary search tree
// link: https://leetcode.com/problems/validate-binary-search-tree/
namespace leet_code {
    bool is_valid(tree::node* root, long min, long max)
    {
        if (root) {
            return root->val>min && root->val<max
                    && is_valid(root->left, min, root->val)
                    && is_valid(root->right, root->val, max);
        }
        return true;
    }

    bool isValidBST(tree::node* root)
    {
        return is_valid(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    }

    struct sample {
        tree::node* root;
        bool res;
    };

    void test_is_valid_bst()
    {
        std::vector<sample> samples{
                {tree::build({2, 1, 3}),                                 true},
                {tree::build({5, 1, 4, tree::empty, tree::empty, 3, 6}), false},
        };
        for (auto& s: samples) {
            assert(s.res==isValidBST(s.root));
        }
    }
}

#endif //LEET_CODE_VALIDATE_BINARY_SEARCH_TREE_HPP
