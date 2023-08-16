//
// Created by Tomáš Petříček on 16.08.2023.
//

#ifndef LEET_CODE_RANGE_SUM_OF_BST_HPP
#define LEET_CODE_RANGE_SUM_OF_BST_HPP

#include "../tree.hpp"
#include <vector>
#include <cassert>

namespace leet_code {
    void search(tree::node* node, int low, int high, int& sum)
    {
        if (node) {
            if (node->val>=low && node->val<=high) {
                sum += node->val;
            }
            if (node->val>low) {
                search(node->left, low, high, sum);
            }
            if (node->val<high) {
                search(node->right, low, high, sum);
            }
        }
    }

    int rangeSumBST(tree::node* root, int low, int high)
    {
        int sum{0};
        search(root, low, high, sum);
        return sum;
    }

    struct sample {
        tree::node* root;
        int low, high, res;
    };

    void test_range_sum_bst()
    {
        std::vector<sample> samples{
                {tree::build({10, 5, 15, 3, 7, tree::empty, 18}), 7, 15, 32},
                {tree::build({10, 5, 15, 3, 7, 13, 18, 1, tree::empty, 6}), 6, 10, 23},
        };
        for (auto& s: samples) {
            assert(s.res==rangeSumBST(s.root, s.low, s.high));
        }
    }
}

#endif //LEET_CODE_RANGE_SUM_OF_BST_HPP
