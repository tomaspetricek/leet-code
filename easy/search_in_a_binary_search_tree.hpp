//
// Created by Tomáš Petříček on 16.08.2023.
//

#ifndef LEET_CODE_SEARCH_IN_A_BINARY_SEARCH_TREE_HPP
#define LEET_CODE_SEARCH_IN_A_BINARY_SEARCH_TREE_HPP

#include <vector>
#include <cassert>
#include "../tree.hpp"

namespace leet_code {
    tree::node* searchBST(tree::node* root, int val)
    {
        if (root) {
            if (root->val==val) {
                return root;
            }
            if (val<root->val) {
                return searchBST(root->left, val);
            }
            else {
                return searchBST(root->right, val);
            }
        }
        return nullptr;
    }
}

#endif //LEET_CODE_SEARCH_IN_A_BINARY_SEARCH_TREE_HPP
