//
// Created by Tomáš Petříček on 15.08.2023.
//

#ifndef LEET_CODE_FIND_A_CORRESPONDING_NODE_OF_A_BINARY_TREE_IN_A_CLONE_OF_THAT_TREE_HPP
#define LEET_CODE_FIND_A_CORRESPONDING_NODE_OF_A_BINARY_TREE_IN_A_CLONE_OF_THAT_TREE_HPP

#include "../tree.hpp"

// topic: binary tree
// link: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
namespace leet_code {
    tree::node* getTargetCopy(tree::node* original, tree::node* cloned, tree::node* target)
    {
        if (original) {
            if (cloned->val==target->val) {
                return cloned;
            }
            else {
                tree::node* cloned_target = getTargetCopy(original->right, cloned->right, target);
                if (cloned_target) {
                    return cloned_target;
                }
                return getTargetCopy(original->left, cloned->left, target);
            }
        }
        return nullptr;
    }
}

#endif //LEET_CODE_FIND_A_CORRESPONDING_NODE_OF_A_BINARY_TREE_IN_A_CLONE_OF_THAT_TREE_HPP
