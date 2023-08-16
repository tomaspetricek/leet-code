//
// Created by Tomáš Petříček on 16.08.2023.
//

#ifndef LEET_CODE_BINARY_SEARCH_TREE_TO_GREATER_SUM_TREE_HPP
#define LEET_CODE_BINARY_SEARCH_TREE_TO_GREATER_SUM_TREE_HPP

#include <vector>
#include <cassert>
#include "../tree.hpp"

namespace leet_code {
    void search(tree::node* node, int& sum)
    {
        if (node) {
            search(node->right, sum);
            node->val = (sum += node->val);
            search(node->left, sum);
        }
    }

    tree::node* bstToGst(tree::node* root)
    {
        int sum{0};
        search(root, sum);
        return root;
    }
}

#endif //LEET_CODE_BINARY_SEARCH_TREE_TO_GREATER_SUM_TREE_HPP
