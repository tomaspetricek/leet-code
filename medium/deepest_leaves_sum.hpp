//
// Created by Tomáš Petříček on 15.08.2023.
//

#ifndef LEET_CODE_DEEPEST_LEAVES_SUM_HPP
#define LEET_CODE_DEEPEST_LEAVES_SUM_HPP

#include "../tree.hpp"

// topic: binary tree
// link: https://leetcode.com/problems/deepest-leaves-sum/description/
namespace leet_code {
    void search(tree::node* node, int depth, int& max_depth, int& sum)
    {
        if (node) {
            if (depth>max_depth) {
                sum = node->val;
                max_depth = depth;
            }
            else if (depth==max_depth) {
                sum += node->val;
            }
            search(node->right, depth+1, max_depth, sum);
            search(node->left, depth+1, max_depth, sum);
        }
    }

    int deepestLeavesSum(tree::node* root)
    {
        int sum, depth, max_depth;
        sum = depth = max_depth = 0;
        search(root, depth, max_depth, sum);
        return sum;
    }

    struct sample {
        tree::node* root;
        int res;
    };

    void test_deepest_leaves_sum()
    {
        std::vector<sample> samples{
                {tree::build({1, 2, 3, 4, 5, tree::empty, 6, 7, tree::empty, tree::empty, tree::empty, tree::empty, 8}),
                                   15},
                {tree::build({6, 7, 8, 2, 7, 1, 3, 9, tree::empty, 1, 4, tree::empty, tree::empty, tree::empty,
                              5}), 19},
        };
        for (auto& s: samples) {
            assert(s.res==deepestLeavesSum(s.root));
        }
    }
}

#endif //LEET_CODE_DEEPEST_LEAVES_SUM_HPP
